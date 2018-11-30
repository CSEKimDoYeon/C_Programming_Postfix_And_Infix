
#include "AppController.h"
#include "VStack.h"

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
	_this->_postfix = Postfix_new(MAX_NUMBER_OF_TOKENS); // ���ο� Postfix ����ü ����.
	_this->_infix = Infix_new(MAX_NUMBER_OF_TOKENS); // ���ο� infix ����ü ����.

	expressionIsAvailable = AppIO_in_infixExpression(_this->_expression); 
	// Postfix �޽��� �Է�.

	while (expressionIsAvailable) {
		Infix_setExpression(_this->_infix, _this->_expression); //infix ������ ����
		Infix_toPostfix(_this->_infix);
	
		Postfix_setExpression(_this->_postfix, Infix_postfix(_this->_infix));
		// infox to postfix �� ��ģ expression�� postfix�� ����.
		printf("\n>Postfix ������ ����մϴ�:\n");

		evaluationError = Postfix_evaluate(_this->_postfix);
		if (evaluationError == PostfixError_None) {	//������ ������� �ʾ����� ���� ���.
			AppIO_out_evaluatedValue(Postfix_evaluatedValue(_this->_postfix));
		}
		else {	//������ ����Ǿ����� �ش� ������ ���� ���� �޽��� ���.
			AppIO_out_postfixEvaluationErrorMessage(evaluationError);
		}
		expressionIsAvailable = AppIO_in_infixExpression(_this->_expression);//�ٽ� infix ���� �Է�.
	}
	Postfix_delete(_this->_postfix); // ��ü �Ҹ�
	AppIO_out_endingMessage();	// ����.
}

