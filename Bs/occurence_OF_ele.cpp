#include<bits/stdc++.h>
using namespace std;

/**
 * @brief we will find the occurance of ele in a sorted array 
 * 
 * @return pair<int,int> first and last occurance of ele in an array 
 */

// Bruteforce.. T.c = o(n) s.c = o(1)

pair<int,int> firstAndLastOcuu(vector<int>&arr,int x){
    pair<int,int>ans;
    int first=-1;
    int last=-1;
    for(int i=0;i<arr.size();i++){
        if(arr[i] == x){
            if(first == -1){
                first = i;
            }
            last=i;
        }
    }
    ans.first=first;
    ans.second=last;
    return ans;
}

// efficient algorithm... we can also solve using lower_bound and upper_bound concept...

// pair<int,int> Ocuurences(vector<int>&arr,int x){

//     auto it=lower_bound(arr.begin(),arr.end(),x);
//     auto it2=upper_bound(arr.begin(),arr.end(),x);
//     cout<<*it<<" "<<*it2<<endl;
//     if(arr[*it] != x || *it2 >= arr.size()){
//         return {-1,-1};
//     }else{
//         return {*it,*it2-1};
//     }
// }

// using binary search...

int FO(vector<int>&arr,int x){
    int low=0;
    int first=-1;
    int high=arr.size()-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(arr[mid] == x){
            first=mid;
            high=mid-1;
        }else if(arr[mid]>x){
           high=mid-1;
        }else{
            low=mid+1;
        }
    }
    return first;
}

int LO(vector<int>&arr,int x){
    int sec=-1;
    int low=0;
    int high=arr.size()-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(arr[mid] == x){
            sec=mid;
            low=mid+1;
        }else if(arr[mid]>x){
            high=mid-1;
        }else{
            low=mid+1;
        }
    }
    return sec;
}

int main(){
vector<int>arr={1,2,3,8,8,8,8,9,78};
pair<int,int>ans=firstAndLastOcuu(arr,8);
cout<<ans.first<<" "<<ans.second<<endl;
int first=FO(arr,9);
int sec=LO(arr,9);
cout<<first<<" "<<sec<<endl;
return 0;
}