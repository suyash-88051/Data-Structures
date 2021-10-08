#include<iostream>
using namespace std;

class LinearQueue
{
public:
    int front;
    int rear;
    int size;
    int queue[];
    bool IsEmpty();
    bool IsFull();
    int FirstEle();
    void EnQueue(int);
    void DeQueue();
    void Display();
    LinearQueue(int n)
    {
        front=rear=-1;
        size=n;
    }
};

bool LinearQueue :: IsEmpty()
{
    if(rear==-1)
        return true;
    else
        return false;
}
bool LinearQueue :: IsFull()
{
    if(rear==size-1)
        return true;
    else
        return false;
}
void LinearQueue :: EnQueue(int item)
{

    if(IsEmpty())
    {   
        rear++;
        queue[++front]=item;
    }
    else if(rear<size-1)
        {
         queue[++rear]=item;
        }
        else
        {
            cout<<"The Queue is Full"<<endl;
        }
}
void LinearQueue ::  DeQueue()
{
   if(IsEmpty())
    {
        cout<<"The Queue is already empty"<<endl;
    }
    else
    {
        cout<<queue[front]<<" is deleted"<<endl;
        front++;
    }
}
void LinearQueue :: Display()
{
    cout<<endl;
    if(IsEmpty())
    {
        cout<<"The Queue is empty"<<endl;
    }
    for(int i=front;i<=rear;i++)
    {
        cout<<queue[i]<<"\t";
    }
    cout<<endl;
}
int LinearQueue :: FirstEle()
{
    return queue[front];
}
int main()
{
    int a=1;
    int element,n;
    int ans;
    cout<<"Enter the size of queue : ";
    cin>>n;
    LinearQueue obj(n);
    do
    {
        cout<<endl<<"-------------------------"<<endl;
        cout<<"LINEAR QUEUE USING ARRAYS"<<endl;
        cout<<"1. Insert an Element"<<endl;
        cout<<"2. Delete and Element"<<endl;
        cout<<"3. Display the Queue"<<endl;
        cout<<"4. To view the First Element"<<endl;
        cout<<"5. Exit"<<endl;
        cout<<"Enter your choice: ";
        cin>>ans;
        switch(ans)
        {
        case 1:
              {
                if(obj.IsFull()!=true){
                cout<<"Enter the element to be added : ";
                cin>>element;
                obj.EnQueue(element);
                }
                else{
                    cout<<"The Queue is Full";
                }
                break;
              }
        case 2:
            {
                obj. DeQueue();
                break;

            }
        case 3:
            {
                obj.Display();
                break;
            }
        case 4:
            {
                int temp=obj.FirstEle();
                cout<<"First element is : "<<temp;
                break;
            }
        case 5:
            {
                cout<<"Program Ended";
                a=0;
                break;
            }
        default :
            {
                cout<<"Wrong choice"<<endl;
                break;
            }
        }
    }while(a==1);
}