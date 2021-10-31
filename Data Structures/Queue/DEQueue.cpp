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
		void AddToHead(int);
		void AddToTail(int);
		void DelFromHead();
		void DelFromTail();
		void Display();
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
	node* temp1 = new node(item);
	temp1->prev = NULL;
	if(head != NULL)
		head->prev = temp1;
	temp1->next = head;
	head = temp1;
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
		cout<<temp->data <<" ";
		temp = temp->next;
	}
	cout<<endl;
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
int menu(){
	int ch;
	cout<<"1.Insert at beginning";
    cout<<"\n2.Insert at end";
    cout<<"\n3.Deletion from front";
    cout<<"\n4.Deletion from rear";
    cout<<"\n5.Show";
    cout<<"\n6.Exit";
	cout<<"\nEnter your choice : ";
	cin>>ch;
	return ch;
}
int main(){
      DLL d;
      int ch,i,c;
      cout<<"\t\tDEQUEUE"<<endl;
      do{
      ch= menu();
      switch(ch) {
         case 1:
            cout<<"Enter the element to be inserted : ";
            cin>>i;
            d.AddToHead(i);
         break;
         case 2:
            cout<<"Enter the element to be inserted : ";
            cin>>i;
            d.AddToTail(i);
         break;
         case 3:
            d.DelFromHead();
         break;
         case 4:
            d.DelFromTail();
         break;
         case 5:
            d.Display();
         break;
         case 6:
            exit(1);
         break;
         default:
            cout<<"invalid choice";
         break;
      }
      cout<<endl;
   } while(ch!=7);
}
