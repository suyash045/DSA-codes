//Q. Create adjacency matrix
#include<iostream>
using namespace std;
class graph{
    public:
    bool adjMatrix[20][20];

    graph(){
        for(int i=0;i<20;i++){
            for(int j=0;j<20;j++){
                adjMatrix[i][j]=false;
            }
        }
    }

    void addEdge(int u,int v){
        adjMatrix[u][v]=true;
        adjMatrix[v][u]=true;
    }
    void print(int vertices){
        for(int i=0;i<vertices;i++){
            for(int j=0;j<vertices;j++){
                cout<<adjMatrix[i][j]<<" ";
            }
            cout<<endl;
        }
    }
}; 
int main(){
    graph g;
    g.addEdge(0,2);
    g.addEdge(0,4);
    g.addEdge(2,4);
    g.addEdge(4,5);
    g.addEdge(2,3);
    g.addEdge(3,5);
    g.print(6);
return 0;
}