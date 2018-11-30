
#include "OStack.h"
#include "ONode.h"

struct _OStack {
	ONode* _top;
	int _size; // �߰�
	ElementForOStack* _elements;
};

OStack* OStack_new() {
	OStack* _this;
	_this = NewObject(OStack);
	_this->_top = NULL;
	_this->_size = 0;
	return _this;
}// Stack ��ü ����.

void OStack_delete(OStack* _this) {
	// There may be some elements in the stack.
	OStack_deleteLinkedNodes(_this);
	free(_this);
}// ���� ��ü �Ҹ�.


Boolean OStack_isEmpty(OStack* _this) {
	return(OStack_size(_this)) == 0;	//size�� 0�϶� empty���� �˷���
}// ������ ����ִ��� �˻�.

Boolean OStack_isFull(OStack* _this) {
	return  OStack_size(_this) == MAX_STACK_SIZE;
}// ������ ���� ���ִ��� �˻�.

Boolean OStack_push(OStack* _this, ElementForOStack anElement)
{
	ONode* addedNode = ONode_new();
	if (OStack_isFull(_this)) {
		return false;
	}
	ONode_setElement(addedNode, anElement);
	ONode_setNext(addedNode, _this->_top);
	_this->_top = addedNode;
	_this->_size++;
	return true;
}

ElementForOStack OStack_pop(OStack* _this)
{
	ElementForOStack poppedElement;
	ONode* poppedNode = _this->_top;
	if (OStack_isEmpty(_this)) {
		return false;
	}
	poppedElement = ONode_element(poppedNode);
	_this->_top = ONode_next(poppedNode);
	ONode_delete(poppedNode);
	_this->_size--;
	//printf("�˵� element : %d", poppedElement);
	return poppedElement;
}

void OStack_deleteLinkedNodes(OStack* _this)
{
	OStack_deleteLinkedNodesRecursively(_this, _this->_top);
}

void OStack_deleteLinkedNodesRecursively(OStack* _this, ONode* firstNode)
{
	if (firstNode != NULL) {
		OStack_deleteLinkedNodesRecursively(_this, ONode_next(firstNode));
		ONode_delete(firstNode);
	}
}

//////////////////////////////////////////////////////////////////////



void OStack_showAll(OStack* _this) {

	int size = OStack_size(_this);
	char* arr = NewVector(int, size); // ������ �����ŭ�� �迭 ����.

	ONode* currentNode;
	currentNode = _this->_top;
	for (int i = 0; i < OStack_size(_this); i++) {
		arr[i] = ONode_element(currentNode); // ������ element���� �迭�� �Ҵ�
		currentNode = ONode_next(currentNode);
	}

	for (int j = size - 1; j >= 0; j--) {
		printf("%c ", arr[j]); // �迭�� �������� ���.
	}
}


void OStack_reset(OStack* _this) { // this�� operendstack �̴�.. �������־�� �Ѵ�.

	_this->_top = NULL;
	_this->_size = 0;

}//������ reset��Ų��.

int OStack_size(OStack* _this) { //����
	return _this->_size;
}//������ ������ ��ȯ.


 // Infix_toPostfix �ȿ��� Infix_showTokenAndOStack() ���� ���, �ش� anOrder�� element�� �ҷ��´�.
ElementForOStack OStack_elementAt(OStack* _this, int anOrder) {
	int numberOfIteration = _this->_size - anOrder - 1;
	ONode* currentNode = _this->_top;
	for (int i = 0; i< numberOfIteration; i++) {
		//currentNode = currentNode->_next;
		currentNode = ONode_next(currentNode); // �����Ͽ���.
	}
	return ONode_element(currentNode);
}

// �����Ұ�.
ElementForOStack OStack_peek(OStack* _this) {
	ONode* peekNode = _this->_top;
	return ONode_element(peekNode);
}