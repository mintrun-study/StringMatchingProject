#include <iostream>
#include "process.h"
using namespace std;



int main(int argc, char * argv[]){
    if(argc != 4){
        cout<<"Wrong Command"<<endl;
        return;
    }
    RunCommand(argv[1],argv[2],argv[3]);
}