#include "Subtract_Node.h"

Subtract_Node::Subtract_Node ()
{ }

int Subtract_Node::eval () {
	return this->left_->eval()-this->right_->eval();
}

int Subtract_Node::precedence() {
	return 0;
}

void Subtract_Node::printName() {
	std::cout<<"Subtract Command"<<std::endl;
}
