#include <iostream>
#include "process.h"
using namespace std;



int main(int argc, char* argv[]) {
    if (argc != 7) {
        cout << "Wrong Command" << endl;
        return 1;
    }
    string algo = argv[2];
    string outputfile = argv[6];
    RunCommand(algo, string(argv[4]), outputfile);
}