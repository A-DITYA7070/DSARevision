#include<bits/stdc++.h>
using namespace std;
/**
 * @brief Lower Bound means the smallest ind i such that arr[i]>=x;
 * 
 * @param arr  :- stores the elements
 * @param x    :- value to find the lower index of..
 * @return int 
 */
// Iterative solution...
int LB(vector<int>&arr,int x){
   int s=0;
   int e=arr.size()-1;
   int ans=0;
   while(s<=e){
     int mid=(s+e)/2;
     if(arr[mid] >= x){
         ans=mid;
         e=mid-1;
     }else{
        s=mid+1;
     }
   }
   return ans;
}

// rec implementation..

void LBR(vector<int>&arr,int x,int s,int e,int &ans){
    if(s>e){
        return;
    }else{
        int mid=(s+e)/2;
        if(arr[mid]>=x){
            ans=mid;
            LBR(arr,x,s,mid-1,ans);
        }else{
            LBR(arr,x,mid+1,e,ans);
        }
    }
}
int main(){
vector<int>arr={3,6,8,15,19};
int ans=0;
LBR(arr,8,0,arr.size()-1,ans);
cout<<ans<<endl;
return 0;
}