/*
NAME    - ANKIT MISHRA
DATE    - 04/02/2018
PROGRAM - To print HUFFMAN CODE(GREEDY ALGORITHM)

// BECAUSE OF EASE OF TAKING INPUT IN C++, CODE WILL BE COMPILED using g++ INSTEAD OF gcc ..
// PROBLEM FACED :: TAKING INPUT AS CHAR ARRAY SEPERATED BY SPACE
// ELSE EVERYTHING IS SAME AS TO BE ETIHER IN C++ OR C
*/
#include <stdio.h>
#include <stdlib.h>
#include<bits/stdc++.h>
#define th 100
using namespace std;
/* definition for a single node of the huffman tree*/
struct MinHeapNode
{
    char data;
    int freq;
    struct MinHeapNode *left, *right;
};
/*contain the nodes of the huffman tree*/
struct MinHeap
{
    int width;
    int capacity;
    struct MinHeapNode ** ptr_arr;   // array of pointers for MinHeapNode
};
struct MinHeapNode * newNode(char data, int freq)
{
    struct MinHeapNode* temp = (struct MinHeapNode*)malloc(sizeof(struct MinHeapNode));
    temp->left = temp->right = NULL;
    temp->data = data;
    temp->freq = freq;
    return temp;
}
/*minimum heap creation*/
struct MinHeap * createMinHeap(int capacity)
{
    struct MinHeap* minHeap = (struct MinHeap*)malloc(sizeof(struct MinHeap));
    minHeap->width = 0;    // make current size of heap as 0
    minHeap->capacity = capacity;
    minHeap->ptr_arr= (struct MinHeapNode**)malloc(minHeap->capacity*sizeof(struct MinHeapNode*));
    return minHeap;
}
void swapMinHeapNode(struct MinHeapNode** a,struct MinHeapNode** b)
{
    struct MinHeapNode* temp = *a;
    *a = *b;
    *b = temp;
}
/*minimum heapify function*/
void minHeapify(struct MinHeap* minHeap, int idx)
{
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;
    if (left < minHeap->width && minHeap->ptr_arr[left]->freq < minHeap->ptr_arr[smallest]->freq)
        smallest = left;
    if (right < minHeap->width && minHeap->ptr_arr[right]->freq < minHeap->ptr_arr[smallest]->freq)
        smallest = right;
    if (smallest != idx)
    {
        swapMinHeapNode(&minHeap->ptr_arr[smallest],&minHeap->ptr_arr[idx]);
        minHeapify(minHeap, smallest);
    }
}
/*check size of heap if it is 1 or not*/
int isSizeOne(struct MinHeap* minHeap)
{
    return (minHeap->width == 1);
}
struct MinHeapNode* extractMin(struct MinHeap* minHeap)
{
    struct MinHeapNode* temp = minHeap->ptr_arr[0];
    minHeap->ptr_arr[0]  = minHeap->ptr_arr[minHeap->width - 1];
    --minHeap->width;
    minHeapify(minHeap, 0);
    return temp;
}
/*Insertion in minimum heap*/
void insertMinHeap(struct MinHeap* minHeap, struct MinHeapNode* minHeapNode)
{
    ++minHeap->width;
    int i = minHeap->width - 1;
    while (i && minHeapNode->freq < minHeap->ptr_arr[(i - 1) / 2]->freq)
    {
        minHeap->ptr_arr[i] = minHeap->ptr_arr[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    minHeap->ptr_arr[i] = minHeapNode;
}
void buildMinHeap(struct MinHeap* minHeap)
{
    int n = minHeap->width - 1;
    int i;
    for (i = (n - 1) / 2; i >= 0; --i)
        minHeapify(minHeap, i);
}
void printArr(int arr[], int n)
{
    int i;
    for (i = 0; i < n; ++i)
        printf("%d", arr[i]);
    printf("\n");
}
/*leaf check*/
int isLeaf(struct MinHeapNode* root)
{
    return !(root->left) && !(root->right);
}
struct MinHeap* createAndBuildMinHeap(char data[], int freq[], int width)
{
    struct MinHeap* minHeap = createMinHeap(width);
    for (int i = 0; i < width; ++i)
        minHeap->ptr_arr[i] = newNode(data[i], freq[i]);
    minHeap->width = width;
    buildMinHeap(minHeap);

    return minHeap;
}
/* THIS IS THE MAIN FUNCTION TO  BUILD THE HUFFMAN TREE*/
struct MinHeapNode* buildHuffmanTree(char data[], int freq[], int width)
{
    struct MinHeapNode *left, *right, *top;
    struct MinHeap* minHeap = createAndBuildMinHeap(data, freq, width);
    // Iterate while size of heap doesn't become 1
    while (!isSizeOne(minHeap))
   {
        left = extractMin(minHeap);
        right = extractMin(minHeap);
        top = newNode('$', left->freq + right->freq);
        top->left = left;
        top->right = right;

        insertMinHeap(minHeap, top);
    }
    return extractMin(minHeap);
}
void printCodes(struct MinHeapNode* root, int arr[], int top)
{
    if (root->left)
    {
        arr[top] = 0;
        printCodes(root->left, arr, top + 1);
    }
    if (root->right)
    {
        arr[top] = 1;
        printCodes(root->right, arr, top + 1);
    }
   // if leaf found print that character
    if (isLeaf(root))
    {
        printf("%c: ", root->data);
        printArr(arr, top);
    }
}
void HuffmanCodes(char data[], int freq[], int width)
{
    struct MinHeapNode* root = buildHuffmanTree(data, freq, width);
    int arr[th], top = 0;
    printCodes(root, arr, top);
}
int main()
{
  	char arr[100000];
  	int freq[100000];
  	int n;
  	printf("\n Enter the number of the characters in the huffman code :");
  	scanf("%d", &n);
  	printf("\n Enter the character :");
  	for(int i=0;i<n;i++)
        cin>>arr[i];
  	printf("\n Enter the frequency of the characters :");
  	for(int i=0;i<n;i++)
  		scanf("%d",&freq[i]);
    HuffmanCodes(arr, freq, n);
    return 0;
}
