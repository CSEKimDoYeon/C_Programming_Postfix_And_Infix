#pragma once
#include "Common.h"
#include "ONode.h"

#define MAX_STACK_SIZE 5;

typedef struct _OStack OStack;
//Stack 객체의 생성과 소멸
OStack* OStack_new();
void OStack_delete(OStack* _this);

//Stack 객체의 점검
Boolean OStack_isEmpty(OStack* _this);
//스택이 empty 이면 TRUE를, 아니면, FALSE를 얻는다.
Boolean OStack_isFull(OStack* _this);
//스택이 full 이면 TRUE 를, 아니면, FALSE 를 얻는다.


//Stack 객체에게 행위를 지시
Boolean OStack_push(OStack* _this, ElementForOStack anElement);
//스택에 anElement 를 삽입한다.
//삽입을 성공하면 TRUE, 실패하면 FALSE를 얻는다.
ElementForOStack OStack_pop(OStack* _this);
//스택의 top에서 원소를 삭제하고 그 값을 얻는다.

void OStack_deleteLinkedNodes(OStack* _this);
void OStack_deleteLinkedNodesRecursively(OStack* _this, ONode* firstNode);

int OStack_size(OStack* _this);