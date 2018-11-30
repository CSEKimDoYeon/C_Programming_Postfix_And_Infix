
#include "AppController.h"
#include "VStack.h"

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
	_this->_postfix = Postfix_new(MAX_NUMBER_OF_TOKENS); // 새로운 Postfix 구조체 생성.
	_this->_infix = Infix_new(MAX_NUMBER_OF_TOKENS); // 새로운 infix 구조체 생성.

	expressionIsAvailable = AppIO_in_infixExpression(_this->_expression); 
	// Postfix 메시지 입력.

	while (expressionIsAvailable) {
		Infix_setExpression(_this->_infix, _this->_expression); //infix 수식을 세팅
		Infix_toPostfix(_this->_infix);
	
		Postfix_setExpression(_this->_postfix, Infix_postfix(_this->_infix));
		// infox to postfix 를 거친 expression을 postfix에 세팅.
		printf("\n>Postfix 수식을 계산합니다:\n");

		evaluationError = Postfix_evaluate(_this->_postfix);
		if (evaluationError == PostfixError_None) {	//오류가 검출되지 않았으면 수식 계산.
			AppIO_out_evaluatedValue(Postfix_evaluatedValue(_this->_postfix));
		}
		else {	//오류가 검출되었으면 해당 오류에 따른 에러 메시지 출력.
			AppIO_out_postfixEvaluationErrorMessage(evaluationError);
		}
		expressionIsAvailable = AppIO_in_infixExpression(_this->_expression);//다시 infix 수식 입력.
	}
	Postfix_delete(_this->_postfix); // 객체 소멸
	AppIO_out_endingMessage();	// 종료.
}

