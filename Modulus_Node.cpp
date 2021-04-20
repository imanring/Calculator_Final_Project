#include "Modulus_Node.h"

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
}
