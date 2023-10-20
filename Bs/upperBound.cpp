#include<bits/stdc++.h>
using namespace std;
/**
 * @brief upper Bound means :- index i such that arr[index]>x;
 * in short upper_bound func in cpp can gives you upper bound..
 * up = upper_bound(arr.begin(),arr.end(),x);
 * @return int 
 */

int upper_bound(vector<int>&arr,int x){
    int s=0;
    int e=arr.size()-1;
    int ans=0;
    while(s<=e){
        int mid=(s+e)/2;
        if(arr[mid]>x){
            ans=mid;
            e=mid-1;
        }else{
            s=mid+1;
        }
    }
    return ans;
}

// recursive algo...

void Upper_Bound(vector<int>&arr,int s,int e,int x,int &ans){
    if(s>e){
        return;
    }else{
        int mid=(s+e)/2;
        if(arr[mid]>x){
            ans=mid;
            Upper_Bound(arr,s,mid-1,x,ans);
        }else{
            Upper_Bound(arr,mid+1,e,x,ans);
        }
    }
}

int main(){
vector<int>arr={1,2,3,5,6,78};
cout<<upper_bound(arr,5)<<endl;
int ans=0;
Upper_Bound(arr,0,arr.size()-1,5,ans);
cout<<ans<<endl;
return 0;
}