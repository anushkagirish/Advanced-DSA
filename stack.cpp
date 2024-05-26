//assignment 7 to create stack using array

#include<iostream>
#include<stdlib.h>
using namespace std;
class stackop
{
    int mystack[20];
    int top , i;
    public:
    stackop()
    {
        top = -1;
    }

    void display()
    {
        if(top<0)
        {
            cout<<"Empty stack";
            return;
        }
        else
        {
            for(i=top; i>=0; i--)
            cout<<" "<<mystack[i];
        }

    }

    void pushop()
    {
        int n,x;

        if(top>=19)
        {
            cout<<"Stack overflow";
            return;
        }
        else
        {
            cout<<"Enter the number of elements you want to insert into stack: ";
            cin>>n;
            cout<<"Enter "<<n<<" elements: ";
            for(i=0;i<n;i++)
            {
                cin>>x;
                mystack[++top]=x;
                cout<<"Element "<<x<<" inserted \n";
            }
        }

    }

    void popop()
    {
        if(top<0)
        {
            cout<<"Stack underflow";
            return;
        }
        else
        {
            cout<<"Element "<<mystack[top--]<<" deleted";
        }
    }
};

int main()
{
    int ch;
    stackop s;
    cout<<"\n*************************STACK OPERATIONS USING ARRAY******************************** \n";
    while(true)
    {
        cout<<"\n 1.Insert\n 2.Delete\n 3.Display\n 4.Exit\n Enter your choice: ";
        cin>>ch;

        switch (ch)
        {
        case 1:
            s.pushop();
            break;
        case 2:
            s.popop();
            break;
        case 3:
            s.display();
            break;
        case 4:
            exit(0);
            break;
        
        default:
            cout<<"Invalid option";
            break;
        }
    }

    return 0;
}