#include<iostream>
using namespace std;
void heapify(int arr[],int n,int i){
    int smallest=i;
    int leftCI=2*i;
    int rightCI=2*i+1;
    if(leftCI<=n && arr[smallest]>arr[leftCI]){
        smallest=leftCI;
    }
    if(rightCI<=n && arr[smallest]>arr[rightCI]){
        smallest=rightCI;
    }
    if(smallest!=i){
        swap(arr[smallest],arr[i]);
        heapify(arr,n,smallest);
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