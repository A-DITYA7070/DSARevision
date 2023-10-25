
/**
 * @file minPathSumInGrid.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-10-24
 * 
 * @copyright Copyright (c) 2023
 * 
 */

/**
 * Problem Statement :- Given a m x n grid filled with non-negative numbers, find a path from top left to 
 *                      bottom right, which minimizes the sum of all numbers along its path.
                        Note: You can only move either down or right at any point in time.

                        Input: grid = [[1,3,1],[1,5,1],[4,2,1]]
                        Output: 7
                        Explanation: Because the path 1 → 3 → 1 → 1 → 1 minimizes the sum.
 * 
 */

#include<bits/stdc++.h>
using namespace std;

class TWODDP{
    private:
    int minPathMemo(int m,int n,vector<vector<int>>&paths,vector<vector<int>>&dp){
        if(m==0 && n==0)return paths[m][n];
        if(m<0 || n<0)return 1e9;
        if(dp[m][n]!=-1)return dp[m][n];
        int up = minPathMemo(m-1,n,paths,dp)+paths[m][n];
        int left = minPathMemo(m,n-1,paths,dp)+paths[m][n];
        return dp[m][n]=min(up,left);
    }
    public:
    /**
     * Recursion implementation of min path sum..
     * T.c :- O(2^n);
     * S.c :- O(1);
     */
    int minPathSumRecursion(int m,int n,vector<vector<int>>&paths){
        if(m==0 && n==0)return paths[m][n];
        if(m<0 || n<0)return 1e9;
        int up = minPathSumRecursion(m-1,n,paths)+paths[m][n];
        int left = minPathSumRecursion(m,n-1,paths)+paths[m][n];
        return min(up,left);
    }
    
    /**
     * Memoisation implementation of min path sum in grid..
     * T.c :- O(m,n);
     * s.c :- O(m,n);
     */
    int memoisationImplementation(int m,int n,vector<vector<int>>&paths){
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        return minPathMemo(m-1,n-1,paths,dp);
    }
    
    /**
     * Tabulation implementation of min path sum in grid..
     * T.c :- O(m*n);
     * S.c :- O(m*n);
     */
    int tabulationImplementation(int m,int n,vector<vector<int>>&paths){
        vector<vector<int>>dp(m,vector<int>(n,-1));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 && j==0){
                    dp[i][j]=paths[i][j];
                    continue;
                }
                int up=paths[i][j];
                int left=paths[i][j];
                if(i>0){
                    up=dp[i-1][j]+up;
                }else{
                    up=1e9;
                }
                if(j>0){
                    left=dp[i][j-1]+left;
                }else{
                    left=1e9;
                }
                dp[i][j]=min(left,up);
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
cout<<"Enter the path matrix "<<endl;
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
cout<<"Recursion solution "<<obj.minPathSumRecursion(m-1,n-1,paths)<<endl;
cout<<"MEMOIsation solution "<<obj.memoisationImplementation(m,n,paths)<<endl;
cout<<"Tabulation solution "<<obj.tabulationImplementation(m,n,paths)<<endl;
return 0;
}