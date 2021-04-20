#include <iostream>
#include <string>
#include <sstream>
#include "Add_Node.h"
#include "Subtract_Node.h"
#include "Multiply_Node.h"
#include "Divide_Node.h"
#include "Modulus_Node.h"
#include "Number_Node.h"
#include "Expr_Tree_Builder.h"


int main () {
	/*Expr_Node * n1 = new Number_Node(5);
	Expr_Node * n2 = new Number_Node(4);
	Add_Node * expr = new Add_Node ();
	expr->setLeft(n1);
	expr->setRight(n2);
	*/
	Expr_Tree_Builder * equ = new Expr_Tree_Builder();
	equ->build_number(5);
	equ->build_add_operator();
	equ->build_number (4);
	int result = equ->get_expression()->eval();
	std::cout<<result<<std::endl;
	delete equ;
}
