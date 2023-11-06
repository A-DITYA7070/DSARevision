/**
 * @file lcs.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-11-06
 * 
 * @copyright Copyright (c) 2023
 * 
 */

/**
 * Problem statement :- Given two strings text1 and text2, return the length of their longest common subsequence. 
 *                      If there is no common subsequence, return 0. A subsequence of a string is a new string generated 
 *                      from the original string with some characters (can be none) deleted without changing the relative 
 *                      order of the remaining characters.

                        For example, "ace" is a subsequence of "abcde".
                        A common subsequence of two strings is a subsequence that is common to both strings.

                        Example 1:
                        Input: text1 = "abcde", text2 = "ace" 
                        Output: 3  
                        Explanation: The longest common subsequence is "ace" and its length is 3.

 * 
 */

#include<bits/stdc++.h>
using namespace std;
class DP{
    private:
    int memoisation(int ind1,int ind2,string st1,string st2,vector<vector<int>>&dp){
       if(ind1 < 0 || ind2 < 0)return 0;
       if(dp[ind1][ind2]!=-1)return dp[ind1][ind2];
       if(st1[ind1] == st2[ind2]){
          return dp[ind1][ind2]=1+memoisation(ind1-1,ind2-1,st1,st2,dp);
       }else{
          return dp[ind1][ind2]=max(memoisation(ind1-1,ind2,st1,st2,dp),memoisation(ind1,ind2-1,st1,st2,dp));
       }
    }
    int tabulation(int ind1,int ind2,string st1,string st2){
        vector<vector<int>>dp(ind1+1,vector<int>(ind2+1,-1));
        for(int i=0;i<=ind1;i++){
            dp[i][0]=0;
        }
        for(int i=0;i<=ind2;i++){
            dp[0][i]=0;
        }
        for(int i=1;i<=ind1;i++){
           for(int j=1;j<=ind2;j++){
              if(st1[i-1]==st2[j-1]){
                 dp[i][j]=1+dp[i-1][j-1];
              }else{
                 dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
              }
           }
        }
        return dp[ind1][ind2];
    }
    public:
    int recursionLcs(int ind1,int ind2,string st1,string st2){
        if(ind1 < 0 || ind2 < 0)return 0;
        if(st1[ind1] == st2[ind2]){
            return 1+recursionLcs(ind1-1,ind2-1,st1,st2);
        }else{
            return max(recursionLcs(ind1-1,ind2,st1,st2),recursionLcs(ind1,ind2-1,st1,st2));
        }
    }
    int memoisationImplementation(string st1,string st2){
        int n1=st1.length();
        int n2=st2.length();
        vector<vector<int>>dp(n1+1,vector<int>(n2+1,-1));
        return memoisation(n1-1,n2-1,st1,st2,dp);
    }
    int tabulationImplementation(string st1,string st2){
        int n1=st1.length();
        int n2=st2.length();
        return tabulation(n1,n2,st1,st2);
    }
};
int main(){
cout<<"Enter the first string "<<endl;
string st1;
cin>>st1;
cout<<"Enter the second string "<<endl;
string st2;
cin>>st2;
int n1=st1.length();
int n2=st2.length();
DP obj;
cout<<"Recursion solution "<<obj.recursionLcs(n1-1,n2-1,st1,st2)<<endl;
cout<<"Memoisation solution "<<obj.memoisationImplementation(st1,st2)<<endl;
cout<<"Tabulation solution "<<obj.tabulationImplementation(st1,st2)<<endl;
return 0;
}