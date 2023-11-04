/**
 * @file fractionalKnapsack.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-11-04
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include<bits/stdc++.h>
using namespace std;
class DP{
    private:
    int memoImplement(int ind,int bag,vector<int>&wt,vector<int>&arr,vector<vector<int>>&dp){
        if(ind == 0){
            if(wt[0]<=bag){
                return arr[0];
            }
            return 0;
        }
        if(dp[ind][bag]!=-1)return dp[ind][bag];
        int ntake=memoImplement(ind-1,bag,wt,arr,dp);
        int take=INT_MIN;
        if(wt[ind]<=bag){
            take=arr[ind]+memoImplement(ind-1,bag-wt[ind],wt,arr,dp);
        }
        return dp[ind][bag]=max(take,ntake);
    }
    public:
    int fKanpRecursion(int ind,int bag,vector<int>&wt,vector<int>&arr){
        if(ind == 0){
           if(wt[0]<=bag){
             return arr[0];
           }
           return 0;
        }
        int ntake=fKanpRecursion(ind-1,bag,wt,arr);
        int take=INT_MIN;
        if(wt[ind]<=bag){
            take=arr[ind]+fKanpRecursion(ind-1,bag-wt[ind],wt,arr);
        }
        return max(take,ntake);
    }
    int memoIsationSolution(int n,int bag,vector<int>&wt,vector<int>&arr){
        vector<vector<int>>dp(n,vector<int>(bag+1,-1));
        return memoImplement(n-1,bag,wt,arr,dp);
    }
};
int main(){
DP obj;
int n;
cout<<"Enter the size of the array "<<endl;
cin>>n;
vector<int>arr;
vector<int>wt;
cout<<"Enter the value of the items "<<endl;
for(int i=0;i<n;i++){
   int x;
   cin>>x;
   arr.push_back(x);
}
cout<<"Enter the wt of the items "<<endl;
for(int i=0;i<n;i++){
    int x;
    cin>>x;
    wt.push_back(x);
}
int bag;
cout<<"Enter the capacity of the bag "<<endl;
cin>>bag;
cout<<"max amount the theif can rob is "<<obj.fKanpRecursion(n-1,bag,wt,arr)<<endl;
cout<<"Memoisation solution "<<obj.memoIsationSolution(n-1,bag,wt,arr)<<endl;
return 0;
}