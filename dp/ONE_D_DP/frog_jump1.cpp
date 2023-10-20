/**
 * @file frog_jump1.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-10-20
 * 
 * @copyright Copyright Aditya raj 2023
 * 
 * problem statement 1.=:- 
    There is a frog on the 1st step of an 'N' stairs long staircase. 
    The frog wants to reach the 'Nth' stair HEIGHT is the height of the (1+1)th' stair 
    If Frog jumps from 'ith' to jth' stair, the energy lost in the jump is given by absolute value of (HEIGHT 11 HEIGHT 1] ) 
    If the Frog is on ith' staircase he can jump either to (+1)th stair or to (1+2)th stair 
    Your task is to find the minimum total energy used by the frog to reach from 1st stair to 'Nth' stair For Example
    If the given 'HEIGHT array is [10,20,30,10], the answer 20 as the frog can jump from 
    1st stair to 2nd stain (120-101 10 energy lost) and then a jump from 2nd stair to last stair (11e 201 10 energy lost) So, 
    the total energy lost is 20
    ex-2
    8
    7 4 4 2 6 6 3 4 
    ans :- 7
 * 
 */

#include<bits/stdc++.h>
using namespace std;

class ONEDDP{
   public:
   int minJumps(int ind,vector<int>&heights,vector<int>&dp){
      if(ind == 0){
        return 0;
      }
      if(dp[ind]!=-1)return dp[ind];
      int oneStep=INT_MAX;
      int twoStep=INT_MAX;
      oneStep = minJumps(ind-1,heights,dp)+abs(heights[ind]-heights[ind-1]);
      if(ind>1){
        twoStep = minJumps(ind-2,heights,dp)+abs(heights[ind]-heights[ind-2]);
      }
      return dp[ind]=min(oneStep,twoStep);
   }
};

int main(){
 int n;
 cout<<"Enter the size of the array "<<endl;
 cin>>n;   
 vector<int>heights;
 cout<<"Enter the cost of jumping "<<endl;
 for(int i=0;i<n;i++){
    int x;cin>>x;
    heights.push_back(x);
 }
 vector<int>dp(n+1,-1);
 ONEDDP obj;
 int ans = obj.minJumps(n-1,heights,dp);
 cout<<"The minimum jumps required to reach in less Energy is "<<ans<<endl;
 return 0;
}