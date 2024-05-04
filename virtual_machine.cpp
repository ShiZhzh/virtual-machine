#include<iostream>
#include<fstream>
#include<vector>
using namespace std;

class Memory{
    private:
        int N=0;//内存大小
        vector<string>orders;//内存命令部分
        int *num;//内存数据部分
        int position=0;//内存指针
    public:
        string order;
        Memory(){}
        ~Memory(){
            delete[] num;
            orders.clear();
        }
        Memory(int n){
			N=n;
		}
        void load_order(string file){
            ifstream infile;
            infile.open(file, ios::in);
            if(!infile.is_open())
            {
                cout << "读取文件失败" << endl;
            }
            
            int size=0;
            while(getline(infile,order)){
				//cout<<"successful"<<endl;
                orders.push_back(order);
                size++;
            }
            num=(int*)malloc((N-orders.size())*sizeof(int));
        }
        int orders_size(){
            return orders.size();
        }
        string get_order(int i){
            return orders[i];
        }
        int get_num(int p_num){
            return num[p_num];
        }
        void change_num(int number,int p_num){
            num[p_num]=number;
        }
        void change_position(int pos){
            position=pos;
        }
};
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
        }
};
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

   
class Computer:public CU{
    public:
    Computer(){};
    Computer(string a,string b,int N,string c,string d):CU(a,b,N,c,d){}	
    void run(string file){
		CU::run_order(file);
    }
};
int main(){
	string filename("D:/IDE/visual stadio code/C++/virtual/order.txt");
    Computer mycomputer("青芯CU1","青芯ALU1",1024,"输入设备1","输出设备1");
    mycomputer.run(filename);
    return 0;
}
/**/