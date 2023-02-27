#include<iostream>
using namespace std;
int DACpow(int a,int n){
    if(n == 1)
        return a;
    else
    {
        int mid = n/2;
        int tempResult;
        if(n%2 == 0)
            {
                tempResult = DACpow(a,mid);
                return tempResult*tempResult;
            }
        else
            {
                tempResult = DACpow(a,mid);
                return tempResult*tempResult*a;
            }
    }
}
int main(){
    int a,n;
    cout<<"Enter Number then it's power(>0)\n";
    cin>>a>>n;
    int res = DACpow(a,n);
    cout<<res;
   return 0; 
}