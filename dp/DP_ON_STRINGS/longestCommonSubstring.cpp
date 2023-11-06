/**
 * @file longestCommonSubstring.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-11-07
 * 
 * @copyright Copyright (c) 2023
 * 
 */

/**
 * Problem :- longest common substring...
 * 
 */

#include<bits/stdc++.h>
using namespace std;
class DP{
    public:
    int tabulationSolution(int ind1,int ind2,string st1,string st2){
        vector<vector<int>>dp(ind1+1,vector<int>(ind2+1,0));
        int ans=0;
        for(int i=1;i<=ind1;i++){
            for(int j=1;j<=ind2;j++){
                if(st1[i-1] == st2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                    ans=max(ans,dp[i][j]);
                }else{
                    dp[i][j]=0;
                }
            }
        }
        return ans;
    }
};
int main(){
string st1,st2;
cout<<"enter the first string "<<endl;
cin>>st1;
cout<<"Enter the second string "<<endl;
cin>>st2;
DP obj;
cout<<"Longest common sub string "<<obj.tabulationSolution(st1.length(),st2.length(),st1,st2)<<endl;
return 0;
}