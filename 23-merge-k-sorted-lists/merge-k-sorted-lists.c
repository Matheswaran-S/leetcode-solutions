/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
#include <stdio.h>
#include <stdlib.h>

struct MinHeapNode {
    struct ListNode* node;
};

struct MinHeap {
    struct MinHeapNode* array;
    int size;
    int capacity;
};

void swap(struct MinHeapNode *a, struct MinHeapNode *b) {
    struct MinHeapNode temp = *a;
    *a = *b;
    *b = temp;
}

void minHeapify(struct MinHeap* minHeap, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < minHeap->size && minHeap->array[left].node->val < minHeap->array[smallest].node->val)
        smallest = left;

    if (right < minHeap->size && minHeap->array[right].node->val < minHeap->array[smallest].node->val)
        smallest = right;

    if (smallest != i) {
        swap(&minHeap->array[i], &minHeap->array[smallest]);
        minHeapify(minHeap, smallest);
    }
}

void buildMinHeap(struct MinHeap* minHeap) {
    int i = (minHeap->size - 1) / 2;
    while (i >= 0) {
        minHeapify(minHeap, i);
        i--;
    }
}

struct ListNode* extractMin(struct MinHeap* minHeap) {
    if (minHeap->size == 0)
        return NULL;

    struct ListNode* root = minHeap->array[0].node;

    if (root->next) {
        minHeap->array[0].node = root->next;
    } else {
        minHeap->array[0] = minHeap->array[minHeap->size - 1];
        minHeap->size--;
    }
    minHeapify(minHeap, 0);
    return root;
}

struct ListNode* mergeKLists(struct ListNode** lists, int listsSize) {
    if (listsSize == 0) return NULL;

    struct MinHeap* minHeap = (struct MinHeap*)malloc(sizeof(struct MinHeap));
    minHeap->array = (struct MinHeapNode*)malloc(sizeof(struct MinHeapNode) * listsSize);
    minHeap->size = 0;
    minHeap->capacity = listsSize;

    for (int i = 0; i < listsSize; i++) {
        if (lists[i]) {
            minHeap->array[minHeap->size++].node = lists[i];
        }
    }
    buildMinHeap(minHeap);

    struct ListNode dummy;
    struct ListNode* tail = &dummy;
    dummy.next = NULL;

    while (minHeap->size > 0) {
        struct ListNode* minNode = extractMin(minHeap);
        tail->next = minNode;
        tail = tail->next;
    }

    free(minHeap->array);
    free(minHeap);

    return dummy.next;
}
