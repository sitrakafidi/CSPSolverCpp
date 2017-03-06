#ifndef NODE_HPP
#define NODE_HPP
#include "Domain.hpp"
#include <vector>
using namespace std;

class Node{
private :
	vector<Domain> domains;
public :
	Node();
	Node(vector<Domain> dom);
	vector<Domain>* getDomains();
	bool isSolution();
	int smallestDomainIndex();
	bool hasEmptyDomain();
	Node* clone();

};
#endif