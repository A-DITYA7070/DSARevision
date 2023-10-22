/**
 * @file HouseRobber2.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-10-22
 * 
 * @copyright Copyright (c) 2023
 * 
 */

/**
 * Problem :- 
 *    You are a professional robber planning to rob houses along a street. 
 *    Each house has a certain amount of money stashed. All houses at this place are arranged in a circle. 
 *    That means the first house is the neighbor of the last one. Meanwhile, adjacent houses have a security 
 *    system connected, and it will automatically contact the police if two adjacent houses were broken into on the same night.
      Given an integer array nums representing the amount of money of each house, 
      return the maximum amount of money you can rob tonight without alerting the police.

      Example 1:
        Input: nums = [2,3,2]
        Output: 3
        Explanation: You cannot rob house 1 (money = 2) and then rob house 3 (money = 2), 
                      because they are adjacent houses.
 * 
 */

#include<bits/stdc++.h>
using namespace std;

class ONEDDP{
    private:
    int houserobberRec(int ind,vector<int>&nums){
        if(ind == 0)return nums[0];
        if(ind<0)return 0;
        int ntake = 0+houserobberRec(ind-1,nums);
        int take = nums[ind]+houserobberRec(ind-2,nums);
        return max(take,ntake);
    }
    int houserobberMemo(int ind,vector<int>&nums,vector<int>&dp){
        if(ind == 0)return nums[ind];
        if(ind < 0)return 0;
        if(dp[ind]!=-1)return dp[ind];
        int ntake=0+houserobberMemo(ind-1,nums,dp);
        int take=nums[ind]+houserobberMemo(ind-2,nums,dp);
        return max(take,ntake);
    }

    int houserobberTabu(vector<int>&nums){
        vector<int>dp(nums.size(),-1);
        dp[0]=nums[0];
        for(int i=1;i<nums.size();i++){
           int ntake = dp[i-1];
           int take=nums[i];
           if(i>1){
            take=take+dp[i-2];
           }
           dp[i]=max(take,ntake);
        }
        return dp[nums.size()-1];
    }
    public:
    
    int houseRobberRecursion(int ind,vector<int>&nums){
        vector<int>first;
        vector<int>second;
        int n=nums.size();
        if(n==0)return nums[0];
        for(int i=0;i<n;i++){
            if(i!=0)first.push_back(nums[i]);
            if(i!=n-1)second.push_back(nums[i]);
        }
        return max(houserobberRec(n-2,first),houserobberRec(n-2,second));
    }

    int houseRobberMemoisation(int ind,vector<int>&nums){
        vector<int>first;
        vector<int>second;
        int n=nums.size();
        if(n==0)return nums[0];
        for(int i=0;i<n;i++){
            if(i!=0)first.push_back(nums[i]);
            if(i!=n-1)second.push_back(nums[i]);
        }
        vector<int>dp1(n,-1);
        vector<int>dp2(n,-1);
        return max(houserobberMemo(n-2,first,dp1),houserobberMemo(n-2,second,dp2));
    }

    int houseRobberTabulation(vector<int>&nums){
        vector<int>first;
        vector<int>second;
        int n=nums.size();
        if(n==0)return nums[0];
        for(int i=0;i<n;i++){
            if(i!=0)first.push_back(nums[i]);
            if(i!=n-1)second.push_back(nums[i]);
        }
        return max(houserobberTabu(first),houserobberTabu(second));
    }
};

int main(){
    cout<<"Enter the size of the array "<<endl;
    int n;
    cin>>n;
    vector<int>arr;
    for(int i=0;i<n;i++){
        int data;
        cin>>data;
        arr.push_back(data);
    }
    ONEDDP obj;
    cout<<"Rec "<<obj.houseRobberRecursion(arr.size(),arr)<<endl;
    cout<<"memo "<<obj.houseRobberMemoisation(arr.size(),arr)<<endl;
    cout<<"Tabu "<<obj.houseRobberTabulation(arr)<<endl;
    return 0;
}