#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
    int* values = calloc(m*n, sizeof(int));
    int** rows = malloc(n*sizeof(int*));
    for (int i=0; i<n; ++i)
    {
        rows[i] = values + i*m;
    }
    return rows;
}

void freeArray(int** arr){
    free(**arr);
    free(*arr);
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
    int** arr = createDoubleArray(2,2);
    arr[0][0] = 1;
    arr[0][1] = 1;
    arr[1][0] = 2;
    arr[1][1] = 2;

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