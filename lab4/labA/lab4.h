#include <iostream>

namespace Prog4{
	template <class T>
	int getNum(T& a){
		int flag = 0;
		do{
			std::cin>>a;
			if(!std::cin.good()){
				std::cin.clear();
				std::cin.ignore();
			}
			else
				flag =1;
		}while(flag==0);
		return 0;
	}	
	class hero{
		private:
			int x;
			int y;
			int hp;
			
		public:

	};
	class C1{


	};
}
