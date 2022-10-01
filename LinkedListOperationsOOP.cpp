#include <iostream>
#include <stdlib.h>
using namespace std;

struct Node{
    int item;
    struct Node* next;
};

class LinkedList{
public:
    struct Node* head;

    LinkedList(){
        head = NULL;
    }

    void InsertBegin(int new_item){
        struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
        new_node->item = new_item;
        new_node->next = head;

        head = new_node;
    }

    void InsertEnd(int new_item){
        struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
        struct Node* temp = head;

        while(temp->next != NULL){
            temp = temp->next;
        }
        new_node->item = new_item;
        new_node->next = NULL;
        temp->next = new_node;
    }

    void InsertAfter(int new_item,int key){
        struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
        struct Node* temp = head;

        while(temp->item != key){
            temp = temp->next;
        }

        if(temp->item != key){
            cout << "Key does not exist!" << endl;
        }
        new_node->item = new_item;
        new_node->next = temp->next;
        temp->next = new_node;
    }

    void Print(){
        struct Node* temp = head;
        cout<< "Elements on the list are:" << endl;
        while(temp->next != NULL){
            cout << temp->item << ' ';
            temp = temp->next;
        }
        cout << temp->item << endl;
    }

    void DeleteItem(int key){
        struct Node* temp = head,*prevNode;

        if(head->item == key){
            head = temp->next;
            return;
        }

        while(temp->item != key){
            prevNode = temp;
            temp = temp->next;
        }
        prevNode->next = temp->next;

    }

    void SortList(){
        struct Node* temp = head, *cur, *swp;
        int val;

        while(temp != NULL){
            cur = temp->next;
            while(cur != NULL){
                if(temp->item > cur->item)
                {
                    val = temp->item;
                    temp->item = cur->item;
                    cur->item = val;
                }
                cur = cur->next;
            }
            temp = temp->next;
        }
    }
};


int main(){
    LinkedList myList;
    myList.InsertBegin(3);
    myList.InsertBegin(6);
    myList.InsertEnd(1);
    myList.InsertEnd(7);
    myList.InsertAfter(5,3);
    myList.Print();

    myList.SortList();
    myList.Print();

    myList.DeleteItem(3);
    myList.Print();

    return 0;
}
