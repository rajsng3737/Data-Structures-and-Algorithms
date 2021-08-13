#include<iostream>
using namespace std;

// This Function does the basic Binary Search in the block of array passed to it.
int binarySearch(int ar[],int start,int end,int ele){
    if(start>end)
        return -1;              // if start become greater than end then simply return -1 signifying the value asked is not found in the array
    int mid = (start+end)/2;
    if(ar[mid] == ele)
        return mid;
    else if(ar[mid]>ele)
        return binarySearch(ar,start,mid-1,ele);
    else
        return binarySearch(ar,mid+1,end,ele);
}

// This function iterates in O(logn) to the block of array where Number could be found
int infiniteSearch(int ar[],int n,int ele){
    int i;
    if(ar[0] == ele)
        return 0;
    for(i = 1;i<n;i*=2){
        if(ar[i] == ele)
            return i;
        else if(ar[i]>ele)
            return binarySearch(ar,i/2,i,ele);   
    }
    return binarySearch(ar,i/2,n-1,ele);
}
int main(void){
    int a[] = {10,14,15,16,17,18,19,20,21,22,36,61,74};
    int n = sizeof(a)/sizeof(a[0]);
    cout<<infiniteSearch(a,n,74);           
    return 0;
}