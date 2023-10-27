/**
 * @file partitionSubsetwithMindiff.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-10-27
 * 
 * @copyright Copyright (c) 2023
 * 
 */
/**
 * Problem statement :- We are given an array ‘ARR’ with N positive integers. We need to partition the array 
 *                      into two subsets such that the absolute difference of the sum of elements of the subsets is minimum.
                        We need to return only the minimum absolute difference of the sum of elements of the two partitions
*/
#include<bits/stdc++.h>
using namespace std;
bool solve(int ind,int target,vector<int>&nums,vector<vector<int>>&dp){
    if(target == 0)return true;
    if(ind == 0)return nums[ind]==target;
    if(dp[ind][target]!=-1)return dp[ind][target];
    bool ntake = solve(ind-1,target,nums,dp);
    bool take=false;
    if(nums[ind]<=target){
        take = solve(ind-1,target-nums[ind],nums,dp);
    }
    return dp[ind][target]=take|ntake;
}
int main(){
cout<<"Enter the size of the array "<<endl;
int n;
cin>>n;
vector<int>nums;
for(int i=0;i<n;i++){
    int x;
    cin>>x;
    nums.push_back(x);
}
int sum=0;
for(auto it:nums)sum+=it;
vector<vector<int>>dp(n,vector<int>(sum+1,-1));
for(int i=0;i<n;i++){
    bool dummy = solve(n-1,i,nums,dp);
}
int mini=1e9;
for(int i=0;i<=sum;i++){
    if(dp[n-1][i]){
        int diff=abs(i-(sum-i));
        mini=min(mini,diff);
    }
}
/**
 * T.c :- O(n*sum);
 */
cout<<"solution "<<mini<<endl;
return 0;
}