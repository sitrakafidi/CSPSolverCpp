#include "AllDifferent.hpp"
#include <iostream>
using namespace std;

AllDifferent::AllDifferent(vector<int> ind){
	domainIndex = ind;
}

void AllDifferent::apply(vector<Domain>* domains){
		for(int i : domainIndex){
		
		if(domains->at(i).getValues()->size() == 1){
			
			suppValue(i,domains);
		}
	}
}

void AllDifferent::suppValue(int index, vector<Domain>* domains){
	int val = domains->at(index).getValues()->at(0);
	for(int i : domainIndex){
		if(i != index ){
			for(int j=0; j < domains->at(i).getValues()->size() ; j++){
				if(domains->at(i).getValues()->at(j) == val){
					
					int size =  domains->at(i).getValues()->size();
					domains->at(i).getValues()->erase(domains->at(i).getValues()->begin()+j);
					domains->at(i).getValues()->resize(size-1);
				}
			}
		}
	}
}

bool AllDifferent::isRespected(vector<Domain>* domains){
	bool res = true;
	for(int i=0 ; i< domainIndex.size(); ++i){
		if(domains->at(domainIndex.at(i)).getValues()->size() == 1){
			int val = domains->at(domainIndex.at(i)).getValues()->at(0);
			for(int j=0 ; j<domainIndex.size(); ++j){
				if((domainIndex.at(i) != domainIndex.at(j)) && (domains->at(domainIndex.at(j)).contains(val))){
					res = false;				
				}

			}
		}
	
	}
	
	return res;
}