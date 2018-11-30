#pragma once
#include "Common.h"
#include "OStack.h"

#define DEFAULT_MAX_NUMBER_OF_TOKENS 10

typedef struct _Infix Infix;

struct _Infix {
	char* _infixExpression; // AppController ���� �����ش�
							//char* _postfixExpression[DEFAULT_MAX_NUMBER_OF_TOKENS];
	char* _postfixExpression;

	// postfix�� ��ȯ�� ����� �̰��� ����ȴ�.
	OStack* _operatorStack;
}; Infix* Infix_new(int givenMaxNumberOfTokens);
void Infix_delete(Infix* _this);
void Infix_setExpression(Infix* _this, char* newExpression);
Boolean Infix_toPostfix(Infix* _this);
char* Infix_postfix(Infix* _this);


void Infix_showTokenAndOStack(Infix* _this, char aToken);