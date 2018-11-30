#pragma once
typedef struct _VNode VNode;
typedef int ElementForVstack;

VNode* VNode_new();
//��� ��ü�� ����
void VNode_delete(VNode* _this);
//��� ��ü�� �Ҹ�
void VNode_setElement(VNode* _this, ElementForVstack newElement);
ElementForVstack VNode_element(VNode* _this);
void VNode_setNext(VNode* _this, VNode* newNext);
VNode* VNode_next(VNode* _this);