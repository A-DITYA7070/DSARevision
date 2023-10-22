/**
 * @file floodFill.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-10-21
 * 
 * @copyright Copyright (c) 2023
 * 
 */

/**
 * problem statement :- 
 *    An image is represented by an m x n integer grid image where image[i][j] represents the pixel value of the image.
      You are also given three integers sr, sc, and color. You should perform a flood fill on the image starting from the 
      pixel image[sr][sc].To perform a flood fill, consider the starting pixel, plus any pixels connected 4-directionally 
      to the starting pixel of the same color as the starting pixel, plus any pixels connected 4-directionally to those 
      pixels (also with the same color), and so on. Replace the color of all of the aforementioned pixels with color.
      Return the modified image after performing the flood fill.

 *      Input: image = [[1,1,1],[1,1,0],[1,0,1]], sr = 1, sc = 1, color = 2
        Output: [[2,2,2],[2,2,0],[2,0,1]]
        Explanation: From the center of the image with position (sr, sc) = (1, 1) (i.e., the red pixel), 
        all pixels connected by a path of the same color as the starting pixel (i.e., the blue pixels) are colored with the new color.
        Note the bottom corner is not colored 2, because it is not 4-directionally connected to the starting pixel.
 */

/**
 * Intution :- 
 *    we can use either bfs or dfs ...
 *    Bfs..
 *    1. initialize copy of given matrix
 *    2. take a queue and put the given starting index x and y in it
 *    3. check all its neighbours -|- if it matches the conditions push it in queue and paint old loc with new color
 *    4. return the new ans matrix..
 * 
 */

#include<bits/stdc++.h>
using namespace std;

class Graph{
   public:
   
   /**
    * bfs implementation of rotten oranges problem...
    * T.c :- O(NM + 4*NM)
    * S.c :- O(NM + 4*NM);
    */
   void bfs(vector<vector<int>>&image,vector<vector<int>>&ans,int x,int y,int color){
       ans=image;
       int n=image.size();
       int m=image[0].size();
       int oc=image[x][y];
       ans[x][y]=color;
       queue<pair<int,int>>q;
       int dx[4]={-1,0,1,0};
       int dy[4]={0,1,0,-1};
       q.push({x,y});
       while(!q.empty()){
         int r=q.front().first;
         int c=q.front().second;
         q.pop();
         for(int i=0;i<4;i++){
            int nrow=dx[i]+r;
            int ncol=dy[i]+c;
            if(
                nrow>=0 && nrow<n &&
                ncol>=0 && ncol<m &&
                image[nrow][ncol]==oc &&
                ans[nrow][ncol]!=color
            ){
                ans[nrow][ncol]=color;
                q.push({nrow,ncol});
            }
         }
       }
   }
   
   /**
    * dfs implementation of rotten oranges problem...
    * t.c := O(MN+4*MN);
    * s.c := O(MN+4*MN);
    */
   void dfs(vector<vector<int>>&image,vector<vector<int>>&ans,int x,int y,int n,int m,int dx[],int dy[],int oc,int color){
      ans[x][y]=color;
      for(int i=0;i<4;i++){
        int nrow=dx[i]+x;
        int ncol=dy[i]+y;
        if(
            nrow>=0 && nrow<n &&
            ncol>=0 && ncol<m &&
            image[nrow][ncol]==oc &&
            ans[nrow][ncol]!=color
        ){
            dfs(image,ans,nrow,ncol,n,m,dx,dy,oc,color);
        }
      }
   }
};

int main(){
    int n,m;
    cout<<"Enter the row and column size "<<endl;
    cin>>n>>m;
    vector<vector<int>>images;
    for(int i=0;i<n;i++){
        vector<int>temp;
        cout<<"Enter "<<i+1<<" th row "<<endl;
        for(int j=0;j<m;j++){
            int x;
            cin>>x;
            temp.push_back(x);
        }
        images.push_back(temp);
        temp.clear();
    }
    Graph obj;
    cout<<"Enter the cordinates of initial color "<<endl;
    int sr,sc;
    cin>>sr>>sc;
    cout<<"Enter the new color to fill "<<endl;
    int color;
    cin>>color;
    vector<vector<int>>ans;
    obj.bfs(images,ans,sr,sc,color);
    vector<vector<int>>ans2=images;
    int dx[4]={-1,0,1,0};
    int dy[4]={0,1,0,-1};
    int oc=images[sr][sc];
    obj.dfs(images,ans2,sr,sc,n,m,dx,dy,oc,color);
    cout<<"Matrix before filling "<<endl;
    for(auto it:images){
        for(auto i:it){
            cout<<i<<" ";
        }cout<<endl;
    }
    cout<<"Matrix after filling bfs "<<endl;
    for(auto it:ans){
        for(auto i:it){
            cout<<i<<" ";
        }cout<<endl;
    }
    cout<<"Matrix after filling dfs "<<endl;
    for(auto it:ans2){
        for(auto i:it){
            cout<<i<<" ";
        }cout<<endl;
    }
    return 0;
}