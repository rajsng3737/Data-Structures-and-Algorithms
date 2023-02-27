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
    int ar[] = {10,20,30,40,50,50,70};
    int index = search(ar,0,sizeof(ar)/sizeof(ar[0]),50);
    int count = 0; 
    //checking in the left of found element
    for(int i = index;i>=0;i--){            //started from index as count is initialized with 0
        if(ar[i]!=ar[index])
            break;
        count++;
    }
    //checking in the right of found element
    for(int i = index+1;i<=6;i++){      //started with index+1 as previous index has already been traversed in upper loop
        if(ar[i]!=ar[index])
            break;
        count++;
    }
    cout<<count;        //total count 
    return 0;
}