#pragma once
#include "Common.h"
#include "VNode.h"

#define MAX_STACK_SIZE 5;

typedef struct _VStack VStack;
//Stack 객체의 생성과 소멸
VStack* VStack_new();
void VStack_delete(VStack* _this);

//Stack 객체의 점검
Boolean VStack_isEmpty(VStack* _this);
//스택이 empty 이면 TRUE를, 아니면, FALSE를 얻는다.
Boolean VStack_isFull(VStack* _this);
//스택이 full 이면 TRUE 를, 아니면, FALSE 를 얻는다.


//Stack 객체에게 행위를 지시
Boolean VStack_push(VStack* _this, ElementForVstack anElement);
//스택에 anElement 를 삽입한다.
//삽입을 성공하면 TRUE, 실패하면 FALSE를 얻는다.
ElementForVstack VStack_pop(VStack* _this);
//스택의 top에서 원소를 삭제하고 그 값을 얻는다.

void VStack_deleteLinkedNodes(VStack* _this);
void VStack_deleteLinkedNodesRecursively(VStack* _this, VNode* firstNode);

int VStack_size(VStack* _this);
void transStack(VStack* _this);