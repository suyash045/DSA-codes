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
int main(){
    int arr[6]={-1,54,67,40,30,100};
    int n=5;
    for(int i=n/2;i>0;i--){
        heapify(arr,n,i);
    }
    for (int i=1;i<6;i++)
    {
        cout<<arr[i]<<" ";
    } 
return 0;
}