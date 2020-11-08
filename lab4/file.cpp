#include <iostream>
#include <fstream>

int main(){
	//e = new Alive[1];
	char line[10];
	int n = 0;
	//char x[2]; char y[2];
	//std::string line;
	//if (j==1)
	//	std::ifstream in("/home/avtobus/3sem/lab2/3sem/lab4/enemies");
	//else
		std::ifstream in("/home/avtobus/3sem/lab2/3sem/lab4/enemies");
	if (in.is_open()){
		while (!in.eof()){
			//n+=1;
			//std::cout<<n<<std::endl;
			in.getline(line, 10);
			std::cout<<line<<std::endl;
			if (in.eof())
				break;
			n+=1;
			char* x1 = new char[3]; char* y1= new char[3];
			//*n+=1;
			//Alive* ee = new Alive[*n];
			//for (int i = 0; i<*n-1; i++)
			//	ee[i]=e[i];
			//ee[*n-1].setname(line);
			//printw(line);
			in.getline(x1, 3);
			//ee[*n-1].setx(atoi(x1));
			std::cout<<x1<<std::endl;
			if (in.eof())
				break;
			in.getline(y1,3);
			std::cout<<y1<<std::endl;
			//ee[*n-1].sety(atoi(y1));
			//delete[] e;
			delete[] x1; delete[] y1;
			//= ee;
			//if (n==5)
			//	break;
			if (in.eof())
				break;
		}
	}
	in.close();
	return 0;
}

