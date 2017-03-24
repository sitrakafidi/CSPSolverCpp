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
					
					domains->at(j).getValues()->erase(domains->at(j).getValues()->begin() + k);
					
				}
			}
		}
	}
}

bool Diagonal::isRespected(vector<Domain>* domains){
	bool res = true;
	for(int i : domainIndex){
		if(domains->at(i).getValues()->size() == 1){
			int xi = domains->at(i).getValues()->at(0);
			for(int j : domainIndex){
				if(i != j){
					int xj1 = xi - j + i ;
					int xj2 = xi + j - i ;
					if(domains->at(j).contains(xj1) || domains->at(j).contains(xj2)){
						res = false;
					}
				} 
			}
		}
	}
	return res;
}