#include<iostream>
using namespace std;
double search(double a,double i,double j){
    double mid = (i+j)/2;
    double product = mid*mid;
    if(product == a || abs(product-a)<0.00001)
        return mid;
    else if(product< a)
        return search(a,mid,j);
    else
        return search(a,i,mid);
}
int main(void){
    int a;
    cin>>a;
    if(a<=0)
        cout<<"Positive Only\n";
    else{
        bool val = false;
       for(int i = 1;!val;i++){
           if(i*i == a){
               cout<<i<<"\n";
               val = true;
           }
            else if(i*i > a){
                cout<<search(a,i-1,i);
                val = true;
            }
       }
    }
}