#include <iostream>
#include <stdlib.h>
using namespace std;

struct Node{
    int item;
    struct Node* next;
};

void insertBegin(struct Node** Head, int new_item){
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));

    new_node->item = new_item;
    new_node->next = (*Head);

    (*Head) = new_node;
}

void insertEnd(struct Node** Head, int new_item){
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    struct Node* temp = *Head;

    new_node->item = new_item;
    new_node->next = NULL;

    if(*Head == NULL){
        (*Head) = new_node;
        return;
    }

    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = new_node;
    return;
}


void insertAfter(struct Node** Head, int Item, int new_item){
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    struct Node* temp = *Head;

    while(temp->item != Item){///Assuming the node exists in the list
        temp = temp->next;
    }


    new_node->item = new_item;
    new_node->next = temp->next;
    temp->next = new_node;
}

void deleteNode(struct Node** Head,int key){
    struct Node* temp = *Head, *prev;

    ///item is at the beginning
    if(temp->next != NULL && temp->item == key){
        *Head = temp->next;
        free(temp);
        return;
    }
    ///find the item
    while(temp != NULL && temp->item != key){
        prev = temp;
        temp = temp->next;
    }
    ///key is not found
    if(temp == NULL)return;
    prev->next = temp->next;
    free(temp);
}

void Print(struct Node** Head){
    cout << "Current elements on the list:" << endl;
    struct Node* temp = *Head;

    while(temp->next != NULL){
        cout << temp->item << ' ';
        temp = temp->next;
    }
    cout << temp->item << endl;
}


int main(){
    struct Node* head = NULL;

    insertBegin(&head,4);
    insertBegin(&head,6);
    insertEnd(&head,7);
    insertEnd(&head,3);
    insertAfter(&head,4,5);
    Print(&head);

    deleteNode(&head,7);
    Print(&head);

    return 0;
}
