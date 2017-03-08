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
		Node E = L.at(0).clone();
		L.erase(L.begin());
		//cout << "Before prune : " << endl;
		//E.afficher();
		Node F = prune(E); //reference ou pas?
		//cout << "After prune : " << endl;
		//F.afficher();
		if(!F.hasEmptyDomain()){
			//cout << "no empty domain!" << endl;
			if(isSolution(F)){
				showErrors(F);
				//showSolution(F);
			}
			else{
				
				int index = F.smallestDomainIndex();
				//cout << F.getDomains()->at(index).getValues().size() << endl;
				for(int v : *(F.getDomains()->at(index).getValues())){
					
					Node G = F.clone();

					G.getDomains()->at(index).getValues()->clear();
					//cout << "après clear #" << index << endl;
					//G.afficher();
					//G.getDomains()->at(index).getValues()->erase(G.getDomains()->at(index).getValues()->begin());
					//cout << "euh.." << G->getDomains()->at(index).getValues().size() << endl;
					G.getDomains()->at(index).getValues()->push_back(v);
					//G.afficher();
					//cout << "blablaeuh.." << G->getDomains()->at(index).getValues().size() << endl;
					L.push_back(G);
					
				}
			}
		}
	}
}

Node Solver::prune(Node e){
	Node res = e.clone();
	for(int i=0 ; i<constraints.size() ; ++i){
		constraints.at(i)->apply(res.getDomains());
		//cout << "eto" << endl;
	}
	return res;
}

void Solver::showSolution(Node f){
	cout << "solution found : " << endl;
	for(int i=0 ; i<variables.size() ; ++i){
		string line = "";
		for(int j=0; j<variables.size() ; ++j){
			if(j == f.getDomains()->at(i).getValues()->at(0)){
				line = line + "0";
			} else {
				line = line + "-";
			}
		}
		cout << line << endl;
	}
	cout << "===========================" << endl;
}

void Solver::showErrors(Node f){
	for(int i=0; i< f.getDomains()->size() ; ++i){
		int val = f.getDomains()->at(i).getValues()->at(0);
		for (int j=i+1 ; j< f.getDomains()->size() ; ++j){
			if(f.getDomains()->at(j).getValues()->at(0) == val){
				cout << "ERROR found !" << endl;
				f.afficher();
			}
		}
	}
}



bool Solver::isSolution(Node n){
	bool constraintsOK = true;
	int i = 0;
	/*while(constraintsOK && i<constraints.size()){
		if (!(constraints.at(i)->isRespected(n.getDomains()))){
			constraintsOK = false;
		}
		else ++i;
	}*/

	bool singlOK = true;
	i = 0;
	while(singlOK && i< n.getDomains()->size()){
		if(n.getDomains()->at(i).getValues()->size() != 1) {
			singlOK = false;
		}
		else ++i;
	}
	return singlOK && constraintsOK;
}