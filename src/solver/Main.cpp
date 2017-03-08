#include <iostream>
#include "Solver.hpp"
#include "../constraints/AllDifferent.hpp"
#include "../constraints/Diagonal.hpp"
using namespace std;

int main(){
	//Nqueens problem
	int N = 12;

	//Variables
	vector<string> var;
	for(int i=0 ; i<N ; ++i){
		var.push_back("x"+i);
	}

	//Constraints
	vector<Constraint*> constr;
	vector<int> indexCol;
	for(int i=0 ; i<N ; ++i){
		indexCol.push_back(i);
	}
	Constraint* columns = new AllDifferent(indexCol);
	Constraint* diag = new Diagonal(indexCol);
	constr.push_back(columns);
	constr.push_back(diag); 

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

	Solver queenSolv(var,constr,init);
	
	queenSolv.branchAndPrune();

	return 0;
}