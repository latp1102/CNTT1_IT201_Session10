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
    if (head == NULL) {
        return newNode;
    }
    Node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
    return head;
}

Node* xoaCuoi(Node* head) {
    if (head == NULL) return;
    if (head->next == NULL) {
        free(head);
        return NULL;
    }
    Node* current = head;
    while (current->next->next != NULL) {
        current = current->next;
    }
    free(current->next);
    current->next = NULL;
    return head;
}

void inDanhSach(Node* head) {
    Node* current = head;
    while (current != NULL) {
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
    printf("xoa phan tu cuoi: ");
    head = xoaCuoi(head);
    inDanhSach(head);

    Node* current = head;
    while (current != NULL) {
        Node* temp = current;
        current = current->next;
        free(temp);
    }
    return 0;
}
