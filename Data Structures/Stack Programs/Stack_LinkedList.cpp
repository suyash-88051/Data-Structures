#include <iostream>
#include <string>
#include <sstream>
using namespace std;
class node
{
	public:
		int data;
		node* next;
		node(int val){
			data = val;
			next = NULL;
		}
};
class SLL
{
	public:
		node *Head,*tail;
		SLL()
		{
			Head = NULL;
			tail = NULL;
		}
		void AddToHead(int);
		int DelFromHead();
		void Display();
		bool isEmpty();
		void topelement();
		void clear();
		int sizeOfSLL();
		~SLL()
		{
			node* temp;
			while(Head!=NULL)
			{
				temp=Head->next;
				delete Head;
				Head=temp;
			}
		}
};
bool SLL :: isEmpty()
{
	if(Head==NULL)
		return true;
	else
		return false;
}
void SLL :: AddToHead(int item)
{
	node* temp = new node(item);
	temp->next = Head;
	Head = temp;
}
void SLL::topelement()
{
	cout<<Head->data;
}
int SLL :: DelFromHead()
{
	if(Head!=NULL){
	node* temp = Head;
	Head = temp->next;
	int temp2=temp->data;
	delete temp;
	return temp2;
}
}
int SLL :: sizeOfSLL()
{
	int count=0;
	node* temp =  Head;
	while(temp!=NULL)
	{
		count++;
		temp=temp->next;
	}
	return count;
}
void SLL :: clear()
{
	Head=NULL;
}
void SLL :: Display()
{
	int arr[22];
	int count=0;
	node* temp = Head;
	while(temp != NULL)
	{
	
		arr[count]=temp->data;
		temp = temp->next;
		count++;
	}
	for(int i=0;i<=count-1;i++)
	{
		cout<<arr[i]<<endl;
	}
}
SLL s;
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
			s.AddToHead(elem);
			break;
		case 2:
			x=s.DelFromHead();
			cout<<x<<" is removed."<<endl;
			break;
		case 3:
			s.topelement();
			cout<<" is the top-most element."<<endl;
			break;
		case 4:
			if(s.isEmpty())
				cout<<"Yes, the Stack is empty"<<endl;
			else
				cout<<"No, the Stack is not empty"<<endl;
			break;
		case 5:
			cout<<"\nSize of the Stack is : ";
			len=s.sizeOfSLL();
			cout<<len<<endl;
			break;
		case 6:
			s.Display();
			break;
		case 7:
			s.clear();
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
