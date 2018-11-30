#include "Postfix.h"
#include <string.h>

Postfix* Postfix_new(int givenMaxNumberOfTokens) { // 200
	//Postfix ��ü ����
	Postfix* _this = NewObject(Postfix);
	_this->_maxNumberOfTokens = givenMaxNumberOfTokens;
	_this->_expression = NewVector(char, givenMaxNumberOfTokens); // 200ũ���� �迭 ����
	// �迭�� �������� �������ش�.

	//_this->_operandStack = Stack_new(givenMaxNumberOfTokens);
	_this->_operandStack = Stack_new();
	return _this;
}

void Postfix_delete(Postfix* _this) {
	// Postfix ��ü ����
	Stack_delete(_this->_operandStack);
	free(_this->_expression);
	free(_this);
}


PostfixError Postfix_evaluate(Postfix* _this) {
	
	int operand, operand1, operand2, calculated;
	char currentToken;
	int i = 0;
	Stack_reset(_this->_operandStack);	// ��� ���� �� ������ Stack reset
	
	while (_this->_expression[i] != '\0') {
		currentToken = _this->_expression[i];
		if (currentToken >= '0' && currentToken <= '9') {
			operand = (currentToken - '0');		 // ���ڷ� ��ȯ�Ѵ�.
			if (Stack_isFull(_this->_operandStack)) {
				Postfix_showTokenAndStack(_this, currentToken);
				return PostfixError_ExpressionTooLong;
			}
			else {
				Stack_push(_this->_operandStack, operand);
			}
		}
		else {
			if (currentToken == '+') {	//������ ��
				if (Stack_size(_this->_operandStack) >= 2) {
					operand2 = Stack_pop(_this->_operandStack);
					operand1 = Stack_pop(_this->_operandStack);
					calculated = operand1 + operand2;
					Stack_push(_this->_operandStack, calculated);
				}
				else {
					Postfix_showTokenAndStack(_this, currentToken);
					return PostfixError_OperandsTooFew;	//������ �ʹ� ª�ٴ� �޽��� ���.
				}
			}
			else if (currentToken == '-') {	//������ ��
				if (Stack_size(_this->_operandStack) >= 2) {
					operand2 = Stack_pop(_this->_operandStack);
					operand1 = Stack_pop(_this->_operandStack);
					calculated = operand1 - operand2;
					Stack_push(_this->_operandStack, calculated);
				}
				else {
					Stack_pop(_this->_operandStack);
					Postfix_showTokenAndStack(_this, currentToken);
					return PostfixError_OperandsTooFew;
				}
			}
			else if (currentToken == '*') {	//������ ��
				if (Stack_size(_this->_operandStack) >= 2) {
					operand2 = Stack_pop(_this->_operandStack);
					operand1 = Stack_pop(_this->_operandStack);
					calculated = operand1 * operand2;
					Stack_push(_this->_operandStack, calculated);
				}
				else {
					Stack_pop(_this->_operandStack);
					Postfix_showTokenAndStack(_this, currentToken);
					return PostfixError_OperandsTooFew;
				}
			}
			else if (currentToken == '/') {	//�������� ��
				if (Stack_size(_this->_operandStack) >= 2) {
					operand2 = Stack_pop(_this->_operandStack);
					operand1 = Stack_pop(_this->_operandStack);
					if (operand2 == 0) {
						return PostfixError_DivideByZero;
					}
					calculated = operand1 / operand2;
					Stack_push(_this->_operandStack, calculated);
				}
				else {
					Stack_pop(_this->_operandStack);
					Postfix_showTokenAndStack(_this, currentToken);
					return PostfixError_OperandsTooFew;
				}
			}
			else if (currentToken == '%') {	//������������ ��
				if (Stack_size(_this->_operandStack) >= 2) {
					operand2 = Stack_pop(_this->_operandStack);
					operand1 = Stack_pop(_this->_operandStack);
					calculated = operand1 % operand2;
					Stack_push(_this->_operandStack, calculated);
				}
				else {
					Stack_pop(_this->_operandStack);
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
	
	if (Stack_size(_this->_operandStack) == 1) {
		_this->_evaluatedValue = Stack_pop(_this->_operandStack); // ���� ���.
	}
	else if (Stack_size(_this->_operandStack) > 1) {
		return PostfixError_OperandsTooMany; // ������ ���� �� ���� ��� ���� �޽��� ���.
	}
	
	return PostfixError_None; // ���� ���� X
}


void Postfix_setExpression(Postfix* _this, char* anExpression) {
	strcpy(_this->_expression, anExpression); // �Է¹��� ������ ����.
}


int Postfix_evaluatedValue(Postfix* _this) {
	return (_this->_evaluatedValue);
} // ��� ��� ��ȯ.

void Postfix_showTokenAndStack(Postfix* _this, char Token) {
	char element; // element ����.
	AppIO_out_showToken(Token);	// ù �� ° ��ū�� �����ش�.
	AppIO_out_bottomOfStack();

	//for (int i = 0; i<Stack_size(_this->_operandStack); i++) {	//������ ũ�⸸ŭ �ݺ�
	//	element = Stack_elementAt(_this->_operandStack, i);	//������ i��° ����
	//	AppIO_out_element(element);	// �ش� ���� ���.
	//}

	Stack_showAll(_this->_operandStack); // ������ ��� ���Ҹ� ���.

	AppIO_out_topOfStack();
	AppIO_out_newLine();
}