#include "NQueens.hpp"
using namespace std;

NQueens::NQueens(int n){
	N = n;
	initProblem();
}

void NQueens::initProblem(){
	//Variables;
	for(int i=0 ; i<N ; ++i){
		variables.push_back("x"+i);
	}

	//Constraints
	vector<int> indexCol;
	for(int i=0 ; i<N ; ++i){
		indexCol.push_back(i);
	}
	Constraint* columns = new AllDifferent(indexCol);
	Constraint* diag = new Diagonal(indexCol);
	constraints.push_back(columns);
	constraints.push_back(diag);

	//Initial Node
	
	vector<Domain>* doms = new vector<Domain>();
	for(int i=0 ; i<N ; ++i){
		vector<int>* initVec = new vector<int>() ;
		for(int j=0 ; j<N ; ++j){
			initVec->push_back(j);
		}
		doms->push_back(Domain(initVec));
	}
	
	initialNode = new Node(doms);
	
	 
}

void NQueens::showSolutions(vector<Node> solutions){
	int n = 1;
	for(Node f : solutions) {
		cout << "solution #" << n  << " : " << endl;
		for(int i=0 ; i<N ; ++i){
			string line = "";
			for(int j=0; j<N ; ++j){
				if(j == f.getDomains()->at(i).getValues()->at(0)){
					line = line + "0";
				} else {
					line = line + "-";
				}
			}
			cout << line << endl;
		}
		cout << "===========================" << endl;
		++n;
	}
}

void NQueens::showSolution(vector<Node> solutions){
	int n = 1;
	for(Node f : solutions) {
		cout << "solution #" << n  << " : " << endl;
		for(int i=0 ; i<N ; ++i){
			string line = "";
			for(int j=0; j<N ; ++j){
				if(j == f.getDomains()->at(i).getValues()->at(0)){
					line = line + "0";
				} else {
					line = line + "-";
				}
			}
			cout << line << endl;
		}
		cout << "===========================" << endl;
		++n;
	}
}

vector<string>* NQueens::getVariables(){
	return &variables;
}

vector<Constraint*>* NQueens::getConstraints(){
	return &constraints;
}

Node* NQueens::getInitialNode(){
	return initialNode;
}