/**
 * @file longestPallindromicSubsequence.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-11-07
 * 
 * @copyright Copyright (c) 2023
 * 
 */

/**
 * Problem :- Given a string s, find the longest palindromic subsequence's length in s. A subsequence 
 *            is a sequence that can be derived from another sequence by deleting some or no elements 
 *            without changing the order of the remaining elements.
 * 
 * 
            Example 1:
            Input: s = "bbbab"
            Output: 4
            Explanation: One possible longest palindromic subsequence is "bbbb".
 */

#include<bits/stdc++.h>
using namespace std;
class DP{
    private:
    string reverseString(string st){
        string ans="";
        int len=st.length();
        for(int i=len-1;i>=0;i--){
            ans+=st[i];
        }
        return ans;
    }
    int lcsRecursion(int ind1,int ind2,string st1,string st2){
         if(ind1 < 0 || ind2 < 0)return 0;
         if(st1[ind1] == st2[ind2]){
            return 1+lcsRecursion(ind1-1,ind2-1,st1,st2);
         }else{
            return max(lcsRecursion(ind1-1,ind2,st1,st2),lcsRecursion(ind1,ind2-1,st1,st2));
         }
    }
    int lscMemoisation(int ind1,int ind2,string st1,string st2,vector<vector<int>>&dp){
        if(ind1 < 0 || ind2 < 0)return 0;
        if(dp[ind1][ind2]!=-1)return dp[ind1][ind2];
        if(st1[ind1] == st2[ind2]){
            return dp[ind1][ind2] = 1 + lscMemoisation(ind1-1,ind2-1,st1,st2,dp);
        }else{
            return dp[ind1][ind2] = max(lscMemoisation(ind1-1,ind2,st1,st2,dp),lscMemoisation(ind1,ind2-1,st1,st2,dp));
        }
    }
    int lcsTabulation(int ind1,int ind2,string st1,string st2){
        vector<vector<int>>dp(ind1+1,vector<int>(ind2+1,0));
        for(int i=0;i<ind1;i++){
            dp[i][0]=0;
        }
        for(int i=0;i<=ind2;i++){
            dp[0][i]=0;
        }
        for(int i=1;i<=ind1;i++){
            for(int j=1;j<=ind2;j++){
                if(st1[i-1] == st2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[ind1][ind2];
    }
    public:
    int recursionSolution(string st){
        string st2=reverseString(st);
        int ind1=st.length();
        int ind2=st2.length();
        return lcsRecursion(ind1-1,ind2-1,st,st2);
    }
    int memoisation(string st1){
        string st2=reverseString(st1);
        int ind1=st1.length();
        int ind2=st2.length();
        vector<vector<int>>dp(ind1+1,vector<int>(ind2+1,-1));
        return lscMemoisation(ind1-1,ind2-1,st1,st2,dp);
    }
    int tabulation(string st1){
        string st2=reverseString(st1);
        int ind1=st1.length();
        int ind2=st2.length();
        return lcsTabulation(ind1,ind2,st1,st2);
    }
};
int main(){
cout<<"Enter the string "<<endl;
string st1;
cin>>st1;
DP obj;
cout<<"Recursion solution "<<obj.recursionSolution(st1)<<endl;
cout<<"Memoisation solution "<<obj.memoisation(st1)<<endl;
cout<<"Tabulation solution "<<obj.tabulation(st1)<<endl;
return 0;
}