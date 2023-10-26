/**
 * @file subsetsumEqualToK.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-10-26
 * 
 * @copyright Copyright (c) 2023
 * 
 */

/**
 * problem :- 
 * 
 */
#include<bits/stdc++.h>
using namespace std;
class SUBSEQUENCES{
    private:
    int memoisation(int ind,int target,vector<int>&nums,vector<vector<int>>&dp){
        if(target == 0)return true;
        if(ind == 0)return target == nums[ind];
        if(dp[ind][target]!=-1)return dp[ind][target];
        bool ntake = memoisation(ind-1,target,nums,dp);
        bool take=false;
        if(nums[ind]<=target){
           take=memoisation(ind-1,target-nums[ind],nums,dp);
        }
        return dp[ind][target]=take|ntake;
    }
    public:
    bool recursionSolution(int ind,int target,vector<int>&nums){
        if(target == 0)return true;
        if(ind == 0)return nums[ind]==target;
        bool ntake=recursionSolution(ind-1,target,nums);
        bool take=false;
        if(nums[ind]<=target){
            take=recursionSolution(ind-1,target-nums[ind],nums);
        }
        return take|ntake;
    }
    
    bool memoImplement(int ind,int target,vector<int>&nums){
        int n=nums.size();
        vector<vector<int>>dp(n,vector<int>(target+1,-1));
        return memoisation(n-1,target,nums,dp);
    }
    bool tabulationImplement(int target,vector<int>&nums){
        int n=nums.size();
        vector<vector<bool>>dp(n,vector<bool>(target+1,false));
        for(int i=0;i<n;i++){
            dp[i][0]=true;
        }
        if(nums[0]<=target){
            dp[0][nums[0]]=true;
        }
        for(int i=1;i<n;i++){
            for(int tar = 1;tar<=target;tar++){
                bool ntake=dp[i-1][tar];
                bool take=false;
                if(nums[i]<=target){
                    take=dp[i-1][tar-nums[i]];
                }
                dp[i][tar]=take||ntake;
            }
        }
        return dp[n-1][target];
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
cout<<"Enter target "<<endl;
int target;
cin>>target;
SUBSEQUENCES obj;
cout<<"Recursion solution "<<obj.recursionSolution(n-1,target,nums)<<endl;
cout<<"Memoisation solution "<<obj.memoImplement(n,target,nums)<<endl;
cout<<"Tabulation solution "<<obj.tabulationImplement(target,nums)<<endl;
return 0;
}