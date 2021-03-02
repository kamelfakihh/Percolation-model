#ifndef PERCOLATIONSTATS
#define PERCOLATIONSTATS

class PercolationStats {

public :

    // perform independent trials on an n-by-n grid
    PercolationStats(int n, int trials);
    ~PercolationStats();

    // sample mean of percolation threshold
    double mean();

    // sample standard deviation of percolation threshold
    double stddev();

    // low endpoint of 95% confidence interval
    double confidenceLo();

    // high endpoint of 95% confidence interval
    double confidenceHi();

    void RunSimulation();

private :

    int n;               // grid dimensions
    int trials;          // number of trials
    double *threshold;   // percolation threshold of each trial

};

#endif