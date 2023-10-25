/**
 * @file minFallingPathSum.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-10-25
 * 
 * @copyright Copyright (c) 2023
 * 
 */

/**
 * Problem Statement :- Given an n x n array of integers matrix, return the minimum sum of any falling path through matrix.
                        A falling path starts at any element in the first row and chooses the element in the next row that is 
                        either directly below or diagonally left/right. Specifically, the next element from position (row, col) 
                        will be (row + 1, col - 1), (row + 1, col), or (row + 1, col + 1).

                        Input: matrix = [[2,1,3],[6,5,4],[7,8,9]]
                        Output: 13
                        Explanation: There are two falling paths with a minimum sum as shown.
 * 
 */

#include<bits/stdc++.h>
using namespace std;
class TWODDP{
   private:
   int minFallingPathMeMo(int i,int j,vector<vector<int>>&paths,vector<vector<int>>&dp){
      if(i>=paths.size() || i<0 || j<0 || j>=paths.size()){
         return 1e9;
      }
      if(i==0)return paths[i][j];
      if(dp[i][j]!=-1)return dp[i][j];
      int down = paths[i][j]+minFallingPathMeMo(i-1,j,paths,dp);
      int left = paths[i][j]+minFallingPathMeMo(i-1,j-1,paths,dp);
      int right = paths[i][j]+minFallingPathMeMo(i-1,j+1,paths,dp);
      return dp[i][j]=min(down,min(left,right));
   }
   public:
   /**
    * function to implement min falling path sum ...
    * t.c O(2^n);
    * s.c O(1);
    */
   int minPathRecursion(int i,int j,int m,int n,vector<vector<int>>&paths){
      if(i>=m || i<0 || j>=n || j<0){
         return 1e9;
      }
      if(i==0)return paths[i][j];
      int down = paths[i][j]+minPathRecursion(i-1,j,m,n,paths);
      int left = paths[i][j]+minPathRecursion(i-1,j-1,m,n,paths);
      int right = paths[i][j]+minPathRecursion(i-1,j+1,m,n,paths);
      return min(down,min(left,right));
   }
   
   int minPathMemoisation(vector<vector<int>>&paths){
      int m=paths.size();
      int n=paths[0].size();
      vector<vector<int>>dp(m,vector<int>(n,-1));
      int maxi=1e9;
      for(int i=0;i<n;i++){
         maxi=min(maxi,minFallingPathMeMo(m-1,i,paths,dp));
      }
      return maxi;
   }

   /**
    * Tabulation implementation ...
    * T.c :- O(m*n);
    * S.c :- O(m*n);
    */
   int minPathTabulationImplement(vector<vector<int>>&matrix){
       int n = matrix.size(); // Number of rows in the matrix
       int m = matrix[0].size(); // Number of columns in the matrix

    // Create a 2D DP (dynamic programming) array to store maximum path sums
    vector<vector<int>> dp(n, vector<int>(m, 0));

    // Initialize the first row of dp with values from the matrix (base condition)
    for (int j = 0; j < m; j++) {
        dp[0][j] = matrix[0][j];
    }

    // Iterate through the matrix rows starting from the second row
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < m; j++) {
            // Calculate the maximum path sum for the current cell considering three possible directions: up, left diagonal, and right diagonal

            // Up direction
            int up = matrix[i][j] + dp[i - 1][j];
            
            // Left diagonal direction (if it's a valid move)
            int leftDiagonal = matrix[i][j];
            if (j - 1 >= 0) {
                leftDiagonal += dp[i - 1][j - 1];
            } else {
                leftDiagonal = 1e9; // A very large negative value to represent an invalid path
            }

            // Right diagonal direction (if it's a valid move)
            int rightDiagonal = matrix[i][j];
            if (j + 1 < m) {
                rightDiagonal += dp[i - 1][j + 1];
            } else {
                rightDiagonal = 1e9; // A very large negative value to represent an invalid path
            }

            // Store the maximum of the three paths in dp
            dp[i][j] = min(up, min(leftDiagonal, rightDiagonal));
        }
      }
      return dp[n-1][m-1];
   }
};
int main(){
int n;
cout<<"enter the size of row and column of the matrix "<<endl;
int m;
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
int maxi=1e9;
for(int j=0;j<n;j++){
   maxi=min(maxi,obj.minPathRecursion(n-1,j,m,n,paths));
}
cout<<"Recursion solution "<<maxi<<endl;
cout<<"Memoisation soltution "<<obj.minPathMemoisation(paths)<<endl;
cout<<"Tabulation solution "<<obj.minPathTabulationImplement(paths)<<endl;
return 0;
}