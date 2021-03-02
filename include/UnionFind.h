#ifndef UNIONFIND
#define UNIONFIND

class QuickFindUF {

public :

    QuickFindUF(int n);
    ~QuickFindUF();

    void Union(int p, int q);
    bool Connected(int p, int q);

private :

    int *id;   // objects array (each object represented by it index)
    int length;     // length of array

};

class UnionFindUF {

public :

    UnionFindUF(int n);
    ~UnionFindUF();

    void Union(int p, int q);
    bool Connected(int p, int q);


private :

    int Root(int node);

    int *id;       // objects array (each object represented by it index)
    int *sz;      // number of objects rooted at i
    int length;      // length of array

};


#endif