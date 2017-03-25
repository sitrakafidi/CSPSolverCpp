#include "Equation.hpp"
using namespace std;

Equation::Equation(vector<int> ind , vector<int> coef){
	domainIndex = ind;
	coefficients = coef;
}

void Equation::apply(vector<Domain>* domains){
	bool allDomainsSingl = true;
	for(int i : domainIndex){
		if(domains->at(i).getValues()->size() != 1){
			allDomainsSingl = false;
		}
	}
	if(allDomainsSingl){
		int sum = 0;
		for(int i=0 ; i<domainIndex.size() ; ++i){
			sum = sum + domains->at(domainIndex.at(i)).getValues()->at(0) * coefficients.at(i);
		}
		if(sum != 0){
			for(int ind : domainIndex){
				domains->at(ind).getValues()->clear();
			}
		}

	}
}


bool Equation::isRespected(vector<Domain>* domains){
	bool res = true;
	bool allDomainsSingl = true;
	for(int i : domainIndex){
		if(domains->at(i).getValues()->size() != 1){
			allDomainsSingl = false;
		}
	}

	if(allDomainsSingl){
		int sum = 0;
		for(int i=0 ; i<domainIndex.size() ; ++i){
			sum = sum + domains->at(domainIndex.at(i)).getValues()->at(0) * coefficients.at(i);
		}
		if(sum != 0){
			res = false;
		}

	}
	return res; 
}