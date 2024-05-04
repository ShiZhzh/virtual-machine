#define __OUT_H__
#include<iostream>
#include<string>
using namespace std;
class OUT{ 
    private:
        string name_out;
    public:
	    OUT(){}
        OUT(string name){
			name_out=name;
		}
        void get_name_out(){
            cout<<name_out<<endl;
        }
        void output(int number){
            cout<<number<<endl;
        }
};