#include <iostream>
#include <string>
#include <iomanip>
#include "../include/Percolation.h"
#include "../include/PercolationStats.h"

using namespace std;

int main(int argc, char *argv[]){

    if(argc != 3) exit(-1);

    int trials = atoi(argv[1]);
    int n = atoi(argv[2]);

    PercolationStats P = PercolationStats(trials, n);

    cout.precision(8);
    cout << endl;
    cout << trials << " trials on " << n << "x" << n << "grid : " << endl;
    cout <<  "mean                    = "  << P.mean() << endl;
    cout <<  "stddev                  = "  << P.stddev() << endl;
    cout <<  "95\% confidence interval = " << "[" << P.confidenceLo();
    cout <<  ", " << P.confidenceHi() << "]" << endl << endl;

    return 0;
}