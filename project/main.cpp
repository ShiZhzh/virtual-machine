#include<string>
#include"computer.h"
int main(){
    string filename("orders.txt");
    Computer mycomputer("��оCU1","��оALU1",1024,"�����豸1","����豸1");
    mycomputer.run(filename);
    //getchar();
    return 0;
}