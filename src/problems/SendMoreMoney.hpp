#ifndef SENDMOREMONEY_HPP
#define SENDMOREMONEY_HPP
#include "Problem.hpp"
#include <vector>
#include "Problem.hpp"
#include "../solver/Solver.hpp"
#include "../constraints/AllDifferent.hpp"
#include "../constraints/Equals.hpp"
#include "../constraints/Equation.hpp"
using namespace std;
class SendMoreMoney : public Problem{
private:
	vector<string> variables;
	vector<Constraint*> constraints;
	Node* initialNode;
public:
	SendMoreMoney();
	void showSolutions(vector<Node> solutions);
	virtual vector<string>* getVariables(); 
	virtual vector<Constraint*>* getConstraints(); 
	virtual Node* getInitialNode();
};



#endif
