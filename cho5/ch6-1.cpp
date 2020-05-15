#include <stdio.h>
#include <stdlib.h>
#define Q_SIZE 4

typedef char element;
typedef struct {
	element queue[Q_SIZE];
	int front, rear;
}QueueType;

QueueType* createQueue() {
	QueueType* Q;
	Q = (QueueType*)malloc(sizeof(QueueType));
	Q->front = -1;
	Q->rear = -1;
	return Q;
}
int isEmpty(QueueType* Q) {
	if (Q->front == Q->rear) {
		printf("Queue is empty!");
		return 1;
	}
	else return 0;
}
int isFull(QueueType* Q) {
	if (Q->rear == Q_SIZE - 1) {
		printf("Queue is full!");
		return 1;
	}
	else return 0;
}
void enQueue(QueueType* Q, element item) {
	if (isFull(Q))return;
	else {
		Q->rear++;
		Q->queue[Q->rear] = item;
	}
}
element deQueue(QueueType* Q) {
	if (isEmpty(Q)) return' ';
	else {
		Q->front++;
		return Q->queue[Q->front];
	}
}
element peek(QueueType* Q) {
	if (isEmpty(Q)) exit(1);
	else return Q->queue[Q->front + 1];
}
void printQ(QueueType* Q) {
	int i;
	printf("Queue : [");
	for (i = Q->front + 1; i <= Q->rear; i++)
		printf("%3c", Q->queue[i]);
	printf("]");
}
void main(void) {
	QueueType* Q1 = createQueue();
	element data;
	printf("\n ***** ���� ť ���� ***** \n");
	printf("\n ���� A>>"); enQueue(Q1, 'A'); printQ(Q1);
	printf("\n ���� B>>"); enQueue(Q1, 'B'); printQ(Q1);
	printf("\n ���� C>>"); enQueue(Q1, 'C'); printQ(Q1);
	data = peek(Q1); printf(" peek item : %c \n", data);
	printf("\n ���� >>"); data = deQueue(Q1); printQ(Q1);
	printf("\t���� ������ : %c", data);
	printf("\n ���� >>"); data = deQueue(Q1); printQ(Q1);
	printf("\t���� ������ : %c", data);
	printf("\n ���� >>"); data = deQueue(Q1); printQ(Q1);
	printf("\t\t���� ������ : %c", data);

	printf("\n ���� D>>"); enQueue(Q1, 'D'); printQ(Q1);
	printf("\n ���� E>>"); enQueue(Q1, 'E'); printQ(Q1);
	getchar();
}