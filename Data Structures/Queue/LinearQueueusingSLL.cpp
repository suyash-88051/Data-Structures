#include <iostream>
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
		void menu();
		void AddNode(int);
		void AddToHead(int);
		void DelFromHead();
		void AddToTail(int);
		void DelFromTail();
		void Display();
		int peek();
		bool isEmpty();
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
void SLL :: AddNode(int a)
{
	node* temp=new node(a);
	temp->data=a;
	temp->next=NULL;
	if(Head==NULL)
	{
		Head=temp;
		tail=temp;
	}
	else{
		tail->next=temp;
		tail=tail->next;
	}
}
void SLL :: AddToHead(int item)
{
	node* temp = new node(item);
	temp->next = Head;
	Head = temp;
}
void SLL :: DelFromHead()
{
	node* temp = Head;
	Head = temp->next;
	delete temp;
}
void SLL :: AddToTail(int item)
{
	node* temp =  Head;
	while(temp->next!=NULL)
	{
		temp=temp->next;
	}
	node* n = new node(item);
	temp->next=n;
	n->next=NULL;
}
void SLL :: DelFromTail()
{
	node* temp =  Head;
	while((temp->next)->next !=NULL)
	{
		temp=temp->next;
	}
	temp->next = NULL;
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
void SLL :: Display()
{
	node* temp = Head;
	while(temp != NULL)
	{
		cout<<temp->data <<"  ";
		temp = temp->next;
	}
	cout<<endl;
}
int SLL :: peek()
{
	return Head->data;
}
void SLL :: menu()
{
	cout<<"\n\tEnter your Choice\t\n";
	cout<<"1. Add an element to the queue\n";
	cout<<"2. Remove an element from the queue\n";
	cout<<"3. To view the first element\n";
	cout<<"4. Display the Queue"<<endl;
	cout<<"5. Size of the Queue"<<endl;
	cout<<"6. Exit"<<endl;
}
int main()
{
	cout<<"\tQUEUE USING LINKED LIST"<<endl;
	int temp,size;
	SLL queue;
	int ch=1;
	while(ch!=0)
	{
		queue.menu();
		cout<<"Choice : ";
		cin>>ch;		
		switch(ch){
			case 1:
				cout<<"Enter the element : ";
				cin>>temp;
				queue.AddNode(temp);
				break;
			case 2:
				if(queue.isEmpty()!=true){
				queue.DelFromHead();
				}
				else{
					cout<<"Queue is already empty"<<endl;
				}
				break;
			case 3:
				if(queue.isEmpty()!=true){
				int temp2;
				temp2=queue.peek();
				cout<<"First element : "<<temp2;
				}
				else{
					cout<<"Queue is empty"<<endl;
				}
				break;
			case 4:
				queue.Display();
				break;
			case 5:
				size = queue.sizeOfSLL();
				cout<<"Size of the Queue : "<<size<<endl;
				break;
			case 6:
				ch=0;
				break;
			default:
				cout<<"Wrong input";
				break;
		}
	}
	cout<<"Program ended"<<endl;
}
