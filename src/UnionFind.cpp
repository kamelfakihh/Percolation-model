#include "../include/UnionFind.h"
#include <stdexcept>

QuickFindUF::QuickFindUF(int n){

    // we initialize each object to be connected to itself such that id[i] = i 
    if(n>0){
        length = n;
    }else{
        throw std::runtime_error("number of objects can't be less than 0");
    }

    id = new int[length];
    for(int i=0; i<length; i+=1){
        id[i] = i;
    }
}

QuickFindUF::~QuickFindUF(){
    delete[] id;
}

void QuickFindUF::Union(int p, int q){

    int pid = id[p];
    int qid = id[q];

    for(int i=0; i<length; i+=1){
        if(id[i] == pid){
            id[i] = qid;
        }
    }
}

bool QuickFindUF::Connected(int p, int q){

    return id[p] == id[q];
}

UnionFindUF::UnionFindUF(int n){

    // we initialize each object to be connected to itself such that id[i] = i 
    if(n>0){
        length = n;
    }else{
        throw std::runtime_error("number of objects can't be less than 0");
    }

    id = new int[length];
    sz = new int[length];
    for(int i=0; i<length; i+=1){
        id[i] = i;
        sz[i] = 1;
    }
}

UnionFindUF::~UnionFindUF(){
    delete[] id;
    delete[] sz;
}

void UnionFindUF::Union(int p, int q){

    int rp = Root(p);
    int rq = Root(q);

    if(sz[rp] < sz[rq]){
        id[rp] = id[rq];
        sz[rq] += sz[rp];
    }else{
        id[rq] = id[rp];
        sz[rp] += sz[rq];
    }
}

bool UnionFindUF::Connected(int p, int q){

    return Root(p) == Root(q);
}

int UnionFindUF::Root(int i){

    while(i != id[i]){
        id[i] = id[id[i]]; // make every object point to its grand parent in order to half the path length
        i = id[i];
    }
    return i;
}