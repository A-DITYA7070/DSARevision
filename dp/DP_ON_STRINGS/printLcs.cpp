/**
 * @file printLcs.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-11-06
 * 
 * @copyright Copyright (c) 2023
 * 
 */
/**
 * Print Lcs...
 * 
*/

#include<bits/stdc++.h>
using namespace std;
class DP{
    public:
    string lcs(int ind1,int ind2,string st1,string st2){
        vector<vector<string>>dp(ind1+1,vector<string>(ind2+1,""));
        for(int i=1;i<=ind1;i++){
            for(int j=1;j<=ind2;j++){
                if(st1[i-1] == st2[j-1]){
                    dp[i][j] += dp[i-1][j-1]+st1[i-1];
                }else{
                    dp[i][j] += dp[i-1][j].length() > dp[i][j-1].length() ? dp[i-1][j] : dp[i][j-1];
                }
            }
        }
        return dp[ind1][ind2];
    }

};
int main(){
cout<<"Enter the first string "<<endl;
string st1;
cin>>st1;
cout<<"Enter the second string "<<endl;
string st2;
cin>>st2;
DP obj;
cout<<"LCS : "<<obj.lcs(st1.length(),st2.length(),st1,st2)<<endl;
return 0;
}