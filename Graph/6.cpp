//BFS : only works for connected components
#include<iostream>
#include<unordered_map>
#include<set>
#include<vector>
#include<queue>
using namespace std;
void prepareAdjList(unordered_map<int,set<int>> &adjList,vector<pair<int,int>> &edges){
    for(int i=0;i<edges.size();i++){
        int u=edges[i].first;
        int v=edges[i].second;

        adjList[u].insert(v);
        adjList[v].insert(u);
    }
}

vector<int> BFS(int vertex,vector<pair<int,int>> edges){
    unordered_map<int,set<int>> adjList;
    vector<int> ans;
    unordered_map<int,bool> visited;

    prepareAdjList(adjList,edges);

    queue<int> q;
    q.push(0);
    visited[0]=1;

    while(!q.empty()){
        int frontNode=q.front();
        q.pop();

        //Store frontNode in ans
        ans.push_back(frontNode);

        //traverse all neighbours of frontNode
        for(auto j:adjList[frontNode]){
            if(!visited[j]){
                q.push(j);
                visited[j]=1;
            }
        }
    }

    return ans;
}
int main(){
    int n;
    cout<<"Edges : ";
    cin>>n;
    int v;
    cout<<"Vertices : ";
    cin>>v;
    vector<pair<int,int>> edges;
    for(int i=0;i<n;i++){
        int u,v;
        cin>>u>>v;
        edges.push_back(make_pair(u,v));
    }

    vector<int> ans=BFS(v,edges);

    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}