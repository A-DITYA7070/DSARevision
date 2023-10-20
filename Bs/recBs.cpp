#include<bits/stdc++.h>
using namespace std;
/**
 * @brief Recursive implementation of Binary Search...
 * 
 * @param arr  :- arr to store elements...
 * @param low  := starting index initialised to 0..
 * @param high := ending index initalised to arr.size()-1;
 * @param target := ele to find..
 * @return int 
 */
int Bs(vector<int>&arr,int low,int high,int target){
   if(low>high){
     return -1;
   }else{
     int mid=(low+high)/2;
     if(arr[mid] == target){
         return mid;
     }else if(arr[mid]>target){
        return Bs(arr,low,mid-1,target);
     }else{
        return Bs(arr,mid+1,high,target);
     }
   }
}
int main(){
vector<int>arr={1,2,3,34,56,67,86};
cout<<Bs(arr,0,arr.size()-1,343);
return 0;
}