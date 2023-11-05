/**
 * @file coinChange.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-11-04
 * 
 * @copyright Copyright (c) 2023
 * 
 */

/**
 * Problem Statement :- You are given an integer array coins representing coins of different denominations and an 
 *                      integer amount representing a total amount of money.Return the fewest number of coins that 
 *                      you need to make up that amount. If that amount of money cannot be made up by any combination
 *                      of the coins, return -1. You may assume that you have an infinite number of each kind of coin.
 * 
 * Example 1:
                Input: coins = [1,2,5], amount = 11
                Output: 3
                Explanation: 11 = 5 + 5 + 1
 * 
 */
#include<bits/stdc++.h>
using namespace std;
class DP{
    private:
    int coinChangeMemoIsation(int ind,vector<int>&coins,int amount,vector<vector<int>>&dp){
       if(ind == 0){
         if(amount%coins[ind] == 0){
            return amount/coins[ind];
         }else return 1e9;
       }
       if(dp[ind][amount]!=-1)return dp[ind][amount];
       int ntake=0+coinChangeMemoIsation(ind-1,coins,amount,dp);
       int take=1e9;
       if(coins[ind]<=amount){
        take=1+coinChangeMemoIsation(ind,coins,amount-coins[ind],dp);
       }
       return dp[ind][amount]=min(take,ntake);
    }
    public:
    int coinChangeRecursion(int ind,vector<int>&coins,int amount){
        if(ind == 0){
            if(amount%coins[ind] == 0)return amount/coins[ind];
            else return 1e9;
        }
        int ntake=0+coinChangeRecursion(ind-1,coins,amount);
        int take=1e9;
        if(coins[ind]<=amount){
            take=1+coinChangeRecursion(ind,coins,amount-coins[ind]);
        }
        return min(take,ntake);
    }
    int memoisationSolution(int n,vector<int>&coins,int amount){
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        int ans=coinChangeMemoIsation(n-1,coins,amount,dp);
        if(ans == 1e9)return -1;
        return ans;
    }
};
int main(){
int n;
cout<<"Enter the size of the array "<<endl;
cin>>n;
vector<int>coins;
cout<<"Enter the coins "<<endl;
for(int i=0;i<n;i++){
    int x;
    cin>>x;
    coins.push_back(x);
}
DP obj;
int amount;
cout<<"Enter the amount "<<endl;
cin>>amount;
int ans=obj.coinChangeRecursion(n-1,coins,amount);
cout<<"Recursion solution "<<ans<<endl;
cout<<"Memoisaiton solution "<<obj.memoisationSolution(n,coins,amount)<<endl;
return 0;
}