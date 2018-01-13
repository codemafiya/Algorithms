#include<stdio.h>
#include<stdlib.h>
typedef struct Node
{
    int data;
    struct Node *left,*right;
}Node;
//Function Prototypes
Node* initialize(Node *root);
Node* insertBST(Node *root,int data);
int searchBST(Node *root,int data);
Node* deleteBST(Node *root,int data);
Node* rightMost(Node *root);
void inorder(Node *root);
void preorder(Node *root);
void postorder(Node *root);

//main function
int main()
{
    Node *root;
    int choice,data;
    root=initialize(root);
    while(1)
    {
        printf("Enter\n1.Insertion\n2.Search\n3.Deletion\n4.Exit\n");
        int choice;
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                printf("Enter the data to be inserted: ");
                scanf("%d",&data);
                root=insertBST(root,data);
                break;
            case 2:
                printf("Enter the data to be searched: ");
                scanf("%d",&data);
                int result=searchBST(root,data);
                if(result==1)
                printf("%d is present in BST\n",data);
                else
                printf("%d is not present in BST\n",data);
                break;
            case 3:
                printf("Enter the data to be deleted: ");
                scanf("%d",&data);
                root=deleteBST(root,data);
                break;
            case 4:
                printf("EXIT...PROGRAM TERMINATED !");
                exit(1);
            default:
                printf("Invalid choice.. Enter correct choice\n");
                inorder(root);
        }
    }
    return 0;
}

//initializing BST
Node* initialize(Node *root)
{
    root=NULL;
    return root;
}

//Inserting element in BST
Node* insertBST(Node *root,int data)
{
    Node *newnode=(Node*)malloc(sizeof(Node));
    if(newnode==NULL)
    {
        printf("Insufficient memory");
        return root;
    }
    if(root==NULL)
    {
        newnode->data=data;
        newnode->left=NULL;
        newnode->right=NULL;
        root=newnode;
    }
    else if(data<root->data)
        root->left=insertBST(root->left,data);
    else
        root->right=insertBST(root->right,data);
    return root;
}

//Searching element in BST
int searchBST(Node *root,int data)
{
    if(root==NULL)
    {
        return 0;
    }    
    if(root->data==data)
    return 1;
    if(data<root->data)
        return searchBST(root->left,data);
    else
        return searchBST(root->right,data);
}

//deletion of an element in BST
Node* deleteBST(Node *root,int data)
{
    if(root==NULL)
    {
        printf("%d is not present in BST\n");
        return root;
    }
    //found the node to be deleted
    else if(root->data==data)
    {
        if(root->left==NULL)
        {
            Node *temp=root->right;
            free(root);
            return temp;
        }
        else if(root->right==NULL)
        {
        	Node *temp=root->left;
        	free(root);
        	return temp;
		}
        else
        {
            Node *nextInorder=rightMost(root->right);
            root->data=nextInorder->data;
            root->right=deleteBST(root->right,nextInorder->data);
        }
    }
    //comparing the data to be deleted with the root value
    else if(root->data>data)
    {
        root->left=deleteBST(root->left,data);
    }
    else
    {
        root->right=deleteBST(root->right,data);
    }
    return root;
}

//for finding the next data in inorder traversal
Node* rightMost(Node *root)
{
    while(root->left!=NULL)
    {
        root=root->left;
    }
    return root;
}

//prints inorder traversal of the tree
void inorder(Node *root)
{
    if(root==NULL)
    return ;
    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
}

//prints preorder traversal of the tree
void preorder(Node *root)
{
    if(root==NULL)
    return ;
    printf("%d ",root->data);
    inorder(root->left);
    inorder(root->right);
}

//prints postorder traversal of the tree
void postorder(Node *root)
{
    if(root==NULL)
    return ;
    inorder(root->left);
    inorder(root->right);
    printf("%d ",root->data);
}
