#include <ctype.h>
#include <stdio.h>
#include <string.h>

#include "Infix.h"
#include "OStack.h"

Infix* Infix_new(int givenMaxNumberOfTokens) {
	//Postfix ��ü ����
	Infix* _this = NewObject(Infix);
	//_this->_maxNumberOfTokens = givenMaxNumberOfTokens;
	_this->_infixExpression = NewVector(char, givenMaxNumberOfTokens); // �ϴ��� �迭 ũ�� 10����.
																	   //_this->_operandStack = Stack_new(givenMaxNumberOfTokens);
	_this->_postfixExpression = NewVector(char, givenMaxNumberOfTokens);
	//_this->_operandStack = VStack_new();
	_this->_operatorStack = OStack_new();
	return _this;
}

void Infix_delete(Infix* _this) {
	// Postfix ��ü ����
	OStack_delete(_this->_operatorStack);
	free(_this->_infixExpression);
	free(_this);
}

void Infix_setExpression(Infix* _this, char* newExpression) {
	strcpy(_this->_infixExpression, newExpression); // �Է¹��� ������ ����.
}// expression�� ����ڰ� �Է��� ����.

Boolean Infix_toPostfix(Infix* _this) {
	int i = 0;
	int p = 0;
	char currentToken = 0, poppedToken = 0;
	int  infixSize = strlen(_this->_infixExpression);
	strcpy(_this->_postfixExpression, _this->_infixExpression);
	_this->_operatorStack = OStack_new();
	for (int k = 0; k < infixSize; k++) {
		_this->_postfixExpression[k] = 0;
	}
	while (i < infixSize) { // infix�� �����ŭ �ݺ�.
		currentToken = _this->_infixExpression[i++];
		if (currentToken >= '0' && currentToken <= '9') {  // operand �� ���.  
			_this->_postfixExpression[p] = currentToken;
			p++; // postfix�� �־��ְ� p�� ++ ó�����ش�.
		}
		else {
			// operator �� ���.
			if (currentToken == ')') {
				if (OStack_isEmpty(_this->_operatorStack)) {
					return false;   // ���� ���� 
				}
				else {
					poppedToken = OStack_pop(_this->_operatorStack);
					while (poppedToken != '(') {
						_this->_postfixExpression[p++] = poppedToken;
						if (OStack_isEmpty(_this->_operatorStack)) {
							return true;   // ���� ���� 
						}
						else {
							poppedToken = OStack_pop(_this->_operatorStack);
						}
					}
				}
				Infix_showTokenAndOStack(_this, currentToken);
			}
			else {
				int inComingPrecedence = Infix_inComingPrecedence(currentToken);
				while (!OStack_isEmpty(_this->_operatorStack) && Infix_inStackPrecedence(OStack_peek(_this->_operatorStack)) >= inComingPrecedence) {
					poppedToken = OStack_pop(_this->_operatorStack);
					_this->_postfixExpression[p++] = poppedToken;
				} OStack_push(_this->_operatorStack, currentToken);
			}
		}
		Infix_showTokenAndOStack(_this, currentToken);
	}
	while (!OStack_isEmpty(_this->_operatorStack)) {
		poppedToken = OStack_pop(_this->_operatorStack);
		_this->_postfixExpression[p++] = poppedToken;
	}
	//��ȯ�� postfix���
	return true;
}


char* Infix_postfix(Infix* _this) {
	return _this->_postfixExpression;
}

void Infix_showTokenAndOStack(Infix* _this, char aToken) {
	char element; // element ����.
	AppIO_out_showToken(aToken);	// ù �� ° ��ū�� �����ش�.
	AppIO_out_bottomOfOStack();

	OStack_showAll(_this->_operatorStack); // ������ ��� ���Ҹ� ���.

	AppIO_out_topOfOStack();
	AppIO_out_newLine();
}

int Infix_inComingPrecedence(char aToken)
{
	// �� �������� �Է� ��ū ������ �켱 ������ �����ش�
	if (aToken == '(') {
		return 20;
	}
	else if (aToken == ')') {
		return 19;
	}
	else if (aToken == '^') {
		return 17;
	}
	else if (aToken == '*') {
		return 13;
	}
	else if (aToken == '/') {
		return 13;
	}
	else if (aToken == '%') {
		return 13;
	}
	else if (aToken == '+') {
		return 12;
	}
	else if (aToken == '-') {
		return 12;
	}
	else if (aToken == '$') {
		return 0;
	}
	else {
		return -1;
	}
}

int Infix_inStackPrecedence(char aToken)
{
	// �� �������� ���� �ȿ����� �켱 ������ �����ش�.
	if (aToken == '^') {
		return 16;
	}
	else if (aToken == '*') {
		return 13;
	}
	else if (aToken == '/') {
		return 13;
	}
	else if (aToken == '%') {
		return 13;
	}
	else if (aToken == '+') {
		return 12;
	}
	else if (aToken == '-') {
		return 12;
	}
	else if (aToken == '$') {
		return 0;
	}
	else {
		return -1;
	}
}