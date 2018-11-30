#pragma once
#include "Common.h"
#include "ONode.h"

#define MAX_STACK_SIZE 5;

typedef struct _OStack OStack;
//Stack ��ü�� ������ �Ҹ�
OStack* OStack_new();
void OStack_delete(OStack* _this);

//Stack ��ü�� ����
Boolean OStack_isEmpty(OStack* _this);
//������ empty �̸� TRUE��, �ƴϸ�, FALSE�� ��´�.
Boolean OStack_isFull(OStack* _this);
//������ full �̸� TRUE ��, �ƴϸ�, FALSE �� ��´�.


//Stack ��ü���� ������ ����
Boolean OStack_push(OStack* _this, ElementForOStack anElement);
//���ÿ� anElement �� �����Ѵ�.
//������ �����ϸ� TRUE, �����ϸ� FALSE�� ��´�.
ElementForOStack OStack_pop(OStack* _this);
//������ top���� ���Ҹ� �����ϰ� �� ���� ��´�.

void OStack_deleteLinkedNodes(OStack* _this);
void OStack_deleteLinkedNodesRecursively(OStack* _this, ONode* firstNode);

int OStack_size(OStack* _this);