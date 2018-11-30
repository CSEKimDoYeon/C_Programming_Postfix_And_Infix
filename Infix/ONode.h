#pragma once
typedef struct _ONode ONode;
typedef char ElementForOStack;

ONode* ONode_new();
//��� ��ü�� ����
void ONode_delete(ONode* _this);
//��� ��ü�� �Ҹ�
void ONode_setElement(ONode* _this, ElementForOStack newElement);
ElementForOStack ONode_element(ONode* _this);
void ONode_setNext(ONode* _this, ONode* newNext);
ONode* ONode_next(ONode* _this);