/*In an unsorted Array,any element is peak element if it's neighour's are smaller than itself.*/
#include<iostream>
using namespace std;
int peak( int ar[], int low, int high ,int n){
    int mid = (low+high)/2;
    if( (mid == 0 && ar[mid+1]<ar[mid]) || (mid == n && ar[mid-1]<ar[mid]))
        return mid;
    if(ar[mid]>=ar[mid-1] && ar[mid]>=ar[mid+1])
        return mid;
    else if( ar[mid+1]>ar[mid])
        return peak(ar,mid+1,high,n);
    else
        return peak( ar,low,mid-1,n);
}
int main(){
    int ar[] = {10,20,15,5,23,65,67};
    int size = sizeof(ar)/sizeof(ar[0]);
    cout<<peak(ar,0,size-1,size-1);
}