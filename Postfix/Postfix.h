
#include "common.h"
#include "Stack.h"

typedef struct _Postfix Postfix;

struct _Postfix {
	int _maxNumberOfTokens;
	char* _expression;
	int _evaluatedValue;
	Stack* _operandStack;
};

Postfix* Postfix_new(int givenMaxNumberOfTokens);
void Postfix_delete(Postfix* _this);
void Postfix_setExpression(Postfix* _this, char* anExpression);
Boolean Postfix_evaluate(Postfix* _this);
int Postfix_evaluatedValue(Postfix* _this);

void Postfix_showTokenAndStack(Postfix* _this, char Token);