//DFS
#include<iostream>
#include<unordered_map>
#include<vector>
#include<set>
using namespace std;
void dfs(unordered_map<int,set<int>> adjList,vector<int> &ans,unordered_map<int,bool> &visited, int node){
    ans.push_back(node);
    visited[node]=true;

    for(auto i: adjList[node]){
        if(!visited[i]){
            dfs(adjList,ans,visited,i);
        }
    }
    return;
}
vector<int> DFS(int vertices,vector<pair<int,int>> edges){
    //Prepare adjList
    unordered_map<int,set<int>> adjList;
    for(int i=0;i<edges.size();i++){
        int u=edges[i].first;
        int v=edges[i].second;

        adjList[u].insert(v);
        adjList[v].insert(u);
    }

    unordered_map<int,bool> visited;
    vector<int> ans;

    for(int i=0;i<vertices;i++){
        if(!visited[i]){
            dfs(adjList,ans,visited,i);
        }
    }
    return ans;
}
int main(){
    vector<pair<int,int>> edges;
    int vertices,n;
    cout<<"No. of vertices and edges : ";
    cin>>vertices>>n; 
    for(int i=0;i<n;i++){
        int u,v;
        cin>>u>>v;
        edges.push_back(make_pair(u,v));
    }
    vector<int> ans=DFS(vertices,edges);
    for (int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
return 0;
}