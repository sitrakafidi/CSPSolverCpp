#include "Domain.hpp"
using namespace std;
/*Domain::Domain(){
}
*/
Domain::Domain(vector<int>* val){
	values = val;
}

vector<int>* Domain::getValues(){
	return values;
}

void Domain::supprValue(int value){
	for(int i=0 ; i<values->size() ; ++i){
		if(values->at(i) == value) values->erase(values->begin()+i);
	}
}

Domain Domain::clone(){
	vector<int>* val = new vector<int>();
	
	for(int i=0 ; i< values->size() ; ++i){

		val->push_back(values->at(i));
	}
	return Domain(val);
	
}