#include "VNode.h"

struct _VNode {
	ElementForVstack _element;
	VNode* _next;
};
VNode* VNode_new() {
	VNode* _this = (VNode*)malloc(sizeof(VNode));
	return _this;
}
void VNode_delete(VNode* _this) {
	free(_this);
}

void VNode_setElement(VNode* _this, ElementForVstack newElement)
{
	_this->_element = newElement;
}
ElementForVstack VNode_element(VNode* _this)
{
	return _this->_element;
}
void VNode_setNext(VNode* _this, VNode* newNext)
{
	_this->_next = newNext;
}
VNode* VNode_next(VNode* _this)
{
	return _this->_next;
}