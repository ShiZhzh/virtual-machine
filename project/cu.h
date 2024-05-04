#define __CU_H__
#include"memory.h"
#include"in.h"
#include"out.h"
#include"alu.h"
#include<iostream>
#include<string>
using namespace std;

class CU:public ALU,public Memory,public IN,public OUT{	
        
    public:
		string name_qd;
		CU(){}
        CU(string name,string a,int N,string b,string c):ALU(a),Memory(N),IN(b),OUT(c){
			name_qd=name;
	    }
        void run_order(string file){
			Memory::load_order(file);
            for(int j=0;j<orders_size();j++){
                string i=get_order(j);
                if(i[0]=='1'){
					//cout<<"first is 1"<<endl;
                    if(i[1]=='0'){
                        int p=(i[2]-'0')*10+(i[3]-'0');
                        int num=input();
                        change_num(num,p);
                    }
                    else if(i[1]=='1'){
                        int p=(i[2]-'0')*10+(i[3]-'0');
                        int number=get_num(p);
                        output(number);
                    }
                }
                else if(i[0]=='2'){
					//cout<<"first is 2"<<endl;
                    if(i[1]=='0'){
                        int p=(i[2]-'0')*10+(i[3]-'0');
                        load_num(get_num(p));
                    }
                    else if(i[1]=='1'){
                        int p=(i[2]-'0')*10+(i[3]-'0');
                        change_num(num_to_store(),p);
                    }
                }
                else if(i[0]=='3'){
					//cout<<"first is 3"<<endl;
                    if(i[1]=='0'){
                        int p=(i[2]-'0')*10+(i[3]-'0');
                        plus(get_num(p));
                    }
                    else if(i[1]=='1'){
						int p=(i[2]-'0')*10+(i[3]-'0');
                        jian(get_num(p));
                    }
                    else if(i[1]=='2'){
						int p=(i[2]-'0')*10+(i[3]-'0');
                        cheng(get_num(p));
                    }
                    else if(i[1]=='3'){
						int p=(i[2]-'0')*10+(i[3]-'0');
                        chu(get_num(p));
                    }
                }
                else if(i[0]=='4'){
					//cout<<"first is 4"<<endl;
                    if(i[1]=='0'){
                        int p=(i[2]-'0')*10+(i[3]-'0');
                        change_position(p);
                    }
                    else if(i[1]=='3'){
                        break;
                    }
                }
                else{
                    cout<<"第"<<j<<"条命令是无效的"<<endl;
                }
            }
        }
};