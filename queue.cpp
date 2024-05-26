//implementation of queue using array

#include<iostream>
#include<stdlib.h>
using namespace std;

class queue
{
    int myq[20],front,rear;
    int i;

    public:
    queue()
    {
        front = -1;
        rear = -1;
    }

    bool full()
    {
        if(front==0 && rear==19)
        return true;
        else
        return false;
    }

    bool empty()
    {
        if(front==-1)
        return true;
        else
        return false;
    }

    void enqueue(int x)
    {
        if(full())
        {
            cout<<"Queue is full"<<endl;
        }
        else
        {
            if(front==-1)
            ++front;
            rear++;
            myq[rear]=x;
            cout<<"Element "<<x<<" is inserted to queue\n";
        }
    }

    void dequeue()
    {
        int value;
        if(empty())
        {
            cout<<"Queue is empty"<<endl;
        }
        else
        {value = myq[front];
            if(front==rear) //only 1 element in queue
            {
                front = rear = -1;
            }
            else
            front++;

            cout<<"Deleted "<<value<<" from queue"<<endl;

        }
    }

    void display()
    {
        if(empty())
        {
            cout<<"Queue is empty"<<endl;
        }
        else
        {
            cout<<"Queue elements are: \n";
            for(i=front;i<=rear;i++)
            {
                cout<<" "<<myq[i];
            }
        }
    }

};

int main()
{
    int ch;
    int ele;
    queue q;

    cout<<"\n*****************************Queue operations*********************************\n";
    while(true)
    {
        cout<<"\n1. Enqueue \n2. Dequeue \n3. Display \n4. Exit \nEnter your choice: ";
        cin>>ch;

        switch (ch)
        {
            case 1:
                cout<<"\nEnter the element you want to insert: ";
                cin>>ele;
                q.enqueue(ele);
                break;

            case 2:
                q.dequeue();
                break;
            
            case 3:
                q.display();
                break;

            case 4:
                exit(0);
                break;

            default:
                cout<<"\n invalid option";
                break;

        }
    }


    return 0;
}