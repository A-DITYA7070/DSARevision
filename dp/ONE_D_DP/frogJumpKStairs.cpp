/**
 * @file frogJumpKStairs.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-10-21
 * 
 * @copyright Copyright (c) 2023
 * 
 */

/**
 *  Problem Statement:  Frog Jump with K Distance/ Learn to write 1D DP
    Problem Statement:
        This is a follow-up question to “Frog Jump” discussed in the previous article. 
        In the previous question, the frog was allowed to jump either one or two steps at a time. 
        In this question, the frog is allowed to jump up to ‘K’ steps at a time. If K=4, the frog can jump 1,2,3, or 4 steps 
        at every index.
        Ex : - input  :- cost={30,10,60,10,60,50}
                         k=2;
               output :- 40
 * 
 */

#include<bits/stdc++.h>
using namespace std;

class ONEDDP{
    public:

    /**
     * function to implement the k ways frog jump in plain recursion..
     * T.C :- O(2^n);
     * S.C :- O(1);
     */
    int minStepsRec(int ind,int k,vector<int>&heights){
       if(ind == 0)return 0;
       int mmSteps = INT_MAX;
       for(int i=1;i<=k;i++){
          if(ind-i >= 0){
             int cost = abs(heights[ind]-heights[ind-i]) + minStepsRec(ind-i,k,heights);
             mmSteps = min(mmSteps,cost);
          }
       }
       return mmSteps;
    }
    
    /**
     * since there is overlapping subproblems hence we can memoise it.. to get better time complexity..
     * function to memoise the above recursion solution ...
     * T.C :- O(n*k);
     * S.C :- O(n);
     */
    int minStepsMemoisation(int ind,int k,vector<int>&heights,vector<int>&dp){
        if(ind == 0){
            return 0;
        }
        if(dp[ind]!=-1)return dp[ind];
        int mmSteps = INT_MAX;
        for(int i=1;i<=k;i++){
            if(ind-i >= 0){
                int cost = abs(heights[ind]-heights[ind-i])+minStepsMemoisation(ind-i,k,heights,dp);
                mmSteps=min(cost,mmSteps);
            }
        }
        dp[ind]=mmSteps;
        return dp[ind];
    }
    
    /**
     * Tabulation solution (iterative solution of above problem) 
     * T.C = O(N*k);
     * S.C = O(n);
     */
    int miStepsTabulation(int ind,int k,vector<int>&heights){
        vector<int>dp(ind,0);
        dp[0]=0;
        for(int i=1;i<ind;i++){
            int mmStepsCost = INT_MAX;
            for(int j=1;j<=k;j++){
                if(i-j >= 0){
                    int cost = dp[i-j]+abs(heights[i]-heights[i-j]);
                    mmStepsCost=min(mmStepsCost,cost);
                }
            }
            dp[i]=mmStepsCost;
        }
        return dp[ind-1];
    }
};

int main(){
    int n;
    cout<<"Enter the size of the array "<<endl;
    cin>>n;
    vector<int>heights;
    cout<<"Enter the cost of the jumps "<<endl;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        heights.push_back(x);
    }
    ONEDDP obj;
    int k;
    cout<<"Enter the value of k means atmost how many steps frog can jump .. "<<endl;
    cin>>k;
    cout<<"min cost to reach the top after k ways jump "<<obj.minStepsRec(n-1,k,heights)<<endl;
    vector<int>dp(n+1,-1);
    cout<<"Min no to reach memo solution "<<obj.minStepsMemoisation(n-1,k,heights,dp)<<endl;
    cout<<"Min cost to reach tabu solution "<<obj.miStepsTabulation(n,k,heights);
    return 0;
}