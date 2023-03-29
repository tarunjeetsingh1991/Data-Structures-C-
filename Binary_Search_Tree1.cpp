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

node* insert(node* root, int d)
{
	if (root == NULL)
	{
		root = new node(d);
		return root;
	}

	if (d > root->data)
	{
		root->right = insert(root->right, d);
	}
	else
	{
		root->left = insert(root->left, d);
	}
	return root;
}

void input(node* &root)
{
	int data;
	cin >> data;
	while (data != -1)
	{
		root = insert(root, data);
		cin >> data;
	}
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

node* search(node* root,int k)
{
    if (root == NULL || root->data == k)
        return root;
    if (root->data > k)
        return search(root->left, k);
    else
        return search(root->right, k);
}

node* min(node* root)
{
    node* temp = root;
    while (temp->left != NULL)
    {
        temp = temp->left;
    }
    return temp;
}

node* max(node* root)
{
    node* temp = root;
    while (temp->right != NULL)
    {
        temp = temp->right;
    }
    return temp;
}

node* deleteBST(node* root, int val)
{
    if (root == NULL)
        return root;
    if (root->data == val)
    {
        //0 child
        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            return NULL;
        }
        //1 child
        //left
        if (root->left != NULL && root->right == NULL)
        {
            node* temp = root->left;
            delete root;
            return temp;
        }
        //right
        if (root->left == NULL && root->right != NULL)
        {
            node* temp = root->right;
            delete root;
            return temp;
        }

        //2 children
        if (root->left != NULL && root->right != NULL)
        {
            int m = min(root->right)->data;
            root->data = m;
            root->right = deleteBST(root->right, m);
            return root;
        }
    }
    else if (root->data > val)
    {
        root->left = deleteBST(root->left, val);
        return root;
    }
    else
    {
        root->right = deleteBST(root->right, val);
        return root;
    }
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
    
    node* root = NULL;
    cout << "Enter the integer data to create the BST and press -1 to terminate the input stream : " << endl;
    input(root);
    int ch;
    int n,d;
    while (1)
    {
        cout << "\n1:Level Order  \n2:In Order \n3:Pre Order\n4:Post Order\n5:Search data\n6:Minimum Value\n7:Maximum Value\n8:Delete a node\n9:Count of nodes\n10:Height of the tree\n11:Sum of all elements\n12:Nodes with degree = 2 \n13:Leaf Nodes\n14:Nodes with degree = 1 \n";
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
            cout << "Enter the data to be searched : " << endl;
            cin >> n;
                if (search(root, n) == NULL)
                    cout << "Node doesn't exist " << endl;
                else
                    cout << "Element found " << endl;
            break;
        case 6:
            cout << "Minimum value is : " << endl;
            cout << min(root)->data << endl;
            break;
        case 7:
            cout << "Maximum value is : " << endl;
            cout << max(root)->data << endl;
            break;
        case 8:
            cout << "Enter the node to be deleted from these nodes : " << endl;
            inorder(root);
            cout<<endl;
            cin >> d;
            if (search(root, d) != NULL)
            {
                root = deleteBST(root, d);
                cout << "Node with value = " << d << " deleted successfully." << endl;
                cout<<"The tree is : " << endl ;
                inorder(root);
            }
            else
            {
                cout<<"Cannot delete the node which is not in the tree. "<<endl;
            }
            break;
        case 9:
            cout << "Total number of nodes : " << endl;
            cout << count(root) << endl;
            break;
        case 10:
            cout << "Height of the tree : " << endl;
            cout << height(root) << endl;
            break;
        case 11:
            cout << "Sum of all the elements : " << endl;
            cout << sum(root) << endl;
            break;
        case 12:
            cout << "Nodes with degree = 2 : " << endl;
            cout << deg2nodeCount(root) << endl;
            break;
        case 13:
            cout << "Leaf nodes in a binary tree : " << endl;
            cout << leafnodes(root) << endl;
            break;
        case 14:
            cout << "Nodes with degree = 1 :" << endl;
            cout << deg1nodeCount(root) << endl;
            break;

        default:
            cout << "Wrong Choice : " << endl;
            break;
        }
    }
}
