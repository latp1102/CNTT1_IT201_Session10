#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* newNode(int giaTri) {
    Node* node = (Node*)malloc(sizeof(Node));
    if (node == NULL) {
        printf("ko tim thay");
        return 0;
    }
    node->data = giaTri;
    node->next = NULL;
    return node;
}

Node* themDanhSach(Node* head, int giaTri) {
    Node* node = newNode(giaTri);
    if (head == NULL) {
        return node;
    }
    Node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = node;
    return head;
}

void inDanhSach(Node* head) {
    Node* current = head;
    printf("danh sach lien ket: ");
    while (current != NULL) {
        printf("%d->", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    Node* head = NULL;
    head = themDanhSach(head, 1);;
    head = themDanhSach(head, 2);
    head = themDanhSach(head, 3);
    head = themDanhSach(head, 4);
    head = themDanhSach(head, 5);

    inDanhSach(head);
    return 0;
}