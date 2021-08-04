#include<iostream>
using namespace std;
int search(int ar[],int low,int high,int ele){
    if( low > high){
        return -1;
    }
    int mid = (low+high)/2;
    if(ar[mid] < ele)
        return search(ar,mid+1,high,ele);
    else if(ar[mid] > ele)
        return search(ar,low,mid-1,ele);
    else{
        if(mid != high && ar[mid+1] == ele)
            return search(ar,mid+1,high,ele);
        else
            return mid;
    }
}
int main(void){
    int ar[] = {1, 3, 5, 5, 5, 5, 67, 123, 125};
    int index = search(ar,0,8,5);
    cout<<index;
    return 0;
}