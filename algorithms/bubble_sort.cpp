#include<iostream>
#include<string>
using namespace std;
void swap(int *a,int *b)
{
    int x = *a;
    *a = *b;
    *b = x;
}
void bubbleSort_1(int arr[],int n)//let the smallest number on the head of the array
{
    for(int i =0;i< n-1;i++)
    {
        for(int j=n-1;j>i;j--)
            if(arr[j] < arr[j-1])
        {
            swap(&arr[j],&arr[j-1]);
        }
    }
}

void bubbleSort_2(int arr[],int n)//let the biggest number on the head of the array
{
    for(int i =0;i< n-1;i++)
    {
        for(int j=0;j<n-1-i;j++)
            if(arr[j] > arr[j+1])
        {
            swap(&arr[j],&arr[j+1]);
        }
    }
}
void output(int arr[],int n)
{

    for(int i =0;i < n;i++)
    {
        cout<<arr[i] << " ";
    }
    cout<<endl;
}
int main()
{
    int arr[]={12,3424,343,23,42,3424,234,45,6,23,6,74,4};
    int length = sizeof(arr)/sizeof(int);
    bubbleSort_2(arr,length);
    cout<<"The array will be:";
    output(arr,length);
    return 0;
}
