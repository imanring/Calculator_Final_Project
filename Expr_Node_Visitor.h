#ifndef EXPR_NODE_VISITOR_H_EXISTS
#define EXPR_NODE_VISITOR_H_EXISTS

class Binary_Expr_Node;
class Add_Node;
class Subtract_Node;
class Multiply_Node;
class Divide_Node;
class Modulus_Node;
class Number_Node;

class Expr_Node_Visitor {
public:
	~Expr_Node_Visitor();
	virtual void visit_add_operator (Add_Node * add) = 0;
	virtual void visit_subtract_operator (Subtract_Node * subtract) = 0;
	virtual void visit_multiply_operator (Multiply_Node * mult) = 0;
	virtual void visit_divide_operator (Divide_Node * divide) = 0;
	virtual void visit_modulus_operator(Modulus_Node * mod) = 0;
	virtual void visit_number (Number_Node * num) = 0;
};

#endif
