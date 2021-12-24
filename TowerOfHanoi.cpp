#include<iostream>
using namespace std;
 void towerOfHanoi(string s, string a, string t, int n){
    if( n == 1){
        cout<<(s+" to "+t)<<endl;
        return;
    }
    towerOfHanoi(s,t,a,n-1);
    cout<<(s+" to "+t)<<endl;
    towerOfHanoi(a,s,t,n-1);
 }
 int main(){
    int a;
    cout<<"Enter Number Of Disks\n";
    cin>>a;
    towerOfHanoi("source","auxilary","target",a);
 }