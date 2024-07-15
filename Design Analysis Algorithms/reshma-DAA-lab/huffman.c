#include <stdio.h>
#include <stdlib.h>
struct Node {
char data;
int frequency;
struct Node *left, *right;
};
struct PriorityQueueNode {
struct Node *data;
struct PriorityQueueNode *next;
};
struct PriorityQueue {
struct PriorityQueueNode *front;
};
struct Node* createNode(char data, int frequency) {
struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
newNode->data = data;
newNode->frequency = frequency;
newNode->left = newNode->right = NULL;
return newNode;
}
struct PriorityQueueNode* createPriorityQueueNode(struct Node *data) {
struct PriorityQueueNode* newNode = (struct PriorityQueueNode*)malloc(sizeof(struct
PriorityQueueNode));
newNode->data = data;
newNode->next = NULL;
return newNode;
}
struct PriorityQueue* createPriorityQueue() {
struct PriorityQueue* queue = (struct PriorityQueue*)malloc(sizeof(struct PriorityQueue));
queue->front = NULL;
return queue;
}
int isEmpty(struct PriorityQueue *queue) {
return (queue->front == NULL);
}
void insert(struct PriorityQueue *queue, struct Node *data) {
struct PriorityQueueNode* newNode = createPriorityQueueNode(data);
if (isEmpty(queue) || data->frequency < queue->front->data->frequency) {
newNode->next = queue->front;
queue->front = newNode;
} else {
struct PriorityQueueNode *temp = queue->front;
while (temp->next != NULL && temp->next->data->frequency < data->frequency) {
temp = temp->next;
}
newNode->next = temp->next;
temp->next = newNode;
}
}
struct Node* removeFront(struct PriorityQueue *queue) {
if (isEmpty(queue)) {
return NULL;
}
struct Node *data = queue->front->data;
struct PriorityQueueNode *temp = queue->front;
queue->front = queue->front->next;
free(temp);
return data;
}
struct Node* buildHuffmanTree(char data[], int frequency[], int n) {
struct PriorityQueue* queue = createPriorityQueue();
for (int i = 0; i < n; i++) {
struct Node* newNode = createNode(data[i], frequency[i]);
insert(queue, newNode);
}
while (!isEmpty(queue) && queue->front->next != NULL) {
struct Node* left = removeFront(queue);
struct Node* right = removeFront(queue);
struct Node* newNode = createNode('$', left->frequency + right->frequency);
newNode->left = left;
newNode->right = right;
insert(queue, newNode);
}
return removeFront(queue);
}
void printHuffmanCodes(struct Node* root, int codes[], int top) {
if (root->left) {
codes[top] = 0;
printHuffmanCodes(root->left, codes, top + 1);
}
if (root->right) {
codes[top] = 1;
printHuffmanCodes(root->right, codes, top + 1);
}
if (!(root->left) && !(root->right)) {
printf("Character: %c, Huffman Code: ", root->data);
for (int i = 0; i < top; i++) {
printf("%d", codes[i]);
}
printf("\n");
}
}
int main() {
int n;
printf("Enter the number of characters: ");
scanf("%d", &n);
char data[n];
int frequency[n];
for (int i = 0; i < n; i++) {
printf("Enter character and frequency for character %d: ", i + 1);
scanf(" %c %d", &data[i], &frequency[i]);
}
struct Node* root = buildHuffmanTree(data, frequency, n);
int codes[n];
printf("Huffman Codes:\n");
printHuffmanCodes(root, codes, 0);
return 0;
}