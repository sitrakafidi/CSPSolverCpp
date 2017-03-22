#ifndef NQUEENS_H
#define NQUEENS_H
#include <vector>
#include "Problem.hpp"
#include "../solver/Solver.hpp"
#include "../constraints/AllDifferent.hpp"
#include "../constraints/Diagonal.hpp"
using namespace std;
class NQueens : public Problem{
private : 
	int N;
	vector<string> variables;
	vector<Constraint*> constraints;
	Node* initialNode;
	void initProblem();
public :
	NQueens(int n);
	void showSolutions(vector<Node> solutions);
	virtual vector<string>* getVariables(); 
	virtual vector<Constraint*>* getConstraints(); 
	virtual Node* getInitialNode();
};
#endif