#include<iostream>
using namespace std;
int getFirstOne(int ar[],int low,int high){
    int mid = (low+high)/2;
    if( ar[mid] != 0)
        {
            if(ar[mid-1] == 1)
                return getFirstOne(ar,low,mid-1);
            else
                return mid;
        }
    else{
        if(ar[mid+1] == 0 )
            return getFirstOne(ar,low,mid+1);
        else
            return mid+1;
    }  
}
int main(void){
    int ar[] = {0,0,1,1,1,1,1,1,1,1,1,1};
    int size = sizeof(ar)/sizeof(ar[0]);
    if(ar[size-1] != 0)
        cout<<size-getFirstOne(ar,0,size-2);
    else
        cout<<"Only Zeroes\n";
    return 0;
}