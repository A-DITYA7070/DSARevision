/**
 * @file unboundecKnapsack.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-11-06
 * 
 * @copyright Copyright (c) 2023
 * 
 */

/**
 * problem statement :- A thief wants to rob a store. He is carrying a bag of capacity W. 
 *                      The store has ‘n’ items of infinite supply. Its weight is given by the ‘wt’ array 
 *                      and its value by the ‘val’ array. He can either include an item in its knapsack or exclude 
 *                      it but can’t partially have it as a fraction. We need to find the maximum value of items that 
 *                      the thief can steal. He can take a single item any number of times he wants and put it in his knapsack.
 * 
 * 
 */
#include<bits/stdc++.h>
using namespace std;
class DP{
    private:
    int memoisation(int ind,int wt,vector<int>&profits,vector<int>&weights,vector<vector<int>>&dp){
        if(ind == 0){
            return (wt/weights[ind])*profits[ind];
        }
        if(dp[ind][wt]!=-1)return dp[ind][wt];
        int ntake = memoisation(ind-1,wt,profits,weights,dp);
        int take = -1e9;
        if(weights[ind]<=wt){
            take = profits[ind] + memoisation(ind,wt-weights[ind],profits,weights,dp);
        }
        return dp[ind][wt]=max(take,ntake);
    }
    public:
    int recursionSolution(int ind,int wt,vector<int>&profits,vector<int>&weights){
        if(ind == 0){
            return (wt/weights[0])*profits[0];
        }
        int ntake = recursionSolution(ind-1,wt,profits,weights);
        int take = -1e9;
        if(weights[ind]<=wt){
            take = profits[ind] + recursionSolution(ind,wt-weights[ind],profits,weights);
        }
        return max(take,ntake);
    }
    int memoisationImplementation(int n,int wt,vector<int>&weights,vector<int>&profits){
        vector<vector<int>>dp(n,vector<int>(wt+1,-1));
        return memoisation(n-1,wt,profits,weights,dp);
    }
};
int main(){
int n;
cout<<"Enter the size of weights and profits "<<endl;
cin>>n;
vector<int>weights;
vector<int>profits;
cout<<"Enter the weights "<<endl;
for(int i=0;i<n;i++){
    int x;
    cin>>x;
    weights.push_back(x);
}
cout<<"enter the profits "<<endl;
for(int i=0;i<n;i++){
    int x;
    cin>>x;
    profits.push_back(x);
}
int wt;
cout<<"Enter the size of the bag "<<endl;
cin>>wt;
DP obj;
cout<<"Recursion solution "<<obj.recursionSolution(n-1,wt,profits,weights)<<endl;
cout<<"Memoisation solution "<<obj.memoisationImplementation(n,wt,weights,profits)<<endl;
return 0;
}