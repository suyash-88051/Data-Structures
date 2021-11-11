#include <iostream>
using namespace std;

class Diagonal
{
	int* D;
	int len;
	public:
		Diagonal(int n)
		{
			len=n;
			if(len>=0)
				D = new int[len];
			else
				D = 0;
		}
		void store(int r,int c,int data)
		{
			if(r>=0 && r<len && c>=0 && c<len && r==c)
				D[r] = data;
			else
				exit(0);
		}
		int value(int r,int c)
		{
			if(r>=0 && r<len && c>=0 && c<len){
				if(r==c)
					return D[r];
				else
					return 0;
			}
			else{
				cout<<"Wrong Input";
				exit(0);
			}
		}
		void show()
		{
			for(int i=0;i<len;i++)
			{
				for(int j=0;j<len;j++)
				{
					if(i==j)
						cout<<D[i]<<" ";
					else
						cout<<"0 ";
				}
				cout<<endl;
			}
		}
};
int main()
{
	int temp;
	Diagonal dm = Diagonal(5);
	for(int i=0,j=0;i<5;i++,j++)
	{
		temp=i+j;
		dm.store(i,j,temp);
	}
	dm.show();
}
