#include<iostream>
using namespace std;
void mergeAlgo(int *a, int *b, int i, int mid, int afterMid, int j){
    int k = i;
    while( i <= mid && afterMid <= j)
    {
        if(a[i] < a[afterMid]){
            b[k]=a[i];
            i++;
        }
        else{
            b[k] = a[afterMid];
            afterMid++;
        }
        k++;
    }
    while(i<=mid){
        b[k] = a[i];
        k++;
        i++;
    }
    while(afterMid <= j){
        b[k] = a[afterMid];
        k++;
        afterMid++;
    }
}
void mergeSort(int *a, int *b, int i, int j){
    if ( i == j)
        return;
    else{
        int mid = (i+j)/2;
        mergeSort(a, b, i, mid);
        mergeSort(a, b, mid+1, j);
        mergeAlgo(a, b, i, mid, mid+1, j);
        for(i;i<=j;i++)         //TO STORE SORTED ARRAY BACK IN a[], other wise in next MergeAlgo call we won't have sorted array as input
            a[i]=b[i];                            
    }
}


int main(){
    int ar[] = {31, 41, 59, 26, 32, 12, 58};
    int size = sizeof(ar)/sizeof(ar[0]);
    int br[size];
    mergeSort(ar,br,0,size-1);
    for(int i = 0;i<size;i++)
        cout<<ar[i]<<" ";
}