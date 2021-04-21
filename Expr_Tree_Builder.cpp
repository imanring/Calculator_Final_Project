//#include <memory>
#include "Expr_Tree_Builder.h"

Expr_Tree_Builder::Expr_Tree_Builder ()
: expressions (Stack<Calculator>())
{
	expressions.push(Calculator());
}

void Expr_Tree_Builder::build_number (int num) {
	expressions.top().addNode(new Number_Node(num));
}

void Expr_Tree_Builder::build_add_operator () {
	expressions.top().addOp(new Add_Node());
}

void Expr_Tree_Builder::build_subtract_operator () {
	expressions.top().addOp(new Subtract_Node());
}

void Expr_Tree_Builder::build_multiply_operator () {
	expressions.top().addOp(new Multiply_Node());
}

void Expr_Tree_Builder::build_divide_operator () {
	expressions.top().addOp(new Divide_Node());
}

void Expr_Tree_Builder::build_modulus_operator () {
	expressions.top().addOp(new Modulus_Node());
}

void Expr_Tree_Builder::build_open_parenthesis () {
	expressions.push(Calculator());
}

void Expr_Tree_Builder::build_close_parenthesis () {
	Expr_Node * head = expressions.top().get_expression();
	expressions.pop();
	expressions.top().addNode(head);
}

Expr_Node * Expr_Tree_Builder::get_expression () {
	return expressions.top().get_expression();
}
