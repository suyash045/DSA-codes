//T.C. of heap sort is O(nlogn)
#include<iostream>
using namespace std;
void heapify(int arr[],int n,int i){
    int largest=i;
    int leftCI=2*i;
    int rightCI=2*i+1;
    if(leftCI<=n && arr[largest]<arr[leftCI]){
        largest=leftCI;
    }
    if(rightCI<=n && arr[largest]<arr[rightCI]){
        largest=rightCI;
    }
    if(largest!=i){
        swap(arr[largest],arr[i]);
        heapify(arr,n,largest);
    }
}
void heapSort(int arr[],int n){
    int size=n;
    while(size>1){
        swap(arr[1],arr[size]);
        size--;
        heapify(arr,size,1);
    }
}
int main(){
    int arr[6]={-1,100,47,50,60,200};
    int n=5;
    for (int i=n/2;i>0;i--){
        heapify(arr,n,i);
    }
    heapSort(arr,n);
    for (int i = 1; i <=n; i++)
    {
        cout<<arr[i]<<" ";
    }
return 0;
}