#include<iostream>
using namespace std;
int BinarySearch(int *ar,int low,int high,int ele){
    if(low == high){
        if(ar[low] == ele)
            return low;
        return -1;
    }
    else{
        int mid = (low+high)/2;
    if(ar[mid] == ele )
        return mid;
    else if (ar[mid] > ele)
        return BinarySearch(ar,low,mid-1,ele);
    else
        return BinarySearch(ar,mid+1,high,ele);
    }
}
int main(void){
    int ar[] = {10,20,30,40,50,60};
    cout<<BinarySearch(ar,0,sizeof(ar)/sizeof(ar[0]),40);
    return 0;
}