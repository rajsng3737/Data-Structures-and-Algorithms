#include<iostream>
using namespace std;
int main()
{
    int ar[]={10,42,51,13,5,1,451,41,43,52,537,62,1,600};
    int size = sizeof(ar)/sizeof(ar[0]);
    int maxDif = INT_MIN;
    int mArray[size];
    mArray[0] = ar[0];
    for(int i = 1;i<size;i++)
        mArray[i] = min(mArray[i-1],ar[i]);
    int i = size-1, j = size-1;
    while(i>=0 && j>=0){
        if( mArray[i]<= ar[j]){
            maxDif = max(maxDif,j-i);
            i--;
        }
        else
            j--;
    }
    cout<<maxDif;
    return 0;
}