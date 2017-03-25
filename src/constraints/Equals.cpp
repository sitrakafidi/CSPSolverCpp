#include "Equals.hpp"
using namespace std;

Equals::Equals(vector<int> dom){
	domainIndex = dom;
}

void Equals::apply(vector<Domain>* domains){
	for(int i : domainIndex){
		
		if(domains->at(i).getValues()->size() == 1){
			
			suppValue(i,domains);
		}
	}
}

void Equals::suppValue(int index,vector<Domain>* domains){
	int val = domains->at(index).getValues()->at(0);
	for(int j : domainIndex){
		if(j != index){
			if(domains->at(j).contains(val)){
				domains->at(j).getValues()->clear();
				domains->at(j).getValues()->push_back(val);
			}
			else domains->at(j).getValues()->clear();
		}

	}

}

bool Equals::isRespected(vector<Domain>* domains){
	bool res = true;
	for(int i : domainIndex){
		
		if(domains->at(i).getValues()->size() == 1){
			int val = domains->at(i).getValues()->at(0);
			for(int j : domainIndex){
				if((j != i) && (domains->at(j).getValues()->size() != 0)){ //verifier si domain vide -> ca passe
					if((domains->at(j).getValues()->size()!=1) || (domains->at(j).getValues()->at(0) != val) ){ 
						res = false;
					} 
				}
			}
			
		}
	}
	return res;
}