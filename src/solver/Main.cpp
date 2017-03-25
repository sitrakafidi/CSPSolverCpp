#include <iostream>
#include <ctime>
//#include <stdio.h>
#include <string.h>
#include "Solver.hpp"
#include "../constraints/AllDifferent.hpp"
#include "../constraints/Diagonal.hpp"
#include "../problems/NQueens.hpp"
using namespace std;

int main( int argc, char * argv[]){
	clock_t debut, fin;
	string nameProblem = argv[1];
	char* parameter = argv[2];
	string nbSolutions = argv[3];
	int param = atoi(parameter);

	if(nameProblem=="NQueens"){
		Problem* nq = new NQueens(param);
		Solver queenSolv(nq);
		debut = clock();
		
		if(nbSolutions=="all"){
			queenSolv.branchAndPrune();
			queenSolv.showSolutions();
		} else if(nbSolutions=="one"){
			queenSolv.branchAndPrune2();
			queenSolv.showSolution();
		}

		fin = clock();
	}

	if(nameProblem=="Money"){
		/*Problem* nq = new Money(parameter);
		Solver queenSolv(nq);
		debut = clock();
		queenSolv.branchAndPrune();
		fin = clock();
		queenSolv.showSolutions();*/
	}

	cout << "temps : " << (double) (fin-debut)/CLOCKS_PER_SEC << "s" << endl;
	return 0;
}