#include<bits/stdc++.h>
using namespace std;
class ONEDDP{
    public:
    /**
     * @brief simple recursion solution same as fibonacci series..
     * t.c=o(2^n);
     * s.c=o(1);
     * top-down..
     * @param ind no of stairs..
     * @return int no of steps to climb stairs..
     */
    int solveRecursion(int ind){
        if(ind<=2)return ind;
        int oneStep = solveRecursion(ind-1);
        int twoStep = solveRecursion(ind-2);
        return oneStep+twoStep;
    }
    
    /**
     * @brief since the problem has overlapping subproblem hence we can use memoisation..
     * using memoisation will reduce the t.c ..
     * t.c=O(n);
     * s.c=O(n);
     * @param ind no of stairs.
     * @param dp stores the overlapping results..
     * @return int no of steps to climb stairs..
     */
    int solveMemoisation(int ind,vector<int>&dp){
        if(ind<=2)return ind;
        if(dp[ind]!=-1)return dp[ind];
        int oneStep = solveMemoisation(ind-1,dp);
        int twoStep=solveMemoisation(ind-2,dp);
        return dp[ind]=oneStep+twoStep;
    }
    /**
     * @brief tabulation solution iterative solution it reduces extra stack space used in recursion in memoisation solution
     * T.c=O(n);
     * s.c=O(n);
     * Bottom-up solution
     * @param ind :- no of stairs..
     * @return int :- returns the total steps required to reach the top...
     */
    int solveTabulation(int ind){
        vector<int>dp(ind,-1);
        dp[0]=1;
        dp[1]=1;
        for(int i=2;i<=ind;i++){
          dp[i]=dp[i-1]+dp[i-2];
        }
        return dp[ind];
    }

};
int main(){
int n;
cout<<"Enter the total stairs "<<endl;
cin>>n;
ONEDDP obj;
// cout<<obj.solveRecursion(n)<<endl;
vector<int>dp(n+1,-1);
// cout<<obj.solveMemoisation(n,dp)<<endl;
cout<<obj.solveTabulation(n)<<endl;
return 0;
}