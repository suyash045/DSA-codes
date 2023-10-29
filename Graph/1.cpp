//degree of node = no. of edges connected to it
#include<iostream>
#include<unordered_map>
#include<list>
using namespace std;
class graph{
    public:
    unordered_map<int,list<int>> adj;

    void addEdges(int u,int v,bool direction){
        //direction=0 if edge is undirected. 
        //direction=1 if edge is directed. 

        //Create an edge from u to v.
        adj[u].push_back(v);
        if(direction==0){
            adj[v].push_back(u);
        }
    }

    void printGraph(){
        for(auto i: adj){
            cout<<i.first<<"->";
            for(auto j: i.second){
                cout<<j<<",";
            }
            cout<<endl;
        }
    }
};
int main(){
    graph g;
    int m;
    cout<<"Enter no. of edges : ";
    cin>>m;

    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        g.addEdges(u,v,0);
    }
    g.printGraph();
    return 0;
}