#include "Expr_Tree_Builder.h"

Expr_Tree_Builder::Expr_Tree_Builder ()
: head_ (nullptr) { }

Expr_Tree_Builder::~Expr_Tree_Builder () {
	delete head_;
}

void Expr_Tree_Builder::build_number (int num) {
	Expr_Node * top = head_;
	Expr_Node * parent = head_;
	while (top) {
		parent = top;
		if (top.precedence() != -1) {
			top = top->getRight();
		}
	}
	if (parent) {
		parent->setRight(new Number_Node(num));
	} else {
		head_ = new Number_Node(num);
	}
}

void Expr_Tree_Builder::build_add_operator () {
	Expr_Node * temp = head_;
	head_ = new Add_Node ();
	head_->setLeft(temp);
}

Expr_Node * get_expression () {
	return head_;
}
