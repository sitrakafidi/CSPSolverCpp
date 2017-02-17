#include "AllDifferent.hpp"
using namespace std;

AllDifferent::AllDifferent(vector<int> ind){
	domainIndex = ind;
}

void AllDifferent::apply(vector<Domain>* domains){
	for(int i : domainIndex){
		if(domains->at(i).getValues().size() == 1){
			suppValue(i,domains);
		}
	}
}

void AllDifferent::suppValue(int index, vector<Domain>* domains){
	int val = domains->at(index).getValues().at(0);
	for(int i : domainIndex){
		if(i!=index){
			for(int j=0; j < domains->at(i).getValues().size() ; ++j){
				if(domains->at(i).getValues().at(j) == val){
					domains->at(i).getValues().erase(domains->at(i).getValues().begin()+j);
				}
			}
		}
	}
}