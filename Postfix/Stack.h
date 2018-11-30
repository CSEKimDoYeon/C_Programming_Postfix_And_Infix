#include "common.h"
#include "Node.h"

#define MAX_STACK_SIZE 5;

typedef struct _Stack Stack;
//Stack 객체의 생성과 소멸
Stack* Stack_new();
void Stack_delete(Stack* _this);

//Stack 객체의 점검
Boolean Stack_isEmpty(Stack* _this);
//스택이 empty 이면 TRUE를, 아니면, FALSE를 얻는다.
Boolean Stack_isFull(Stack* _this);
//스택이 full 이면 TRUE 를, 아니면, FALSE 를 얻는다.


//Stack 객체에게 행위를 지시
Boolean Stack_push(Stack* _this, Element anElement);
//스택에 anElement 를 삽입한다.
//삽입을 성공하면 TRUE, 실패하면 FALSE를 얻는다.
Element Stack_pop(Stack* _this);
//스택의 top에서 원소를 삭제하고 그 값을 얻는다.

void Stack_deleteLinkedNodes(Stack* _this);
void Stack_deleteLinkedNodesRecursively(Stack* _this, Node* firstNode);

int Stack_size(Stack* _this);