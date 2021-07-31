#include<iostream>
using namespace std;
int search(int ar[],int low,int high,int ele){
    if(ele < ar[low] || ele > ar[high])
        return -1;
    if(low+1 == high){
        if(ar[low] == ele)
            return low;
        if(ar[high] == ele)
            return high;
        return -1;
    }
    if(ar[(low+high)/2] < ele)
        return search(ar,(low+high)/2,high,ele);
    else if(ar[(low+high)/2] > ele)
        return search(ar,low,(low+high)/2,ele);
    else
        return (low+high)/2;
}
int main(void){
    int ar[] = {10};
    int index = search(ar,0,0,20);
    int i;
    for(i = index-1; i>=0; i--){
        if(ar[i] != ar[index] )
            break;
    }
    cout<<i+1;
    return 0;
}