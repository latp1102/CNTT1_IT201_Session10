#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* createNode(int giaTri) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = giaTri;
    newNode->next = NULL;
    return newNode;
}

Node* themDanhSach(Node* head, int giaTri) {
    Node* newNode = createNode(giaTri);
    newNode->next = head;
    return newNode;
}

void inDanhSach(Node* head) {
    Node* newNode = head;
    while (newNode != NULL) {
        printf("%d->", newNode->data);
        newNode = newNode->next;
    }
    printf("NULL\n");
}

void inNode(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("data: %d\n", current->data);
        current = current->next;
    }
}
int main() {
    Node* head = NULL;
    head = themDanhSach(head,1);
    head = themDanhSach(head,2);
    head = themDanhSach(head,3);
    head = themDanhSach(head,4);
    head = themDanhSach(head,5);

    inDanhSach(head);
    inNode(head);
    Node* current = head;
    while (current != NULL) {
        Node* temp = current;
        current = current->next;
        free(temp);
    }
    return 0;

}
