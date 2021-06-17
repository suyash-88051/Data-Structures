#include<iostream>
using namespace std;

int fibo(int); // To find fibonacci sequence (recursively)
void fibonaciiSeries(int); // To print fibonacci Series

int  fibo(int num ){
    if (num==1){
        return 1;
    }
    else if(num==0){
        return 0;
    }
    else{
        return fibo(num-1) + fibo(num-2);
    }
}
void fibonaciiSeries(int n){
    for (int i = 0; i < n; i++){
        cout<<fibo(i)<<" ";
    }
}

int main(){
	
	int i;
	cout<<"Enter the no. of terms want to print(of fibonacci series) : ";
	cin>>i;
    cout<<"Finonacii Series"<<endl;
    fibonaciiSeries(i);
    return 0;
    
}
