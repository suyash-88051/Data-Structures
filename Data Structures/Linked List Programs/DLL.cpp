#include<iostream>
using namespace std;
struct node{
    int data;
    struct node* next;
    struct node* prev;
    node(int data){
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
};
class DLL{
	public:
		node *head,*tail;
		DLL()
		{
			head = NULL;
			tail = NULL;
		}
		bool isEmpty();
		void AddNode(int);
		void menu();
		void AddToHead(int);
		void AddToTail(int);
		void DelFromHead();
		void DelFromTail();
		void Display();
		bool Search(int);
		void InsertAt(int,int);
		void DeleteAt(int);
		void reverse();
		int concatenate(DLL);
		int sizeOfSLL();
		~DLL()
		{
			node* temp;
			while(head!=NULL)
			{
				temp=head->next;
				delete head;
				head=temp;
			}
		}
};
bool DLL :: isEmpty()
{
	if(head==NULL)
		return true;
	else
		return false;
}
void DLL :: AddNode(int a)
{
	node* temp=new node(a);
	temp->data=a;
	temp->next=NULL;
	if(head==NULL)
	{
		head=temp;
		tail=temp;
	}
	else{
		temp->prev=tail;
		tail->next=temp;
		tail=tail->next;
	}
}
void DLL :: AddToHead(int item)
{
	node* temp = new node(item);
	head->prev=temp;
	temp->next = head;
	temp->prev=NULL;
	head = temp;
}
void DLL  :: AddToTail(int item)
{
	node* n = new node(item);
	node* temp =  head;
	while(temp->next!=NULL)
	{
		temp=temp->next;
	}
	temp->next=n;
	n->prev=temp;
	n->next=NULL;
}
void DLL :: DelFromHead()
{
	node* temp = head;
	head = temp->next;
	head->prev=NULL;
	delete temp;
}
void DLL :: DelFromTail()
{
	node* temp =  head;
	while((temp->next)->next !=NULL)
	{
		temp=temp->next;
	}
	delete temp->next->next;
	temp->next = NULL;
}
void DLL :: Display()
{
	node* temp = head;
	while(temp != NULL)
	{
		cout<<temp->data <<"->";
		temp = temp->next;
	}
	cout<<"NULL"<<endl;
}
bool DLL :: Search(int ele)
{
	node* temp = head;
	int count = 1;
	while(temp != NULL)
	{
		if(temp->data == ele)
		{return true;}
		temp = temp->next;
	}
	return false;
}
void DLL :: InsertAt(int pos,int val)
{
	node* newnode = new node(val);
	node* temp = head;
	int count = 1;
	if(pos==1)
	return AddToHead(val);
	while(temp != NULL)
	{
		if((count+1) == pos)
		{
			node* temp2 = temp;
			newnode->next = (temp2->next);
			temp->next=newnode;
		}
		temp = temp->next;
		count+=1;
	}
}
void DLL :: DeleteAt(int pos)
{
	node* temp= head;
	int count = 1;
	if(pos==1)
	return DelFromHead();
	while(temp != NULL)
	{
		if((count+1)==pos)
		{
			node* temp2 = temp->next;
			temp->next=temp2->next;
			temp2->next=temp;
			delete temp2;
		}
		temp = temp->next;
		count++;
	}
}
void DLL :: reverse()
{
	node* p=head;
	node* q = p->next;
	
	p->next=NULL;
	p->prev=q;
	while(q!=NULL)
	{
		q->prev=q->next;
		q->next=p;
		p=q;
		q=q->prev;
	}
	head=p;
}
int DLL :: sizeOfSLL()
{
	int count=0;
	node* temp =  head;
	while(temp!=NULL)
	{
		count++;
		temp=temp->next;
	}
	return count;
}
int DLL :: concatenate(DLL b)
{
	node* temp = head;
	while(temp->next != NULL)
	{
		temp=temp->next;
	}
	node* temp2= b.head;
	while(temp2!=NULL)
	{
		AddToTail(temp2->data);
		temp2=temp2->next;
	}
}
void DLL :: menu()
{
	cout<<endl<<"\t\tEnter your choice\t\t"<<endl;
	cout<<"\t1. Add to Head"<<endl;
	cout<<"\t2. Add to Tail"<<endl;
	cout<<"\t3. Delete from Head"<<endl;
	cout<<"\t4. Delete from Tail"<<endl;
	cout<<"\t5. Search in the Doubly Linked List"<<endl;
	cout<<"\t6. Insert in the Doubly Linked List"<<endl;
	cout<<"\t7. Delete in the Doubly Linked List"<<endl;
	cout<<"\t8. Reverse the Doubly Linked List"<<endl;
	cout<<"\t9. To check isEmpty"<<endl;
	cout<<"\t10. To Enter new Doubly Linked List"<<endl;
	cout<<"\t11. To Find the size of Entered Doubly Linked List"<<endl;
	cout<<"\t0. To Exit"<<endl;
}
int main()
{	
	cout<<"\t\tProgram Started :"<<endl;
	cout<<"Enter the elements of the Doubly Linked List(enter 911 to stop) : "<<endl;
	DLL a;
	DLL b;
	DLL c;
	int elem,ch=1;
	while(elem != 911)
	{
		cin>>elem;
		if(elem!=911)
		{	
		a.AddNode(elem);}
	}
	cout<<endl<<"Entered Linked List : ";
	a.Display();
	a.menu();
	while(ch!=0)
	{
	cout<<endl<<"Enter your choice : ";
	cin>>ch;
	switch(ch)
	{
		case 0:
			break;
		case 1:
			int i;
			cout<<endl<<"Enter the element : ";
			cin>>i;
			a.AddToHead(i);
			break;
		case 2:
			int i2;
			cout<<endl<<"Enter the element : ";
			cin>>i2;
			a.AddToTail(i2);
			break;
		case 3:
			if(!a.isEmpty())
				a.DelFromHead();
			break;
		case 4:
			if(!a.isEmpty())
				a.DelFromTail();
			break;
		case 5:
			int i3;
			cout<<endl<<"Enter the element : ";
			cin>>i3;
			if(a.Search(i3))
				cout<<"Element is present in the Doubly Linked List";
			else
				cout<<"Element is not present in the Doubly Linked List";
			break;
		case 6:
			int i4,j;
			cout<<endl<<"Enter the position : ";
			cin>>i4;
			cout<<endl<<"Enter the element : ";
			cin>>j;
			a.InsertAt(i4,j);
			break;
		case 7:
			int i5;
			cout<<endl<<"Enter the position : ";
			cin>>i5;
			a.DeleteAt(i5);
			break;
		case 8:
			if(a.isEmpty() != true){
				a.reverse();
			}
			break;
		case 9:
			if(a.isEmpty())
				cout<<"Linked List is empty";
			else
				cout<<"Linked List is not-empty";
			break;
		case 10:
			cout<<"Enter the elements of the Doubly Linked List(enter 911 to stop) : "<<endl;
			elem=0;
			while(elem!=911)
			{
				cin>>elem;
				if(elem!=911)
					b.AddNode(elem);
			}
			cout<<endl<<"Entered Linked List : ";
			b.Display();
			a.concatenate(b);
			a.Display();
			break;
		case 11:
			cout<<"Size of entered Doubly Linked List : "<<a.sizeOfSLL();
			break;
		default:
			cout<<"Enter a valid choice";
	}
	if(ch!=0 || ch!=10 ){
	cout<<endl<<"After Operations"<<endl;
	a.Display();
}
}	
}
