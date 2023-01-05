// Practicing Linked Nodes and Outputs

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void printdata(struct Node* ptr);

int main() 
{    
    struct Node* head = NULL;
    struct Node* second = NULL;
    struct Node* third = NULL;
    
    struct Node* newNode = NULL;

    head = (struct Node*)malloc(sizeof(struct Node));
    second = (struct Node*)malloc(sizeof(struct Node));
    third = (struct Node*)malloc(sizeof(struct Node));
    
    newNode = (struct Node*)malloc(sizeof(struct Node));

    head->data = 1; 
    head->next = second; 
    second->data = 2; 
    second->next = third; 
    third->data = 3; 
    third->next = NULL; 
    
    newNode->data = 4;
    newNode->next = head;
    
    head = newNode; 
    printdata(head); 

    return 0;
}

void printdata(struct Node* ptr)
{
    while (ptr != NULL) {
        printf("%d\n", ptr->data);
        ptr=ptr->next;
    }
}
