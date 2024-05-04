#include<string>
#include"computer.h"
int main(){
    string filename("orders.txt");
    Computer mycomputer("青芯CU1","青芯ALU1",1024,"输入设备1","输出设备1");
    mycomputer.run(filename);
    //getchar();
    return 0;
}