#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int Max(int arr[], int n)
{
    int max = arr[0];
        for (int i=1; i<n; i++)
        if (arr[i] > max)
            max = arr[i];
    return max;
}

void countSort(int arr[], int n, int exponent,int base)
{
    int out[n];
    int temp[base];
    for(int i=0;i<base;i++) temp[i]=0;

        for (int i = 0; i < n; i++)
        temp[(arr[i]/exponent)%base]++;

        for (int i = 1; i < base; i++)
        temp[i] += temp[i - 1];

        for (int i = n - 1; i >= 0; i--)
        out[--temp[(arr[i]/exponent)%base]] = arr[i];

        for (int i = 0; i < n; i++)
        arr[i] = out[i];
}


void radixSort(int arr[], int n,int base)
{
    int m = Max(arr, n);
    for (int exponent = 1; m / exponent > 0; exponent *= base)
        countSort(arr, n, exponent,base);
}

void print(int arr[], int n)
{
    for (int i=0; i < n; i++)
        printf("%d ", arr[i]);

    printf("\n");
}

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

void inorder_traversal(struct node *root)
{
    if (root != NULL)
    {
        inorder_traversal(root->left);
        printf("%d ", root->data);
        inorder_traversal(root->right);
    }
}

void insertion(struct node *root, int key)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = key;
    newnode->left = NULL;
    newnode->right = NULL;
    struct node *temp = root, *parent = NULL;
    while (temp != NULL)
    {
        parent = temp;
        if (newnode->data < temp->data)
            temp = temp->left;
        else
            temp = temp->right;
    }
    if (newnode->data < parent->data)
        parent->left = newnode;
    else
        parent->right = newnode;
}

int search(struct node *temp, int x)
{
    if (temp == NULL)
        return 0;
    else
    {
        if (temp->data == x)
            return 1;
        else if (x < temp->data)
            return search(temp->left, x);
        else return search(temp->right, x);
    }
}

struct node *minValueNode(struct node *root)
{
    while (root->left != NULL)
        root = root->left;
    return root;
}

struct node *deleteNode(struct node *root, int key)
{
    if (root == NULL)
        return NULL;
    if (key < root->data)
        root->left = deleteNode(root->left, key);
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
    else
    {
        if (root->left == NULL)
        {
            struct node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            struct node *temp = root->left;
            free(root);
            return temp;
        }
        else
        {
            struct node *temp = minValueNode(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
    }
    return root;
}

int main()
{
    double radix_time=0.0;

	clock_t start, end;
	int base=2;

     for(int i=0 ; i<100 ; i++)
    {
    int arr[] = { 170, 45, 75, 90, 802, 24, 2, 66 };
    int n = sizeof(arr) / sizeof(arr[0]);

    //CALCULATING RUNTIME WITH ALTERNATING BASE IN EVERY ITERATION
    if(base>10) base=2;

    start = clock();
    radixSort(arr, n,base++);
    end = clock();

    radix_time =radix_time + ((double) (end - start)) /CLOCKS_PER_SEC;

    if(i==99)
    {
        printf("Array after sorting with radix sort :");
        print(arr,n);
    }
    }

	printf("\nAvg Time taken for radixsort is(avg. of 100 iterations): %f\n", radix_time/100.0);


	int n1, x;

    printf("Enter the number of elements in the Tree : \n");
    scanf("%d", &n1);

    struct node *root = (struct node *)malloc(sizeof(struct node));
    root->left = NULL;
    root->right = NULL;

    printf("Enter the elements :\n");
    scanf("%d", &root->data);

    for (int i = 1; i < n1; i++)
    {
        scanf("%d", &x);
        insertion(root, x);
    }

    inorder_traversal(root);

    printf("\n");
    printf("Enter the element to search : ");

    scanf("%d", &x);
    int s = search(root, x);

    s == 1 ? printf("Given element is present in the Tree\n") : printf("Given element is not present in the Tree\n");

        printf("\nEnter the element to delete : ");
        scanf("%d", &x);
        root = deleteNode(root, x);
        inorder_traversal(root);
        printf("\n");

    return 0;
}
