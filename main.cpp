#include <iostream>
#include <string>
#include <sstream>
#include "Expr_Node_Visitor.h"
#include "Add_Node.h"
#include "Subtract_Node.h"
#include "Multiply_Node.h"
#include "Divide_Node.h"
#include "Modulus_Node.h"
#include "Number_Node.h"
#include "Expr_Tree_Builder.h"
#include "Eval_Expr_Tree.h"


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

int create_expression(Stack<std::string> equation) {
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
	//try {
		//equ.get_expression()->printName();
		Expr_Node * n = equ.get_expression();
		Eval_Expr_Tree * v = new Eval_Expr_Tree();
		n->accept(v);
		int r = v->result();
		delete v;
		return r;
	/*} catch (std::exception e) {
		std::cout<<"You are annoying"<<std::endl;
		//return create_expression(readCommand());
		throw "Error... Please enter a valid equation";
	}*/
}


int main () {
	///*
	bool keepGoing = true;
	while (keepGoing) {
		try {
			std::cout<<"Enter equation: "<<std::endl;
			std::cout<<create_expression(readCommand())<<std::endl;
		} catch (int quit) {
			keepGoing = false;
		} catch (std::invalid_argument & e) {
			std::cout<<"Please enter a valid equation"<<std::endl;
		} catch (...) {
			std::cout << "You annoying individual. You entered an invalid equation"<<std::endl;
		}
	}
	//*/
}
