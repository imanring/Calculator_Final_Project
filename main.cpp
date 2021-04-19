#include <iostream>
#include <string>
#include <sstream>
#include "Add_Command.h"
#include "Subtract_Command.h"
#include "Multiply_Command.h"
#include "Divide_Command.h"
#include "Modulus_Command.h"
#include "Number_Command.h"
#include "Stack.h"
#include "Stack_Expr_Command_Factory.h"

Stack <Command *> commands = Stack<Command*>();

void printStack(Stack <Command *> cmds) {
	while (!cmds.is_empty()) {
		cmds.top()->printName();
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
	return splitEqu;
}

void infix_to_postfix(Stack <int> & s, Stack<std::string> equation){
	Stack_Expr_Command_Factory sf = Stack_Expr_Command_Factory(s);
	Stack<Command *> ops = Stack<Command *>();
	Command * cmd = 0;
	int num;
	Stack <int> parenthesisCount;
	// test to see if the value is an int
	while (!equation.is_empty()) {
		try{
			num = std::stoi(equation.top());
			cmd = sf.create_number_command(num);
			commands.push(cmd);
		//the value is not an int
		} catch (std::invalid_argument & e) {
			if(equation.top() == "+"){
				cmd = sf.create_add_command ();
			} else if (equation.top() == "-") {
				cmd = sf.create_subtract_command();
			} else if (equation.top() == "*") {
				cmd = sf.create_multiply_command();
			} else if (equation.top() == "/") {
				cmd = sf.create_divide_command();
			} else if (equation.top() == "%") {
				cmd = sf.create_modulus_command();
			} else if (equation.top() == "(" ) {
				// COMMENT: Create a design that does not require having parenthesis as
				// as command object since parenthesis are not executed.
				// RESPONSE: Deleted Parenthesis_Command. Now I keep track of where parenthesis is entered with parenthesisCount
				parenthesisCount.push(ops.size());
			} else if (equation.top() == ")" && !parenthesisCount.is_empty()) {
				printStack(ops);
				// move ops in parenthesis to command stack
				while (parenthesisCount.top() < ops.size()) {
					commands.push(ops.top());
					ops.pop();
				}
				parenthesisCount.pop();
			} else {
				throw "Error... Please enter a valid equation";
			}
			if (cmd) {
				// if the operation is lower priority and it is not in parenthesis
				while (!ops.is_empty() && ops.top()->precedence() >= cmd->precedence() && (parenthesisCount.is_empty() || ops.size() > parenthesisCount.top())) {
					// add command to command stack
					commands.push(ops.top());
					ops.pop();
				}
				ops.push(cmd);
			}
		}
		cmd = nullptr;
		equation.pop();
	}
	while (!ops.is_empty()) {
		commands.push(ops.top());
		ops.pop();
	}
}

void execute (Stack <int> & s) {
	while (!commands.is_empty()) {
		commands.top()->execute();
		delete commands.top();
		commands.pop();
	}
}


int main() {
	// COMMENT Your program needs to loop until QUIT is entered.
	// RESPONSE Added a check in readCommand for QUIT. I will break out of this loop if QUIT is entered.
	Stack <int> s = Stack<int>();
	bool keepGoing = true;
	while (keepGoing) {
		try {
			Stack <std::string> equation = readCommand();
			infix_to_postfix(s,equation);
			commands.reverse();
			printStack(commands);
			execute(s);
			std::cout<<"Result: "<<s.top()<<std::endl;
		} catch (int quit) { //QUIT
			keepGoing = false;
		} catch (const char * error) { //invalid equation
			std::cout<<error<<std::endl;
		}
		s.clear();
	}
}
