#ifndef SOLVER_HPP
#define SOLVER_HPP
#include "../constraints/Constraint.hpp"
#include "Node.hpp"
#include "../problems/Problem.hpp"
#include <iostream>
using namespace std;
class Solver{
private:
	Problem *pb;
	vector<string> variables;
	vector<Constraint*> constraints;
	Node* initialNode;
	vector<Node> solutions;
	
	void showErrors(Node f);
	Node prune(Node e);
	bool isSolution(Node n);
	bool allConstraintsRespected(Node n);



public:
	Solver(Problem* pbl);
	void branchAndPrune();
	void showSolutions();
};
#endif