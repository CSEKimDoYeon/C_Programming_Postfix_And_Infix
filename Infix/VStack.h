#pragma once
#include "Common.h"
#include "VNode.h"

#define MAX_STACK_SIZE 5;

typedef struct _VStack VStack;
//Stack ��ü�� ������ �Ҹ�
VStack* VStack_new();
void VStack_delete(VStack* _this);

//Stack ��ü�� ����
Boolean VStack_isEmpty(VStack* _this);
//������ empty �̸� TRUE��, �ƴϸ�, FALSE�� ��´�.
Boolean VStack_isFull(VStack* _this);
//������ full �̸� TRUE ��, �ƴϸ�, FALSE �� ��´�.


//Stack ��ü���� ������ ����
Boolean VStack_push(VStack* _this, ElementForVstack anElement);
//���ÿ� anElement �� �����Ѵ�.
//������ �����ϸ� TRUE, �����ϸ� FALSE�� ��´�.
ElementForVstack VStack_pop(VStack* _this);
//������ top���� ���Ҹ� �����ϰ� �� ���� ��´�.

void VStack_deleteLinkedNodes(VStack* _this);
void VStack_deleteLinkedNodesRecursively(VStack* _this, VNode* firstNode);

int VStack_size(VStack* _this);
void transStack(VStack* _this);