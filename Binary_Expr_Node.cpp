#include "Binary_Expr_Node.h"

Binary_Expr_Node::Binary_Expr_Node ()
: left_ (nullptr),
right_ (nullptr) 
{ }

Binary_Expr_Node::Binary_Expr_Node (Expr_Node * left, Expr_Node * right)
: left_ (left),
right_ (right) 
{ }

Binary_Expr_Node::~Binary_Expr_Node () {
	delete this->left_;
	delete this->right_;
}

void Binary_Expr_Node::setLeft (Expr_Node * left) {
	this->left_ = left;
}


void Binary_Expr_Node::setRight (Expr_Node * right) {
	this->right_ = right;
}
Expr_Node * Binary_Expr_Node::getLeft () {
	return this->left_;
}
Expr_Node * Binary_Expr_Node::getRight () {
	return this->right_;
}
