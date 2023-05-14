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

// Write a program to implement the inorder traversal of a binary tree using iterative approach
void inorder(Node*root)
{
    stack<Node*> st;
    st.push(root);
    
    while(true)
    {
        if(curr)
        {
            st.push(curr);
            curr = curr->left;
        }
        else if(!st.empty())
        {
            Node*temp = st.top();
            st.pop();
            cout<<temp->data<<" ";
            curr = temp->right;
        }
        else 
        {
            break;
        }
    }
}

// Write a program to implement the preorder traversal of the binary tree using iterative approach
void preorder(Node*root)
{
    if(root == NULL)
    {
        return;
    }
    stack<Node*> st;
    st.push(root);
    
    while(!st.empty())
    {
        Node*temp = st.top();
        st.pop();
        cout<<temp->data<<" ";
        if(temp->right)
        {
            st.push(temp->right);
        }
        if(temp->left)
        {
            st.push(temp->left);
        }
    }
    return;
}

void preorderIterative(Node*root)
{
    if(root == NULL)
    {
        return;
    }
    
    stack<Node*> st;
    Node*curr = root;
    
    while(curr != NULL || st.empty() == false)
    {
        while(curr)
        {
            cout<<curr->data<<" ";
            if(curr->right)
            {
                st.push(curr->right);
            }
            
            curr = curr->left;
        }
        
        if(!st.empty())
        {
            curr = st.top();
            st.pop();
        }
    }
}

// Write a program to implement the postorder traversal of a binary tree using the iterative approach
void postOrder(Node*root)
{
    if(root == NULL)return;
    stack<Node*> first;
    stack<Node*> second;
    
    first.push(root);
    while(!first.empty())
    {
        Node*temp = first.top();
        first.pop();
        second.push(temp);
        if(temp->left)
        {
            first.push(temp->left);
        }
        if(temp->right)
        {
            first.push(temp->right);
        }
    }
    while(!second.empty())
    {
        cout<<second.top()->data<<" ";
        second.pop();
    }
}

int main() {
    
    std::cout << "Hello world!";
    Node*root = NULL;
    root = buildTree(root);
    levelOrderTraversal(root);
    return 0;
}