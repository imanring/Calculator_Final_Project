#include "Number_Node.h"

Number_Node::Number_Node (int val)
: val_ (val)
{ }

//Number_Node::~Number_Node() {}

int Number_Node::eval () {
	return this->val_;
}

int Number_Node::precedence() {
	return -1;
}

void Number_Node::printName() {
	std::cout<<"Number: "<<val_<<std::endl;
}
