#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};


int height(struct Node* node) {
    if (node == NULL)
        return 0;
    else {
        int lheight = height(node->left);
        int rheight = height(node->right);
 
        if (lheight > rheight)
            return (lheight + 1);
        else
            return (rheight + 1);
    }
}


void printCurrentLevel(struct Node* root, int level) {
    if (root == NULL)
        return;
    if (level == 1)
        printf("%d ", root->data);
    else if (level > 1) {
        printCurrentLevel(root->left, level - 1);
        printCurrentLevel(root->right, level - 1);
    }
}


void printLevelOrder(struct Node* root) {
    int h = height(root);
    int i;
    for (i = 1; i <= h; i++)
        printCurrentLevel(root, i);
}
 

struct Node* newNode(int key) {
    struct Node* temp
        = (struct Node*)malloc(sizeof(struct Node));
    temp->data = key;
    temp->left = temp->right = NULL;
    return temp;
}

struct Node* insert(struct Node* node, int key) {
    if (node == NULL)
        return newNode(key);
 
    if (key % 4 == 0)
        node->left = insert(node->left, key);
    else
        node->right = insert(node->right, key);
 
    return node;
}


void preorder(struct Node* root)
{
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

int main() {
    int i,j,T, N, arr[1000];
    scanf("%d", &T);
    
    for(i = 0; i < T; i++){
         struct Node *root = NULL;
        scanf("%d", &N);
        for(j = 0; j < N; j++)
            scanf("%d", &arr[j]);
        
        root = insert(root, arr[0]);
        for(j = 1; j < N; j++)
            insert(root, arr[j]);
        
        printLevelOrder(root);
        printf("\n");
    }
    return 0;
}
