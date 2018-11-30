#include "Node.h"

struct _Node {
	Element _element;
	Node* _next;
};
Node* Node_new() {
	//Node* _this = NewObject(Node);
	Node* _this = (Node*)malloc(sizeof(Node));
	return _this;
}
void Node_delete(Node* _this) {
	free(_this);
}

void Node_setElement(Node* _this, Element newElement)
{
	_this->_element = newElement;
}
Element Node_element(Node* _this)
{
	return _this->_element;
}
void Node_setNext(Node* _this, Node* newNext)
{
	_this->_next = newNext;
}
Node* Node_next(Node* _this)
{
	return _this->_next;
}