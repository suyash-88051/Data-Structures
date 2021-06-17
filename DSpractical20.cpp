#include<iostream>
using namespace std;
//returns the number of leafs (no. of leafs = internal_vertices * (m-1) + 1)
int calLeafNod(int m, int i)
{
int leaf = 0;
leaf = i * (m-1) + 1;
return leaf;
}

int main()
{
int m,i;
cout<<"Enter the value of m in an m-ary Tree , m = ";
cin>>m;
cout<<"Enter the number of Internal Vertices : ";
cin>>i;
cout<<"Total number of Leaf Nodes are : "<<calLeafNod(m,i);
}
