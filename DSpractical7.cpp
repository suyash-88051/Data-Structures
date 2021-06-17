#include<iostream>
#include<string>
using namespace std;

void displayArray(int* &array , int* &size){
    cout<<endl;
    cout<<"[ ";
    for (int i = 0; i < *size; i++){
        cout<<array[i];
        if(i!= *size-1){
            cout<<" ,";
        }
    }
    cout<<" ]";
    cout<<endl;  
}
string binarySearch(int arr[] , int key,int start,int end){
    if(key<arr[start] && key>arr[end-1]){
        return "Sorry, Element isn't present";
    }
    int mid   = (start+end)/2;
    if(arr[mid]==key){
        return "Element found at position '"+to_string(mid+1)+"'";
    }
    else if (key>arr[mid])
    {
        return binarySearch(arr , key,mid+1,end);
    }
    else{
        return binarySearch(arr , key,start,mid-1);
    }
    
    
}
int main()
{
    int arr[] = {1,3,4,5,8,21,34,35,44,56,60,67};
    int key;
    int *size = new int(12);
    int *array = arr;
    cout<<"Enter the element to search : ";
    cin>>key;
    cout<<endl;
    cout<<binarySearch(arr ,key ,0,12)<<endl<<endl;
    cout<<"Original Array : ";
    displayArray(array,size);
    return 0;
}
