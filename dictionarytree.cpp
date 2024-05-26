#include <iostream>  
using namespace std;  

struct Node {  
    string key;
    string mean;  
    Node *left;  
    Node *right;  
};  

Node* cnode(string k, string m)  {  
    Node* node = new Node;      
    node->key=k;  
    node->mean=m;  
    node->left = NULL;
    node->right = NULL;  
    return node;  
}  

void display(Node *root){  
    if (root == NULL)  
        return;  
    display(root->left); 
    cout<< " Keyword: "<<root->key << "  Meaning: "<<root->mean<<"\n";  
    display(root->right); 
}  
 
Node* insert(Node* root, string k,string m) {  
    if (root == NULL)  
        return cnode(k,m); 
    if (k< root->key)  
        root->left = insert(root->left,k,m);  
    else  
        root->right = insert(root->right,k,m);  
    return root;  
}  

Node* createdict(Node* root){
    int ans=1;
    string ke,me;

    do{
        cout<<"Enter the keyword: ";
        cin>>ke;
        cout<<"Enter the meaning: ";
        cin>>me;
        root=insert(root,ke,me);

        cout<<"Do You want to continue(1->yes || 0->no): ";
        cin>>ans;
    }while(ans==1);
    return root;
}

Node* search(Node* root, string key){

    if (root == NULL || root->key == key)
       return root;
    if (root->key < key)
       return search(root->right, key);
    return search(root->left, key);
}

Node* update(Node*root){
    string k,um;
    cout<<"Enter the key to update: ";
    cin>>k;
    cout<<"Enter the updated meaning: ";
    cin>>um;
    Node* temp=search(root,k);
    temp->mean=um;
    return root;
}

int main(){  
    Node* root = NULL;
    Node* temp;
    string a,b,f;
    int ch;
    do{
        cout<<"\nMenu";
        cout<<"\n1->Create Dictionary";
        cout<<"\n2->Insert an element";
        cout<<"\n3->Display";
        cout<<"\n4->Search";
        cout<<"\n5->Update";
        cout<<"\n6->Exit ";
        cout<<"\nEnter your choice: ";\
        cin>>ch;

        switch (ch)
        {
        case 1:
            root=createdict(root);
            break;
        case 2:
            cout<<"Enter the keyword: ";
            cin>>a;
            cout<<"Enter the meaning: ";
            cin>>b;
            root=insert(root,a,b);
            break;
        case 3:
            display(root);
            break;
        case 4:
            cout<<"Enter the key to search: ";
            cin>>f;
            temp=search(root,f);
            if(temp==NULL) cout<<"Element not present";
            else {
                    cout<<"\nElement found: "<<f;
                    cout<<"  Meaning: "<<temp->mean;
                }
            break;
        case 5:
            update(root);    
        default:
            break;
        }
    }while(ch!=6);
    return 0;  
}