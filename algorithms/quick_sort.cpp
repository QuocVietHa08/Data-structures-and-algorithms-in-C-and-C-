#include<iostream>
#include<string>

using namespace std;
void swap(int *a,int *b)
{
    int tg = *a;
    *a = *b;
    *b = tg;
}

int partion(int arr[],int l,int h)
{
    int p = arr[h];
    int i = l- 1;//bien giam sat qua trinh thuc hien sap xep
    for(int j = l;j < h;j++)
    {

        if(arr[j] < p)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }//find the right deraction of the l value
    swap(&arr[i + 1],&arr[h]);
    return (i +1);

}


//quick sort algorithym
void quickSort(int arr[],int l,int h)
{
    if(l < h){
        int pi = partion(arr,l,h);
        quickSort(arr,l,pi -1);
        quickSort(arr,pi + 1,h);
    }
}

void hello(int arr[],int n)
{
	cout<<"xin chao moi nguoi";

}
void output(int arr[], int n)
{
    for(int i =0;i < n;i++)
    {
        cout<< arr[i]<< " ";
    }
    cout<<endl;
}
int main()
{

    int arr[]={12323,324234,21,56,2,3,67,2,46,346,36,4};
    int length = sizeof(arr) / sizeof(int);
    cout<<"the arr before switch: ";
    output(arr,length);
    cout<<endl;
    cout<<"the arr after switch:";
    quickSort(arr,0,length -1);
    output(arr,length);
}
