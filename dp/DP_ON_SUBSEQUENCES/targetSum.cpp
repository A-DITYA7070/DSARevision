/**
 * @file targetSum.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-11-05
 * 
 * @copyright Copyright (c) 2023
 * 
 */

/**
 * Problem statement :- You are given an integer array nums and an integer target.You want to build an expression out of 
 *                      nums by adding one of the symbols '+' and '-' before each integer in nums and then concatenate all 
 *                      the integers.For example, if nums = [2, 1], you can add a '+' before 2 and a '-' before 1 and 
 *                      concatenate them to build the expression "+2-1".Return the number of different expressions that 
 *                      you can build, which evaluates to target.
 * 
 * Input: nums = [1,1,1,1,1], target = 3
   Output: 5
*/

#include<bits/stdc++.h>
using namespace std;
class DP{
    private:
    int recursionSolution(int ind,int target,vector<int>&nums){
        if(ind == 0){
            if(target == 0 && nums[ind] == 0)return 2;
            if(target == 0 || nums[ind] == target)return 1;
            return 0;
        }
        int ntake = recursionSolution(ind-1,target,nums);
        int take = 0;
        if(nums[ind]<=target){
            take = recursionSolution(ind-1,target-nums[ind],nums);
        }
        return take+ntake;
    }
    int recursionMemoisationSolution(int ind,int target,vector<int>&nums,vector<vector<int>>&dp){
        if(ind == 0){
            if(target == 0 && nums[ind] == 0)return 2;
            if(target == 0 || nums[ind] == target)return 1;
            return 0;
        }
        if(dp[ind][target]!=-1)return dp[ind][target];
        int ntake = recursionMemoisationSolution(ind-1,target,nums,dp);
        int take = 0;
        if(nums[ind]<=target){
            take = recursionMemoisationSolution(ind-1,target-nums[ind],nums,dp);
        }
        dp[ind][target]=take+ntake;
    }
    public:
    int recursionImplementation(int n,int target,vector<int>&nums){
        int sum=0;
        for(auto &it:nums)sum+=it;
        if((sum-target) < 0)return 0;
        if((sum-target)%2 != 0)return 0;
        int s2 = (sum-target)/2;
        return recursionSolution(n-1,s2,nums);
    }
    int memoisationImplementation(int n,int target,vector<int>&nums){
        int sum=0;
        for(auto &it:nums)sum+=it;
        if((sum-target)<0)return 0;
        if((sum-target)%2 != 0)return 0;
        int s2 = (sum-target)/2;
        vector<vector<int>>dp(n,vector<int>(s2+1,-1));
        return recursionMemoisationSolution(n-1,s2,nums,dp);
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
cout<<"Enter the target "<<endl;
int target;
cin>>target;
DP obj;
cout<<"Recursion solution "<<obj.recursionImplementation(n,target,nums)<<endl;
cout<<"Memoisation solution "<<obj.memoisationImplementation(n,target,nums)<<endl;
return 0;
}