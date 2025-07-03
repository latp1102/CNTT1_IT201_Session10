#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* createNode(int data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    return node;
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

void inDanhSach(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%d->", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

Node* xoaPhanTu(Node* head, int giaTri) {
    while (head != NULL && head->data == giaTri) {
        Node* temp = head;
        head = head->next;
        free(temp);
    }
    Node* current = head;
    while (current != NULL && current->next != NULL) {
        if (current->next->data == giaTri) {
            Node* temp = current->next;
            current->next = current->next->next;
            free(temp);
        } else {
            current = current->next;
        }
    }
    return head;
}

int main() {
    Node* head = NULL;
    head = themDanhSach(head, 5);
    head = themDanhSach(head, 4);
    head = themDanhSach(head, 3);
    head = themDanhSach(head, 5);
    head = themDanhSach(head, 2);
    head = themDanhSach(head, 1);
    head = themDanhSach(head, 5);

    inDanhSach(head);
    int x;
    printf("nhap gia tri can xoa: ");
    scanf("%d", &x);
    head = xoaPhanTu(head, x);
    inDanhSach(head);
    Node* current = head;
    while (current != NULL) {
        Node* temp = current;
        current = current->next;
        free(temp);
    }
    return 0;
}