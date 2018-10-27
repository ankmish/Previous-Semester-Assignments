/*
NAME    - ANKIT MISHRA
REG NO. - 20168047
DATE    - 02/04/18
PROGRAM - AUGMENTED DS USING AVL
*/
#include<stdio.h>
#include<stdlib.h>
int order=0;
struct node
{
    int info;
    struct node * left,*right,*p;
    int height;
    int size;
};
int max(int a , int b)
{
    return ( a > b ) ? a : b ;
}
void  size_set(struct node * ptr)
{
    if(ptr==NULL)
        return ;
    if(ptr->left == NULL && ptr->right == NULL)
    {
        ptr->size = 1;
        return ;
    }
    size_set(ptr->left);
    size_set(ptr->right);
    if(ptr->left!=NULL)
        ptr->size+=ptr->left->size;
    if(ptr->right != NULL)
        ptr->size+=ptr->right->size;

    ptr->size = ptr -> size + 1;
}
struct node * newNode(int data)
{
    struct node * tmp=(struct node *)malloc(sizeof(struct node));
    tmp->left = tmp->right = NULL;
    tmp ->height = 1 ;
    tmp -> info = data;
    tmp -> size = 0;
    //tmp->p = NULL;
    return tmp;
}
int height(struct node * ptr)
{
    if(ptr==NULL)
        return 0;
    return ptr->height ;
}
int getbalance(struct node * ptr)
{
    if(ptr==NULL)
        return 0;
    int a , b;
    a = height(ptr->left);
    b = height(ptr->right);
    int res = a - b;

    return res;
}
struct node *rightrotate(struct node * ptr )
{
    struct node * x = ptr->left;
    struct node * temp = x->right;

   // rotate it
    x->right = ptr;
    ptr->left = temp;

    // Update heights
    ptr->height = max(height(ptr->left), height(ptr->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;   // new root
}

struct node *leftrotate(struct node * ptr)
{
    struct node * y = ptr->right;
    struct node * temp = y->left;

    y->left = ptr;
    ptr->right = temp;

    ptr->height = max(height(ptr->left), height(ptr->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;  // new root will be 'y'
}
struct node * insert(struct node * root, int data)
{
    if(root==NULL)
        return (newNode(data));
    if(data < root->info)
    {
        root->left = insert(root->left,data);
        //root->left->parent = root;
    }
    else if(data > root->info)
    {
        root->right = insert(root->right , data);
        //root -> right -> p = root;
    }
    else if(data == root->info)
        return root;

    root -> height = 1 + max(height(root->left),height(root->right));

    /*now find out balance factor of this nodoes created*/

    int bal = getbalance(root);

    // 4 case possible (ref. to 3rd. sem DS course for more)

    if(bal < -1 && data > root->right->info)  // RR case
        return leftrotate(root); // left rotation required

    if(bal > 1 && data < root->left->info) // LL case
        return rightrotate(root);

    if(bal > 1 && data > root->left->info)   // LR case
    {
        root->left = leftrotate(root->left);
        return rightrotate(root);
    }
    if(bal < -1 && data < root->right->info) // RL case
    {
        root->right = rightrotate(root->right);
        return leftrotate(root);
    }

    return root ; // if balanced case
}
void preorder(struct node * root)
{
    if(root!=NULL)
    {
        printf("%d ", &root->info);
        preorder(root->left);
        preorder(root->right);
    }
}
int i_num(struct node * root, int k)
{
    int or;
    if(root->left==NULL)
        or = 1;
    else
        or = root->left->size + 1;
    if(k == or)
        return root->info ;
    else if(k < or)
        return (i_num(root->left,k));
    else
        return (i_num(root->right,k - or)) ;
}
int num_i(struct node * root,int num)
{
    int rc;
    if(root->left == NULL)
        rc = 1;
    else
         rc = root->left->size + 1;
    if(root->info == num)
        return order+=rc;
    else if(root ->info < num)
    {
         order+=rc;
      num_i(root->right,num);
    }
    else
        return num_i(root->left,num);
}
int ptr_i(struct node * root, struct node * ptr)
{
    if(ptr==NULL)
        return -1;
    return num_i(root,ptr->info);
}
int main()
{
    int n;
    struct node * root = NULL;
    printf("\n Enter the no. of elements :");
    scanf("%d",&n);
    int i,a;s
    for(i=0;i<n;i++)
    {
        printf("\n Enter  the %d th element :", i+1);
        scanf("%d", &a);
        root = insert(root,a);
    }
    printf("\n Preorder travesal of AVL :\n");
    preorder(root);

    size_set(root);
    int k;
    printf("\n Enter the kth order :");
    scanf("%d", &k);
    int res = i_num(root, k);
    printf("\n Result is : %d \n", res);
    int  num;
    printf("\n Enter the number whose order is to be determined :");
    scanf("%d", &num);
    int res1 = num_i(root,num);
    printf("\n Rank of given num. will be :%d\n", res1);
    printf("\n Enter the address whose order is to be determined :");
    unsigned int add;
    scanf("%d", &add);
    order = 0;
    int res2 = ptr_i(root,add);
    printf("\n order obtained from ptr is :%d\n", res2);
    return 0;
}
