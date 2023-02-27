#include<iostream>
using namespace std;
int buildHeap(int *ar, int size)
{
    int internalNodes = (size/2)-1;
    while(internalNodes >= 0)
    {
        int temp = internalNodes;
        while( (temp*2) + 1 <= size-1 && (temp*2) + 2 <= size)
        {
            if( (temp*2)+2 == size)
            {
                if( ar[temp*2+1] < ar[temp] ){
                    swap(ar[temp*2+1],ar[temp]);
                    temp = temp*2+1;
                }
                else break;
            }
            else if(ar[temp*2+1] < ar[temp] || ar[temp*2+2] < ar[temp])
            {
                if(ar[temp*2+1] <= ar[temp*2+2])
                    {
                        swap(ar[temp*2+1],ar[temp]);
                        temp = temp*2+1;
                    }
                else
                    {
                        swap(ar[temp*2+2],ar[temp]);
                        temp = temp*2+2;
                    }
            }
            else break;
        }
        internalNodes--;
        
    }
    return 0;
}
int heapify(int *ar,int size,int temp)
{
    while( (temp*2) + 1 <= size-1 && (temp*2) + 2 <= size)
        {
            if( (temp*2)+2 == size)
            {    if(ar[temp*2+1] < ar[temp] )
                {
                    swap(ar[temp*2+1], ar[temp]);
                    temp = temp*2+1;
                }
                else break;
            } 
            else if(ar[temp*2+1] < ar[temp] || ar[temp*2+2] < ar[temp])
            {
                if(ar[temp*2+1] <= ar[temp*2+2])
                    {
                        swap(ar[temp*2+1],ar[temp]);
                        temp = temp*2+1;
                    }
                else 
                    {
                        swap(ar[temp*2+2],ar[temp]);
                        temp = temp*2+2;
                    }
            }
            else break;
        }
    return 0;
}
int extractMin(int *ar, int size){
    int temp = ar[0];
    ar[0] = ar[size-1];
    heapify(ar,size-1,0);
    return temp;
}
int main(){
    int ar[] = {180,129,447,368,932,654,776,8,3,4};
    int size = sizeof(ar)/sizeof(ar[0]);
    buildHeap(ar,size);
    for(int i = 0;i<size;i++)
        cout<<ar[i]<<" ";
    cout<<"\n"<<extractMin(ar,size)<<"\n";
    for(int i = 0;i<size;i++)
        cout<<ar[i]<<" ";
    return 0;
}