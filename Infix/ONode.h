#pragma once
typedef struct _ONode ONode;
typedef char ElementForOStack;

ONode* ONode_new();
//³ëµå °´Ã¼¸¦ »ý¼º
void ONode_delete(ONode* _this);
//³ëµå °´Ã¼¸¦ ¼Ò¸ê
void ONode_setElement(ONode* _this, ElementForOStack newElement);
ElementForOStack ONode_element(ONode* _this);
void ONode_setNext(ONode* _this, ONode* newNext);
ONode* ONode_next(ONode* _this);