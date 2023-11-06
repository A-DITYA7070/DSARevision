/**
 * @file coinChange2.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-11-06
 * 
 * @copyright Copyright (c) 2023
 * 
 */

/**
 * problem statement :- You are given an integer array coins representing coins of different denominations and an integer 
 *                      amount representing a total amount of money.Return the number of combinations that make up that amount. 
 *                      If that amount of money cannot be made up by any combination of the coins, return 0.You may assume that 
 *                      you have an infinite number of each kind of coin.
                        The answer is guaranteed to fit into a signed 32-bit integer.

                        Example 1:
                        Input: amount = 5, coins = [1,2,5]
                        Output: 4
                        Explanation: there are four ways to make up the amount:
                        5=5
                        5=2+2+1
                        5=2+1+1+1
                        5=1+1+1+1+1
*/

#include<bits/stdc++.h>
using namespace std;
class DP{
    private:
    int memoisationSolution(int ind,int amount,vector<int>&coins,vector<vector<int>>&dp){
        if(ind == 0){
            if(amount == 0 || amount % coins[ind] == 0)return 1;
            else return 0;
        }
        if(dp[ind][amount]!=-1)return dp[ind][amount];
        int ntake = memoisationSolution(ind-1,amount,coins,dp);
        int take=0;
        if(coins[ind]<=amount){
           take=memoisationSolution(ind,amount-coins[ind],coins,dp);
        }
        return dp[ind][amount]=take+ntake;
    }
    public:
    int recursionsolution(int ind,int amount,vector<int>&coins){
        if(ind == 0){
            if(amount == 0 || amount % coins[ind] == 0){
                return 1;
            }else return 0;
        }
        int ntake = recursionsolution(ind-1,amount,coins);
        int take=0;
        if(coins[ind]<=amount){
            take = recursionsolution(ind,amount-coins[ind],coins);
        }
        return take+ntake;
    }
    int memoisationImplementation(int amount,vector<int>&coins){
       int n=coins.size();
       vector<vector<int>>dp(n,vector<int>(amount+1,-1));
       return memoisationSolution(n-1,amount,coins,dp);
    }
};
int main(){
int n;
cout<<"enter the size of the array "<<endl;
cin>>n;
vector<int>coins;
cout<<"Enter the coins denominations "<<endl;
for(int i=0;i<n;i++){
    int x;
    cin>>x;
    coins.push_back(x);
}
int amount;
cout<<"Enter the amount "<<endl;
cin>>amount;
DP obj;
cout<<"Recursion solution "<<obj.recursionsolution(n-1,amount,coins)<<endl;
cout<<"Memoisation solution "<<obj.memoisationImplementation(amount,coins)<<endl;
return 0;
}