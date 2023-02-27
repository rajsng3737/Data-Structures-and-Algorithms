#include<iostream>
using namespace std;
pair<int,int> DACmaxmin(int ar[], int i, int j){
    int max,min;
    if(i==j)
    {
        max = min = ar[i];
        return pair<int,int> (max,min);
    }
    else if(i+1 == j)
    {
        if(ar[i]>=ar[j])
        {
            max = ar[i];
            min = ar[j];
        }
        else
        {
            max = ar[j];
            min = ar[i];
        }
        return pair<int,int> (max,min);
    }
    else{
        int mid = (i+j)/2;
        pair<int,int> max1min1 = DACmaxmin(ar,i,mid);
        pair<int,int> max2min2 = DACmaxmin(ar,mid+1,j);
        if(max1min1.first >= max2min2.first)
            max = max1min1.first;
        else
            max = max2min2.first;
        if(max1min1.second <= max2min2.second)
            min = max1min1.second;
        else
            min = max2min2.second;
    }
    return pair<int,int> (max,min);
}
int main()
{
    int ar[] = {31, 41, 59, 59, 26, 41, 59, 58};
    int size = sizeof(ar)/sizeof(ar[0]);
    pair<int,int> maxmin = DACmaxmin(ar,0,size-1);
    cout<<maxmin.first<<" "<<maxmin.second;
    return 0;
}