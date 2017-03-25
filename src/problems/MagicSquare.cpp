#include "MagicSquare.hpp"
using namespace std;

MagicSquare::MagicSquare(int n){
	N = n;
	initProblem();
}

void MagicSquare::initProblem(){
	//Variables
	//cells of the grid
	for(int i=0 ; i<N*N; ++i){
		variables.push_back("X"+ to_string(i));
	}
	//magic sum
	variables.push_back("S");

	//Constraints
	//Alldifferent(x1,...,xN²)
	vector<int> index;
	for(int i=0; i<N*N ; ++i){
		index.push_back(i);
	}
	Constraint* alldif = new AllDifferent(index);
	constraints.push_back(alldif);

	//sum of each row equals to magic sum : exemple in the first row, x(0) + ... + x(N-1) - S = 0
	vector<int> coefs;
	for(int i=0; i<N ; ++i){
		coefs.push_back(1);
	}
	coefs.push_back(-1); // coefficient of the magic sum
	for(int i=0; i<N ; ++i){
		vector<int>* indexEq = new vector<int>() ;
		for(int j=0; j<N ; ++j){
			indexEq->push_back(i*N+j);
		} 
		indexEq->push_back(N*N); //index of the magic sum
		Constraint* Eq = new Equation(*indexEq,coefs);
		constraints.push_back(Eq);
	}

	//sum of each column equals to magic sum : exemple in the first column, x(0) + x(N) + ... + x (N*(N-1)) - S = 0  
	for(int i=0 ; i<N ; ++i){
		vector<int>* indexEq = new vector<int>() ;
		for(int j=0; j<N; ++j){
			indexEq->push_back(j*N+i);
		}
		indexEq->push_back(N*N); //index of the magic sum
		Constraint* Eq = new Equation(*indexEq,coefs);
		constraints.push_back(Eq);
	}

	// sum of first diagonal equals to magic sum
	vector<int> indexDiag1;
	for(int i=0 ; i<N ; ++i){
		indexDiag1.push_back(i*N+i);
	}
	indexDiag1.push_back(N*N);
	Constraint* EqDiag1 = new Equation(indexDiag1,coefs);
	constraints.push_back(EqDiag1);

	// sum of second diagonal equals to magic sum
	vector<int> indexDiag2;
	for(int i=0 ; i<N ; ++i){
		indexDiag2.push_back((i+1)*N - (i+1));
	}
	indexDiag2.push_back(N*N);
	Constraint* EqDiag2 = new Equation(indexDiag2,coefs);
	constraints.push_back(EqDiag2);

	//InitialNode
	vector<Domain>* doms = new vector<Domain>();
	for(int i=0 ; i<N*N ; ++i){
		vector<int>* initVec = new vector<int>() ;
		for(int j=1 ; j<N*N +1; ++j){
			initVec->push_back(j);
		}
		doms->push_back(Domain(initVec));
	}
	vector<int>* initVec2 = new vector<int>() ;
	for(int j=1 ; j<N*N*N ; ++j){
		initVec2->push_back(j);
	}
	doms->push_back(Domain(initVec2));
	
	initialNode = new Node(doms);
		
}

void MagicSquare::showSolutions(vector<Node> solutions){
	int n = 1;
	for(Node f : solutions) {
		cout << "solution #" << n  << " : " << endl;
		for(int i=0 ; i<N ; ++i){
			for(int j=0 ; j<N ; ++j){
				cout << f.getDomains()->at(i*N+j).getValues()->at(0) << "  ";
			}
			cout << endl;
		}
		cout << "===========================" << endl;
		++n;
	}
}

vector<string>* MagicSquare::getVariables(){
	return &variables;
}

vector<Constraint*>* MagicSquare::getConstraints(){
	return &constraints;
}

Node* MagicSquare::getInitialNode(){
	return initialNode;
}