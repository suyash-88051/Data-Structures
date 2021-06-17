#include<iostream>
using namespace std;

void swap(int *a, int *b)
{
    int temp =*a;
    *a=*b;
    *b=temp;
}

void bubbleSort(int arr[],int n)
{
    int noOfSwaps;
    int noOfComparisons;
    bool swapped;
    for(int i = 0; i<n-1;i++)
    {
        noOfSwaps=0;
        noOfComparisons=0;
        for(int j=0;j<n-i-1;j++)
        {
            noOfComparisons++;
            if(arr[j]>arr[j+1])
            {
                swap(&arr[j],&arr[j+1]);
                noOfSwaps++;
            }
        }
        std::cout<<"Array after"<<i+1<<" iteration: \n";
        for(int k=0;k<n;k++){
            std::cout<<arr[k]<<" ";
        }
        std::cout<<"\nNo of swaps: "<<noOfSwaps;
        std::cout<<"\nNo of comparisons: "<<noOfComparisons<<std::endl<<std::endl;
        
    }
}

void printArray(int arr[],int size)
{
    for(int i=0;i<size;i++)
        std::cout<<arr[i]<<" ";
    std::cout<<"\n";
}

int main()
{
    int arr[]={64,34,25,12,22,11};
    int n=sizeof(arr)/sizeof(arr[0]);
    std::cout<<"Unsorted array:\n";
    printArray(arr,n);
    cout<<endl;
    bubbleSort(arr,n);
    std::cout<<"Sorted array:\n";
    printArray(arr,n);
    return 0;
}
