
#include "OStack.h"
#include "ONode.h"

struct _OStack {
	ONode* _top;
	int _size; // 추가
	ElementForOStack* _elements;
};

OStack* OStack_new() {
	OStack* _this;
	_this = NewObject(OStack);
	_this->_top = NULL;
	_this->_size = 0;
	return _this;
}// Stack 객체 생성.

void OStack_delete(OStack* _this) {
	// There may be some elements in the stack.
	OStack_deleteLinkedNodes(_this);
	free(_this);
}// 스택 객체 소멸.


Boolean OStack_isEmpty(OStack* _this) {
	return(OStack_size(_this)) == 0;	//size가 0일때 empty임을 알려줌
}// 스택이 비어있는지 검사.

Boolean OStack_isFull(OStack* _this) {
	return  OStack_size(_this) == MAX_STACK_SIZE;
}// 스택이 가득 차있는지 검사.

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
	//printf("팝된 element : %d", poppedElement);
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
	char* arr = NewVector(int, size); // 스택의 사이즈만큼의 배열 선언.

	ONode* currentNode;
	currentNode = _this->_top;
	for (int i = 0; i < OStack_size(_this); i++) {
		arr[i] = ONode_element(currentNode); // 스택의 element들을 배열에 할당
		currentNode = ONode_next(currentNode);
	}

	for (int j = size - 1; j >= 0; j--) {
		printf("%c ", arr[j]); // 배열을 역순으로 출력.
	}
}


void OStack_reset(OStack* _this) { // this는 operendstack 이다.. 리셋해주어야 한다.

	_this->_top = NULL;
	_this->_size = 0;

}//스택을 reset시킨다.

int OStack_size(OStack* _this) { //수정
	return _this->_size;
}//스택의 사이즈 반환.


 // Infix_toPostfix 안에서 Infix_showTokenAndOStack() 에서 사용, 해당 anOrder의 element를 불러온다.
ElementForOStack OStack_elementAt(OStack* _this, int anOrder) {
	int numberOfIteration = _this->_size - anOrder - 1;
	ONode* currentNode = _this->_top;
	for (int i = 0; i< numberOfIteration; i++) {
		//currentNode = currentNode->_next;
		currentNode = ONode_next(currentNode); // 변경하였음.
	}
	return ONode_element(currentNode);
}

// 구현할것.
ElementForOStack OStack_peek(OStack* _this) {
	ONode* peekNode = _this->_top;
	return ONode_element(peekNode);
}