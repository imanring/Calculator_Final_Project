#include "Calculator.h"

Calculator::Calculator()
: nodes_ (Stack<Expr_Node *>()),
ops_ (Stack<Binary_Expr_Node *>())
{ }

Calculator::~Calculator () {
	delete get_expression();
}

void Calculator::addOp (Binary_Expr_Node * op) {
	if (!ops_.is_empty() && ops_.top()->precedence() >= op->precedence()) {
		get_expression();
	}
	ops_.push(op);
}

void Calculator::addNode (Expr_Node * node) {
	nodes_.push(node);
}

void Calculator::print() {
	std::cout<<"Calculator: "<<std::endl;
	nodes_.top()->printName();
}

Expr_Node * Calculator::get_expression () {
	while (!ops_.is_empty()) {
		ops_.top()->setRight(nodes_.top());
		nodes_.pop();
		ops_.top()->setLeft(nodes_.top());
		nodes_.pop();
		nodes_.push(ops_.top());
		ops_.pop();
	}
	return nodes_.top();
}
