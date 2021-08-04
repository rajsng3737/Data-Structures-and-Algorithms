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
        if(mid != 0 && ar[mid-1] == ele)
            return search(ar,low,mid-1,ele);
        else
            return mid;
    }
}
int main(void){
    int ar[] = {1,2,3,3,3,3,3,3,3,3,3,3,3,4};
    int index = search(ar,0,14,3);
    cout<<index;
    return 0;
}