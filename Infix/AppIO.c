#pragma once
#include "AppIO.h"

AppIO* AppIO_new(void) {
	// AppIO ����ü�� �������� ����.
	AppIO* _this = NewObject(AppIO);
	return _this;
}

void AppIO_delete(AppIO* _this) {
	// AppIO ��ü �Ҹ�.
	free(_this);
}

void AppIO_out_startingMessage() {
	printf("<<< Infix ������ ����մϴ� >>>\n\n");
}

Boolean AppIO_in_postfixExpression(char* _elements) {
	// Postfix ������ �Է¹޾� elements �迭�� ����. ���� $ �� �ԷµǸ� �Է��� ����.
	printf("> Postfix ������ �Է��Ͻÿ�:");
	scanf("%s", _elements);
	if (_elements[0] == '@') {
		return true;
	}
	else {
		return false;
	}
}

Boolean AppIO_in_infixExpression(char* _elements) {
	// Postfix ������ �Է¹޾� elements �迭�� ����. ���� $ �� �ԷµǸ� �Է��� ����.
	printf("? Infix ������ �Է��Ͻÿ�:");
	scanf("%s", _elements);
	if (_elements[0] == '@') {
		return false;
	}
	else {
		printf("> Infix�� Postfix�� ��ȯ�մϴ�:\n");
		return true;
	}
}

void AppIO_out_errorInExpression() {
	printf("���Ŀ� ������ �ֽ��ϴ�. ");
}// ���� �޽��� ���.

void AppIO_out_evaluatedValue(int value) {
	printf("��갪: %d \n\n", value);
}// ��� ��� ���.

void AppIO_out_endingMessage() {
	printf("<<< Postfix ���� ����� �����մϴ� >>>\n");
}// ���� �޽��� ���.

void AppIO_out_element(int anElement) {
	printf("%d ", anElement);
}// anElement���Ҹ� ���.

void AppIO_out_showToken(char token) {
	printf("%c", token);
}//�ش� ��ū�� ���.

void AppIO_out_topOfVStack() {
	printf(" <Top>");
}// Top �޽��� ���.

void AppIO_out_bottomOfVStack() {
	printf("  :  VStack <Bottom> ");
}// Bottom �޽��� ���.

void AppIO_out_topOfOStack() {
	printf(" <Top>");
}// Top �޽��� ���.

void AppIO_out_bottomOfOStack() {
	printf("  :  OStack <Bottom> ");
}// Bottom �޽��� ���.

void AppIO_out_newLine() {
	printf("\n");
}// �ٹٲٱ�.


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
