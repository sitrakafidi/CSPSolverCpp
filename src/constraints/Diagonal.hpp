#ifndef DIAGONAL_HPP
#define DIAGONAL_HPP
#include "Constraint.hpp"
class Diagonal : public Constraint{
private :
	vector<int> domainIndex;
	void suppValue(int i,vector<Domain>* domains);
public :
	Diagonal(vector<int> ind);
	void apply(vector<Domain>* domains);
	bool isRespected(vector<Domain>* domains);


};
#endif