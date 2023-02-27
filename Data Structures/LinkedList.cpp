#include<iostream>
using namespace std;
struct LinkedList{
    int element;
    LinkedList *next;
}*head;
int insertAtBegining(int x, LinkedList *argNode){
    LinkedList *temp = new LinkedList();
    temp->element = x;   //(*temp).element = x;
    if(argNode == NULL){
        temp->next == NULL;
        head = temp;
        return 1;
    }
    temp->next = argNode;
    head = temp;
    return 1;
}
int insertAtEnding(int x, LinkedList* argNode){
    LinkedList *temp = new LinkedList();
    temp->element = x;
    temp->next = NULL;
    if(argNode == NULL){
        head = temp;
    }
    while(argNode->next != NULL){
        argNode = argNode->next;
    }
    argNode->next = temp;
    return 1;
}
int insertAfter(int x, int y, LinkedList* argNode){ //x elememt already present in linked list
    if(argNode == NULL)
        return 0;
    while(argNode->element != x && argNode->next !=  NULL){
        argNode = argNode->next;
    }
    if(argNode->element == x){
        LinkedList *temp = new LinkedList();
        temp->element = y;
        if(argNode->next!=NULL){
            temp->next = argNode->next;
            argNode->next = temp;
            return 1;
        }
        else{
            argNode->next = temp;
            temp->next = NULL;
            return 1;
        }
    }
    else return 0;
}
int deleteNode(int x, LinkedList *argNode){
    LinkedList *prevNode = argNode;
    if(argNode == NULL)
        return 0;
    if(argNode->next == NULL && argNode->element == x){
        free(argNode);
        head = NULL;
    }
    while(argNode->element != x && argNode->next != NULL){
        prevNode = argNode;
        argNode = argNode->next;
    }
    if(argNode->element == x){
        prevNode->next = argNode->next;
        free(argNode);
        return 1;
    }
    else{
        return 0;
    }
}
int deleteBeginning(LinkedList *argNode){
    if(!argNode)\
        return 0;
    else{
        head = argNode->next;
        free(argNode);
        return 1;
    }
}
int deleteLast(LinkedList *argNode){
    LinkedList *prevNode = NULL;
    if(argNode == NULL){
        return 0;
    }
    while(argNode->next!=NULL)
    {
        prevNode = argNode;
        argNode = argNode->next;
    }
    if(prevNode == NULL){
        free(argNode);
        head = NULL;
        return 1;
    }
    else{
        prevNode->next = NULL;
        free(argNode);
        return 1;
    }
}
void printLL(LinkedList *argNode){
    while(argNode != NULL){
        cout<<argNode->element<<" ";
        argNode = argNode->next;
    }
}
int main(){
    for(int i = 0;i<10;i++){
        if(i%2 == 0)
            insertAtBegining(i,head);
        else
            insertAtEnding(i,head);
    }
    printLL(head);
    for(int i = 0;i<10;i++){
        if(i%2 == 0)
            deleteBeginning(head);
        else
            deleteLast(head);
        cout<<"\n";
        printLL(head);
    }

}