#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#define true 1!=0
#define false !true
typedef struct bstnode{
    uint32_t data;
    struct bstnode* left;
    struct bstnode* right;
}treenode;
treenode* create_node(uint32_t data);
treenode* insert_node(treenode* root, uint32_t data);
treenode* root = NULL;
uint32_t arr[10] = {1,6,3,8,7,9,0,2,5,4};
static uint16_t arr_len = sizeof(arr)/sizeof(arr[0]);
treenode* create_node(uint32_t data){
    treenode* p = (treenode*)malloc(sizeof(treenode)*1);
    if(p!=NULL){
        p->left = NULL;
        p->right = NULL;
        p->data = data;
    }
    return p;
}
treenode* insert_node(treenode* root, uint32_t data){
    if(root==NULL){
        root = create_node(data);
        return root;
    }else if(data<=root->data){
        root->left = insert_node(root->left, data);
    }else{
        root->right = insert_node(root->right, data);
    }
    return root;
}
uint8_t search(treenode* root, uint32_t data){
    if(root==NULL){
        return false;
    }else if(root->data==data){
        return true;
    }else if(data<=root->data){
        return search(root->left, data);
    }else{
        return search(root->right, data);
    }
}
int main(int argc, char* argv[], char** env){
    uint32_t value;
    uint8_t opt;
    for(int i=0; i<arr_len; i++){
        root = insert_node(root, arr[i]);
    }
    for(int i=0; i<arr_len; i++){
        printf("%d\n", search(root, arr[i]));
    }
    // printf("%d\n", search(root, 100));
    return 0;
}