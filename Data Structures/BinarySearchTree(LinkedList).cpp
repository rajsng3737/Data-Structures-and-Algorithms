#include<iostream>
#include<random>
using namespace std;
struct BST{
    int element;
    BST *leftC;
    BST *rightC;
}*root;
void insert(int x,BST *rootArg, BST *parentNode){
    if(root == NULL){
        root = new BST();
        root->element = x;
        root->leftC = NULL;
        root->rightC = NULL;
    }
    else if(rootArg == NULL){
        rootArg = new BST();
        rootArg->element = x;
        rootArg->leftC = NULL;
        rootArg->rightC = NULL;
        if(parentNode->element > x)
            parentNode->leftC = rootArg;
        else
            parentNode->rightC = rootArg;
    }
    else{
        if(rootArg->element > x)
            insert(x,rootArg->leftC,rootArg);
        else
            insert(x,rootArg->rightC,rootArg);
    }
}
void postorder(BST *rootArg){
    if(rootArg == NULL)
        return;
    postorder(rootArg->leftC);
    postorder(rootArg->rightC);
    cout<<rootArg->element<<" ";
}
void inorder(BST *rootArg){
    if(rootArg == NULL)
        return ;
    inorder(rootArg->leftC);
    cout<<rootArg->element<<" ";
    inorder(rootArg->rightC);
}
void preorder(BST *rootArg){
    if(rootArg == NULL)
        return;
    cout<<rootArg->element<<" ";
    preorder(rootArg->leftC);
    preorder(rootArg->rightC);
}
int main(){
    cout<<"Inserted values in BST are :- \n";
    int temp;
    for(int i = 0;i<=10;i++){
        temp = rand();
        cout<<temp<<" ";
        insert(temp,root,root);
    }
    cout<<"\n The Preorder travel of generated Binary Search Tree is:- \n";
    preorder(root);
    cout<<"\n The Postorder travel of generated Binary Search Tree is:- \n";
    postorder(root);
    cout<<"\n The Inorder travel of generated Binary Search Tree is:- \n";
    inorder(root);
    return 1;
}