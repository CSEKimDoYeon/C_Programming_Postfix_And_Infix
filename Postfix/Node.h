typedef struct _Node Node;
typedef int Element;

Node* Node_new();
//³ëµå °´Ã¼¸¦ »ý¼º
void Node_delete(Node* _this);
//³ëµå °´Ã¼¸¦ ¼Ò¸ê
void Node_setElement(Node* _this, Element newElement);
Element Node_element(Node* _this);
void Node_setNext(Node* _this, Node* newNext);
Node* Node_next(Node* _this);