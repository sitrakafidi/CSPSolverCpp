#include <iostream>
#include <ctime>
#include "Solver.hpp"
#include "../constraints/AllDifferent.hpp"
#include "../constraints/Diagonal.hpp"
#include "../problems/NQueens.hpp"
using namespace std;

int main(){
	clock_t debut, fin;
	Problem* nq = new NQueens(10);
	
	Solver queenSolv(nq);
	debut = clock();
	queenSolv.branchAndPrune();
	fin = clock();
	queenSolv.showSolutions();
	cout << "temps : " << (double) (fin-debut)/CLOCKS_PER_SEC << "s" << endl;
	return 0;
}