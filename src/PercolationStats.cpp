



#include "../include/PercolationStats.h"
#include "../include/Percolation.h"
#include <cmath>
#include <time.h>
#include <stdlib.h>

// perform independent trials on an n-by-n grid
PercolationStats::PercolationStats(int n, int trials){

    this->n = n;
    this->trials = trials;
    threshold = new double[trials];

    this->RunSimulation();

}

PercolationStats::~PercolationStats(){

    delete[] threshold;
}

// sample mean of percolation threshold
double PercolationStats::mean(){

    double sum = 0;
    for(int i=0; i<trials; i+=1) sum+=threshold[i];
    return sum/trials;
}

// sample standard deviation of percolation threshold
double PercolationStats::stddev(){

    double sum = 0;
    double x = this->mean();
    for(int i=0; i<trials; i+=1) sum+= pow(threshold[i]-x,2);
    return sqrt(sum/(trials-1));
}

// low endpoint of 95% confidence interval
double PercolationStats::confidenceLo(){

    double s = this->stddev();
    double x = this->mean();

    return x - (1.96*s)/sqrt(trials);
}

// high endpoint of 95% confidence interval
double PercolationStats::confidenceHi(){

    double s = this->stddev();
    double x = this->mean();

    return x + (1.96*s)/sqrt(trials);
}

// run the simulation
void PercolationStats::RunSimulation(){

    for(int i=0; i<trials; i+=1){

        // use a different seed for every percolation
        srand(time(NULL));

        Percolation P = Percolation(n); 
        int row, col;

        while(1){

            row = rand()%n;
            col = rand()%n;

            // open random sites in syste,
            P.open(row, col);

            // check if system percolates on each iteration
            if(P.percolates()) break;
        }

        // save percolation threshold of each system
        threshold[i] = (double) P.numberOfOpenSites()/(n*n);
    }
}