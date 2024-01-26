#include <stdio.h>
#include <stdlib.h>

struct Node {
    // payload
    int data;
    // pointer
    struct Node* next;
};

// Function to create a new node with a certian payload
struct Node* createNode(int data){
    // allocate memory for this new node
    // done by taking the size of the linkedlist (data+nodeNext)
    // recall malloc is dynamic memory allocation
    // (struct Node*) casts the return of malloc to the struct datatype
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    // now we should ensure the memory allocation was a succcess
    if (newNode != NULL) {
        // if so, add payload and pointer to newNode
        newNode->data = data;
        newNode->next = NULL;
    //else describe the error
    } else {
        fprintf(stderr, "Failed to allocate memory for new node.\n");
    }

    return newNode;
}

// Function to append a new node with data to the end of the linked list
void appendNode(struct Node** head, int data) {
    // create the new node
    struct Node* newNode = createNode(data);

    // if the new node is appended to an empty list, make this node the head
    if (*head == NULL) {
        *head = newNode;

    //else append the new node to the end of the list
    } else {
        // create a pointer to current, which begins at the head
        struct Node* current =*head;
        // while the next pointer of current is not null
        while (current->next != NULL) {
            // more the current pointer down the line
            current = current->next;
        }
        // now current points to the last node in the list, so we can add our new node
        current->next = newNode;
        
    }
}

//Function to delete node, given a certian key
void deleteNode(struct Node** head, int key) {
    // get head
    struct Node* temp = *head;
    // get prev
    struct Node* prev = NULL;

    // what if the key is in the head node?
    if (temp != NULL && temp->data == key) {
        // decouple the head
        *head = temp->next;
        // free the storage space
        free(temp);
        return;
    }

    // look for the key to be deleted 
    while(temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    // what if the key isnt present at all
    if (temp == NULL) {        
        printf("Key %d not found in the linked list.\n", key);
        return;
    }
    
    // Unlink the node from the linked list
    prev->next = temp->next;

    // Free the memory allocated for the node
    free(temp);
}

// Function to print the elements of the linked list
void printList(struct Node* head) {
    // Start at the head of the linked list
    struct Node* current = head;
    
    // Traverse the list and print each element
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    
    // Print NULL to indicate the end of the list
    printf("NULL\n");
}

// Function to free the memory allocated for the linked list
void freeList(struct Node* head) {
    // Start at the head of the linked list
    struct Node* current = head;
    
    // Traverse the list, free each node, and move to the next node
    while (current != NULL) {
        struct Node* nextNode = current->next;
        free(current);
        current = nextNode;
    }
}

int main(int argc, char ** argv) {
    // Initialize an empty linked list
    struct Node* head = NULL;

    // Append nodes with values 1, 2, and 3 to the linked list
    appendNode(&head, 7);
    appendNode(&head, 1);
    appendNode(&head, 2);
    appendNode(&head, 3);

    // Print the linked list
    printf("Linked List: ");
    printList(head);

    // Delete a node with value 2 from the linked list
    deleteNode(&head, 1);

    // Print the linked list after deleting the node with value 2
    printf("Linked List after deleting node with value 1: \n");
    printList(head);

    // Free the memory allocated for the linked list
    freeList(head);
}