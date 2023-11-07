/**
 * @file minimumInsertionTomakePallindrome.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-11-07
 * 
 * @copyright Copyright (c) 2023
 * 
 */

/**
 * Problem :- Given a string s. In one step you can insert any character at any index of the string.
              Return the minimum number of steps to make s palindrome.
              A Palindrome String is one that reads the same backward as well as forward.

                Input: s = "mbadm"
                Output: 2
                Explanation: String can be "mbdadbm" or "mdbabdm".
 * 
 */
#include<bits/stdc++.h>
using namespace std;
class DP{
    private:
    string reverse(string st){
        string s="";
        for(int i=st.length()-1;i>=0;i--)s+=st[i];
        return s;
    }
    int recursionSolution(int ind1,int ind2,string st1,string st2){
       if(ind1 < 0 || ind2 < 0)return 0;
       if(st1[ind1] == st2[ind2]){
          return 1+recursionSolution(ind1-1,ind2-1,st1,st2);
       }else{
          return max(recursionSolution(ind1-1,ind2,st1,st2),recursionSolution(ind1,ind2-1,st1,st2));
       }
    }
    int memoisaitonsolution(int ind1,int ind2,string st1,string st2,vector<vector<int>>&dp){
        if(ind1 < 0 || ind2 < 0)return 0;
        if(dp[ind1][ind2] != -1)return dp[ind1][ind2];
        if(st1[ind1] == st2[ind2]){
            return dp[ind1][ind2]=1+memoisaitonsolution(ind1-1,ind2-1,st1,st2,dp);
        }else{
           return dp[ind1][ind2]=max(memoisaitonsolution(ind1-1,ind2,st1,st2,dp),memoisaitonsolution(ind1,ind2-1,st1,st2,dp));
        }
    }
    int tabulationSolution(int len,string st1,string st2){
        vector<vector<int>> dp(len+1,vector<int>(len+1,0));
        for(int i=0;i<=len;i++){
            dp[i][0]=0;
            dp[0][i]=0;
        }
        for(int i=1;i<=len;i++){
            for(int j=1;j<=len;j++){
                if(st1[i-1] == st2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[len][len];
    }
    public:
    int recursion(string st1){
        string st2=reverse(st1);
        int len = recursionSolution(st1.length()-1,st2.length()-1,st1,st2);
        return st1.length()-len;
    }
    int memoisation(string st1){
        string st2=reverse(st1);
        int len=st1.length();
        vector<vector<int>>dp(len+1,vector<int>(len+1,-1));
        int l = memoisaitonsolution(len-1,len-1,st1,st2,dp);
        return len-l;
    }
    int tabulation(string st1){
        string st2=reverse(st1);
        int len=st1.length();
        int l = tabulationSolution(len,st1,st2);
        return len-l;
    }
};
int main(){
cout<<"Enter the string "<<endl;
string st;
cin>>st;
DP obj;
cout<<"Recursion solution "<<obj.recursion(st)<<endl;
cout<<"Memoisation "<<obj.memoisation(st)<<endl;
cout<<"Tabulation "<<obj.tabulation(st)<<endl;
return 0;
}