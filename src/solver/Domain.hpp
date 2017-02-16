#ifndef DOMAIN_HPP
#define DOMAIN_HPP
#include <vector>
using namespace std;

class Domain{
private :
	vector<int> values;
public:
	Domain();
	Domain(vector<int> val);
	vector<int> getValues();
	void supprValue(int value);

};
#endif