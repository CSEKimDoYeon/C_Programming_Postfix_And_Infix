
#include "VStack.h"
#include "VNode.h"

struct _VStack {
	VNode* _top;
	int _size; // 추가
	ElementForVstack* _elements;
};

VStack* VStack_new() {
	VStack* _this;
	_this = NewObject(VStack);
	_this->_top = NULL;
	_this->_size = 0;
	return _this;
}// Stack 객체 생성.

void VStack_delete(VStack* _this) {
	// There may be some elements in the stack.
	VStack_deleteLinkedNodes(_this);
	free(_this);
}// 스택 객체 소멸.


Boolean VStack_isEmpty(VStack* _this) {
	return(VStack_size(_this)) == 0;	//size가 0일때 empty임을 알려줌
}// 스택이 비어있는지 검사.

Boolean VStack_isFull(VStack* _this) {
	return  VStack_size(_this) == MAX_STACK_SIZE;
}// 스택이 가득 차있는지 검사.

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
	int* arr = NewVector(int, size); // 스택의 사이즈만큼의 배열 선언.

	VNode* currentNode;
	currentNode = _this->_top;
	for (int i = 0; i < VStack_size(_this); i++) {
		arr[i] = VNode_element(currentNode); // 스택의 element들을 배열에 할당
		currentNode = VNode_next(currentNode);
	}

	for (int j = size - 1; j >= 0; j--) {
		printf("%d ", arr[j]); // 배열을 역순으로 출력.
	}
}

void VStack_reset(VStack* _this) { // this는 operendstack 이다.. 리셋해주어야 한다.

	_this->_top = NULL;
	_this->_size = 0;

}//스택을 reset시킨다.

int VStack_size(VStack* _this) { //수정
	return _this->_size;
}//스택의 사이즈 반환.

void transStack(VStack* _this) {
	printf(">>변환된 Postfix: ");
	VNode* trans = _this->_top;
	for (int i = 0; i < _this->_size; i++) {
		printf("%c", VNode_element(trans));
		trans = VNode_next(trans);
	}

}