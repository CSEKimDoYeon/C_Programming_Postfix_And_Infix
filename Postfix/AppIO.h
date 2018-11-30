#include "common.h"
#include <stdio.h>

#define ErrorMsg_ExpressionTooLong "[오류] 수식이 너무 길어 처리가 불가능합니다.\n\n"
#define ErrorMsg_OperandsTooMany "[오류] 연산자에 비해 연산값의 수가 많습니다.\n\n"
#define ErrorMsg_OperandsTooFew "[오류] 연산자에 비해 연산값의 개수가 적습니다.\n\n"
#define ErrorMsg_UndefinedOperator "[오류] 수식에 알 수 없는 연산자가 있습니다.\n\n"
#define ErrorMsg_DivideByZero "[오류] 나눗셈의 분모가 0입니다.\n\n"

typedef struct _AppIO AppIO;

struct _AppIO {
	AppIO* _this;
};

AppIO* AppIO_new();
void AppIO_out_startingMessage();
void AppIO_delete(AppIO* _this);
Boolean AppIO_in_postfixExpression(char* _elements);
void AppIO_out_errorInExpression();
void AppIO_out_evaluatedValue(int value);
void AppIO_out_endingMessage();
void AppIO_out_element(int anElement);
void AppIO_out_showToken(char token);
void AppIO_out_topOfStack();
void AppIO_out_bottomOfStack();
void AppIO_out_newLine();
void AppIO_out_postfixEvaluationErrorMessage(PostfixError aPostfixError);

