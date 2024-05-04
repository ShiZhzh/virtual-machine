//#ifdef __MEMORY_H__
#define __MEMORY_H__
#include<iostream>
#include<fstream>
#include<string>
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
//#endif