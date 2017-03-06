#ifndef SOLVER_HPP
#define SOLVER_HPP
#include "../constraints/Constraint.hpp"
#include "Node.hpp"
#include <iostream>
using namespace std;
class Solver{
private:
	vector<string> variables;
	vector<Constraint*> constraints;
	Node initialNode;
	void showSolution(Node f);
	Node prune(Node e);

public:
	Solver(vector<string> var, vector<Constraint*> constr, Node initialN);
	void branchAndPrune();
};
#endif