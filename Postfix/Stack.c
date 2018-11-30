
#include "Stack.h"
#include "Node.h"

struct _Stack {
	Node* _top;
	int _size; // 추가
	Element* _elements;
};

Stack* Stack_new() {
	Stack* _this;
	_this = NewObject(Stack);
	_this->_top = NULL;
	_this->_size = 0;
	return _this;
}// Stack 객체 생성.

void Stack_delete(Stack* _this) {
	// There may be some elements in the stack.
	Stack_deleteLinkedNodes(_this);
	free(_this);
}// 스택 객체 소멸.


Boolean Stack_isEmpty(Stack* _this) {
	return(Stack_size(_this)) == 0;	//size가 0일때 empty임을 알려줌
}// 스택이 비어있는지 검사.

Boolean Stack_isFull(Stack* _this) {
	return  Stack_size(_this) == MAX_STACK_SIZE;
}// 스택이 가득 차있는지 검사.

Boolean Stack_push(Stack* _this, Element anElement)
{
	Node* addedNode = Node_new();
	if (Stack_isFull(_this)) {
		printf("스택이 꽉찼습니다.");
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
		printf("스택이 비어있습니다.");
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
	int* arr = NewVector(int, size); // 스택의 사이즈만큼의 배열 선언.
	
	Node* currentNode;
	currentNode = _this->_top;
	for (int i = 0; i < Stack_size(_this); i++) {
		arr[i] = Node_element(currentNode); // 스택의 element들을 배열에 할당
		currentNode = Node_next(currentNode);
	}

	for (int j = size-1; j >= 0; j--) { 
		printf("%d ", arr[j]); // 배열을 역순으로 출력.
	}
}


void Stack_reset(Stack* _this) { // this는 operendstack 이다.. 리셋해주어야 한다.
	
	_this->_top = NULL;
	_this->_size = 0;
	
}//스택을 reset시킨다.

int Stack_size(Stack* _this) { //수정
	return _this->_size;
}//스택의 사이즈 반환.
