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

void sapXep(Node* head) {
    if (head == NULL) return;
    Node* i = head;
    while (i != NULL) {
        Node* minNode = i;
        Node* j = i->next;
        while (j != NULL) {
            if (j->data < minNode->data) {
                minNode = j;
            }
            j = j->next;
        }
        if (minNode != i) {
            int temp = i->data;
            i->data = minNode->data;
            minNode->data = temp;
        }
        i = i->next;
    }
}

int main() {
    Node* head = NULL;
    head = themDanhSach(head, 5);
    head = themDanhSach(head, 7);
    head = themDanhSach(head, 3);;

    sapXep(head);
    inDanhSach(head);

    Node* current = head;
    while (current != NULL) {
        Node* temp = current;
        current = current->next;
        free(temp);
    }
    return 0;
}