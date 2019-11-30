#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

struct node{
    int key;
    struct node *left;
    struct node *right;
}typedef node;

node* newNode(node*, int);
node* insertNode(node*, int);

int main() {
    //initilize input sequence
    printf("Please enter the sequence to build the Binary Search Tree. \n");

    char input[MAX];
    int nodes[MAX];
    fgets(input, MAX, stdin);
    printf("%s", input);
    // Extract the first token
    char * token = strtok(input, " ");
    // loop through the string to extract all other tokens
    for (int i = 0; i < MAX ; ++i) {
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