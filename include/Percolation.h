#ifndef PERCOLATION
#define PERCOLATION

class Percolation {

public :

    // creates n-by-n grid, with all sites initially blocked
    Percolation(int n);
    ~Percolation();

    // opens the site (row, col) if it is not open already
    void open(int row, int col);

    // is the site (row, col) open?
    bool isOpen(int row, int col);

    // is the site (row, col) full?
    bool isFull(int row, int col);

    // returns the number of open sites
    int numberOfOpenSites();

    // checks if the system percolates
    bool percolates();

    void printGrid();

private :

    void Union(int p, int q);
    bool Connected(int p, int q);
    int Root(int node);

    int *grid;          // union find object representing the grid representing the grid (two dimensional)
    int *sz;            // number of children of a node i 
    int length;         // length of grid sides  
    int nb_open;        // number of open sites   

};

#endif