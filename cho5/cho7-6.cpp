#include <stdio.h>
#include <stdlib.h>
#define MAX_ELEMENT 100

typedef struct {
	int heap[MAX_ELEMENT];
	int heap_size;
}heapType;

heapType* createHeap() {
	heapType* h = (heapType*)malloc(sizeof(heapType));
	h->heap_size = 0;
	return h;
}
void insertHeap(heapType* h, int item) {
	int i;
	h->heap_size = h->heap_size + 1;
	i = h->heap_size;
	while ((i != 1) && (item > h->heap[i / 2])) {
		h->heap[i] = h->heap[i / 2];
		i /= 2;
	}
	h->heap[i] = item;
}
int deleteHeap(heapType* h) {
	int parent, child;
	int item, temp;
	item = h->heap[1];
	temp = h->heap[h->heap_size];
	h->heap_size = h->heap_size - 1;
	parent = 1;
	child = 2;
	while (child <= h->heap_size) {
		if ((child < h->heap_size) && (h->heap[child]) < h->heap[child + 1])
			child++;
		if (temp >= h->heap[child]) break;
		else {
			h->heap[parent] = h->heap[child];
			parent = child;
			child = child * 2;
		}
	}
	h->heap[parent] = temp;
	return item;
}
void printHeap(heapType* h){
	int i;
	printf("Heap :");
	for (i = 1; i <= h->heap_size; i++)
		printf("[%d]", h->heap[i]);
}
void main() {
	int i, n, item;
	heapType* heap = createHeap();
	insertHeap(heap, 10);
	insertHeap(heap, 45);
	insertHeap(heap, 19);
	insertHeap(heap, 11);
	insertHeap(heap, 96);

	printHeap(heap);

	n = heap->heap_size;
	for(i = 1; i <= n; i++){
		item = deleteHeap(heap);
		printf("\n delete : [%d]", item);
}
	getchar();

}