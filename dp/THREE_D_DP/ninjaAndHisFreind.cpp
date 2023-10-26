/**
 * @file ninjaAndHisFreind.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-10-26
 * 
 * @copyright Copyright (c) 2023
 * 
 */

/**
 * Problem Description: 
       We are given an ‘N*M’ matrix. Every cell of the matrix has some chocolates on it, 
       mat[i][j] gives us the number of chocolates. We have two friends ‘Alice’ and ‘Bob’. 
       initially, Alice is standing on the cell(0,0) and Bob is standing on the cell(0, M-1). 
       Both of them can move only to the cells below them in these three directions: to the bottom cell (↓), 
       to the bottom-right cell(↘), or to the bottom-left cell(↙).
       When Alica and Bob visit a cell, they take all the chocolates from that cell with them. 
       It can happen that they visit the same cell, in that case, the chocolates need to be considered only once.
       They cannot go out of the boundary of the given matrix, we need to return the maximum number of chocolates 
       that Bob and Alice can together collect.
 * 
 */

#include<bits/stdc++.h>
using namespace std;
class THREEDDP{
    private:
    int maxChocolate(int ind,int j1,int j2,int r,int c,vector<vector<int>>&matrix,vector<vector<vector<int>>>&dp){
        if(j1<0 || j1>=r || j2<0 || j2>=c){
            return -1e9;
        }
        if(ind == r-1){
            if(j1 == j2){
                return matrix[ind][j1];
            }else{
                return matrix[ind][j1]+matrix[ind][j2];
            }
        }
        if(dp[ind][j1][j2]!=-1)return dp[ind][j1][j2];
        int maxi=-1e9;
        for(int dj1=-1;dj1<=1;dj1++){
            for(int dj2=-1;dj2<=1;dj2++){
                int value=0;
                if(j1 == j2){
                    value=matrix[ind][j1];
                }else{
                    value=matrix[ind][j1]+matrix[ind][j2];
                }
                value+=maxChocolate(ind+1,j1+dj1,j2+dj2,r,c,matrix,dp);
                maxi = max(maxi,value);
            }
        }
        return dp[ind][j1][j2]=maxi;
    }
    public:
    /**
     * Recursion implementation T.c:- O(2^n);
     *                          S.c :- O(1);
     */
    int maChocolate(int ind,int j1,int j2,int r,int c,vector<vector<int>>&matrix){
        if(j1<0 || j1>=r || j2<0 || j2>=c){
            return -1e9;
        }
        if(ind==r-1){
            if(j1 == j2){
                return matrix[ind][j1];
            }else{
                return matrix[ind][j1]+matrix[ind][j2];
            }
        }
        int maxi=-1e9;
        for(int dj1=-1;dj1<=1;dj1++){
            for(int dj2=-1;dj2<=1;dj2++){
                int value=0;
                if(j1==j2){
                    value=matrix[ind][j1];
                }else{
                    value=matrix[ind][j1]+matrix[ind][j2];
                }
                value+=maChocolate(ind+1,j1+dj1,j2+dj2,r,c,matrix);
                maxi=max(maxi,value);
            }
        }
        return maxi;
    }
    /**
     *memoisation implementation of max chocolate problem 
        T.c :- O(m*n);
        S.c :- O(m*n);
     */
    int memoisationImplement(vector<vector<int>>&matrix){
        int r=matrix.size();
        int c=matrix[0].size();
        vector<vector<vector<int>>>dp(r,vector<vector<int>>(c,vector<int>(c,-1)));
        return maxChocolate(0,0,c-1,r,c,matrix,dp);
    }
   
};
int main(){
int r,c;
cout<<"Enter the size of row and column "<<endl;
cin>>r>>c;
cout<<"Enter the matrix "<<endl;
vector<vector<int>>matrix;
for(int i=0;i<r;i++){
    vector<int>temp;
    for(int j=0;j<c;j++){
        int x;
        cin>>x;
        temp.push_back(x);
    }
    matrix.push_back(temp);
    temp.clear();
}
THREEDDP obj;
cout<<"Recursion solution "<<obj.maChocolate(0,0,c-1,r,c,matrix)<<endl;
cout<<"Memoisation solution "<<obj.memoisationImplement(matrix)<<endl;
return 0;
}