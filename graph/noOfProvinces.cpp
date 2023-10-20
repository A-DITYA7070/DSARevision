/**
 * @file noOfProvinces.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-10-20
 * 
 * @copyright Copyright (c) Aditya raj 2023
 * 
 */

/**
 * Problem Statement: Given an undirected graph with V vertices. We say two vertices u and v belong to a single province
                   if there is a path from u to v or v to u. Your task is to find the number of provinces.
 * 
 */

/**
 * Approach:
    A province is a group of directly or indirectly connected cities and no other cities outside of the group. 
    Considering the above example, we can go from 1 to 2 as well as to 3, from every other node in a province 
    we can go to each other. As we cannot go from 2 to 4 so it is not a province. We know about both the traversals,
    Breadth First Search (BFS) and Depth First Search (DFS). We can use any of the traversals to solve this problem 
    because a traversal algorithm visits all the nodes in a graph. In any traversal technique, we have one starting 
    node and it traverses all the nodes in the graph. Suppose there is an ‘N’ number of provinces so we need to call 
    the traversal algorithm ‘N‘ times, i.e., there will be ‘N’ starting nodes. 
    So, we just need to figure out the number of starting nodes.
 * 
    The algorithm steps are as follows:

    We need a visited array initialized to 0, representing the nodes that are not visited.
    Run the for loop looping from 0 to N, and call the DFS for the first unvisited node. 
    DFS function call will make sure that it starts the DFS call from that unvisited node,
     and visits all the nodes that are in that province, and at the same time, it will also mark them as visited. 
    Since the nodes traveled in a traversal will be marked as visited, they will no further be called for any further DFS traversal. 
    Keep repeating these steps, for every node that you find unvisited, and visit the entire province. 
    Add a counter variable to count the number of times the DFS function is called, as in this 
    way we can count the total number of starting nodes, which will give us the number of provinces.
    */


#include<bits/stdc++.h>
using namespace std;

class Graph{
    private:
    void dfs(int node,int vis[],vector<int>adj[]){
        vis[node]=1;
        for(auto it:adj[node]){
            if(!vis[it]){
                dfs(it,vis,adj);
            }
        }
    }
    public:
    int noOfProvinces(int v,vector<vector<int>>&edges){
        vector<int>adj[v];
        for(int i=0;i<v;i++){
           for(int j=0;j<v;j++){
             if(edges[i][j]==1 && i!=j){
                adj[i].push_back(j);
                adj[j].push_back(i);
             }
           }
        }
        int vis[v];
        for(int i=0;i<v;i++)vis[i]=0;
        int count = 0;
        for(int i=0;i<v;i++){
            if(!vis[i]){
                count++;
                dfs(i,vis,adj);
            }
        }
        return count;
    }

};

int main(){
int n;
cout<<"Enter the size of the matrix "<<endl;
cin>>n;
vector<vector<int>>edges;
for(int i=0;i<n;i++){
    vector<int>temp;
    cout<<"Enter the "<<i+1<<" th matrix elements "<<endl;
    for(int j=0;j<n;j++){
        int x;
        cin>>x;
        temp.push_back(x);
    }
    edges.push_back(temp);
    temp.clear();
}
Graph obj;
cout<<"The no of provinces : "<<obj.noOfProvinces(n,edges)<<endl;
return 0;
}