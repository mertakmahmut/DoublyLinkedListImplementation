#include <iostream>

using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* prev;
};
Node* addItemFront(Node* head, int key){
    if(head == NULL){
        Node* temp = new Node();
        temp->data = key;
        temp->next = NULL;
        temp->prev = NULL;
        head = temp;
        cout << "First node inserted which is our head." << endl ;
    }
    else{
        Node* temp = new Node();
        temp->data = key;
        temp->next = head;
        head->prev = temp;
        head = temp;
        cout << "Node added to head." << endl ;
    }
    return head;
}
Node* addItemTail(Node* head, int key){
    if(head == NULL){
        Node* temp = new Node();
        temp->data = key;
        temp->next = NULL;
        temp->prev =NULL;
        head = temp;
        cout << "First node inserted which is our tail." << endl ;
    }
    else{
        Node* temp = new Node();
        temp->data = key;
        temp->next = NULL;
        Node* temp2 = head;
        while(temp2->next != NULL){
            temp2 = temp2->next;
        }
        temp2->next = temp;
        temp->prev = temp2;
        cout << "New node added to tail." << endl ;
    }
    return head;
}
void printList(Node* head){
    system("cls");
    Node* temp = head;
    while(temp != NULL){
        cout << temp->data << endl ;
        temp = temp->next;
    }
}
Node* addItemSecond(Node* head, int key){
    if(head == NULL){
        Node* temp = new Node();
        temp->data = key;
        temp->next = NULL;
        temp->prev = NULL;
        head = temp;
    }
    else{
        Node* temp = new Node();
        temp->data = key;
        Node* temp2 = head;
        temp2 = temp2->next;

        Node* temp3 = temp2->prev;
        Node* temp4 = temp2;
        temp3->next = temp;
        temp->prev = temp3;
        temp->next = temp4;
        temp4->prev = temp;
        cout << "Node added to second position." << endl ;

    }
    return head;
}
void getItemFront(Node* head){
    cout << "The first item: " << head->data << endl ;
}
void getItemTail(Node* head){
    Node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    cout << "The tail is : " << temp->data << endl ;
}
Node* deleteItemFront(Node* head){
    if(head == NULL){
        cout << "The list is empty." << endl ;
    }
    else{
        if(head->next == NULL){
            delete head;
            head = NULL;
            cout << "The last node is deleted which was head." << endl ;
        }
        else{
            Node* temp = head->next;
            delete head;
            head = temp;
            head->prev = NULL;
            cout << "Head node is deleted." << endl ;
        }
    }
    return head;
}
Node* deleteItemTail(Node* head){
    if(head == NULL){
        cout << "The list is empty." << endl ;
    }
    else{
        if(head->next == NULL){
            delete head;
            head = NULL;
            cout << "The last node is deleted which was tail." << endl ;
        }
        else{
            Node* temp = head;
            while(temp->next != NULL){
                temp = temp->next;
            }
            Node* temp2 = temp->prev;
            delete temp;
            temp2->next = NULL;
            cout << "The tail is deleted." << endl ;
        }
        return head;
}
}
Node* deleteAllItems(Node* head){
    Node* temp = head;
    while(head != NULL){
        temp = head;
        head = head->next;
        delete temp;
    }
    cout << "All items deleted. " << endl ;
    return head;
}
int main()
{
    Node* head = NULL;
    int choice, number;
    while(1){
        cout << endl ;
        cout << "1- Add an item to the front" << endl ;
        cout << "2- Add an item to the tail" << endl;
        cout << "3- Add an item to the second position in the list" << endl;
        cout << "4- Get the item in the front" << endl ;
        cout << "5- Get the item in the tail" << endl ;
        cout << "6- Remove an item from the front" << endl ;
        cout << "7- Remove an item from the tail" << endl ;
        cout << "8- Remove all items from the list" << endl ;
        cout << "9- PRINT" << endl ;
        cout << "0- EXIT" << endl ;
        cin >> choice;
        switch(choice){
            case 0: return 0; break;
            case 9: printList(head); break;
            case 1: cout << "Number: " ; cin>>number;
            head = addItemFront(head, number); break;
            case 2: cout << "Number: " ; cin>>number;
            head = addItemTail(head, number); break;
            case 3: cout << "Number: " ; cin>>number;
            head = addItemSecond(head, number); break;
            case 4: getItemFront(head); break;
            case 5: getItemTail(head); break;
            case 6: head = deleteItemFront(head); break;
            case 7: head = deleteItemTail(head); break;
            case 8: head = deleteAllItems(head); break;

        }
    }

    return 0;
}
