#include "Diagonal.hpp"
#include <iostream>
using namespace std;

Diagonal::Diagonal(vector<int> ind){
	domainIndex = ind;
}

void Diagonal::apply(vector<Domain>* domains){
	for(int i : domainIndex){
		if(domains->at(i).getValues()->size() == 1){
			suppValue(i, domains);
			//cout << "singleton !" << endl;
		}
	}
}

void Diagonal::suppValue(int i,vector<Domain>* domains){
	int xi = domains->at(i).getValues()->at(0);
	for(int j : domainIndex){
		if(i != j){
			int xj1 = xi - j + i ;
			int xj2 = xi + j - i ;
			for(int k=0; k<domains->at(j).getValues()->size() ; ++k){
				if((domains->at(j).getValues()->at(k) == xj1) || (domains->at(j).getValues()->at(k) == xj2) ){
					//cout << "avant :" << domains->at(j).getValues().size() << endl;
					domains->at(j).getValues()->erase(domains->at(j).getValues()->begin() + k);
					//cout << "après :" << domains->at(j).getValues().size() << endl;
				}
			}
		}
	}
}

bool Diagonal::isRespected(vector<Domain>* domains){
	return true;
}