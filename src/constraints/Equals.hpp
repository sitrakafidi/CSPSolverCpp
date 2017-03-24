#ifndef EQUALS_HPP
#define EQUALS_HPP
#include "Constraint.hpp"
class Equals : public Constraint{
private :
	private :
	vector<int> domainIndex;
	void suppValue(int index,vector<Domain>* domains);
public :
	Equals(vector<int> ind);
	void apply(vector<Domain>* domains);
	bool isRespected(vector<Domain>* domains);
};
#endif