#include "Add_Node.h"
#include "Expr_Node_Visitor.h"

Add_Node::Add_Node ()
{ }

/*Add_Node::~Add_Node() {
	std::cout<<"Visisted"<<std::endl;
	delete this->left_;
	delete this->right_;
}*/

int Add_Node::eval (){
	return this->left_->eval()+this->right_->eval ();
}

int Add_Node::precedence() {
	return 0;
}

void Add_Node::printName() {
	std::cout<<"Add Command"<<std::endl;
	std::cout<<"Left: "<<std::endl;
	left_->printName();
	std::cout<<"Right: "<<std::endl;
	right_->printName();
}

void Add_Node::accept(Expr_Node_Visitor * visitor) {
	visitor->visit_add_operator(this);
}
