/**
 * @file cycleDetectionUnDirected.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-10-21
 * 
 * @copyright Copyright (c) 2023
 * 
 */

/**
 * problem :- detect cycle in undirected graph....
 * 
 */

#include<bits/stdc++.h>
using namespace std;

class Graph{
   private:
   bool isCyclic(int node,int parent,vector<int>adj[],vector<int>&vis){
     vis[node]=true;
     for(auto it:adj[node]){
        if(isCyclic(it,node,adj,vis) == true){
            return true;
        }else if(it == parent)return true;
     }
     return false;
   }
   bool isCylicBfs(int node,vector<int>adj[],vector<int>&vis){
      queue<pair<int,int>>q;
      q.push({node,-1});
      vis[node]=true;
      while(!q.empty()){
        int f=q.front().first;
        int parent=q.front().second;
        q.pop();
        for(auto it:adj[f]){
            if(!vis[it]){
                q.push({it,f});
            }else if(it!=parent){
                return true;
            }
        }
      }
      return true;
   }
   public:
   bool isCycle(int v,vector<int>adj[]){
      vector<int>vis(v,0);
      for(int i=0;i<v;i++){
        if(!vis[i]){
            bool cycle=isCyclic(i,-1,adj,vis);
            if(cycle){
                return true;
            }
        }
      }
      return false;
   }

   bool isCycleBfs(int v,vector<int>adj[]){
       vector<int>vis(v,0);
      for(int i=0;i<v;i++){
        if(!vis[i]){
            bool cycle=isCylicBfs(i,adj,vis);
            if(cycle){
                return true;
            }
        }
      }
      return false;
   }
};

int main(){
    Graph g;
    vector<int> adj[4] = {{}, {2}, {1, 3}, {2}};
    bool ans = g.isCycle(4,adj);
    if (ans)
        cout << "1\n";
    else
        cout << "0\n";
    return 0;
}