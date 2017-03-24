#ifndef EQUATION_HPP
#define EQUATION_HPP
#include "Constraint.hpp"
class Equation : public Constraint{
private :
	private :
	vector<int> domainIndex;
	vector<int> coefficients;	
	//void suppValue(int index,vector<Domain>* domains);
public :
	Equation(vector<int> ind , vector<int> coef);
	void apply(vector<Domain>* domains);
	bool isRespected(vector<Domain>* domains);
};
#endif