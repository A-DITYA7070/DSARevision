/**
 * @file countSubsetsumEqualToK.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-10-27
 * 
 * @copyright Copyright (c) 2023
 * 
 */

/**
 * Problem :- We are given an array ‘ARR’ with N positive integers and an integer K. 
 *            We need to find the number of subsets whose sum is equal to K.
 *            Enter the size of the array 
              4
              1 2 2 3
              Enter the target
              3
              Recursion solution 3
              Memoisation solution 3
 * 
 */

#include<bits/stdc++.h>
using namespace std;
class SUBSEQUENCE{
   private:
   int memoisationSolution(int ind,int target,vector<int>&nums,vector<vector<int>>&dp){
      if(target == 0)return true;
      if(ind == 0){
        return nums[ind]==target ? 1 : 0;
      }
      if(dp[ind][target]!=-1)return dp[ind][target];
      int ntake = memoisationSolution(ind-1,target,nums,dp);
      int take = false;
      if(nums[ind]<=target){
        take = memoisationSolution(ind-1,target-nums[ind],nums,dp);
      }
      return dp[ind][target]=take+ntake;
   }
   public:
   /**
    * Recursive solution ...
    * T.c :- O(2^n);
    */
   int recursionsolution(int ind,int target,vector<int>&nums){
      if(target == 0)return 1;
      if(ind == 0){
        return nums[0]==target ? 1 : 0;
      }
      int ntake = recursionsolution(ind-1,target,nums);
      int take=false;
      if(nums[ind]<=target){
        take = recursionsolution(ind-1,target-nums[ind],nums);
      }
      return take+ntake;
   }
   /**
    * memoisation solution ...
    * T.c :- O(n*target);
    * s.c :- O(n*target);
    */
   int memoisationsolution(vector<int>&nums,int target){
      int n=nums.size();
      vector<vector<int>>dp(n,vector<int>(target+1,-1));
      return memoisationSolution(n-1,target,nums,dp);
   }
};
int main(){
int n;
cout<<"Enter the size of the array "<<endl;
cin>>n;
vector<int>nums;
for(int i=0;i<n;i++){
    int x;
    cin>>x;
    nums.push_back(x);
}
int target;
cout<<"Enter the target "<<endl;
cin>>target;
SUBSEQUENCE obj;
cout<<"Recursion solution "<<obj.recursionsolution(n-1,target,nums)<<endl;
cout<<"Memoisation solution "<<obj.memoisationsolution(nums,target)<<endl;
return 0;
}