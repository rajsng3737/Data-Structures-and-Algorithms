#include<iostream>
using namespace std;
void reverse(int *arr, int low, int high){
    int temp;
    for(low; low<high; low++, high--){
        temp = arr[low];
        arr[low] = arr[high];
        arr[high] = temp;
    }
}
int main(){
    int ar[]={10,42,51,13,134,14,14,13,1,451,41,43,52,537,62,4,123};
    int size = sizeof(ar)/sizeof(ar[0]);
    int rotateBy;
    cout<<"Enter No of places to Rotate ";
    cin>>rotateBy;
    reverse(ar,0,rotateBy-1);
    reverse(ar,rotateBy,size-1);
    reverse(ar,0,size-1);
    for(int i = 0; i<size;i++){
        cout<<ar[i]<<" ";
    }
    return 0;
}