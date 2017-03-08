#include <iostream>
#include "src/solver/Solver.hpp"
#include "src/constraints/AllDifferent.hpp"
#include "src/constraints/Diagonal.hpp"
using namespace std;

int main(){
	int N = 4;

	//Initial Node
	vector<Domain> doms;
	for(int i=0 ; i<N ; ++i){
		vector<int>* initVec = new vector<int>() ;
		for(int j=0 ; j<N ; ++j){
			initVec->push_back(j);
		}
		doms.push_back(Domain(initVec));
	}
	Node init(&doms);
	
	Node G = init.clone();

	//cout << G.getDomains()->size() << endl;
	init.getDomains()->at(0).getValues()->push_back(17);

	cout << "Initial node : " << endl;
	init.afficher();
	cout << "Cloned node : " << endl;
	//cout << G.getDomains()->size() << endl;

	G.afficher();

}