#include "Eval_Expr_Tree.h"
#include "Add_Node.h"
#include "Subtract_Node.h"
#include "Multiply_Node.h"
#include "Divide_Node.h"
#include "Modulus_Node.h"
#include "Number_Node.h"

Eval_Expr_Tree::Eval_Expr_Tree()
: result_ (0) { }

Eval_Expr_Tree::~Eval_Expr_Tree() { }

void Eval_Expr_Tree::visit_add_operator (Add_Node * add) {
	add->getLeft()->accept(this);
	int temp = result_;
	add->getRight()->accept(this);
	result_ = temp + result_;
}

void Eval_Expr_Tree::visit_subtract_operator (Subtract_Node * subtract) {
	subtract->getLeft()->accept(this);
	int temp = result_;
	subtract->getRight()->accept(this);
	result_ = temp - result_;

}

void Eval_Expr_Tree::visit_multiply_operator (Multiply_Node * mult) {
	mult->getLeft()->accept(this);
	int temp = result_;
	mult->getRight()->accept(this);
	result_ = temp * result_;
}
void Eval_Expr_Tree::visit_divide_operator (Divide_Node * divide) {
	divide->getLeft()->accept(this);
	int temp = result_;
	divide->getRight()->accept(this);
	result_ = temp / result_;
}
void Eval_Expr_Tree::visit_modulus_operator (Modulus_Node * mod) {
	mod->getLeft()->accept(this);
	int temp = result_;
	mod->getRight()->accept(this);
	result_ = temp % result_;
}

void Eval_Expr_Tree::visit_number (Number_Node * num) {
	result_ = num->getVal();
}

int Eval_Expr_Tree::result () const {
	return result_;
}
