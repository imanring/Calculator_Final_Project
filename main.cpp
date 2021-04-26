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

void printStack(Stack <std::string> cmds) {
	while (!cmds.is_empty()) {
		std::cout<<cmds.top()<<std::endl;
		cmds.pop();
	}
}


Stack <std::string> readCommand() {
	std::string equ;
	getline(std::cin,equ);
	if (equ == "QUIT") {
		throw -1;
	}
	std::stringstream ss(equ);
	std::string token;
	Stack <std::string> splitEqu = Stack<std::string>();
	while (getline(ss,token,' ')) {
		splitEqu.push(token);
	}
	// need to fix should probably use a vector
	splitEqu.reverse();
	printStack(splitEqu);
	return splitEqu;
}

int create_expression(Stack<std::string> equation){
	Expr_Tree_Builder equ = Expr_Tree_Builder();
	int num;
	// test to see if the value is an int
	while (!equation.is_empty()) {
		try{
			num = std::stoi(equation.top());
			equ.build_number (num);
		//the value is not an int
		} catch (std::invalid_argument & e) {
			if(equation.top() == "+"){
				equ.build_add_operator();
			} else if (equation.top() == "-") {
				equ.build_subtract_operator();
			} else if (equation.top() == "*") {
				equ.build_multiply_operator();
			} else if (equation.top() == "/") {
				equ.build_divide_operator();
			} else if (equation.top() == "%") {
				equ.build_modulus_operator();
			} else if (equation.top() == "(" ) {
				equ.build_open_parenthesis();
			} else if (equation.top() == ")" ) {
				equ.build_close_parenthesis();
			} else {
				throw "Error... Please enter a valid equation";
			}
		}
		equation.pop();
	}
	equ.get_expression()->printName();
	return equ.get_expression()->eval();
}


int main () {
	///*
	bool keepGoing = true;
	while (keepGoing) {
		try {
			std::cout<<create_expression(readCommand())<<std::endl;
		} catch (int quit) {
			keepGoing = false;
		} catch (const char * e) {
			std::cout<<e<<std::endl;
		}
	}
	//*/
	/*Expr_Tree_Builder equ = Expr_Tree_Builder();
	equ.build_number(8);
	equ.build_add_operator();
	equ.build_number (0);
	//equ.build_modulus_operator();
	//equ.build_number (6);
	//equ.get_expression();
	int result = equ.get_expression()->eval();
	std::cout<<result<<std::endl;
	//delete equ;
	*/
}
