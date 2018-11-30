#include "common.h"
#include <stdio.h>

#define ErrorMsg_ExpressionTooLong "[����] ������ �ʹ� ��� ó���� �Ұ����մϴ�.\n\n"
#define ErrorMsg_OperandsTooMany "[����] �����ڿ� ���� ���갪�� ���� �����ϴ�.\n\n"
#define ErrorMsg_OperandsTooFew "[����] �����ڿ� ���� ���갪�� ������ �����ϴ�.\n\n"
#define ErrorMsg_UndefinedOperator "[����] ���Ŀ� �� �� ���� �����ڰ� �ֽ��ϴ�.\n\n"
#define ErrorMsg_DivideByZero "[����] �������� �и� 0�Դϴ�.\n\n"

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

