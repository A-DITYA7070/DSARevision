
/**
 * @file ninjaTraining.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-10-22
 * 
 * @copyright Copyright (c) 2023
 * 
 */

/**
 *problem statement :- A Ninja has an ‘N’ Day training schedule. He has to perform one of these 
                       three activities (Running, Fighting Practice, or Learning New Moves) each day. 
                       There are merit points associated with performing an activity each day. 
                       The same activity can’t be performed on two consecutive days. We need to 
                       find the maximum merit points the ninja can attain in N Days.
                       We are given a 2D Array POINTS of size ‘N*3’ which tells us the merit point of 
                       specific activity on that particular day. Our task is to calculate the maximum number 
                       of merit points that the ninja can earn.

 *                     EX :- If the given ‘POINTS’ array is [[1,2,5],[3 ,1 ,1],[3,3,3]],the answer will be 11 as 5 + 3 + 3.
 */

#include<bits/stdc++.h>
using namespace std;

class TWODDP{
    public:
    int NinjaTrainingRec(int ind,int last,vector<vector<int>>&points){
        if(ind == 0){
            int maxi=0;
            for(int i=0;i<3;i++){
                if(i!=last){
                    maxi=max(maxi,points[ind][i]);
                }
            }
            return maxi;
        }
        int maxi = 0;
        for(int i=0;i<3;i++){
            if(i!=last){
                int point=points[ind][i]+NinjaTrainingRec(ind-1,i,points);
                maxi=max(maxi,point);
            }
        }
        return maxi;
    }

    int ninjaTrainingMemo(int ind,int last,vector<vector<int>>&points,vector<vector<int>>&dp){
         if(ind == 0){
        int maxi=0;
        for(int i=0;i<3;i++){
            if(i!=last){
                maxi=max(maxi,points[ind][i]);
            }
        }
        return dp[ind][last]=maxi;
        }
        if(last != 3){
            if(dp[ind][last]!=-1)return dp[ind][last];
        }
        int maxi=0;
        for(int task=0;task<3;task++){
            if(task!=last){
                int point=points[ind][task]+ninjaTrainingMemo(ind-1,task,points,dp);
                maxi=max(maxi,point);
            }
        }
        return dp[ind][last]=maxi;
    }

    int ninjaTrainingTabu(int ind,int last,vector<vector<int>>&points){
       vector<vector<int>>dp(points.size(),vector<int>(4,0));
        dp[0][0] = max(points[0][1], points[0][2]);
        dp[0][1] = max(points[0][0], points[0][2]);
        dp[0][2] = max(points[0][0], points[0][1]);
        dp[0][3] = max(points[0][0], max(points[0][1], points[0][2]));
        for(int day = 1; day < points.size(); day++) {
            for (int last = 0; last < 4; last++) {
                dp[day][last] = 0;
                for (int task = 0; task <= 2; task++) {
                    if (task != last){
                       int activity = points[day][task] + dp[day - 1][task];
                       dp[day][last] = max(dp[day][last], activity);
                    }
                }
            }
        }
       return dp[points.size()-1][3];
    }

};
int main(){
  vector<vector<int>> points = {{10, 40, 70},
                                 {20, 50, 80},
                                 {30, 60, 90}};
int n = points.size(); 
TWODDP obj;
cout << obj.NinjaTrainingRec(n-1,3,points)<<endl;
cout<<obj.ninjaTrainingTabu(n,3,points)<<endl;
vector<vector<int>>dp(n,vector<int>(3,-1));
cout<<obj.ninjaTrainingMemo(n-1,3,points,dp)<<endl;
return 0;
}