#include<iostream>
#include<queue>
using namespace std;

class node
{
public:
    int data;
    node* left;
    node* right;

    node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

node* buildTree(node* root)
{

    cout << "Enter the data: " << endl;
    int data;
    cin >> data;
    root = new node(data);

    if (data == -1)
    {
        return NULL;
    }

    cout << "Enter data for inserting in left of " << data << endl;
    root->left = buildTree(root->left);
    cout << "Enter data for inserting in right of " << data << endl;
    root->right = buildTree(root->right);
    return root;

}

void levelOrderTraversal(node* root)
{
    queue<node*> q;
    q.push(root);

    while (!q.empty())
    {
        node* temp = q.front();
        cout << temp->data << " ";
        q.pop();

        if (temp->left)
        {
            q.push(temp->left);
        }

        if (temp->right)
        {
            q.push(temp->right);
        }
    }
}

void inorder(node* root)
{
    if (root == NULL)
    {
        return;
    }

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);

}

void preorder(node* root)
{
    if (root == NULL)
    {
        return;
    }

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);

}

void postorder(node* root)
{
    if (root == NULL)
    {
        return;
    }

    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";

}

int count(node* p)
{
    int x, y;
    if (p != NULL)
    {
        x = count(p->left);
        y = count(p->right);
        return x + y + 1;
    }
    return 0;
}

int height(node* h)
{
    int x = 0;
    int y = 0;

    if (h == 0)
        return 0;
    x = height(h->left);
    y = height(h->right);
    if (x > y)
        return x + 1;
    else
        return y + 1;

}

int sum(node* s)
{
    int x, y;
    if (s != NULL)
    {
        x = sum(s->left);
        y = sum(s->right);
        return x + y + s->data;
    }
    return 0;
}
int deg2nodeCount(node* p)
{
    int x;
    int y;
    if (p != nullptr) {
        x = deg2nodeCount(p->left);
        y = deg2nodeCount(p->right);
        if (p->left && p->right)
        {
            return x + y + 1;
        }
        else
        {
            return x + y;
        }
    }
    return 0;
}
int leafnodes(node* p)
{
    int x;
    int y;
    if (p != nullptr) {
        x = leafnodes(p->left);
        y = leafnodes(p->right);
        if (p->left == NULL && p->right == NULL)
        {
            return x + y + 1;
        }
        else
        {
            return x + y;
        }
    }
    return 0;
}
int deg1nodeCount(node* p)
{
    int x;
    int y;
    if (p != nullptr) {
        x = deg1nodeCount(p->left);
        y = deg1nodeCount(p->right);
        if ((p->left != NULL && p->right == NULL) || (p->left == NULL && p->right != NULL))
        {
            return x + y + 1;
        }
        else
        {
            return x + y;
        }
    }
    return 0;
}
int main()
{
    // Dataset 1 : 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    // Dataset 2 : 1 2 4 -1 -1 5 -1 -1 3 6 -1 -1 7 -1 -1
    node* root = NULL;
    root = buildTree(root);
    int ch;
    while (1)
    {
        cout << "\n1:Level Order  \n2:In Order \n3:Pre Order\n4:Post Order \n5:Count of nodes\n6:Height of the tree\n7:Sum of all elements\n8:Nodes with degree = 2 \n9:Leaf Nodes in a tree\n10:Nodes with degree = 1\n";
        cout << "\nEnter Your Choice:";
        cin >> ch;
        switch (ch)
        {
        case 1:
            cout << "Level order Traversal : " << endl;
            levelOrderTraversal(root);
            break;
        case 2:
            cout << "In order Traversal : " << endl;
            inorder(root);
            break;
        case 3:
            cout << "Pre order Traversal : " << endl;
            preorder(root);
            break;
        case 4:
            cout << "Post order Traversal : " << endl;
            postorder(root);
            break;
        case 5:
            cout << "Total number of nodes : " << endl;
            cout << count(root) << endl;
            break;
        case 6:
            cout << "Height of the tree : " << endl;
            cout << height(root) << endl;
            break;
        case 7:
            cout << "Sum of all the elements : " << endl;
            cout << sum(root) << endl;
            break;
        case 8:
            cout << "Nodes with degree = 2 : " << endl;
            cout << deg2nodeCount(root) << endl;
            break;
        case 9:
            cout << "Leaf nodes in a binary tree : " << endl;
            cout << leafnodes(root) << endl;
            break;
        case 10:
            cout << "Nodes with degree = 1 :" << endl;
            cout << deg1nodeCount(root) << endl;
            break;
        default:
            cout << "Wrong Choice : " << endl;
            break;
        }
    }
}
