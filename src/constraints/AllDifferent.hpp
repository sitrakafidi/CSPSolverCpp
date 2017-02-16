#ifndef ALLDIFFERENT_HPP
#define ALLDIFFERENT_HPP
#include "Constraint.hpp"
class AllDifferent : Constraint{
private :
	vector<int> domainIndex;
	void suppValue(int index,)
public :
	AllDifferent::AllDifferent(vector<int> ind);
	void apply(vector<Domain> domains);

}

#endif