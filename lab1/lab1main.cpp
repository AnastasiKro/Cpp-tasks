#include <iostream>
#include "lab1.h"
using namespace std;
using namespace Prog1;
int main(){
	Node* lines = nullptr;
	int m;
	double res;
	lines = input(m);
	if(!lines){
		cout<<"incorrect data" << endl;
		erase(lines);
		return 1;
	}
	output(lines, m);
	double* b = B(lines, m);
	outputB(b, m);
	erase(lines);
	delete [] b;
	return 0;
}

