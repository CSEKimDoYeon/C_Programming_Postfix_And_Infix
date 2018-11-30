#pragma once
#include <stdlib.h>

#define NewObject(TYPE) (TYPE*)malloc(sizeof(TYPE))	//��ü�� �������� ����
#define NewVector(TYPE,SIZE) (TYPE*)malloc(sizeof(TYPE)*SIZE)	//�迭�� �������� ����

typedef int Boolean;
#define true 1
#define false 0

typedef enum {
	PostfixError_None,
	PostfixError_ExpressionTooLong,
	PostfixError_OperandsTooMany,
	PostfixError_OperandsTooFew,
	PostfixError_UnknownOperator,
	PostfixError_DivideByZero
}PostfixError;
