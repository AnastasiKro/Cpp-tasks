#include <iostream>
#include "lab1.h"
using namespace std;
namespace Prog1{
	Node* input(int &rm){
		int m;
		const char *pr = "";
		Node* lines = nullptr;
		do {
			cout << pr << endl;
			cout << "Input number of lines --> ";
			pr = "You are wrong, repeat please!";
			getNum(m);
		}while(m<1);
		Node* l = lines;
		for (int i = 0; i< m; i++){
			double r;
			cout << "input elements in line #" << i+1 << ":" <<endl;
			for (int j =0; j<m; j++){
				getNum(r);
				if (r!=0){
						Node* n = new Node;
					if (lines==nullptr){
						lines = n;
						l = lines;
					}
					else{
						l->next = n;
						l = l->next;
					}

					n->value = r;
					n->row=i;
					n->column = j;
					n->next = nullptr;
				}
			}
		}
		rm = m;
		return lines;
	}
	void output(Node* lines, int m){
		int i, j;
		cout << "Sourced matrix:\n";
		Node* n = lines;
		for (i=0; i< m; i++){
			for(j=0; j<m; j++){
				if (n!=nullptr){
				if ((n->row == i)&&(n->column == j)){
					cout << n->value << "  ";
					n = n->next;
				}
				else
					cout << "0  ";
				}
				else{
					cout << "0 ";
				}
			}
			cout<<endl;
		}
	}
	Node* findel(Node* lines, int i, int j){
		while(lines!=nullptr){
			if((lines->row ==i) && (lines->column ==j))
				return lines;
			if ((lines->row>i) || (lines->row==i && lines->column>j)){
				Node* n = new Node;
				n->value = 0;
				n->row = i;
				n->column=j;
				return n;
			}
			lines=lines->next;
		}
		Node* n = new Node;
		n->value = 0;
		n->row = i;
		n->column = j;
		return n;
	}
	Node *erase(Node *lines){
		Node* n = lines;
		while(n!=nullptr){
			n = n->next;
			delete lines;
			lines = n;
		}
		return nullptr;
	}
	
	int findmax(Node*lines, int i,int m, int(*f)(double, double)){
		Node* n = findel(lines, i, 0);
			double a = n->value;
		Node* N;
		for (int j = 1; j<m; j++){
			N = findel(lines, i, j);
			double b = N->value;
			if(f(b,a)==1){
				a = b;
				n = N;
			}
		}
		return n->column;
	}		
	double* B(Node* lines, int m){
		double* b;
		try{
			b = new double[m];
		}
		catch(bad_alloc &ba){
			cout << "no memory" <<endl;
			return nullptr;
		}
		for (int i = 0; i<m; i++){
			int k=findmax(lines, i, m, isgreater);
			for (int j =0; j<m; j++){
				Node* aij=findel(lines, i, j);
				Node* ajk=findel(lines, j, k);
				b[i]+=aij->value*ajk->value;
			}
		}
		return b;
	}
	void outputB(double* b, int m){
		cout << "Vector B: " << endl;
		for (int i = 0; i<m; i++){
			cout << b[i] << " ";
		}
		cout << endl;
	}	

}




