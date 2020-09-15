#include <iostream>
//using namespace std;
namespace Prog1{
	struct Node{
		int row;
		int column;
		double value;
		struct Node* next;
	};
	/*struct Line{i
		int n;
		double* a;
	};*/
	template <class T>
	int getNum(T &a){
		int b = 0;
		do{
			std::cin >> a;
		if (!std::cin.good()){
			std::cin.clear();
			std::cin.ignore();
			std::cout << "Input a number" << std::endl;
			//return -1;
		}
		else
			b=1;
		}while(b==0);
		return 0;
	}
	inline int isgreater(double a, double b){
		return a > b;
	}
	Node* findel(Node* lines, int i, int j);
	Node* input(int &);
	void output(Node* a, int m);
	Node* erase(Node* a);
	void outputB(double* b, int m);
	double* B(Node* lines, int m);
	int findmax(Node* lines, int i, int k, int(*f)(double, double));
}
