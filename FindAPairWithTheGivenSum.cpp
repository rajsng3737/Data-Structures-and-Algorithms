//the following code works for only sorted array
#include<iostream>
using namespace std;
int firstIndex = -1,secondIndex = -1;
int getPair(int ar[],int size,int sum){
    for(int i = 0,j= size-1;i<j;){
        if(ar[i]+ar[j] > sum)
            j--;
        else if(ar[i]+ar[j] < sum)
            i++;
        else 
            {
                firstIndex = i;
                secondIndex = j;
                return 1;
            }
    }
    return -1;
}
int main(){
    int ar[] = {10,13,19,20,26,33,47,55,58,61}, sum;
    int size = sizeof(ar)/sizeof(ar[0]);
    cin>>sum;
    int what = getPair(ar,size,sum);
    if(what)
        cout<<firstIndex<<" "<<secondIndex;
    else
        cout<<"Not Found";
}