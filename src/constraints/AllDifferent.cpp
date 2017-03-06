#include "AllDifferent.hpp"
#include <iostream>
using namespace std;

AllDifferent::AllDifferent(vector<int> ind){
	domainIndex = ind;
}

void AllDifferent::apply(vector<Domain>* domains){

	for(int i : domainIndex){
		if(domains->at(i).getValues().size() == 1){
			suppValue(i,domains);
			cout << "singleton !" << endl;
		}
	}
}

void AllDifferent::suppValue(int index, vector<Domain>* domains){
	int val = domains->at(index).getValues().at(0);
	for(int i : domainIndex){
		if(i!=index){
			for(int j=0; j < domains->at(i).getValues().size() ; ++j){
				if(domains->at(i).getValues().at(j) == val){
					cout << "avant :" << domains->at(i).getValues().size() << endl;
					domains->at(i).getValues().erase(domains->at(i).getValues().begin()+j);
					cout << "après :" << domains->at(i).getValues().size() << endl;
				}
			}
		}
	}
}