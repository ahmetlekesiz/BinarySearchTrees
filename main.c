#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <rpcndr.h>

#define inputMax 100
#define resultMax 100000000

struct node{
    int key;
    struct node *left;
    struct node *right;
}typedef node;

node* newNode(node*, int);
node* insertNode(node*, int);
int** createDoubleArray(int m, int n){
    int* values = calloc(n * m, sizeof(int));
    int** rows = malloc(m * sizeof(int*));
    for (int i=0; i < m; ++i)
    {
        rows[i] = values + i * n;
    }
    return rows;
}
/*
void freeArray(int** arr){
    free(**arr);
    free(*arr);
}*/

void initializeArray(int* arr, int defaultValue, int arrSize){
    for (int i = 0; i < arrSize; ++i) {
        arr[i] = defaultValue;
    }
}


int lengthOfArray(int* arr, int arrSize){
    //assume array initialized to -1
    int counter = 0;
    for (int i = 0; i < arrSize; ++i) {
        if(arr[i] == -1){
            return counter;
        }
        counter++;
    }
    return arrSize;
}

int* mergeTwoArrays(int* firstArray, int* secondArray, int firstSize, int secondSize){
    int lenFirst = lengthOfArray(firstArray, firstSize);
    int lenSecond = lengthOfArray(secondArray, secondSize);
    int lenResult = lenFirst + lenSecond;
    int iter = lenFirst;
    int result[lenResult];
    int *p = result;
    for (int i = 0; i < lenFirst ; ++i) {
        result[i] = firstArray[i];
    }
    for (int j = 0; j < lenSecond ; ++j) {
        result[iter] = secondArray[j];
        iter++;
    }
    return p;
}

int isArrayEmpty(int* arr){
    if(arr[0] == -1){
        return 1;
    }else{
        return 0;
    }
}

int** findCombinations(int* support, int* firstSubtree, int* secondSubtree, int suppSize, int firstSize, int secondSize, int** result){
    int resultCounter = 0;
    //if firstSubtree == 0 or secondSubtree == 0, join and return
    if(isArrayEmpty(firstSubtree) == 1 || isArrayEmpty(secondSubtree) == 1){
        //results.append(support + firstSubtree + secondSubtree)
        int firstMergeSize = suppSize + firstSize;
        int *firstMerge;
        firstMerge = mergeTwoArrays(support, firstMerge, suppSize, firstSize);
        int* resultArray;
        resultArray = mergeTwoArrays(firstMerge, secondSubtree, firstMergeSize, secondSize);
        result[resultCounter] = resultArray;
        resultCounter++;
        return result;
    }
    //****For First Subtree****//
    //move the item which in the left from firstSubtree to supportArray
    findCombinations(support, firstSubtree, secondSubtree, suppSize, firstSize, secondSize, result);
    //return back the item which is in the right to firstSubtree

    //****For Second Subtree****//
    //move the item which in the left from secondSubtree to supportArray
    //findCombinations()
    //return back the item which is in the right to firstSubtree
}


int main() {
    //initilize input sequence
    printf("Please enter the sequence to build the Binary Search Tree. \n");

    char input[inputMax];
    int nodes[inputMax];

    fgets(input, inputMax, stdin);
    printf("%s", input);
    // Extract the first token
    char * token = strtok(input, " ");
    // loop through the string to extract all other tokens
    for (int i = 0; i < inputMax ; ++i) {
        nodes[i] = 'a';
    }
    int counter = 0;
    while( token != NULL ) {
        int deneme = atoi(token);
        nodes[counter] = deneme;
        printf( " %s\n", token ); //printing each token
        token = strtok(NULL, " ");
        counter++;
    }

    //Binary Search Tree
    node* root = NULL;
    for (int j = 0; j < counter ; ++j) {
        int deneme = nodes[j];
        root = insertNode(root, deneme);
    }

    //Create 2D Array
    int** arr = createDoubleArray(3,2);
    arr[0][0] = 1;
    arr[0][1] = 1;
    arr[1][0] = 2;
    arr[1][1] = 2;
    arr[2][0] = 3;
    arr[2][1] = 3;

    for (int k = 0; k < 3 ; ++k) {
        for (int i = 0; i < 2 ; ++i) {
            printf("%d", arr[k][i]);
        }
    }

    return 0;
}

node* newNode(node *nodePointer, int key) {
    nodePointer = (node*)malloc(sizeof(node));
    nodePointer->key = key;
    nodePointer->left = NULL;
    nodePointer->right = NULL;
}

node* insertNode(node *nodePointer, int key){
    node *temp;
    if(nodePointer == NULL){
        //createNode
        nodePointer = newNode(nodePointer, key);
        return nodePointer;
    }
    else if(key < nodePointer->key){
        //add to left
        nodePointer->left = insertNode(nodePointer->left, key);
    }else if(key > nodePointer->key){
        //add to right
        nodePointer->right = insertNode(nodePointer->right, key);
    }
    return nodePointer;
}