#include "Add_Node.h"

Add_Node::Add_Node ()
{ }

int Add_Node::eval (){
	return this->left_->eval()+this->right_->eval ();
}

int Add_Node::precedence() {
	return 0;
}

void Add_Node::printName() {
	std::cout<<"Add Command"<<std::endl;
}
