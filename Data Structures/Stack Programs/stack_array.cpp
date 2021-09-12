#include<iostream>
using namespace std;

//Global variables
int MAX = 15;
int stack_arr[15];
int top=-1;

bool isFull()
{
	if(top == MAX-1)
		return 1;
	else
		return 0;
}
bool isEmpty()
{
	if(top==-1)
		return true;
	else
		return false;
}
void push(int data)
{
	top=top+1;
	if(isFull()){
		cout<<"Stack Overflow";
		return ;
	}
	else
		stack_arr[top]=data;
}
void clear()
{
	top=-1;
}
int pop()
{
	if(isEmpty()){
		cout<<"Stack Underflow";
	}
	else{
		int value=stack_arr[top];
		top=top-1;
		return value;
	}
}
void display()
{
	int i=top;
	while(i>=0){
		cout<<stack_arr[i]<<endl;
		i--;
	}
}
void topelement()
{
	if(!isEmpty())
	{
		cout<<stack_arr[top];
	}
}
int size()
{
	return top+1;
}
void menu()
{
	cout<<endl<<"1. Push an element into the Stack.\n";
	cout<<"2. Pop out an element from the Stack.\n";
	cout<<"3. Show the top most element of the Stack\n";
	cout<<"4. Check if Stack is empty.\n";
	cout<<"5. Size of the Stack\n";
	cout<<"6. Display the Stack\n";
	cout<<"7. Clear the Stack\n";
	cout<<"8. EXIT.\n";
	cout<<endl<<"\tEnter your choice : ";
}
void menudriven(int ch)
{
	int x,len;
	switch(ch)
	{
		case 1:
			int elem;
			cout<<"Enter the element to be pushed : "<<endl;
			cin>>elem;
			push(elem);
			break;
		case 2:
			x= pop();
			cout<<x<<" is removed."<<endl;
			break;
		case 3:
			topelement();
			cout<<" is the top-most element."<<endl;
			break;
		case 4:
			if(isEmpty())
				cout<<"Yes, the Stack is empty"<<endl;
			else
				cout<<"No, the Stack is not empty"<<endl;
			break;
		case 5:
			cout<<"\nSize of the Stack is : ";
			len=size();
			cout<<len<<endl;
			break;
		case 6:
			display();
			break;
		case 7:
			clear();
			break;
		case 8:
			exit(1);
		default:
			cout<<"Enter a valid choice."<<endl;
	}
}
int main()	
{	
	cout<<"\t\tProgram Started\n\n";
	int ch;
	while(1){
		menu();
		cin>>ch;
		menudriven(ch);
	}
}
