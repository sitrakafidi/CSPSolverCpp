#include "Domain.hpp"

Domain::Domain(){
}

Domain::Domain(vector<int> val){
	values = val;
}

vector<int> Domain::getValues(){
	return values;
}

void Domain::supprValue(int value){
	for(int i=0 ; i<values.size() ; ++i){
		if(values.at(i) == value) values.erase(values.begin()+i);
	}
}

Domain* Domain::clone(){
	vector<int> val;
	for(int i : values){
		val.push_back(i);
	}
	Domain* copy = new Domain(val);
	return copy;
}