#include "SendMoreMoney.hpp"
using namespace std;

SendMoreMoney::SendMoreMoney(){
	//variables
	vector<string> vars;
	vars.push_back("S");
	vars.push_back("E");
	vars.push_back("N");
	vars.push_back("D");
	vars.push_back("M");
	vars.push_back("O");
	vars.push_back("R");
	vars.push_back("Y");

	for(int i=0; i<4 ; ++i){
		vars.push_back("R"+to_string(i+1));
	}
	variables = vars;

	//Constraints
	//Alldif 
	vector<int> indexVar;
	for(int i=0 ; i<8 ; ++i){
		indexVar.push_back(i);
	}
	Constraint* alldif = new AllDifferent(indexVar);
	constraints.push_back(alldif);

	//Equation 1 :
	vector<int> indexEq1;
	indexEq1.push_back(3);
	indexEq1.push_back(1);
	indexEq1.push_back(7);
	indexEq1.push_back(8);
	vector<int> coefEq1;
	coefEq1.push_back(1);
	coefEq1.push_back(1);
	coefEq1.push_back(-1);
	coefEq1.push_back(-10);

	Constraint* Eq1 = new Equation(indexEq1,coefEq1);
	constraints.push_back(Eq1);

	//Equation 2 : 
	vector<int> indexEq2;
	indexEq2.push_back(8);
	indexEq2.push_back(2);
	indexEq2.push_back(6);
	indexEq2.push_back(1);
	indexEq2.push_back(9);
	vector<int> coefEq2;
	coefEq2.push_back(1);
	coefEq2.push_back(1);
	coefEq2.push_back(1);
	coefEq2.push_back(-1);
	coefEq2.push_back(-10);

	Constraint* Eq2 = new Equation(indexEq2,coefEq2);
	constraints.push_back(Eq2);

	//Equation 3 :
	vector<int> indexEq3;
	indexEq3.push_back(9);
	indexEq3.push_back(1);
	indexEq3.push_back(5);
	indexEq3.push_back(2);
	indexEq3.push_back(10);
	vector<int> coefEq3;
	coefEq3.push_back(1);
	coefEq3.push_back(1);
	coefEq3.push_back(1);
	coefEq3.push_back(-1);
	coefEq3.push_back(-10);

	Constraint* Eq3 = new Equation(indexEq3,coefEq3);
	constraints.push_back(Eq3);

	//Equation 4 :
	vector<int> indexEq4;
	indexEq4.push_back(10);
	indexEq4.push_back(0);
	indexEq4.push_back(4);
	indexEq4.push_back(5);
	indexEq4.push_back(11);
	vector<int> coefEq4;
	coefEq4.push_back(1);
	coefEq4.push_back(1);
	coefEq4.push_back(1);
	coefEq4.push_back(-1);
	coefEq4.push_back(-10);

	Constraint* Eq4 = new Equation(indexEq4,coefEq4);
	constraints.push_back(Eq4);

	//Equals
	vector<int> indexEq;
	indexEq.push_back(11);
	indexEq.push_back(4);
	Constraint* Eq = new Equals(indexEq);
	constraints.push_back(Eq);


	//InitialNode

	vector<Domain>* doms = new vector<Domain>();
	for(int i=0 ; i<8 ; ++i){
		vector<int>* initVec = new vector<int>() ;
		for(int j=0 ; j<10 ; ++j){
			initVec->push_back(j);
		}
		doms->push_back(Domain(initVec));
	}
	for(int i=0 ; i<4 ; ++i){
		vector<int>* initVec = new vector<int>() ;
		for(int j=0 ; j<2 ; ++j){
			initVec->push_back(j);
		}
		doms->push_back(Domain(initVec));
	}
	initialNode = new Node(doms);
	



}


void SendMoreMoney::showSolutions(vector<Node> solutions){
	int n = 1;
	for(Node f : solutions) {
		cout << "solution #" << n << endl;
		for(int i=0; i<8 ; ++i){
			cout << variables.at(i) << " : " << f.getDomains()->at(i).getValues()->at(0) << endl;
		}
		cout << "========================" << endl;
		++n;
	}
}

vector<string>* SendMoreMoney::getVariables(){
	return &variables;
}

vector<Constraint*>* SendMoreMoney::getConstraints(){
	return &constraints;
}

Node* SendMoreMoney::getInitialNode(){
	return initialNode;
}