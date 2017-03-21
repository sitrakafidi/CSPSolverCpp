#include <iostream>
#include "Solver.hpp"
#include "../constraints/AllDifferent.hpp"
#include "../constraints/Diagonal.hpp"
#include "../problems/NQueens.hpp"
using namespace std;

int main(){

	NQueens* nq = new NQueens(4);
	//cout << nq->getInitialNode()->getDomains()->size() << endl;
	
	Solver queenSolv(nq);
	
	queenSolv.branchAndPrune();
	
	queenSolv.showSolutions();

	return 0;
}