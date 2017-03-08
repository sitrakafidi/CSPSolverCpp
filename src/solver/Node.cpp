#include "Node.hpp"
#include <iostream>
Node::Node(){} 



Node::Node(vector<Domain>* doms){
	domains = doms;
}

vector<Domain>* Node::getDomains(){
	return domains;
}

bool Node::isSolution(){
	bool res = true;
	int i = 0;
	while(res && i<domains->size()){
		if(domains->at(i).getValues()->size() != 1) res = false;
		else ++i;
	}
	return res;
}

int Node::smallestDomainIndex(){
	int min = 0;
	while(domains->at(min).getValues()->size() <= 1) ++min;
	for(int i=0; i<domains->size(); ++i){
		if((domains->at(i).getValues()->size() < domains->at(min).getValues()->size()) && (domains->at(i).getValues()->size() > 1)){
			min =i;
		}
	}
	return min;
}

bool Node::hasEmptyDomain(){
	bool empty = false;
	int i = 0;
	while((!empty)&&(i<domains->size())){
		if(domains->at(i).getValues()->size() == 0) empty = true;
		else ++i;
	}
	return empty;
}

Node Node::clone(){
	vector<Domain>* doms = new vector<Domain>();
	for(Domain d : *domains){
		doms->push_back(d.clone());
	}
	return Node(doms);
	
} 

void Node::afficher(){
	for(Domain d : *domains){
		cout << "[ " ;
		for(int i : *(d.getValues())){
			cout << i << " ";
		}
		cout << "]";
	}
	cout << "*************************" << endl;
}