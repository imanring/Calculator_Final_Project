//#include <memory>
#include "Expr_Tree_Builder.h"

Expr_Tree_Builder::Expr_Tree_Builder ()
: head_ (nullptr),
nodes_ (Stack<Expr_Node *>()),
ops_ (Stack<Binary_Expr_Node *>()),
parenthesisCount (Stack<int>())
{ }

Expr_Tree_Builder::~Expr_Tree_Builder () {
	delete head_;
}

void Expr_Tree_Builder::build_number (int num) {
	nodes_.push(new Number_Node(num));
	/*Expr_Node * top = head_;
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
	}*/
}

void Expr_Tree_Builder::build_add_operator () {
	Stack<Binary_Expr_Node *> temp = Stack<Binary_Expr_Node *>();
	while (!ops_.is_empty() && ops_.top()->precedence()>0) {
		temp.push(ops_.top());
		ops_.pop();
	}
	ops_.push(new Add_Node());
	while (!temp.is_empty()) {
		ops_.push(temp.top());
		temp.pop();
	}
	/*Expr_Node * temp = head_;
	head_ = new Add_Node ();
	dynamic_cast<Add_Node *>(head_)->setLeft(temp);*/
}

void Expr_Tree_Builder::build_multiply_operator () {
	ops_.push(new Multiply_Node());
	/*if (head_ && head_->precedence() != -1) {
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
	}*/
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
	while (!ops_.is_empty()) {
		ops_.top()->setRight(nodes_.top());
		nodes_.pop();
		ops_.top()->setLeft(nodes_.top());
		nodes_.pop();
		nodes_.push(ops_.top());
		ops_.top()->printName();
		ops_.pop();
	}
	head_ = nodes_.top();
	return nodes_.top();
}
