
#include "AppController.h"


AppController* AppController_new() {
	// 새로운 AppController 객체를 동적으로 생성.
	AppController* _this;
	_this = NewObject(AppController);
	return _this;
}

void AppController_delete(AppController* _this) {
	//생성된 객체를 소멸.
	free(_this);
}

void AppController_run(AppController* _this) {

	Boolean expressionIsAvailable, noErrorIsInEvaluation;
	PostfixError evaluationError;

	AppIO_out_startingMessage(); // 시작 메시지 출력.
	_this->_postfix = Postfix_new(MAX_NUMBER_OF_TOKENS); // 새로운 Postfix 객체 생성.
	expressionIsAvailable = AppIO_in_postfixExpression(_this->_expression);	//Postfix 수식 입력.
	while (expressionIsAvailable) {
		Postfix_setExpression(_this->_postfix, _this->_expression);
		evaluationError = Postfix_evaluate(_this->_postfix);
		if (evaluationError == PostfixError_None) {	//오류가 검출되지 않았으면 수식 계산.
			AppIO_out_evaluatedValue(Postfix_evaluatedValue(_this->_postfix));
		}
		else {	//오류가 검출되었으면 해당 오류에 따른 에러 메시지 출력.
			AppIO_out_postfixEvaluationErrorMessage(evaluationError);
		}
		expressionIsAvailable = AppIO_in_postfixExpression(_this->_expression);//다시 Postfix 수식 입력.
	}
	Postfix_delete(_this->_postfix); // 객체 소멸
	AppIO_out_endingMessage();	// 종료.
}

