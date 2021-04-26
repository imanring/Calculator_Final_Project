#include "Modulus_Node.h"
#include "Expr_Node_Visitor.h"

Modulus_Node::Modulus_Node ()
{ }

int Modulus_Node::eval() {
	return this->left_->eval() % this->right_->eval();
}

int Modulus_Node::precedence() {
	return 1;
}

void Modulus_Node::printName() {
	std::cout<<"Modulus Command"<<std::endl;
	std::cout<<"Left: ";
	this->left_->printName();
	std::cout<<"Right: ";
	this->right_->printName();
}

void Modulus_Node::accept(Expr_Node_Visitor * visitor) {
	visitor->visit_modulus_operator(this);
}
