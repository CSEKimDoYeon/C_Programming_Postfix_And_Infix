#pragma once
#include "Common.h"
#include "OStack.h"

#define DEFAULT_MAX_NUMBER_OF_TOKENS 10

typedef struct _Infix Infix;

struct _Infix {
	char* _infixExpression; // AppController 에서 보내준다
							//char* _postfixExpression[DEFAULT_MAX_NUMBER_OF_TOKENS];
	char* _postfixExpression;

	// postfix로 변환된 결과는 이곳에 저장된다.
	OStack* _operatorStack;
}; Infix* Infix_new(int givenMaxNumberOfTokens);
void Infix_delete(Infix* _this);
void Infix_setExpression(Infix* _this, char* newExpression);
Boolean Infix_toPostfix(Infix* _this);
char* Infix_postfix(Infix* _this);


void Infix_showTokenAndOStack(Infix* _this, char aToken);