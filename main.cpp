#include <iostream>
#include <string>
#include <sstream>
#include "Add_Node.h"
#include "Subtract_Node.h"
#include "Multiply_Node.h"
#include "Divide_Node.h"
#include "Modulus_Node.h"
#include "Number_Node.h"

int main () {
	Expr_Node * n1 = new Number_Node(5);
	Expr_Node * n2 = new Number_Node(4);
	Add_Node * expr = new Add_Node ();
	expr->setLeft(n1);
	expr->setRight(n2);
	int result = expr->eval();
	std::cout<<result<<std::endl;
	delete expr;
}
