#include<iostream>
#include<string>
using namespace std;
//before using binary search we have to arrange the array from small to big or big to small
void swap(int *a,int *b)
{
    int tg = *a;
    *a = *b;
    *b = tg;
}
int partion(int arr[],int l,int h)
{
    int p = arr[h];
    int i = l - 1;
    for(int j = l;j < h;j++)
    {
        if(arr[j] < p)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1],&arr[h]);
    return (i + 1);
}
void quickSort(int arr[],int l,int h)
{
        if(l < h)
        {
            int pi = partion(arr,l,h);
            quickSort(arr,l,pi -1);
            quickSort(arr,pi+1,h);
        }
}

int binarySearch(int arr[],int l,int h,int x)
{
    while(l <= h)
    {
        int m = l + (h - l)/2;
        if(arr[m] == x)//if the loop can find value x
        {               // if will return x
            return m;
        }
        if(arr[m] < x)//if the value x is greater than than value m
        {             // the first value of the array l will plus 1
            l = m +1;
        }
        if(arr[m] > x)// if the value x is smaller than the value m
        {             // the last value of the arra will minus 1
            h = m -1;
        }
    }
    return -1;
}

void output(int arr[],int n)
{
    for(int i = 0; i < n;i++)
    {

        cout<<arr[i] << " ";
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

    //using binary search to find the right number
    int x ;
    cout<<"Enter the number you need to find ";
    cin>>x;
    int index = binarySearch(arr,0,length -1,x);
    if(index != -1)
    {
        cout<<"Exist the number that need to find";
    }
    else{
        cout<<"Not exist the number "<<x<<endl;
    }

    return 0   ;
}
