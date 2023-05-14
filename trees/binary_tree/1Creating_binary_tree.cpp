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

// Write a program to print a given level of tree
void printGivenLevel(Node*root , int level)
{
    if(root == NULL)
    {
        return;
    }
    else if(level== 1)
    {
        cout<<root->data << " ";
    }
    else if(level>1)
    {
        printGivenLevel(root->left , level-1);
        printGivenLevel(root->right,level-1);
    }
}

int height(Node*root)
{
    if(root == NULL)
    {
        return 0;
    }
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    return max(leftHeight , rightHeight) + 1;
}

int main() {
    
    std::cout << "Hello world!";
    Node*root = NULL;
    root = buildTree(root);
    levelOrderTraversal(root);
    return 0;
}