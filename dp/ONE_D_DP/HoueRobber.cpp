/**
 * @file HoueRobber.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-10-21
 * 
 * @copyright Copyright (c) 2023
 * 
 */

/**
 * Problem StateMent :- You are a professional robber planning to rob houses along a street. 
 *                      Each house has a certain amount of money stashed, the only constraint 
 *                      stopping you from robbing each of them is that adjacent houses have security 
 *                      systems connected and it will automatically contact the police if two adjacent 
 *                      houses were broken into on the same night.
                        Given an integer array nums representing the amount of money of each house, 
                        return the maximum amount of money you can rob tonight without alerting the police.
                        Example :
                            Input: nums = [1,2,3,1]
                            Output: 4
                            Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
                            Total amount you can rob = 1 + 3 = 4.
 * 
 */

/**
 * Intution :- solve on the basis of take and not take...
 */

#include<bits/stdc++.h>
using namespace std;

class ONEDDP{
    public:

    /**
     * Recursion imple of max Amount theif can rob..
     * T.c :- O(2^n);
     * S.C :- O(1);
     */
    int maxAmountRec(int ind,vector<int>&nums){
        if(ind == 0){
            return nums[ind];
        }
        int ntake = maxAmountRec(ind-1,nums);
        int take = INT_MIN;
        if(ind>1){
            take = nums[ind]+maxAmountRec(ind-2,nums);
        }
        return max(take,ntake);
    }
    
    /**
     *Memoisation solution since the problem has overlapping sub problems hence we can memoise it
      T.c : - O(n);
      S.c :- O(n);
     */
    int maxAmountMemo(int ind,vector<int>&num,vector<int>&dp){
        if(ind == 0)return num[ind];
        if(dp[ind] != -1)return dp[ind];
        int ntake = maxAmountMemo(ind-1,num,dp);
        int take=INT_MIN;
        if(ind>1){
            take = num[ind]+maxAmountMemo(ind-2,num,dp);
        }
        return dp[ind]=max(take,ntake);
    }
    
    /**
     * Tabulation solution of above problem .
     * T.c :- O(n);
     * S.c :- O(n); 
     */
    int maxAmountTabu(int ind,vector<int>&nums){
        vector<int>dp(ind,0);
        dp[0]=nums[0];
        for(int i=1;i<ind;i++){
            int ntake = dp[i-1];
            int take = INT_MIN;
            if(i>1){
                take = nums[i]+dp[i-2];
            }
            dp[i]=max(take,ntake);
        }
        return dp[ind-1];
    }
};

int main(){
    int n;
    cout<<"Enter the size of the houses "<<endl;
    cin>>n;
    vector<int>nums;
    cout<<"Enter the amount in houses "<<endl;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        nums.push_back(x);
    }
    ONEDDP obj;
    cout<<"Rec solution "<<obj.maxAmountRec(n-1,nums)<<endl;
    vector<int>dp(n+1,-1);
    cout<<"Memo solution "<<obj.maxAmountMemo(n-1,nums,dp)<<endl;
    cout<<"Tabu solution "<<obj.maxAmountTabu(n-1,nums);
    return 0;
}