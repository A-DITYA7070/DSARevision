/**
 * @file gridUniquePath.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-10-23
 * 
 * @copyright Copyright (c) 2023
 * 
 */

/**
 * Problem statement :-There is a robot on an m x n grid. The robot is initially located at 
        * the top-left corner (i.e., grid[0][0]). The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). 
        * The robot can only move either down or right at any point in time.
        Given the two integers m and n, return the number of possible unique paths that the robot can take 
        to reach the bottom-right corner.The test cases are generated so that the answer will be less than or equal to 2 * 109.
 */

/**
 * Intution..
 *    1.since the tobot can move only down or right... we will write two cases...
 */

#include<bits/stdc++.h>
using namespace std;

class TWODDP{
    int uniquePathMemo(int m,int n,vector<vector<int>>&dp){
        if(m<0 || n<0)return 0;
        if(m == 0 && n == 0)return 1;
        if(dp[m][n]!=-1)return dp[m][n];
        int up=uniquePathMemo(m-1,n,dp);
        int left=uniquePathMemo(m,n-1,dp);
        return dp[m][n]=up+left;
    }
    public:

    /**
     * Recursion implementation of unique path in grid..
     * t.c = O(2^n);
     * s.c = O(1);
     */
    int uniquePathRecursion(int m,int n){
        if(m<0 || n<0)return 0;
        if(m==0 && n==0)return 1;
        int up = uniquePathRecursion(m-1,n);
        int left = uniquePathRecursion(m,n-1);
        return up+left;
    }

    /**
     * memoisation implementation of unique path in grid...
     * t.c = O(m*n);
     * s.c = O(m*n);
     */
    int memoisationImplement(int m,int n){
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        return uniquePathMemo(m,n,dp);
    }

    /**
     * Tabulation implementation ,,,
     * T.c O(m*n);
     * s.c o(m*n);
     */
    int uniquePathTabulation(int m,int n){
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        for(int i=0;i<=m;i++){
            for(int j=0;j<=n;j++){
                if(i==0 && j==0){
                    dp[i][j]=1;
                    continue;
                }
                int up=0;
                int left=0;
                if(i>0){
                    up = dp[i-1][j];
                }
                if(j>0){
                    left = dp[i][j-1];
                }
                dp[i][j]=up+left;
            }
        }
        return dp[m][n];
    }
};
int main(){
cout<<"Enter the size of row and column "<<endl;
int m,n;
cin>>m>>n;
TWODDP obj;
try{
   cout<<"Recursion solution "<<obj.uniquePathRecursion(m-1,n-1)<<endl; 
}catch(const std::exception& e){
   std::cerr<<"Stack overflow "<<std::endl;
}
cout<<"Memoisaiton solution "<<obj.memoisationImplement(m-1,n-1)<<endl;
cout<<"Tabulation solution "<<obj.uniquePathTabulation(m-1,n-1)<<endl;
return 0;
}