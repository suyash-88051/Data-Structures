#include<iostream>
using namespace std;

void displayArray(int* &array , int* &size){
    cout<<"\n";
    cout<<"[ ";
    for (int i = 0; i < *size; i++){
        cout<<array[i];
        if(i!= *size-1){
            cout<<" ,";
        }
    }
    cout<<" ]"<<endl<<endl;
}
void insertionSort(int* &array , int* &size){
    int key;
    for (int i = 1; i <*size ; i++)
    {
        key = array[i];
        int j = i-1;
        int* comparisons  = new int(0);
        while (key<array[j] && j>=0){  
            *comparisons+=1;
            array[j+1]=array[j];
            j--;
        }   
        array[j+1]=key;
        cout<<"No. of Iterations : "<<i<<endl;
        cout<<"No. of Comparisons : "<<*comparisons<<endl;
        
    }   

}
int main(){
    int  arr[]  = {7,38,3,60,76,8,3,10,70,8,19,31};
    int *array  = arr;
    int *length = new int(12);
    cout<<endl<<"UNSORTED";
    displayArray(array,length);
    insertionSort(array,length);
    cout<<endl<<"SORTED";
    displayArray(array,length);
    delete[] array;
    delete length;
    
    return 0;
}
