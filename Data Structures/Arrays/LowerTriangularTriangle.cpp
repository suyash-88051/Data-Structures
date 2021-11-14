#include <iostream>
using namespace std;
//LTM = Lower Triangular Matrix
class LTM
{
	int* D;
	int len;
	public:
		LTM(int n)
		{
			len=n;
			if(len>=0)
				D = new int[len*((len+1)/2)];
			else
				D = 0;
		}
		~LTM()
		{
			delete [] D;
		}
		void store(int r,int c,int data)
		{
			if(r>=0 && r<len && c>=0 && c<len && r>=c)
			{
				int ad=((r*(r-1)/2)+c-1);
				D[ad] = data;
			}
		}
		int value(int r,int c)
		{
			r=r-1;
			c=c-1;
			if(r>=0 && r<len && c>=0 && c<len){
				if(r>=c){
					int ad=((r*(r-1)/2)+c-1);
					return D[ad];
				}
				else
					return 0;
			}
			else{
				cout<<"Wrong Input";
			}
		}
		void show()
		{
			for(int i=0;i<len;i++)
			{
				for(int j=0;j<len;j++)
				{
					if(i>=j)
					{
						int ad=((i*(i-1)/2)+j-1);
						cout<<D[ad]<<" ";
						
					}else
						cout<<"0 ";
				}
				cout<<endl;
			}
		}
};
int main()
{
	int temp;
	LTM ltm = LTM(5);
	for (int i=0;i<5;i++)
	{
		for(int j=0;j<5;j++)
		{
			temp=i+j+2;
			ltm.store(i,j,temp);
		}
	}
	ltm.show();
	cout<<endl<<"Printing element at index[2,1] : "<<ltm.value(2,1);
	cout<<endl<<"Printing element at index[2,2] : "<<ltm.value(2,2);
	cout<<endl<<"Printing element at index[2,3] : "<<ltm.value(2,3);
	cout<<endl<<"Printing element at index[2,4] : "<<ltm.value(2,4);
	cout<<endl<<"Printing element at index[2,5] : "<<ltm.value(2,5);
}
