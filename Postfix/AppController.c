
#include "AppController.h"


AppController* AppController_new() {
	// ���ο� AppController ��ü�� �������� ����.
	AppController* _this;
	_this = NewObject(AppController);
	return _this;
}

void AppController_delete(AppController* _this) {
	//������ ��ü�� �Ҹ�.
	free(_this);
}

void AppController_run(AppController* _this) {

	Boolean expressionIsAvailable, noErrorIsInEvaluation;
	PostfixError evaluationError;

	AppIO_out_startingMessage(); // ���� �޽��� ���.
	_this->_postfix = Postfix_new(MAX_NUMBER_OF_TOKENS); // ���ο� Postfix ��ü ����.
	expressionIsAvailable = AppIO_in_postfixExpression(_this->_expression);	//Postfix ���� �Է�.
	while (expressionIsAvailable) {
		Postfix_setExpression(_this->_postfix, _this->_expression);
		evaluationError = Postfix_evaluate(_this->_postfix);
		if (evaluationError == PostfixError_None) {	//������ ������� �ʾ����� ���� ���.
			AppIO_out_evaluatedValue(Postfix_evaluatedValue(_this->_postfix));
		}
		else {	//������ ����Ǿ����� �ش� ������ ���� ���� �޽��� ���.
			AppIO_out_postfixEvaluationErrorMessage(evaluationError);
		}
		expressionIsAvailable = AppIO_in_postfixExpression(_this->_expression);//�ٽ� Postfix ���� �Է�.
	}
	Postfix_delete(_this->_postfix); // ��ü �Ҹ�
	AppIO_out_endingMessage();	// ����.
}

