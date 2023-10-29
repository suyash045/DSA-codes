#include<iostream>
#include<queue>
using namespace std;
int main(){
    //maxheap
    priority_queue<int> pq;
    pq.push(10);
    pq.push(2);
    pq.push(100);
    pq.push(47);
    cout<<pq.size()<<endl;
    cout<<pq.top()<<endl;
    pq.pop();
    cout<<pq.top()<<endl;
    if(pq.empty()){
        cout<<"Empty"<<endl;
    }
    else{
        cout<<"Not empty";
    }

    //minheap
    priority_queue<int, vector<int>, greater<int>> minheap;
    minheap.push(10);
    minheap.push(2);
    minheap.push(100);
    minheap.push(47);
    cout<<minheap.top()<<endl;

return 0;
}