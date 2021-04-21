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
	Expr_Tree_Builder * equ = new Expr_Tree_Builder();
	equ->build_number(5);
	equ->build_add_operator();
	equ->build_number (4);
	equ->build_multiply_operator();
	equ->build_number (6);
	equ->get_expression();
	int result = equ->get_expression()->eval();
	std::cout<<result<<std::endl;
	delete equ;
}
