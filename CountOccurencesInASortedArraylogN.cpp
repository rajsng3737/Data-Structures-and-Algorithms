#include<iostream>
using namespace std;
int firstOc(int ar[],int low,int high,int ele){
    if( low > high){
        return -1;
    }
    int mid = (low+high)/2;
    if(ar[mid] < ele)
        return firstOc(ar,mid+1,high,ele);
    else if(ar[mid] > ele)
        return firstOc(ar,low,mid-1,ele);
    else{
        if(mid != 0 && ar[mid-1] == ele)
            return firstOc(ar,low,mid-1,ele);
        else
            return mid;
    }
}
int lastOc(int ar[],int low,int high,int ele){
    if( low > high){
        return -1;
    }
    int mid = (low+high)/2;
    if(ar[mid] < ele)
        return lastOc(ar,mid+1,high,ele);
    else if(ar[mid] > ele)
        return lastOc(ar,low,mid-1,ele);
    else{
        if(mid != high && ar[mid+1] == ele)
            return lastOc(ar,mid+1,high,ele);
        else
            return mid;
    }
}
int main(void){
    int ar[] = {3,4,5,6};
    int index =  firstOc(ar,0,4,3);
    if(index == -1)
        {
            cout<<index;
            return 0;
        }
    else
        cout<<(lastOc(ar,0,3,3)-(index-1));
    return 0;
}