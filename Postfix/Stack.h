#include "common.h"
#include "Node.h"

#define MAX_STACK_SIZE 5;

typedef struct _Stack Stack;
//Stack ��ü�� ������ �Ҹ�
Stack* Stack_new();
void Stack_delete(Stack* _this);

//Stack ��ü�� ����
Boolean Stack_isEmpty(Stack* _this);
//������ empty �̸� TRUE��, �ƴϸ�, FALSE�� ��´�.
Boolean Stack_isFull(Stack* _this);
//������ full �̸� TRUE ��, �ƴϸ�, FALSE �� ��´�.


//Stack ��ü���� ������ ����
Boolean Stack_push(Stack* _this, Element anElement);
//���ÿ� anElement �� �����Ѵ�.
//������ �����ϸ� TRUE, �����ϸ� FALSE�� ��´�.
Element Stack_pop(Stack* _this);
//������ top���� ���Ҹ� �����ϰ� �� ���� ��´�.

void Stack_deleteLinkedNodes(Stack* _this);
void Stack_deleteLinkedNodesRecursively(Stack* _this, Node* firstNode);

int Stack_size(Stack* _this);