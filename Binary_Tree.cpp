#include <iostream>
#include <queue>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int value)
    {
        data = value;
        left = NULL;
        right = NULL;
    }
};

class Tree
{
public:

    Node* createTree()
    {
        int value;

        cout << "Enter value (-1 for NULL): ";
        cin >> value;

        if (value == -1)
            return NULL;

        Node *temp = new Node(value);

        cout << "Enter left child of " << value << ":\n";
        temp->left = createTree();

        cout << "Enter right child of " << value << ":\n";
        temp->right = createTree();

        return temp;
    }


    void insert(Node *&root, int value)
    {
        if (value == -1)
        {
            cout << "Cannot insert -1 as a node value.\n";
            return;
        }

        Node *newNode = new Node(value);

       
        if (root == NULL)
        {
            root = newNode;
            return;
        }

        queue<Node*> q;
        q.push(root);

        while (!q.empty())
        {
            Node *temp = q.front();
            q.pop();

           
            if (temp->left == NULL)
            {
                temp->left = newNode;
                return;
            }
            else
            {
                q.push(temp->left);
            }

          
            if (temp->right == NULL)
            {
                temp->right = newNode;
                return;
            }
            else
            {
                q.push(temp->right);
            }
        }
    }


   
    void inorder(Node *temp)
    {
        if (temp == NULL)
            return;

        inorder(temp->left);
        cout << temp->data << " ";
        inorder(temp->right);
    }


   
    void preorder(Node *temp)
    {
        if (temp == NULL)
            return;

        cout << temp->data << " ";
        preorder(temp->left);
        preorder(temp->right);
    }


   
    void postorder(Node *temp)
    {
        if (temp == NULL)
            return;

        postorder(temp->left);
        postorder(temp->right);
        cout << temp->data << " ";
    }
};


int main()
{
    Tree t;
    Node *root = NULL;

    int choice;
    int value;

    do
    {
        cout << "\n\n===== Binary Tree Menu =====";
        cout << "\n1. Create Binary Tree";
        cout << "\n2. Insert Node";
        cout << "\n3. Inorder Traversal";
        cout << "\n4. Preorder Traversal";
        cout << "\n5. Postorder Traversal";
        cout << "\n6. Exit";

        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "\nCreate Binary Tree\n";
            root = t.createTree();
            cout << "\nBinary tree created successfully.";
            break;


        case 2:
            cout << "Enter value to insert: ";
            cin >> value;

            t.insert(root, value);

            cout << "Node inserted successfully.";
            break;


        case 3:
            cout << "\nInorder Traversal: ";
            t.inorder(root);
            cout << endl;
            break;


        case 4:
            cout << "\nPreorder Traversal: ";
            t.preorder(root);
            cout << endl;
            break;


        case 5:
            cout << "\nPostorder Traversal: ";
            t.postorder(root);
            cout << endl;
            break;


        case 6:
            cout << "\nProgram Exited.";
            break;


        default:
            cout << "\nInvalid Choice!";
        }

    } while (choice != 6);

    return 0;
}
