#include<iostream>
using namespace std;
int find(int ar[], int low, int high, int ele){
    int mid = (low+high)/2;
    if(low > high)
        return -1;
    if(ar[mid] == ele)
        return mid;
    if(ar[mid] > ar[low]){
        if(ele >= ar[low] && ele <= ar[mid])
            return find(ar,low,mid-1,ele);
        else
            return find(ar,mid+1,high,ele);
    }
    else{
        if(ele >= ar[mid] && ele <= ar[high])
            return find(ar,mid+1,high,ele);
        else
            return find(ar,low,mid-1,ele);
    }
}
int main(void){
    int ar[] = {20,30,40,50,60,10};
    int arSize = sizeof(ar)/sizeof(ar[0]);
    cout<<find(ar,0,arSize-1,10);
    return 0;
}