#include<iostream>
using namespace std;
 
const int size=41;
class Stack
{
	int s[size];
	int top;
	public:
		Stack()
		{
			top=-1;
		}
		void push(int);
		int pop();
		void display();
		int topmost();
		int toppos();
};
void Stack::push(int ele)
{
	if(top == size-1){
		cout<<"Stack Overflow";
		return ;
	}
	else{
		top=top+1;
		s[top]=ele;
	}
}
int Stack::pop()
{
	int item;
	if(top==-1)
	{
		cout<<"Stack Underflowed . ";
	}
	else{
		item=s[top--];
		return item;
	}
}
void Stack::display()
{
	int i=top;
	if(top==-1)
	{
		cout<<"Stack is empty";
		return;
	}
	else{
		while(i>=0)
		{
			cout<<s[i];
			i--;
		}
	}
}
int Stack::topmost()
{
	return s[top];
}
int Stack::toppos()
{
	return top;
}
Stack StringtoStack(string s)
{
	Stack num;
	for(int i=0;i<=s.length()-1;i++)
	{
		num.push((int)s.at(i)-48);
	}
	return num;
}
Stack add(Stack a,Stack b,int len1,int len2)
{
	Stack c;
	int carry=0;
	int temp,x,y;
	int len=len1>=len2?len1:len2;
	for(int i=len-1;i>=0;i--)
	{
		if(a.toppos()>-1)
			x=a.pop();
		else
			x=0;
		if(b.toppos()>-1)
			y=b.pop();
		else
			y=0;
		temp = (x+y+carry)%10;
		c.push(temp);
		
		if((x+y+carry)>=10)
			carry=1;
		else
			carry=0;
	}
	if(carry==1)
	c.push(carry);
	return c;
}
int main()
{
	for(int i=0;i<=1;i++){
	cout<<"\t\tProgram Started\n\n";
	string num1;
	string num2;
	Stack ans;
	cout<<"Enter first number  : ";
	cin>>num1;
	cout<<"Enter second number : ";
	cin>>num2;
	Stack snum1= StringtoStack(num1);
	Stack snum2= StringtoStack(num2);
	ans = add(snum1,snum2,num1.length(),num2.length());
	cout<<"Answer 		    : ";
	ans.display();
	cout<<"\n\n\t\tProgram ended\n\n";
}
}
