#pragma once

#include "Common.h"
#include "Postfix.h"
#include "Infix.h" // Ãß°¡
#include "AppIO.h"
#include "VStack.h"

#define MAX_NUMBER_OF_TOKENS 200

typedef struct _AppController AppController;

struct _AppController {
	char _expression[MAX_NUMBER_OF_TOKENS];
	Postfix* _postfix;
	Infix* _infix;
};

AppController* AppController_new();
void AppController_run(AppController* _this);
void AppController_delete(AppController* _this);


