#define __IN_H__
#include<string>
#include<iostream>
using namespace std;
class IN{
    private:
        string name_in;
        int put;
    public:
		IN(){}
        IN(string name){
			name_in=name;
		}
        void get_name_in(){
            cout<<name_in<<endl;
        }
        int input(){
            cin>>put;
            return put;
        }
};