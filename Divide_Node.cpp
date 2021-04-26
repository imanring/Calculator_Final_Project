#include "Divide_Node.h"

Divide_Node::Divide_Node ()
{ }

int Divide_Node::eval () {
	return this->left_->eval() / this->right_->eval();
}

int Divide_Node::precedence() {
	return 1;
}

void Divide_Node::printName() {
	std::cout<<"Divide Command"<<std::endl;
}
/*
void Divide_Node::accept(Expr_Node_Visitor * visitor) {
	visitor->visit_divide_operator(this);
}*/
