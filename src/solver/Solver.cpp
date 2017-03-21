#include "Solver.hpp"


Solver::Solver(Problem* pbl){
	pb = pbl;
	variables = *(pbl->getVariables());
	constraints = *(pbl->getConstraints());
	initialNode = *(pbl->getInitialNode());
	cout << pbl->getInitialNode()->getDomains()->size() << endl;
	
	
}

void Solver::branchAndPrune(){
	vector<Node> L ;
	L.push_back(initialNode);
	while(!L.empty()){
		
		Node E = L.at(0).clone();
		
		L.erase(L.begin());

		Node F = prune(E); 

		if(!F.hasEmptyDomain()){
		
			if(isSolution(F)){
				
				solutions.push_back(F);
			
			}
			else{
				
				int index = F.smallestDomainIndex();
	
				for(int v : *(F.getDomains()->at(index).getValues())){
					
					Node G = F.clone();

					G.getDomains()->at(index).getValues()->clear();

					G.getDomains()->at(index).getValues()->push_back(v);

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

	}
	return res;
}

void Solver::showSolutions(){
	pb->showSolutions(solutions);
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
	bool constraintsOK = true; //FIX ME
	int i = 0;
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