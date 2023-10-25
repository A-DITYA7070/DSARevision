/**
 * @file minPathSumTriangle.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-10-25
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include<bits/stdc++.h>
using namespace std;
class TWODDP{
     private:
     int TriangleMemo(int i,int j,int n,vector<vector<int>>&grid,vector<vector<int>>&dp){
        if(i == n){
            return grid[i][j];
        }
        if(dp[i][j]!=-1)return dp[i][j];
        int down = TriangleMemo(i+1,j,n,grid,dp)+grid[i][j];
        int right = TriangleMemo(i+1,j+1,n,grid,dp)+grid[i][j];
        return dp[i][j]=min(down,right);
     }
     public:
     int TriangleRecrusion(int i,int j,int n,vector<vector<int>>&grid){
        if(i==n){
            return grid[i][j];
        }
        int down=TriangleRecrusion(i+1,j,n,grid)+grid[i][j];
        int right=TriangleRecrusion(i+1,j+1,n,grid)+grid[i][j];
        return min(down,right);
     }
     int MemoisationImplementation(int n,vector<vector<int>>&grid){
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return TriangleMemo(0,0,n-1,grid,dp);
     }
     int TabulationSolution(int n,vector<vector<int>>&grid){
        vector<vector<int>>dp(n,vector<int>(n,-1));
        for(int i=0;i<n;i++){
            dp[n-1][i]=grid[n-1][i];
        }
        for(int i=n-2;i>=0;i--){
            for(int j=i;j>=0;j--){
                int up=dp[i+1][j]+grid[i][j];
                int right=dp[i+1][j+1]+grid[i][j];
                dp[i][j]=min(up,right);
            }
        }
        return dp[0][0];
     }
};
int main(){
cout<<"Enter the value of n "<<endl;
int n;
cin>>n;
vector<vector<int>>grid;
for(int i=0;i<n;i++){
    vector<int>temp;
    for(int j=i;j>=0;j--){
        int x;
        cin>>x;
        temp.push_back(x);
    }
    grid.push_back(temp);
    temp.clear();
}
TWODDP obj;
cout<<"Recursion implementation "<<obj.TriangleRecrusion(0,0,n-1,grid)<<endl;
cout<<"MEMOISATION "<<obj.MemoisationImplementation(n,grid)<<endl;
cout<<"TABULATION "<<obj.TabulationSolution(n,grid)<<endl;
return 0;
}