/**
 * @file topologicalSort.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-10-27
 * 
 * @copyright Copyright (c) 2023
 * 
 */

/**
 * Problem Statement :- 
 * 
 */

#include<bits/stdc++.h>
using namespace std;
class GRPAH{
    private:
    void dfs(int ind,vector<int>adj[],vector<int>&vis,stack<int>&st){
        vis[ind]=1;
        for(auto it:adj[ind]){
            if(!vis[it]){
                dfs(it,adj,vis,st);
            }
        }
        st.push(ind);
    }
    public:
    /**
     * dfs implementation of topological sorting...
     */
    void topoSort(int n,vector<int>adj[]){
        vector<int>vis(n,0);
        stack<int>st;
        vector<int>ans;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i,adj,vis,st);
            }
        }
        while(!st.empty()){
            cout<<st.top();
            st.pop();
        }
    }
};
int main(){
int n;
cout<<"Enter the no of vetices "<<endl;
cin>>n;
vector<int>adj[n];
for(int i=0;i<n;i++){
    int x,y;
    cin>>x>>y;
    adj[x].push_back(y);
}
GRPAH obj;
cout<<"Topological sort dfs : "<<endl;
obj.topoSort(n,adj);
return 0;
}