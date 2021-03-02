




#include "../include/Percolation.h"
// #include "include/UnionFind.h"
#include <iostream>
#include <iomanip>

Percolation::Percolation(int n){

    length = n;
    grid = new int[n*n + 2];
    sz = new int[n*n + 2];
    nb_open =0;

    // each site is represented by its coordinates (row, column)
    // an open site contains the number of its parent (0-n^2)
    // a blocked site is -1 (initially all sites are blocked)
    for(int i=0; i<n*n; i+=1){
        grid[i] = -1;
        sz[i] = 0;
    }

    // sites n*n+1 and n*n+2 should be connected to top and bottom row 
    // so we can only check these two sites too know if system percolates
    grid[n*n] = n*n;
    grid[n*n + 1] = n*n + 1;
    sz[n*n] = sz[n*n + 1] = 1;

}

Percolation::~Percolation(){
    delete[] grid;
    delete[] sz;
}

// checks if a site is open
bool Percolation::isOpen(int r, int c){
    return grid[r*length + c] != -1;
}

// checks if a site is full
// (a site is full if it is connected to the top row)
bool Percolation::isFull(int r, int c){
    return Connected(r*length + c, length*length);
}

// opens a site (r,c)
void Percolation::open(int r, int c){

    //std::cout << r << " " << c << std::endl;

    if(!isOpen(r,c)){

        grid[r*length + c] = r*length + c;

        // if a site is on first or last row , it is connected to 
        // n*n and n*n+1 sites that are used to check if system percolates
        if(r == 0)        Union(r*length +c, length*length);
        if(r == length-1) Union(r*length +c, length*length+1);

        // connect opened site to its open neighbors (up-down-left-right)
        if( r+1 != length && isOpen(r+1, c)) Union(r*length + c, (r+1)*length +c);
        if( r-1 != -1     && isOpen(r-1, c)) Union(r*length + c, (r-1)*length +c);
        if( c+1 != length && isOpen(r, c+1)) Union(r*length + c, r*length + c + 1);
        if( c-1 != -1     && isOpen(r, c-1)) Union(r*length + c, r*length + c - 1);

        nb_open += 1;
        
    }
}

int Percolation::numberOfOpenSites(){
    return nb_open;
}

bool Percolation::percolates(){
    return Connected(length*length, length*length +1);
}


void Percolation::Union(int p, int q){

    int rp = Root(p);
    int rq = Root(q);

    if(sz[rp] < sz[rq]){
        grid[rp] = grid[rq];
        sz[rq] += sz[rp];
    }else{
        grid[rq] = grid[rp];
        sz[rp] += sz[rq];
    }
}

bool Percolation::Connected(int p, int q){

    return Root(p) == Root(q);
}

int Percolation::Root(int i){

    while(i != grid[i]){
        grid[i] = grid[grid[i]]; // make every object point to its grand parent in order to half the path length
        i = grid[i];
    }
    return i;
}

void Percolation::printGrid(){

    for(int i=0; i<length; i+=1){
        for(int j=0; j<length; j+=1){
            std::cout << std::setw(5) << grid[i*length + j];
        }
        std::cout << std::endl;
    }
    std::cout << std::endl << std::endl;
}