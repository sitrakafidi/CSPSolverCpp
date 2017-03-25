#ifndef MAGICSQUARE_H
#define MAGICSQUARE_H
#include <vector>
#include "Problem.hpp"
#include "../solver/Solver.hpp"
#include "../constraints/AllDifferent.hpp"
#include "../constraints/Equation.hpp"
using namespace std;
class MagicSquare : public Problem{
private : 
	int N;
	vector<string> variables;
	vector<Constraint*> constraints;
	Node* initialNode;
	void initProblem();
public :
	MagicSquare(int n);
	void showSolutions(vector<Node> solutions);
	virtual vector<string>* getVariables(); 
	virtual vector<Constraint*>* getConstraints(); 
	virtual Node* getInitialNode();
};
#endif