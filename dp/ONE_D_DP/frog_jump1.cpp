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

/**
 * we will solve all the dp problems in 3 steps..
 * 1.try to index the problems if given al right else index it..
 * 2.perform all the application on that index...
 * 3.return whatever is asked either min/max,sum etc..
 */

#include<bits/stdc++.h>
using namespace std;

class ONEDDP{
   public:
   /**
    * @brief 1. this is first solution solved using plain recursion bottom-up approach..
    * Time Complexity :- O(2^n);
    * space Complexity :- O(1);
    * Top-Down solution..
    * @param ind :- it is the index to iterate through out the array ... 
    * @param heights :- it is the cost of the jumping ... giving in array form ..
    * @return int :- return the minimum cost taken to reach at the nth stair..
    */
   int minJumpRecursion(int ind,vector<int>&heights){
      if(ind == 0)return 0;
      int oneStep = INT_MAX;
      int twoStep = INT_MAX;
      oneStep = minJumpRecursion(ind-1,heights)+abs(heights[ind]-heights[ind-1]);
      if(ind>1){
         twoStep=minJumpRecursion(ind-2,heights)+abs(heights[ind]-heights[ind-2]);
      }
      return min(oneStep,twoStep);
   }
   /**
    * @brief memoisation solution because this problem has overlapping subproblems..
    * Time complexity :- O(n);
    * space complexity :- O(n) 
    * Top-Down  solution..
    * @param ind :- it is the index to iterate through out the array ... 
    * @param heights :- it is the cost of the jumping ... giving in array form ..
    * @param dp :- it is an extra 1d array which stores the subproblems results initially 
    *            initialized to -1...
    * @return int :- the minimum of the cost required to reach at nth stairs..
    */
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
   
   /**
    * @brief Tabulation solution.. 
    * T.C :- O(n) 
    * S.C :- O(n);
    * Bottom-Up solution..
    * @param ind index to iterate through the cost array..
    * @param heights cost of jumps ..
    * @return int minimum jump required to reach the top..
    */
   int minJumpTabulation(int ind,vector<int>&heights){
     vector<int>dp(ind,-1);
     dp[0]=0;
     for(int i=1;i<ind;i++){
      int oneStep = dp[i-1] + abs(heights[i]-heights[i-1]);
      int twoStep=INT_MAX;
      if(i>1){
         twoStep = dp[i-2]+abs(heights[i]-heights[i-2]);
      }
      dp[i]=min(oneStep,twoStep);
     }
     return dp[ind-1];
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
//  cout<<obj.minJumpRecursion(n-1,heights)<<endl;
//  cout<<obj.minJumpTabulation(n-1,heights)<<endl;
 return 0;
}