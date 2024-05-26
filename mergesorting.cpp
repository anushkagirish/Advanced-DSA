#include<iostream>
using namespace std;

void merge(int a[],int low,int mid,int high)
{
    int i = low;
    int j= mid+1;
    int k=low;
    int t[30];

    while(i<=mid && j<=high)
    {
        if(a[i]<a[j])
        {
            t[k]=a[i];
            i++;
            k++;
        }
        else
        {
            t[k]=a[j];
            j++;
            k++;
        }
    }

    while(i<=mid)
    {
        t[k]=a[i];
            i++;
            k++;
    }
    while(j<=high)
    {
        t[k]=a[j];
            j++;
            k++;
    }

    for(i=0;i<high;i++)
    {
        a[i]=t[i];
    }
}

void sort(int a[],int l,int h)
{
    while(l<h)
    {
        int mid=(l+h)/2;
        sort(a,l,mid);
        sort(a,mid+1,h);
        merge(a,l,mid,h);
    }
}
void display(int a[],int n)
        {
            int i;
            cout<<"\nSorted array using quick sort sort: "<<endl;
            for(i=0;i<n;i++)
            {
                cout<<a[i]<<" ";
            }
        }
int main()
{
    int n,i,array[20];

    cout<<"Enter no. of array elements: ";
    cin>>n;
    cout<<"Enter "<<n<<" elements: ";
    for(i=0;i<n;i++)
    {
        cin>>array[i];
    }

    sort(array,0,n);
    display(array,n);
}