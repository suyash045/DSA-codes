#include<iostream>
using namespace std;
void merge(int arr[],int l,int mid,int r){
    int an=mid-l+1;
    int bn=r-mid;
    int a[an];
    int b[bn];
    for(int i=0;i<an;i++){
        a[i]=arr[l+i];
    }
    for(int j=0;j<bn;j++){
        b[j]=arr[mid+j+1];
    }
    int i=0,j=0,k=l;
    while(i<an && j<bn){
        if(a[i]<b[j]){
            arr[k++]=a[i++];
        }
        else{
            arr[k++]=b[j++];
        }
    }
    while(i<an){
        arr[k++]=a[i++];
    }
    while(j<bn){
        arr[k++]=b[j++];
    }
}
void mergeSort(int arr[],int l,int r){
    if(l>=r){
        return;
    }
    int mid=(l+r)/2;
    mergeSort(arr,l,mid);
    mergeSort(arr,mid+1,r);
    merge(arr,l,mid,r);
}
int main(){
    int arr[]={100,28,44,87,78,39,10,6};
    int n=sizeof(arr)/sizeof(arr[0]);
    mergeSort(arr,0,n-1);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
return 0;
}