/**
 * @file gridUniquePath2.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-10-24
 * 
 * @copyright Copyright (c) 2023
 * 
 */

/**
 * Problem :- You are given an m x n integer array grid. There is a robot initially located 
 *            at the top-left corner (i.e., grid[0][0]). The robot tries to move to the bottom-right 
 *            corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or right at any point in time.
              An obstacle and space are marked as 1 or 0 respectively in grid. A path that the robot takes cannot 
              include any square that is an obstacle. Return the number of possible unique paths that the robot 
              can take to reach the bottom-right corner.

              EX :- Input: obstacleGrid = [[0,0,0],[0,1,0],[0,0,0]]
                    Output: 2
                    Explanation: There is one obstacle in the middle of the 3x3 grid above.
                    There are two ways to reach the bottom-right corner:
                    1. Right -> Right -> Down -> Down
                    2. Down -> Down -> Right -> Right
 */

#include<bits/stdc++.h>
using namespace std;

class TWODDP{
    private:
    int uniquePath2Memoisation(int m,int n,vector<vector<int>>&paths,vector<vector<int>>&dp){
        if(m>=0 && n>=0 && paths[m][n]==1)return 0;
        if(m==0 && n==0)return 1;
        if(m<0 || n<0)return 0;
        if(dp[m][n]!=-1)return dp[m][n];
        int down = uniquePath2Memoisation(m-1,n,paths,dp);
        int up = uniquePath2Memoisation(m,n-1,paths,dp);
        return dp[m][n]=down+up;
    }
    public:
    /**
     * function to implement unique path2 in recursion ,,
     * T.c :- O(2^n);
     * S.c :- O(1);
     */
    int uniquePath2Recursion(int m,int n,vector<vector<int>>&paths){
        if(m>=0 && n>=0 && paths[m][n]==1)return 0;
        if(m==0 && n==0)return 1;
        if(m<0 || n<0)return 0;
        int down = uniquePath2Recursion(m-1,n,paths);
        int up = uniquePath2Recursion(m,n-1,paths);
        return down+up;
    }
    
    /**
     * function to implement the unique path 2 in memeoisation 
     * since this problem has overlapping path hence we can memoise it..
     * T.c:- O(m*n);
     * S.c:- O(m*n);
     */
    int memoisationImplementation(int m,int n,vector<vector<int>>&paths){
        vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
        return uniquePath2Memoisation(m-1,n-1,paths,dp);
    }
    
    /**
     * function to implement the unique path 2 in tabulation :- iterative method..
     * T.c :- O(m*n);
     * s.c :- O(m*n);
     */
    int tabulationImplementation(int m,int n,vector<vector<int>>&paths){
        vector<vector<int>>dp(m,vector<int>(n,-1));
        for(int i=0;i<m;i++){
           for(int j=0;j<n;j++){
             if(i>=0 && j>=0 && paths[i][j]==1){
                dp[i][j]=0;
                continue;
             }
             if(i==0 && j==0){
                dp[i][j]=1;
                continue;
             }
             int up=0;
             int left=0;
             if(i>0){
                left=dp[i-1][j];
             }
             if(j>0){
                up=dp[i][j-1];
             }
             dp[i][j]=up+left;
           }
        }        
        return dp[m-1][n-1];
    }

};
int main(){
    int m,n;
    cout<<"Enter the size of the row and column "<<endl;
    cin>>m>>n;
    vector<vector<int>>paths;
    for(int i=0;i<m;i++){
        vector<int>temp;
        for(int j=0;j<n;j++){
           int x;
           cin>>x;
           temp.push_back(x);
        }
        paths.push_back(temp);
        temp.clear();
    }
    TWODDP obj;
    cout<<"Rec implementation "<<obj.uniquePath2Recursion(m-1,n-1,paths)<<endl;
    cout<<"Memoisation "<<obj.memoisationImplementation(m,n,paths)<<endl;
    cout<<"Tabulation solution "<<obj.tabulationImplementation(m,n,paths)<<endl;
    return 0;
}