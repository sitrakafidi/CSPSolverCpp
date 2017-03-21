#ifndef PROBLEM_H
#define PROBLEM_H
#include <string>
#include "../solver/Node.hpp"
#include "../constraints/Constraint.hpp"
using namespace std;

class Problem{
public:
	virtual void showSolutions(vector<Node> solutions) = 0;
	virtual vector<string>* getVariables() = 0; 
	virtual vector<Constraint*>* getConstraints() = 0; 
	virtual Node* getInitialNode() = 0;
	
};

#endif