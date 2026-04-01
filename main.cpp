#include <iostream>
#include "process.h"
using namespace std;



int main(int argc, char* argv[]) {
    if (argc != 4) {
        cout << "Wrong Command" << endl;
        return 1;
    }
    string algo = argv[1];
    string inputfile = "tests/" + string(argv[2]);
    string outputfile = argv[3];
    RunCommand(algo, inputfile, outputfile);
}