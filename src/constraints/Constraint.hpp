#ifndef CONSTRAINT_HPP
#define CONSTRAINT_HPP
#include <vector>
#include "../solver/Domain.hpp"
using namespace std;
class Constraint{
public:
	virtual void apply(vector<Domain>* domains) = 0;
	virtual bool isRespected(vector<Domain>* domains) = 0;
};
#endif 