//#include <memory>
#include "Expr_Tree_Builder.h"

Expr_Tree_Builder::Expr_Tree_Builder ()
: head_ (nullptr) { }

Expr_Tree_Builder::~Expr_Tree_Builder () {
	std::cout<<"Expr_Tree_Builder destructor"<<std::endl;
	head_->printName();
	delete head_;
}

void Expr_Tree_Builder::build_number (int num) {
	Expr_Node * top = head_;
	Expr_Node * parent = head_;
	while (top) {
		parent = top;
		if (top->precedence() != -1) {
			top = dynamic_cast<Binary_Expr_Node *>(top)->getRight();
		}
	}
	if (parent) {
		dynamic_cast<Binary_Expr_Node *>(parent)->setRight(new Number_Node(num));
	} else {
		head_ = new Number_Node(num);
	}
}

void Expr_Tree_Builder::build_add_operator () {
	Expr_Node * temp = head_;
	head_ = new Add_Node ();
	dynamic_cast<Add_Node *>(head_)->setLeft(temp);
}

void Expr_Tree_Builder::build_multiply_operator () {
	if (head_ && head_->precedence() != -1) {
		Expr_Node * top = head_;
		Expr_Node * parent = head_;
		while (top && top->precedence()<1 && top->precedence() != -1) {
			std::cout<<"top: ";
			top->printName();
			parent = top;
			top = dynamic_cast<Binary_Expr_Node *>(top)->getRight();
			top->printName();
		}
		//parent = dynamic_cast<Binary_Expr_Node *>(parent);
		Expr_Node * temp = top;
		//dynamic_cast<Binary_Expr_Node *>(parent)->getRight();
		dynamic_cast<Binary_Expr_Node *>(parent)->setRight(new Multiply_Node());
		dynamic_cast<Multiply_Node *>(dynamic_cast<Binary_Expr_Node *>(parent)->getRight())->setLeft(temp);
		std::cout<<"Got this far"<<std::endl;
	} else {
		Expr_Node * temp = head_;
		head_ = new Multiply_Node();
		dynamic_cast<Multiply_Node *>(head_)->setLeft(temp);
	}
}

void Expr_Tree_Builder::inOrder(Expr_Node * top) {
	if (top->precedence() == -1) {
		top->printName();
	} else {
		inOrder(dynamic_cast<Binary_Expr_Node *>(top)->getLeft());
		top->printName();
		inOrder(dynamic_cast<Binary_Expr_Node *>(top)->getRight());
	}
}

Expr_Node * Expr_Tree_Builder::get_expression () {
	return head_;
}
