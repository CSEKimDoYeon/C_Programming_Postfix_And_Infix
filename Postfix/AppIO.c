#pragma once
#include "AppIO.h"

AppIO* AppIO_new(void) {
	// AppIO 구조체를 동적으로 생성.
	AppIO* _this = NewObject(AppIO);
	return _this;
}

void AppIO_delete(AppIO* _this) {
	// AppIO 객체 소멸.
	free(_this);
}

void AppIO_out_startingMessage() {
	printf("<<< Postfix 수식을 계산합니다 >>>\n\n");
}

Boolean AppIO_in_postfixExpression(char* _elements) {
	// Postfix 수식을 입력받아 elements 배열에 저장. 만약 $ 가 입력되면 입력을 종료.
	printf("> Postfix 수식을 입력하시오:");
	scanf("%s", _elements);
	if (_elements[0] == '@') {
		return false;
	}
	else {
		return true;
	}
}

void AppIO_out_errorInExpression() {
	printf("수식에 오류가 있습니다. ");
}// 오류 메시지 출력.

void AppIO_out_evaluatedValue(int value) {
	printf("계산값: %d \n\n", value);
}// 계산 결과 출력.

void AppIO_out_endingMessage() {
	printf("<<< Postfix 수식 계산을 종료합니다 >>>\n");
}// 종료 메시지 출력.

void AppIO_out_element(int anElement) {
	printf("%d ", anElement);
}// anElement원소를 출력.

void AppIO_out_showToken(char token) {
	printf("%c", token);
}//해당 토큰을 출력.

void AppIO_out_topOfStack() {
	printf(" <Top>");
}// Top 메시지 출력.

void AppIO_out_bottomOfStack() {
	printf("  :  Stack <Bottom> ");
}// Bottom 메시지 출력.

void AppIO_out_newLine() {
	printf("\n");
}// 줄바꾸기.


void AppIO_out_postfixEvaluationErrorMessage(PostfixError aPostfixError)
{
	if (aPostfixError == PostfixError_ExpressionTooLong) {
		printf(ErrorMsg_ExpressionTooLong);
	}
	else if (aPostfixError == PostfixError_OperandsTooMany) {
		printf(ErrorMsg_OperandsTooMany);
	}
	else if (aPostfixError == PostfixError_OperandsTooFew) {
		printf(ErrorMsg_OperandsTooFew);
	}
	else if (aPostfixError == PostfixError_UnknownOperator) {
		printf(ErrorMsg_UndefinedOperator);
	}
	else if (aPostfixError == PostfixError_DivideByZero) {
		printf(ErrorMsg_DivideByZero);
	}
}
