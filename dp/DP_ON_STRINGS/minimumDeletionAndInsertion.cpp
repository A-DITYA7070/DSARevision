/**
 * @file minimumDeletionAndInsertion.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-11-08
 * 
 * @copyright Copyright (c) 2023
 * 
 */
/**
 * problem :- Given two strings word1 and word2, return the minimum number of steps 
 *            required to make word1 and word2 the same.
              In one step, you can delete exactly one character in either string.

              Input: word1 = "sea", word2 = "eat"
              Output: 2

*/

#include<bits/stdc++.h>
using namespace std;
class DP{
    private:
    int recursionSolution(int ind1,int ind2,string st1,string st2){
        if(ind1<0 || ind2<0)return 0;
        if(st1[ind1] == st2[ind2]){
            return 1+recursionSolution(ind1-1,ind2-1,st1,st2);
        }else{
            return max(recursionSolution(ind1-1,ind2,st1,st2),recursionSolution(ind1,ind2-1,st1,st2));
        }
    }
    int memoisationsolution(int ind1,int ind2,string st1,string st2,vector<vector<int>>&dp){
        if(ind1<0 || ind2<0)return 0;
        if(dp[ind1][ind2]!=-1)return dp[ind1][ind2];
        if(st1[ind1]==st2[ind2]){
            return dp[ind1][ind2]=1+memoisationsolution(ind1-1,ind2-1,st1,st2,dp);
        }else{
            return dp[ind1][ind2]=max(memoisationsolution(ind1-1,ind2,st1,st2,dp),memoisationsolution(ind1,ind2-1,st1,st2,dp));
        }
    }
    int tabulationsolution(string st1,string st2){
        int len1=st1.length();
        int len2=st2.length();
        vector<vector<int>>dp(len1+1,vector<int>(len2+1,-1));
        for(int i=0;i<=len1;i++){
            dp[i][0]=0;
        }
        for(int i=0;i<=len2;i++){
            dp[0][i]=0;
        }
        for(int i=1;i<=len1;i++){
            for(int j=1;j<=len2;j++){
                if(st1[i-1]==st2[j-1]){
                    dp[i][j]=dp[i-1][j-1]+1;
                }else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[len1][len2];
    }
    public:
    int recursion(string st1,string st2){
        int len1=st1.length();
        int len2=st2.length();
        int len=recursionSolution(len1-1,len2-1,st1,st2);
        return len1-len + len2-len;
    }
    int memoisation(string st1,string st2){
        int len1=st1.length();
        int len2=st2.length();
        vector<vector<int>>dp(len1+1,vector<int>(len2+1,-1));
        int len=memoisationsolution(len1-1,len2-1,st1,st2,dp);
        return len1-len + len2-len;
    }
    int tabulation(string st1,string st2){
        int len1=st1.length();
        int len2=st2.length();
        int len=tabulationsolution(st1,st2);
        return len1-len+len2-len;
    }

};
int main(){
cout<<"enter the first string "<<endl;
string st1;
cin>>st1;
cout<<"Enter the second string "<<endl;
string st2;
cin>>st2;
DP obj;
cout<<"Recursion "<<obj.recursion(st1,st2)<<endl;
cout<<"meoisation "<<obj.memoisation(st1,st2)<<endl;
cout<<"Tabulation "<<obj.tabulation(st1,st2)<<endl;
return 0;
}