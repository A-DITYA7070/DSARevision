/**
 * @file partitionEqualSubsetSum.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-10-26
 * 
 * @copyright Copyright (c) 2023
 * 
 */

/**
 * Problem Statement :- Given an integer array nums, return true if you can partition the array into two 
 *                      subsets such that the sum of the elements in both subsets is equal or false otherwise.
 * EX :-
        Input: nums = [1,5,11,5]
        Output: true
        Explanation: The array can be partitioned as [1, 5, 5] and [11].
 * 
 */

#include<bits/stdc++.h>
using namespace std;
class SUBSEQUENCES{
    private:
        bool recusionSolution(int ind,int target,vector<int>&nums){
        if(target == 0)return true;
        if(ind == 0){
            return target == nums[0];
        }
        bool ntake = recusionSolution(ind-1,target,nums);
        bool take = false;
        if(nums[ind]<=target){
            take = recusionSolution(ind-1,target-nums[ind],nums);
        }
        return take || ntake;
    }
    bool memoisationSolution(int ind,int target,vector<int>&nums,vector<vector<int>>&dp){
        if(target == 0)return true;
        if(ind == 0)return nums[ind]==target;
        if(dp[ind][target] != -1)return dp[ind][target];
        bool ntake = memoisationSolution(ind-1,target,nums,dp);
        bool take = false;
        if(nums[ind]<=target){
            take = memoisationSolution(ind-1,target-nums[ind],nums,dp);
        }
        return dp[ind][target]=take|ntake;
    }
    public:
    /**
     * function to implement recursive solution ..
     * T.c :- O(2^n); 
     */
    bool recursionImplementation(vector<int>&nums){
        int n=nums.size();
        int sum=0;
        for(auto it:nums)sum+=it;
        if(sum%2 != 0)return false;
        int sum1=sum/2;
        return recusionSolution(n-1,sum1,nums);
    }
    /**
     * function to implement memoisation solution
     * T.c :- O(n*target);
     * S.c :- O(n*target);
     */
    bool memosationImplementation(vector<int>&nums){
        int n=nums.size();
        int sum=0;
        for(auto it:nums)sum+=it;
        if(sum%2 != 0)return false;
        int sum1=sum/2;
        vector<vector<int>>dp(n,vector<int>(sum1+1,-1));
        return memoisationSolution(n-1,sum1,nums,dp);
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
SUBSEQUENCES obj;
cout<<"Recursion solution "<<obj.recursionImplementation(nums)<<endl;
cout<<"Memoisation solution "<<obj.memosationImplementation(nums)<<endl;
return 0;
}