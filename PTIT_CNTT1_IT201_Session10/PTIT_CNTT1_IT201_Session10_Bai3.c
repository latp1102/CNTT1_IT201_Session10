#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

Node* themDanhSach(Node* head, int giaTri) {
    Node* newNode = createNode(giaTri);
    if(head == NULL) {
        return newNode;
    }
    Node* current = head;
    while(current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
    return head;
}

void inDanhSach(Node* head) {
    Node* current = head;
    while(current != NULL) {
        printf("%d->", current->data);
        current = current->next;
    }
    printf("NULL\n");
}


int main() {
    Node* head = NULL;
    head = themDanhSach(head, 5);
    head = themDanhSach(head, 4);
    head = themDanhSach(head, 3);
    head = themDanhSach(head, 2);
    head = themDanhSach(head, 1);

    inDanhSach(head);
    int x;
    printf("nhap gia tri muon them: ");
    scanf("%d", &x);
    head = themDanhSach(head, x);
    inDanhSach(head);

    Node* current = head;
    while(current != NULL) {
        Node* temp = current;
        current = current->next;
        free(temp);
    }
    return 0;
}