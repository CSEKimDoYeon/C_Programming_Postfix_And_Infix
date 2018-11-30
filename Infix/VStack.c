
#include "VStack.h"
#include "VNode.h"

struct _VStack {
	VNode* _top;
	int _size; // �߰�
	ElementForVstack* _elements;
};

VStack* VStack_new() {
	VStack* _this;
	_this = NewObject(VStack);
	_this->_top = NULL;
	_this->_size = 0;
	return _this;
}// Stack ��ü ����.

void VStack_delete(VStack* _this) {
	// There may be some elements in the stack.
	VStack_deleteLinkedNodes(_this);
	free(_this);
}// ���� ��ü �Ҹ�.


Boolean VStack_isEmpty(VStack* _this) {
	return(VStack_size(_this)) == 0;	//size�� 0�϶� empty���� �˷���
}// ������ ����ִ��� �˻�.

Boolean VStack_isFull(VStack* _this) {
	return  VStack_size(_this) == MAX_STACK_SIZE;
}// ������ ���� ���ִ��� �˻�.

Boolean VStack_push(VStack* _this, ElementForVstack anElement)
{
	VNode* addedNode = VNode_new();
	if (VStack_isFull(_this)) {
		printf("Stack is Full.");
		return false;
	}
	VNode_setElement(addedNode, anElement);
	VNode_setNext(addedNode, _this->_top);
	_this->_top = addedNode;
	_this->_size++;
	return true;
}

ElementForVstack VStack_pop(VStack* _this)
{
	ElementForVstack poppedElement;
	VNode* poppedNode = _this->_top;
	if (VStack_isEmpty(_this)) {
		printf("Stack is Empty.");
	}
	poppedElement = VNode_element(poppedNode);
	_this->_top = VNode_next(poppedNode);
	VNode_delete(poppedNode);
	_this->_size--;
	return poppedElement;
}

void VStack_deleteLinkedNodes(VStack* _this)
{
	VStack_deleteLinkedNodesRecursively(_this, _this->_top);
}

void VStack_deleteLinkedNodesRecursively(VStack* _this, VNode* firstNode)
{
	if (firstNode != NULL) {
		VStack_deleteLinkedNodesRecursively(_this, VNode_next(firstNode));
		VNode_delete(firstNode);
	}
}

//////////////////////////////////////////////////////////////////////

void VStack_showAll(VStack* _this) {

	int size = VStack_size(_this);
	int* arr = NewVector(int, size); // ������ �����ŭ�� �迭 ����.

	VNode* currentNode;
	currentNode = _this->_top;
	for (int i = 0; i < VStack_size(_this); i++) {
		arr[i] = VNode_element(currentNode); // ������ element���� �迭�� �Ҵ�
		currentNode = VNode_next(currentNode);
	}

	for (int j = size - 1; j >= 0; j--) {
		printf("%d ", arr[j]); // �迭�� �������� ���.
	}
}

void VStack_reset(VStack* _this) { // this�� operendstack �̴�.. �������־�� �Ѵ�.

	_this->_top = NULL;
	_this->_size = 0;

}//������ reset��Ų��.

int VStack_size(VStack* _this) { //����
	return _this->_size;
}//������ ������ ��ȯ.

void transStack(VStack* _this) {
	printf(">>��ȯ�� Postfix: ");
	VNode* trans = _this->_top;
	for (int i = 0; i < _this->_size; i++) {
		printf("%c", VNode_element(trans));
		trans = VNode_next(trans);
	}

}