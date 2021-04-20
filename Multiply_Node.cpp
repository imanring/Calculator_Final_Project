#include "Multiply_Node.h"

Multiply_Node::Multiply_Node ()
{ }

int Multiply_Node::eval() {
	return this->left_->eval () * this->right_->eval ();
}

int Multiply_Node::precedence() {
	return 1;
}

void Multiply_Node::printName() {
	std::cout<<"Multiply Command"<<std::endl;
}
