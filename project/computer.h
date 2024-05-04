#define __COMPUTER_H__
#include"cu.h"
#include<string>
using namespace std;
class Computer:public CU{
    public:
    Computer(){};
    Computer(string a,string b,int N,string c,string d):CU(a,b,N,c,d){}	
    void run(string file){
		CU::run_order(file);
    }
};