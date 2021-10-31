#include <iostream>
using namespace std;

class Queue
{
	public:
	int rear, front;
	int size;
	int *arr;

	Queue(int s)
	{
	front = rear = -1;
	size = s;
	arr = new int[s];
	}
	void enQueue(int value);
	int deQueue();
	void displayQueue();
};

void Queue::enQueue(int value)
{
	if ((front == 0 && rear == size-1) ||(rear == (front-1)%(size-1)))
	{
		printf("\nQueue is Full");
		return;
	}

	else if (front == -1) // for first element 
	{
		front = rear = 0;
		arr[rear] = value;
	}
	else if (rear == size-1 && front != 0) // for inserting again at index 0
	{
		rear = 0;
		arr[rear] = value;
	}
	else // for every other case
	{
		rear++;
		arr[rear] = value;
	}
}

int Queue::deQueue()
{
	if (front == -1)
	{
		printf("\nQueue is Empty");
		return INT_MIN;
	}

	int data = arr[front];
	arr[front] = -1;
	
	if (front == rear)
	{
		front = -1;
		rear = -1;
	}
	else if (front == size-1)
		front = 0;
	else
		front++;

	return data;
}

void Queue::displayQueue()
{
	if (front == -1)
	{
		printf("\nQueue is Empty");
		return;
	}
	printf("\nElements in Circular Queue are: ");
	if (rear >= front)
	{
		for (int i = front; i <= rear; i++)
			printf("%d ",arr[i]);
	}
	else
	{
		for (int i = front; i < size; i++)
			printf("%d ", arr[i]);

		for (int i = 0; i <= rear; i++)
			printf("%d ", arr[i]);
	}
}
int menu()
{
	int ch;
    cout<<"1. Insert an Element"<<endl;
    cout<<"2. Delete an Element"<<endl;
    cout<<"3. Display the Queue"<<endl;
    cout<<"4. Exit"<<endl;
    cout<<"Enter your choice : ";
    cin>>ch;
    return ch;
}
int main()
{
	Queue q(4);
	cout<<"CIRCULAR QUEUE USING ARRAYS"<<endl;
	int choice,temp,temp2;
	bool exit=false;
	choice = menu();
	while(exit!=true){
	if(choice==1){
		cout<<"Enter the element : ";
		cin>>temp;
		q.enQueue(temp);
	}
	else if(choice==2)
	{
		temp2 = q.deQueue();
	}
	else if(choice==3)
	{
		q.displayQueue();
	}
	else{
		exit=true;
	}
	cout<<endl;
	choice = menu();
}
	return 0;
}

