#include<iostream>
using namespace std;

void swap(int *a,int *b)
{
    int x = *a;
    *a = *b;
    *b = x;
}
//selection sort main algorithm
void selectionSort(int arr[],int n)
{
    int min_index = 0;//create a variable name min_index
    for(int i =0;i < n-1;i++)
    {
        min_index = i;//give the min_index the value of i
        for(int j = i +1;j < n;j++)
        {
            if(arr[j] < arr[min_index])
            {
                min_index = j;//do a for scrope to find the smallest value in the scope
            }
        }
        swap(&arr[i] ,&arr[min_index]);//swap the smallest value by the value of the number i
    }
}
void output(int arr[], int n)
{
    for(int i = 0;i < n;i++)
    {
        cout<< arr[i] << " ";
    }

    cout<<endl;
}
int main()
{
    int arr[] = {1,23,45,6,7,5,243,36,44,6364,36};
    int length = sizeof(arr) / sizeof(int);
    cout<<"the arr before switch:";
    output(arr,length);
    selectionSort(arr,length);
    cout<<endl;
    cout<<"the arr after switch:";
    output(arr,length);
    return 0;
}
