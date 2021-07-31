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
    int ar[] = {10,20,30,40,50,60};
    cout<<search(ar,0,5,60);
    return 0;
}