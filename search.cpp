#include<iostream>
#include<stdlib.h>
using namespace std;

class search
{
    int i, flag, ub,lb,mid;
    public:
    void linear(int a[], int n, int value)
    {
        flag =0;
        for(i=0;i<n;i++)
        {
            if(a[i]==value)
            {
                cout<<"Element found at location: "<<i+1<<endl;
                flag = 1;
            }
        }
        if(flag!=1)
        {
            cout<<"Element not preseent in the array"<<endl;
        }
    }

    void binary(int a[], int n, int value)
    {
        lb=0;
        ub=n-1;
        mid=(lb+ub)/2;

        while(a[mid]!=value && lb<=ub)
        {
           
            if(value<a[mid])
            {
                ub=mid-1;
                mid=(lb+ub)/2;
            }
            else
            {
                lb=mid+1;
                mid=(lb+ub)/2;
            }
        }
         if(value==a[mid])
            {
                cout<<"Element found at location: "<<mid+1<<endl;
            }
        else{
            cout<<"element not present in array"<<endl;
        }
        
    }
};

int main()
{
    int n,i,arr[20],ch,key;
    search s;

    cout<<"\nEnter number of array elements: ";
    cin>>n;
    cout<<"\nEnter "<<n<<" array elements: ";
    for(i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cout<<"enter elemnt to be searched: ";
    cin>>key;
    while(true){
    cout<<"\n1.linear \n2.binary \n3.exit";
    cout<<"\nenter choice: ";
    cin>>ch;

    switch(ch)
    {
        case 1:
        {
            s.linear(arr,n ,key );
            break;
        }

        case 2:
        {
            s.binary(arr,n ,key );
            break;
        }
        case 3:
        {
            exit(0);
            break;
        }
    }
    }

    
    return 0;
}
