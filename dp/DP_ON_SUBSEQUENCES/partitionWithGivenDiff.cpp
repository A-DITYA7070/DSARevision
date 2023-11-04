/**
 * @file partitionWithGivenDiff.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-11-04
 * 
 * @copyright Copyright (c) 2023
 * 
 */

/**
 * Problem Statement :-  Count Partitions with Given Difference
 * 
 */

#include<bits/stdc++.h>
using namespace std;
int mod=1e9+7;
int f(int ind,int target,vector<int>&arr,vector<vector<int>>&dp){
    if(ind == 0){
        if(target == 0 && arr[0]==0)return 2;
        if(target == 0 || arr[0]==target)return 1;
        return 0;
    }
    if(dp[ind][target]!=-1)return dp[ind][target];
    int ntake=f(ind-1,target,arr,dp);
    int take=0;
    if(arr[ind]<=target){
        take=f(ind-1,target-arr[ind],arr,dp);
    }
    return dp[ind][target]=(take+ntake)%mod;
}
int count(int n,int target,vector<int>&arr){
    vector<vector<int>>dp(n,vector<int>(target+1,-1));
    return f(n-1,target,arr,dp);
}
int solve(int n,int totSum,int target,vector<int>&arr){
   if((totSum-target)<0 || (totSum-target)%2 != 0)return false;
   return count(n,(totSum-target)/2,arr);
}
int main(){
cout<<"Enter the size of the array "<<endl;
int n;
cin>>n;
cout<<"Enter the array "<<endl;
vector<int>arr;
for(int i=0;i<n;i++){
    int x;
    cin>>x;
    arr.push_back(x);
}
int totSum=0;
for(auto &it:arr){
    totSum+=it;
}
cout<<"Enter the target "<<endl;
int target;
cin>>target;
cout<<solve(n,totSum,target,arr)<<endl;
return 0;
}