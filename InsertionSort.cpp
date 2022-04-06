#include<iostream>
using namespace std;
int main(){
    int ar[]={31, 41, 59, 26, 41, 58};
    int size = sizeof(ar)/sizeof(ar[0]);
    int key,j;
    for(int i = 1; i<size; i++){
        key = ar[i];
        j = i - 1;
        while(j>=0 && ar[j]<key){
            ar[j+1] = ar[j];
            j = j-1;
        }
        ar[j+1] = key;
    }
    for (int i = 0;i<size;i++)
        cout<<ar[i]<<" ";
    return 0;
}