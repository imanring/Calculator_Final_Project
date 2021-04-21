#include "Calculator.h"

Calculator::Calculator()
: nodes_ (Stack<Expr_Node *>()),
ops_ (Stack<Binary_Expr_Node *>())
{ }

Calculator::~Calculator () {
	delete get_Expression();
}

void Calculator::addOp (Binary_Expr_Node * op) {
	Stack<Binary_Expr_Node *> temp = Stack<Binary_Expr_Node *>();
	while (!ops_.is_empty() && ops_.top()->precedence()>op->precedence()) {
		temp.push(ops_.top());
		ops_.pop();
	}
	ops_.push(op);
	while (!temp.is_empty()) {
		ops_.push(temp.top());
		temp.pop();
	}	
}

void Calculator::addNode (Expr_Node * node) {
	nodes_.push(node);
}

void Calculator::print() {
	nodes_.top()->printName();
}

int Calculator::get_expression () {
	while (!ops_.is_empty()) {
		ops_.top()->setRight(nodes_.top());
		nodes_.pop();
		ops_.top()->setLeft(nodes_.top());
		nodes_.pop();
		nodes_.push(ops_.top());
		ops_.top()->printName();
		ops_.pop();
	}
	return nodes_.top();
}
