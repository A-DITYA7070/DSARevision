#include<bits/stdc++.h>
using namespace std;
int Bs(int *arr,int n,int key){
    int i=0;
    int j=n-1;
    while(i<=j){
        int mid=(i+j)/2;
        if(arr[mid]==key){
            return mid;
        }else if(arr[mid]>key){
            j=mid-1;
        }else{
            i=mid+1;
        }
    }
    return -1;
}
int main(){
cout<<"Enter the size of the array "<<endl;
int n;
cin>>n;
int *arr=new int[n];
for(int i=0;i<n;i++){
    cin>>arr[i];
}
int key;
cin>>key;
cout<<Bs(arr,n,key);
return 0;
}