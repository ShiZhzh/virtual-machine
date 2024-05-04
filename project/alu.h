#define __ALU_H__
#include<iostream>
#include<string>
using namespace std;
class ALU{
    private:
        string name_alu;  
        int num1=0;//ALU内存  
    public:
	    ALU(){}
        ALU(string name){
			name_alu=name;
		}
        void get_name_alu(){
            cout<<name_alu<<endl;
        }
        /*void change(int &x,int y){
            x=y;
        }*/
        void load_num(int number){
            num1=number;
        }
        int num_to_store(){
            return num1;
        }
        void plus(int pos){
            int result=0;
            result=pos+num1;
            num1=result;
            
        }
        void jian(int pos){
            int result=0;
            result=num1-pos;
            num1=result;
        }
        void cheng(int pos){
            int result=0;
            result=num1*pos;
            num1=result;
        }
        void chu(int pos){
            int result=0;
            result=num1/pos;
            num1=result;
            if((num1%pos)!=0){
                cout<<"异常：无法整除"<<endl;
            }
        }
};