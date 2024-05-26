#include<iostream>
#include<string.h>
#include<cstdlib>

using namespace std;


class llist{
private:
    typedef struct node{
        int data;
        struct node* next;
    }* nodeptr;
    
    nodeptr head;
    nodeptr curr;
    nodeptr temp;
    public:   //all functions accessing the private data help operate the list
        llist();  //constructor function
        void AddNode(int addData);
        void DelNode(int delData);
        void PrintList();
};

llist::llist(){
    head = NULL;
    curr = NULL;
    temp = NULL;
}

void llist::AddNode(int addData){
     nodeptr nn=new node;
     nn->next=NULL;
     nn->data=addData;

     if(head!=NULL)
     {
         curr = head;
         while(curr->next != NULL)
         {
             curr = curr->next;
         }
         curr->next=nn;
     }
     else
     {
         head=nn;
     }
}


void llist::DelNode(int delData){
    nodeptr delptr=NULL;
    temp=head;
    curr=head;
    while(curr!=NULL &&curr->data!=delData)
    {
        temp=curr;
        curr=curr->next;
    }
    if(curr==NULL)
    {
        cout<<"The value "<<delData<<" is not in the list"<<endl;
        delete delptr;
    }
    else
    {
        delptr=curr;
        curr=curr->next;
        temp->next=curr;
        delete delptr;
        cout<<"The value "<<delData<<" was deleted  "<<endl;
    }
}

void llist::PrintList(){
    cout<<"The list : "<<endl;
    curr=head;
    while(curr!=NULL)
    {
        cout<<curr->data<<endl;
        curr=curr->next;
    }
    cout<<endl;
}


int main()
{
    int ch,cnt;
    llist Ll1;
    Ll1.PrintList();
    do
    {
        cout<<"1.Add Node  2.Delete Node  3.Print Linked List  4.Exit"<<endl;
        cout<<"Enter choice : ";
        cin>>ch;
        if(ch==4)
        {
            break;
        }
        switch(ch)
        {
        case 1:
            int ad;
            cout<<"Enter data to add = ";
            cin>>ad;
            Ll1.AddNode(ad);
            break;

        case 2:
            {
                int dd;
                Ll1.PrintList();
                cout<<"Select data to delete = ";
                cin>>dd;
                Ll1.DelNode(dd);
                break;
            }
        case 3:
            {
                Ll1.PrintList();
                break;
            }

        default:
            {
                cout<<"Invalid Input"<<endl;
                break;
            }
        }
    } while(ch<4);
    return 0;
}