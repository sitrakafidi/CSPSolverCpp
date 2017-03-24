#include "Solver.hpp"


Solver::Solver(Problem* pbl){

	
	pb = pbl;
	variables = *(pbl->getVariables());
	constraints = *(pbl->getConstraints());
	initialNode = pbl->getInitialNode();
	
	
}

void Solver::branchAndPrune(){
	vector<Node> L ;
	L.push_back(*initialNode);
	while(!L.empty()){
		
		Node E = L.at(0).clone();
		
		L.erase(L.begin());

		Node F = prune(E); 

		if(!F.hasEmptyDomain()){
		
			if(isSolution(F)){
				//showErrors(F);
				solutions.push_back(F);
			
			}
			else{
				
				int index = F.smallestDomainIndex();
					
				for(int v : *(F.getDomains()->at(index).getValues())){
					//cout << "branch" << endl;
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
	do{
		for(int i=0 ; i<constraints.size() ; ++i){
			constraints.at(i)->apply(res.getDomains());
			/*for(int j=0 ; j<constraints.size() ;++j){
				constraints.at(j)->apply(res.getDomains());
			}*/
		}
	} while(!allConstraintsRespected(res));
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
	bool constraintsOK = true; 
	int i = 0;
	bool singlOK = true;
	i = 0;
	while(singlOK && i< n.getDomains()->size()){
		if(n.getDomains()->at(i).getValues()->size() != 1) {
			singlOK = false;
		}
		else ++i;
	}
	int j = 0;
	while(j<constraints.size() && constraintsOK ){
		if(!(constraints.at(j)->isRespected(n.getDomains()))){ 
			constraintsOK = false;
		} else j++;

	}
	return singlOK && constraintsOK;
}

bool Solver::allConstraintsRespected(Node n){
	bool constraintsOK = true; 
	int j = 0;
	while(j<constraints.size() && constraintsOK ){
		if(!(constraints.at(j)->isRespected(n.getDomains()))){ 
			constraintsOK = false;
		} else j++;

	}
	

	return constraintsOK;
}