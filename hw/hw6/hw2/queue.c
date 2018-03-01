/**
 * @file queue.c
 */

#include <stdio.h>
#include <stdlib.h>

#include "queue.h"

static void copy_to_node(Item item, Node *pn);
static void copy_to_item(Node *pn, Item *pi);

void initialize_queue(Queue *pq)
{
	pq->front = pq->rear = NULL;
	pq->items = 0;
}

int queue_is_full(const Queue *pq)
{
	return pq->items == MAXQUEUE;
}

int queue_is_empty(const Queue *pq)
{
	return pq->items == 0;
}

int queue_item_count(const Queue *pq)
{
	return pq->items;
}

int enqueue(Item item, Queue *pq)
{
    if(pq == NULL || queue_is_full(pq))
        //case when you cannot operate on it
        return -1;

    Node* newNode = (Node*) malloc(sizeof(Node));

    //allocation guard
    if(newNode == NULL)
        return -1;

    newNode->next = pq->rear;
    copy_to_node(item, newNode);
    pq->items++;
    //enlarge everything

    //change the rear
    pq->rear = newNode;
    if(pq->items == 1)
        pq->front = newNode;

    return 0;
}

int dequeue(Item *pitem, Queue *pq)
{
    if(pq == NULL || queue_is_empty(pq))
        //not suppose to pop
        return -1;

    Node* nd;
    if(pq->items == 1){
        //get the content
        nd = pq->front;
        pq->front = NULL;
        pq->rear = NULL;
        pq->items = 0;
    }
    else{
        nd = pq->front;
        Node* secondFront = pq->rear;

        //move to the element after the front
        while(secondFront->next != nd)
            secondFront = secondFront->next;
        pq->front = secondFront;
        secondFront->next = NULL;
        pq->items--; //decrease the size
    }

    if(nd == NULL)
        //make sure it is null pointer
        return -1;

    copy_to_item(nd, pitem);
    //remove the node
    //deallocate
    free(nd);
    return 0;
}

void empty_queue(Queue *pq)
{
	Item dummy;
	while (!queue_is_empty(pq)) {
		dequeue(&dummy, pq);
	}
}

static void copy_to_node(Item item, Node *pn)
{
	pn->item = item;
}

static void copy_to_item(Node *pn, Item *pi)
{
	*pi = pn->item;
}
