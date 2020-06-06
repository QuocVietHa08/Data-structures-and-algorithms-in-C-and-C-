#include<iostream>
#include<string>
using namespace std;

void merge(int arr[],int l,int m,int h)
{
    int i,j,k =l;
    int n1 = m-l + 1;
    int n2 = h -m;

    int *L = new int[n1];
    int *R = new int[n2];

    for( i =0;i < n1;i++)
    {

        L[i] = arr[ l + i];
    }
    for( j = 0; j < n2;j++)
    {
        R[j] = arr[ m + j + 1];
    }
    i = 0; j =0;
    while( i< n1 && j < n2)
    {
        arr[k++] = (L[i] <= R[j]) ? L[i++]: R[j++];
    }
    while(i < n1){
         arr[k++] = L[i++];
    }
    while(j < n2)
    {
        arr[k++] = R[j++];
        /*
        arr[k] = R[j[
        k++;
         j++;
         */
    }

}


void mergeSort(int arr[],int l,int h)
{
    if(l < h)
    {
    int m = l + (h -l)/2;
    mergeSort(arr,l,m);
    mergeSort(arr,m+1,h);
    merge(arr,l,m,h);
    }
}

void output(int arr[],int n)
{
    for(int i = 0;i<n;i++)
    {
        cout<<arr[i] << " ";
    }
}

int main()
{
    int arr[] = {2234,234,45,242,626,72,23,1432};
    int length = sizeof(arr) / sizeof(int);
    mergeSort(arr,0,length);
    output(arr,length);
    return 0;
}
