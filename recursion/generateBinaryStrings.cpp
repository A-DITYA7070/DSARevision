/**
 * @file generateBinaryStrings.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-11-07
 * 
 * @copyright Copyright (c) 2023
 * 
 */

/**
 * Generate all binary strings of the given length given that strings should not have two consecutive 1..
 * and ans should be sorted in lexographical order..
 * 
 */
#include<bits/stdc++.h>
using namespace std;
void solve(int ind,int prev,string st,vector<string>&ans){
    if(ind<0){
        ans.push_back(st);
        return;
    }
    solve(ind-1,0,st+"0",ans);
    if(prev!=1){
        solve(ind-1,1,st+"1",ans);
    }
}
int main(){
int n;
cout<<"Enter the len of the string to be generated "<<endl;
cin>>n;
vector<string>ans;
solve(n-1,0,"",ans);
cout<<"Generated Binary strings "<<endl;
for(auto it:ans){
    cout<<it<<" ";
}
return 0;
}