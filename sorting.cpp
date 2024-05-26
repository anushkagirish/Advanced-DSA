#include<iostream>
using namespace std;

class sort
{
    
    int i,j,temp;
    public:
    void bubble(int a[],int n)
    {
       
        for(i=0;i<n;i++)
        {
            for(j=0;j<n-i;j++)
            {
                if(a[j+1]<a[j])
                {
                    temp = a[j];
                    a[j]=a[j+1];
                    a[j+1]=temp;
                }
            }
        }

        cout<<"\nSorted array using bubble sort: "<<endl;

        for(i=0;i<n;i++)
        {
            cout<<a[i]<<" ";
        }

    }

    void selection(int a[],int n)
    {
        int pos;

        for(i=0;i<n;i++)
        {
            pos = i;
            for(j=i+1;j<n;j++)
            {
                if(a[j]<a[pos])
                {
                    pos = j;
                }
            }
            temp = a[pos];
            a[pos] = a[i];
            a[i] = temp;
            cout<<a[i];

        }
        cout<<"\nsorted array using selection sort: "<<endl;

        for(i=0;i<n;i++)
        {
            cout<<a[i]<<" ";
        }
    }

    void insertion(int a[],int n)
    {
        for(i=1;i<n;i++)
        {
            j = i-1;
            while(j>=0)
            {
                if(a[i]<a[j])
                {
                    temp = a[j];
                    a[j] = a[i];
                    a[i] = temp;
                }
                j--;
            }
        }

        cout<<"\nSorted array using insertion sort: "<<endl;

        for(i=0;i<n;i++)
        {
            cout<<a[i]<<" ";
        }
    }

    int partition(int a[],int low,int high)
    {
        int temp;
        int pivot = a[low];
        int i = low+1;
        int j= high;

    do{
        while(a[i]<=pivot)
        {
            i++;
        }
        while(a[j]>pivot)
        {
            j--;
        }
        if(i<j)
        {
            temp = a[j];
            a[j] = a[i];
            a[i]= temp;
        }
    }while(i<j);

    //swap pivot(a[low]) and a[j]
            temp = a[j];
            a[j] = a[low];
            a[low]= temp;

            return j;

    }
    void display(int a[],int n)
    {
        cout<<"\nSorted array using quick sort sort: "<<endl;
        for(i=0;i<n;i++)
        {
            cout<<a[i]<<" ";
        }
    }
    void quicksort(int a[], int l,int h)
    {
        int partitionindex;  //index of pivot after partition

        if(l<h)
        {
        partitionindex = partition(a,l,h);
        quicksort(a,l,partitionindex-1);  //sorting left sub array
        quicksort(a,partitionindex+1,h);  //sorting right sub array

        

        }
       

    }
};

int main()
{
    int n,i,array[20];
    sort s;

    cout<<"Enter no. of array elements: ";
    cin>>n;
    cout<<"Enter "<<n<<" elements: ";
    for(i=0;i<n;i++)
    {
        cin>>array[i];
    }

    //s.bubble(array,n);
    //s.selection(array,n);
    //s.insertion(array,n);
    s.quicksort(array,0,n-1);
    s.display(array,n);

}