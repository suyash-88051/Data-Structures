#include<iostream>
#include<math.h>
#include<bits/stdc++.h>
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
int Stack::topmost()
{
	return s[top];
}

int prefix(string s)
{
	Stack num;
	int temp=0;
	for(int i=s.length()-1;i>=0;i--)
	{
		if(s.at(i)=='+')
		{
			int a=num.pop();
			int b=num.pop();
			temp=a+b;
			num.push(temp); 
		}
		else if(s.at(i)=='-')
		{
			int a=num.pop();
			int b=num.pop();
			temp=a-b;
			num.push(temp); 
		}
		else if(s.at(i)=='*')
		{
			int a=num.pop();
			int b=num.pop();
			temp=b*a;
			num.push(temp); 
		}
		else if(s.at(i)=='/')
		{
			int a=num.pop();
			int b=num.pop();
			temp=a/b;
			num.push(temp); 
		}
		else if(s.at(i)=='%')
		{
			int a=num.pop();
			int b=num.pop();
			temp=a%b;
			num.push(temp); 
		}
		else if(s.at(i)=='$')
		{
			int a=num.pop();
			int b=num.pop();
			temp=pow(a,b);
			num.push(temp); 
		}
		else{
			num.push((int)s.at(i)-48);
		}
	}
	int ans=num.pop();
	return ans;
}
int main()
{
	string expression;
	cout<<"Enter the prefix expression : ";
	cin>>expression;
	int ans=prefix(expression);
	cout<<"After evaluation : "<<ans;
}
