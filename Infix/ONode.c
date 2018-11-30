#include "ONode.h"

struct _ONode {
	ElementForOStack _element;
	ONode* _next;
};
ONode* ONode_new() {
	ONode* _this = (ONode*)malloc(sizeof(ONode));
	return _this;
}
void ONode_delete(ONode* _this) {
	free(_this);
}

void ONode_setElement(ONode* _this, ElementForOStack newElement)
{
	_this->_element = newElement;
}
ElementForOStack ONode_element(ONode* _this)
{
	return _this->_element;
}
void ONode_setNext(ONode* _this, ONode* newNext)
{
	_this->_next = newNext;
}
ONode* ONode_next(ONode* _this)
{
	return _this->_next;
}