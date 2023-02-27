#include<iostream>
using namespace std;
void quicksort(int *ar,int i ,int j )
{
    if ( i>=j )
        return;
    else
    {
        int pivot = ar[i];
        int p = i;
        for( int q = p+1;q<=j;q++)
            {
                if(ar[q]<pivot)
                {
                    p++;
                    swap(ar[q],ar[p]);
                }
            }
            swap(ar[i],ar[p]);
        quicksort(ar,i,p-1);
        quicksort(ar,p+1,j);
        return;
    }
}
int main()
{
    int ar[] = {31, 41, 59, 26, 32, 12, 58};
    int size = sizeof(ar)/sizeof(ar[0]);
    quicksort(ar,0,size-1);
    for(int i = 0; i<size ;i++)
        cout<<ar[i]<<" ";
    return 0;
}