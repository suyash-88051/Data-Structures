#include<iostream>
#include<set>
#include<stdio.h>
#include<iomanip>
using namespace std;

int conj(int a,int b){
    cout<<setw(5)<<"x"<<setw(5)<<"|"<<setw(5)<<"y"<<setw(5)<<"|"<<setw(10)<<"x AND y\n";
    cout<<"   -------------------------\n";
                cout<<setw(5)<<a<<setw(5)<<"|"<<setw(5)<<b<<setw(5)<<"|";
                cout<<"    ";
                printf("%d",a && b);
                cout<<"\n";
    return 0;
}

int disj(int a,int b){
    cout<<setw(5)<<"x"<<setw(5)<<"|"<<setw(5)<<"y"<<setw(5)<<"|"<<setw(10)<<"x OR y\n";
    cout<<"   -------------------------\n";
                cout<<setw(5)<<a<<setw(5)<<"|"<<setw(5)<<b<<setw(5)<<"|";
                cout<<"    ";
                printf("%d",a || b);
                cout<<"\n";
    return 0;
}

int exOR(int a,int b){
    cout<<setw(5)<<"x"<<setw(5)<<"|"<<setw(5)<<"y"<<setw(5)<<"|"<<setw(10)<<"x XOR y\n";
    cout<<"   -------------------------\n";
                cout<<setw(5)<<a<<setw(5)<<"|"<<setw(5)<<b<<setw(5)<<"|";
                cout<<"    ";
                printf("%d",a ^ b);
                cout<<"\n";
    return 0;
}

int cond(int a,int b){
    cout<<setw(5)<<"x"<<setw(5)<<"|"<<setw(5)<<"y"<<setw(5)<<"|"<<setw(10)<<"x --> y\n";
    cout<<"   -------------------------\n";
                cout<<setw(5)<<a<<setw(5)<<"|"<<setw(5)<<b<<setw(5)<<"|";
                cout<<"    ";
                printf("%d",(!a)||b);
                cout<<"\n";
    return 0;
}

int biCond(int a,int b){
    cout<<setw(5)<<"x"<<setw(5)<<"|"<<setw(5)<<"y"<<setw(5)<<"|"<<setw(10)<<"x <--> y\n";
    cout<<"   -------------------------\n";
                cout<<setw(5)<<a<<setw(5)<<"|"<<setw(5)<<b<<setw(5)<<"|";
                cout<<"    ";
                printf("%d",(((!a)|| b) && ((!a)|| b)));
                cout<<"\n";
    return 0;
}

int exNOR(int a,int b){
    cout<<setw(5)<<"x"<<setw(5)<<"|"<<setw(5)<<"y"<<setw(5)<<"|"<<setw(10)<<"x XNOR y\n";
    cout<<"   -------------------------\n";
                cout<<setw(5)<<a<<setw(5)<<"|"<<setw(5)<<b<<setw(5)<<"|";
                cout<<"    ";
                printf("%d",!(a ^ b));
                cout<<"\n";
    return 0;
}

int negx(int a){
    cout<<setw(5)<<"x"<<setw(5)<<"|"<<setw(7)<<"x'\n";
    cout<<"   -------------\n";
        cout<<setw(5)<<a<<setw(5)<<"|";
            cout<<"    ";
            printf("%d",!a);
            cout<<"\n";
    return 0;

}
int negy(int b){
    cout<<setw(5)<<"y"<<setw(5)<<"|"<<setw(7)<<"y'\n";
    cout<<"   -------------\n";
        cout<<setw(5)<<b<<setw(5)<<"|";
            cout<<"    ";
            printf("%d",!b);
            cout<<"\n";
    return 0;

}

int nand(int a,int b){
    cout<<setw(5)<<"x"<<setw(5)<<"|"<<setw(5)<<"y"<<setw(5)<<"|"<<setw(10)<<"x NAND y\n";
    cout<<"   -------------------------\n";
                cout<<setw(5)<<a<<setw(5)<<"|"<<setw(5)<<b<<setw(5)<<"|";
                cout<<"    ";
                printf("%d",!(a && b));
                cout<<"\n";
    return 0;

}

int nor(int a,int b){
    cout<<setw(5)<<"x"<<setw(5)<<"|"<<setw(5)<<"y"<<setw(5)<<"|"<<setw(10)<<"x NOR y\n";
    cout<<"   -------------------------\n";
                cout<<setw(5)<<a<<setw(5)<<"|"<<setw(5)<<b<<setw(5)<<"|";
                cout<<"    ";
                printf("%d",!(a || b));
                cout<<"\n";
    return 0;

}
int main(){
	int choice = 1;
	int x,y;
	
	while(choice)
	{
	cout<<"Enter the values of x and y (0 for True and 1 for False)"<<endl;
	cout<<endl<<"x = ";
	cin>>x;
	cout<<"y = ";
	cin>>y;
	cout<<endl;
    conj(x,y);
    cout<<"\n\n";
    disj(x,y);
    cout<<"\n\n";
    exOR(x,y);
    cout<<"\n\n";
    cond(x,y);
    cout<<"\n\n";
    biCond(x,y);
    cout<<"\n\n";
    exNOR(x,y);
    cout<<"\n\n";
    negx(x);
    cout<<"\n\n";
    negy(y);
    cout<<"\n\n";
    nand(x,y);
    cout<<"\n\n";
    nor(x,y);
    cout<<endl<<"Enter 1 for re-entering values or 0 to EXIT: ";
    cout<<endl;
    cin>>choice;
	}
}
