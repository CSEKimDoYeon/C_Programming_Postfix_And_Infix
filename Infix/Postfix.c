#include "Postfix.h"
#include <string.h>

Postfix* Postfix_new(int givenMaxNumberOfTokens) { // 200
												   //Postfix ��ü ����
	Postfix* _this = NewObject(Postfix);
	_this->_maxNumberOfTokens = givenMaxNumberOfTokens;
	_this->_expression = NewVector(char, givenMaxNumberOfTokens); // 200ũ���� �迭 ����
															
	_this->_operandStack = VStack_new();
	return _this;
}

void Postfix_delete(Postfix* _this) {
	// Postfix ��ü ����
	VStack_delete(_this->_operandStack);
	free(_this->_expression);
	free(_this);
}


PostfixError Postfix_evaluate(Postfix* _this) {

	int operand, operand1, operand2, calculated;
	char currentToken;
	int i = 0;
	VStack_reset(_this->_operandStack);	// ��� ���� �� ������ Stack reset

	while (_this->_expression[i] != '\0') {
		currentToken = _this->_expression[i];
		if (currentToken >= '0' && currentToken <= '9') {
			operand = (currentToken - '0');		 // ���ڷ� ��ȯ�Ѵ�.
			if (VStack_isFull(_this->_operandStack)) {
				Postfix_showTokenAndStack(_this, currentToken);
				return PostfixError_ExpressionTooLong;
			}
			else {
				VStack_push(_this->_operandStack, operand);
			}
		}
		else {
			if (currentToken == '+') {	//������ ��
				if (VStack_size(_this->_operandStack) >= 2) {
					operand2 = VStack_pop(_this->_operandStack);
					operand1 = VStack_pop(_this->_operandStack);
					calculated = operand1 + operand2;
					VStack_push(_this->_operandStack, calculated);
				}
				else {
					Postfix_showTokenAndStack(_this, currentToken);
					return PostfixError_OperandsTooFew;	//������ �ʹ� ª�ٴ� �޽��� ���.
				}
			}
			else if (currentToken == '-') {	//������ ��
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
			else if (currentToken == '*') {	//������ ��
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
			else if (currentToken == '/') {	//�������� ��
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
			else if (currentToken == '%') {	//������������ ��
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
			else if (currentToken == '^') {	//���������� ��
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
				return PostfixError_UnknownOperator;//�� �� ���ٴ� ���ڰ� �����Ѵٴ� ���� �޽��� ���.
			}
		}
		Postfix_showTokenAndStack(_this, currentToken);	//��� ��ū�� ���� ���.
		i++;
	}

	if (VStack_size(_this->_operandStack) == 1) {
		_this->_evaluatedValue = VStack_pop(_this->_operandStack); // ���� ���.
	}
	else if (VStack_size(_this->_operandStack) > 1) {
		return PostfixError_OperandsTooMany; // ������ ���� �� ���� ��� ���� �޽��� ���.
	}

	return PostfixError_None; // ���� ���� X
}

void Postfix_setExpression(Postfix* _this, char* anExpression) {
	strcpy(_this->_expression, anExpression); // �Է¹��� ������ ����.
	printf(">>��ȯ�� Postfix: ");
	for (int i = 0; i < strlen(_this->_expression); i++) {
		printf("%c ", _this->_expression[i]);
	}
	printf("\n");
}


int Postfix_evaluatedValue(Postfix* _this) {
	return (_this->_evaluatedValue);
} // ��� ��� ��ȯ.

void Postfix_showTokenAndStack(Postfix* _this, char Token) {
	char element; // element ����.
	AppIO_out_showToken(Token);	// ù �� ° ��ū�� �����ش�.
	AppIO_out_bottomOfVStack();

	VStack_showAll(_this->_operandStack); // ������ ��� ���Ҹ� ���.

	AppIO_out_topOfVStack();
	AppIO_out_newLine();
}