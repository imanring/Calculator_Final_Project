#include "Eval_Exrp_Tree.h"

Eval_Expr_Tree::Eval_Expr_Tree()
: result_ (0) { }

Eval_Expr_Tree::~Eval_Expr_Tree() { }

void Eval_Expr_Tree:visit_add_operator (const Add_Node * add) {
	add->getLeft()->accept(this);
	int temp = result_;
	add->getRight()->accept(this);
	result_ = temp + result_;
}

void Eval_Expr_Tree::visit_subtract_operator (Subtract_Node * subtract) {}
