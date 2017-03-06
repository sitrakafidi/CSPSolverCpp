#include "Solver.hpp"

Solver::Solver(vector<string> var, vector<Constraint*> constr, Node initialN){
	variables = var;
	constraints = constr;
	initialNode = initialN;
}

void Solver::branchAndPrune(){
	vector<Node> L ;
	L.push_back(initialNode);
	while(!L.empty()){
		//cout << L.size() << endl;
		Node* E = L.at(0).clone();
		L.erase(L.begin());
		Node F = prune(*E); //reference ou pas?
		
		if(!F.hasEmptyDomain()){
			if(F.isSolution()){
				showSolution(F);
			}
			else{
				
				int index = F.smallestDomainIndex();
				//cout << F.getDomains()->at(index).getValues().size() << endl;
				for(int v : F.getDomains()->at(index).getValues()){
					
					Node* G = F.clone();

					G->getDomains()->at(index).getValues().clear();
					//G->getDomains()->at(index).getValues().erase(G->getDomains()->at(index).getValues().begin()+1);
					cout << "euh.." << G->getDomains()->at(index).getValues().size() << endl;
					G->getDomains()->at(index).getValues().push_back(v);
					cout << "blablaeuh.." << G->getDomains()->at(index).getValues().size() << endl;
					L.push_back(*G);
					
				}
			}
		}
	}
}

Node Solver::prune(Node e){
	Node* res = e.clone();
	for(int i=0 ; i<constraints.size() ; ++i){
		constraints.at(i)->apply(res->getDomains());
		//cout << "eto" << endl;
	}
	return *res;
}

void Solver::showSolution(Node f){
	cout << "solution found : " << endl;
	for(int i=0 ; i<variables.size() ; ++i){
		string line = "";
		for(int j=0; j<variables.size() ; ++j){
			if(j == f.getDomains()->at(i).getValues().at(0)){
				line = line + "0";
			} else {
				line = line + "-";
			}
		}
		cout << line << endl;
	}
	cout << "===========================" << endl;
}