#include<bits/stdc++.h>
using namespace std;
/**
 * @brief key point :- identify the sorted half eliminate unsorted part...
 * 
 * @return int (index of the found ele if not found -1);
 */

int solve(vector<int>&arr,int x){
    int low=0;
    int high=arr.size()-1;
    while(low <= high){
        int mid=(low+high)/2;
        if(arr[mid]==x){
            return mid;
        }
        // if tar lies on the left part of the mid...
        if(arr[low]<=arr[mid]){
            if(arr[low]<=x && x<=arr[mid]){
                high=mid-1;
            }else{
                low=mid+1;
            }
        }else{
            // if tar lies on the right part of the mid...
            if(arr[mid]<=x && x<=arr[high]){
                low=mid+1;
            }else{
                high=mid-1;
            }
        }
    }
    return -1;
}
int main(){
vector<int>arr={7,8,9,1,2,3,4,5,6};
cout<<solve(arr,1);
return 0;
}