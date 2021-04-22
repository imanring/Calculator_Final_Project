#ifndef EVAL_EXPR_TREE_H_EXISTS
#define EVAL_EXPR_TREE_H_EXISTS

#include "Expr_Node_Visitor.h"

class Eval_Expr_Tree : public Expr_Node_Visitor {
public:
	Eval_Expr_Tree();
	~Eval_Expr_Tree();
	void visit_add_operator (Add_Node * add);
	void visit_subtract_operator(Subtract_Node * subtract);
	void visit_number (Number_Node * num);
private:
	int result_;
};

#endif
