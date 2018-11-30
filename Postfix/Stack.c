
#include "Stack.h"
#include "Node.h"

struct _Stack {
	Node* _top;
	int _size; // �߰�
	Element* _elements;
};

Stack* Stack_new() {
	Stack* _this;
	_this = NewObject(Stack);
	_this->_top = NULL;
	_this->_size = 0;
	return _this;
}// Stack ��ü ����.

void Stack_delete(Stack* _this) {
	// There may be some elements in the stack.
	Stack_deleteLinkedNodes(_this);
	free(_this);
}// ���� ��ü �Ҹ�.


Boolean Stack_isEmpty(Stack* _this) {
	return(Stack_size(_this)) == 0;	//size�� 0�϶� empty���� �˷���
}// ������ ����ִ��� �˻�.

Boolean Stack_isFull(Stack* _this) {
	return  Stack_size(_this) == MAX_STACK_SIZE;
}// ������ ���� ���ִ��� �˻�.

Boolean Stack_push(Stack* _this, Element anElement)
{
	Node* addedNode = Node_new();
	if (Stack_isFull(_this)) {
		printf("������ ��á���ϴ�.");
		return false;
	}
	Node_setElement(addedNode, anElement);
	Node_setNext(addedNode, _this->_top);
	_this->_top = addedNode;
	_this->_size++;
	return true;
}

Element Stack_pop(Stack* _this)
{
	Element poppedElement;
	Node* poppedNode = _this->_top;
	if (Stack_isEmpty(_this)) {
		printf("������ ����ֽ��ϴ�.");
	}
	poppedElement = Node_element(poppedNode);
	_this->_top = Node_next(poppedNode);
	Node_delete(poppedNode);
	_this->_size--;
	return poppedElement;
}

void Stack_deleteLinkedNodes(Stack* _this)
{
	Stack_deleteLinkedNodesRecursively(_this, _this->_top);
}

void Stack_deleteLinkedNodesRecursively(Stack* _this, Node* firstNode)
{
	if (firstNode != NULL) {
		Stack_deleteLinkedNodesRecursively(_this, Node_next(firstNode));
		Node_delete(firstNode);
	}
}

//////////////////////////////////////////////////////////////////////



void Stack_showAll(Stack* _this) {

	int size = Stack_size(_this);
	int* arr = NewVector(int, size); // ������ �����ŭ�� �迭 ����.
	
	Node* currentNode;
	currentNode = _this->_top;
	for (int i = 0; i < Stack_size(_this); i++) {
		arr[i] = Node_element(currentNode); // ������ element���� �迭�� �Ҵ�
		currentNode = Node_next(currentNode);
	}

	for (int j = size-1; j >= 0; j--) { 
		printf("%d ", arr[j]); // �迭�� �������� ���.
	}
}


void Stack_reset(Stack* _this) { // this�� operendstack �̴�.. �������־�� �Ѵ�.
	
	_this->_top = NULL;
	_this->_size = 0;
	
}//������ reset��Ų��.

int Stack_size(Stack* _this) { //����
	return _this->_size;
}//������ ������ ��ȯ.
