#include "Number_Node.h"
#include "Expr_Node_Visitor.h"

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

int Number_Node::getVal() {
	return val_;
}

void Number_Node::accept(Expr_Node_Visitor * visitor) {
	visitor->visit_number (this);
}
