#include <iostream>
#include<queue>

using namespace std;

class Node 
{
    public:
        int data;
        Node* left;
        Node*right;
        
        Node(int data)
        {
            this->data = data;
            left = NULL;
            right = NULL;
        }
};

Node* buildTree(Node*root)
{
    int data;
    cout<<"Enter the data :"<<endl;
    cin>>data;
    
    if(data == -1)
    {
        return NULL;
    }
    
    root = new Node(data);
    cout<<"Enter the data for inserting in left of "<<data<<endl;
    root->left = buildTree(root->left);
    cout<<"Enter the data for inserting in right of "<<data<<endl;
    root->right = buildTree(root->right);
    
    return root;
}

void levelOrderTraversal(Node*root)
{
    if(root == NULL)
    {
        return ;
    }
    queue<Node*> q;
    q.push(root);
    while(!q.empty())
    {
        int x = q.size();
        while(x--)
        {
            Node*front = q.front();
            q.pop();
            cout<<front->data<<" ";
            if(front->left)
            {
                q.push(front->left);
            }
            if(front->right)
            {
                q.push(front->right);
            }
        }
        cout<<endl;
    }
    return;
}

int main() {
    
    std::cout << "Hello world!";
    Node*root = NULL;
    root = buildTree(root);
    levelOrderTraversal(root);
    return 0;
}