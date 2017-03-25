#include <iostream>
#include <ctime>
//#include <stdio.h>
#include <string.h>
#include "Solver.hpp"
#include "../problems/NQueens.hpp"
#include "../problems/SendMoreMoney.hpp"
#include "../problems/MagicSquare.hpp"
using namespace std;

int main( int argc, char * argv[]){
	clock_t debut, fin;
	string nameProblem ;
	string nbSolutions;
	int N ;

	cout << "Choose a problem among: NQueens, SendMoreMoney, MagicSquare" << endl;
	cin >> nameProblem;
	if(nameProblem!="NQueens" && nameProblem!="SendMoreMoney" && nameProblem!="MagicSquare"){
		cout << "This problem doesn't exist" << endl;
		return 0;
	}

	if(nameProblem != "SendMoreMoney"){
		cout << "Enter the range N :" << endl;
		cin >> N;
	}

	do{
		cout << "all or one solution(s) ? " << endl;
		cin >> nbSolutions;
	} while(nbSolutions!="all" && nbSolutions!="one" );

	

	if(nameProblem=="NQueens"){
		Problem* nq = new NQueens(N);
		Solver queenSolv(nq);
		debut = clock();
		
		if(nbSolutions=="all"){
			queenSolv.branchAndPrune();			
		} 
		else{
			queenSolv.branchAndPrune2();
		}
		fin = clock();
		queenSolv.showSolutions();
	}

	if(nameProblem=="SendMoreMoney"){
		Problem* smm = new SendMoreMoney();
		Solver smmSolv(smm);
		debut = clock();

		if(nbSolutions=="all"){
			smmSolv.branchAndPrune();
		}
		else{
			smmSolv.branchAndPrune2();
		}

		fin = clock();
		smmSolv.showSolutions();
	}

	if(nameProblem=="MagicSquare"){
		Problem* ms = new MagicSquare(N);
		Solver msSolv(ms);
		debut = clock();

		if(nbSolutions=="all"){
			msSolv.branchAndPrune();
		}
		else{
			msSolv.branchAndPrune2();
		}

		fin = clock();
		msSolv.showSolutions();
	}


	cout << "temps : " << (double) (fin-debut)/CLOCKS_PER_SEC << "s" << endl;
	
	return 0;
}