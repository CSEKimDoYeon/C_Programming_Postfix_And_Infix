#include "Postfix.h"
#include <string.h>

Postfix* Postfix_new(int givenMaxNumberOfTokens) { // 200
												   //Postfix 객체 생성
	Postfix* _this = NewObject(Postfix);
	_this->_maxNumberOfTokens = givenMaxNumberOfTokens;
	_this->_expression = NewVector(char, givenMaxNumberOfTokens); // 200크기의 배열 생성
															
	_this->_operandStack = VStack_new();
	return _this;
}

void Postfix_delete(Postfix* _this) {
	// Postfix 객체 삭제
	VStack_delete(_this->_operandStack);
	free(_this->_expression);
	free(_this);
}


PostfixError Postfix_evaluate(Postfix* _this) {

	int operand, operand1, operand2, calculated;
	char currentToken;
	int i = 0;
	VStack_reset(_this->_operandStack);	// 계산 진행 할 때마다 Stack reset

	while (_this->_expression[i] != '\0') {
		currentToken = _this->_expression[i];
		if (currentToken >= '0' && currentToken <= '9') {
			operand = (currentToken - '0');		 // 숫자로 변환한다.
			if (VStack_isFull(_this->_operandStack)) {
				Postfix_showTokenAndStack(_this, currentToken);
				return PostfixError_ExpressionTooLong;
			}
			else {
				VStack_push(_this->_operandStack, operand);
			}
		}
		else {
			if (currentToken == '+') {	//덧셈일 때
				if (VStack_size(_this->_operandStack) >= 2) {
					operand2 = VStack_pop(_this->_operandStack);
					operand1 = VStack_pop(_this->_operandStack);
					calculated = operand1 + operand2;
					VStack_push(_this->_operandStack, calculated);
				}
				else {
					Postfix_showTokenAndStack(_this, currentToken);
					return PostfixError_OperandsTooFew;	//수식이 너무 짧다는 메시지 출력.
				}
			}
			else if (currentToken == '-') {	//뺄셈일 때
				if (VStack_size(_this->_operandStack) >= 2) {
					operand2 = VStack_pop(_this->_operandStack);
					operand1 = VStack_pop(_this->_operandStack);
					calculated = operand1 - operand2;
					VStack_push(_this->_operandStack, calculated);
				}
				else {
					VStack_pop(_this->_operandStack);
					Postfix_showTokenAndStack(_this, currentToken);
					return PostfixError_OperandsTooFew;
				}
			}
			else if (currentToken == '*') {	//곱셈일 때
				if (VStack_size(_this->_operandStack) >= 2) {
					operand2 = VStack_pop(_this->_operandStack);
					operand1 = VStack_pop(_this->_operandStack);
					calculated = operand1 * operand2;
					VStack_push(_this->_operandStack, calculated);
				}
				else {
					VStack_pop(_this->_operandStack);
					Postfix_showTokenAndStack(_this, currentToken);
					return PostfixError_OperandsTooFew;
				}
			}
			else if (currentToken == '/') {	//나누기일 때
				if (VStack_size(_this->_operandStack) >= 2) {
					operand2 = VStack_pop(_this->_operandStack);
					operand1 = VStack_pop(_this->_operandStack);
					if (operand2 == 0) {
						return PostfixError_DivideByZero;
					}
					calculated = operand1 / operand2;
					VStack_push(_this->_operandStack, calculated);
				}
				else {
					VStack_pop(_this->_operandStack);
					Postfix_showTokenAndStack(_this, currentToken);
					return PostfixError_OperandsTooFew;
				}
			}
			else if (currentToken == '%') {	//나머지연산일 때
				if (VStack_size(_this->_operandStack) >= 2) {
					operand2 = VStack_pop(_this->_operandStack);
					operand1 = VStack_pop(_this->_operandStack);
					calculated = operand1 % operand2;
					VStack_push(_this->_operandStack, calculated);
				}
				else {
					VStack_pop(_this->_operandStack);
					Postfix_showTokenAndStack(_this, currentToken);
					return PostfixError_OperandsTooFew;
				}
			}
			else if (currentToken == '^') {	//제곱연산일 때
				if (VStack_size(_this->_operandStack) >= 2) {
					operand2 = VStack_pop(_this->_operandStack);
					operand1 = VStack_pop(_this->_operandStack);
					calculated = operand1;
					for (int k = 0; k < operand2 - 1; k++) {
						calculated = calculated*operand1;
					}
					VStack_push(_this->_operandStack, calculated);
				}
				else {
					VStack_pop(_this->_operandStack);
					Postfix_showTokenAndStack(_this, currentToken);
					return PostfixError_OperandsTooFew;
				}
			}
			else {
				Postfix_showTokenAndStack(_this, currentToken);
				return PostfixError_UnknownOperator;//알 수 없다는 문자가 존재한다는 에러 메시지 출력.
			}
		}
		Postfix_showTokenAndStack(_this, currentToken);	//모든 토큰의 정보 출력.
		i++;
	}

	if (VStack_size(_this->_operandStack) == 1) {
		_this->_evaluatedValue = VStack_pop(_this->_operandStack); // 수식 계산.
	}
	else if (VStack_size(_this->_operandStack) > 1) {
		return PostfixError_OperandsTooMany; // 연산자 수가 더 많을 경우 에러 메시지 출력.
	}

	return PostfixError_None; // 에러 검출 X
}

void Postfix_setExpression(Postfix* _this, char* anExpression) {
	strcpy(_this->_expression, anExpression); // 입력받은 수식을 복사.
	printf(">>변환된 Postfix: ");
	for (int i = 0; i < strlen(_this->_expression); i++) {
		printf("%c ", _this->_expression[i]);
	}
	printf("\n");
}


int Postfix_evaluatedValue(Postfix* _this) {
	return (_this->_evaluatedValue);
} // 계산 결과 반환.

void Postfix_showTokenAndStack(Postfix* _this, char Token) {
	char element; // element 선언.
	AppIO_out_showToken(Token);	// 첫 번 째 토큰을 보여준다.
	AppIO_out_bottomOfVStack();

	VStack_showAll(_this->_operandStack); // 스택의 모든 원소를 출력.

	AppIO_out_topOfVStack();
	AppIO_out_newLine();
}