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
    newNode->next = head;
    head = newNode;
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

int demPhanTu(Node* head) {
    int count = 0;
    Node* current = head;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}
void timPhanTuGiua(Node* head) {
    if (head == NULL) {
        printf("NULL\n");
        return;
    }
    int length = demPhanTu(head);
    int minIndex = length / 2;
    Node* current = head;
    int index = 0;
    while (index < minIndex) {
        current = current->next;
        index++;
    }
    printf("Node %d: %d\n", minIndex + 1, current->data);
}

int main() {
    Node* head = NULL;
    head = themDanhSach(head, 1);
    head = themDanhSach(head, 2);
    head = themDanhSach(head, 3);
    head = themDanhSach(head, 4);
    head = themDanhSach(head, 5);

    inDanhSach(head);
    timPhanTuGiua(head);

    Node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = createNode(6);
    inDanhSach(head);
    timPhanTuGiua(head);

    current = head;
    while (current != NULL) {
        Node* temp = current;
        current = current->next;
        free(temp);
    }
    return 0;
}