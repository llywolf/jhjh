#include "cozi.h"

Queue* createQueue(){
	Queue *q;
	q=(Queue *)malloc(sizeof(Queue));
	if (q==NULL) return NULL;	
	q->qFront=q->qRear=NULL;
	return q;	
}

 void enQueue(Queue*q, Data1 v){
	qNode* newqNode=(qNode*)malloc(sizeof(qNode));
	newqNode->val=v;
	newqNode->next=NULL;
	if (q->qRear==NULL) q->qRear=newqNode;
	else{
		(q->qRear)->next=newqNode;
		(q->qRear)=newqNode;
	}
	if (q->qFront==NULL) q->qFront=q->qRear;
}
 
Data1 deQueue(Queue*q) {
	qNode* aux; Data1 d;
	if (isqEmpty(q)) return INT_MIN;
	
	aux=q->qFront;
	d=aux->val;
	q->qFront=(q->qFront)->next;
	free(aux);
	return d;  	
} 

int isqEmpty(Queue* q){
	return (q->qFront==NULL);
}

void deleteQueue(Queue*q){
	qNode* aux;
	while (!isqEmpty(q)){
		aux=q->qFront;
		q->qFront=q->qFront->next;
		free(aux);
	}
	free(q);
}

void printQueue(Queue* queue){
    printf("\n");
    while(!isqEmpty(queue)){
        printf("%d ", deQueue(queue));
    }
}

Data1 peekQueue(Queue* queue){
    Data1 result = queue->qFront->val;
    return result;
}
