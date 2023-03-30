#include "stive.h"

Data top(Node *top){
	if (isEmpty(top))
        return INT_MIN;
	return top->val;
}

void push(Node**top, Data v) {
	Node* newNode=(Node*)malloc(sizeof(Node));
	newNode->val=v;
	newNode->next=*top;
	*top=newNode;
}

Data pop(Node**top) {
	if (isEmpty(*top)) return INT_MIN;
	Node *temp=(*top);
	Data aux=temp->val;
	*top=(*top)->next;
	free(temp);
	return aux;
}

int isEmpty(Node*top){
	return top==NULL;
}

void deleteStack(Node**top){
	Node  *temp;
	while (!isEmpty(*top))
    {
		temp=*top;
		*top=(*top)->next;
		free(temp);
	}
}

void print(Node *top){
    while(!isEmpty(top)){
        printf("%c ", top->val);
        top = top->next;
    }
}

void move(Node *source, Node **dest){
    while(!isEmpty(source)){
        Data aux=source->val;
        push(dest, aux);
        source = source->next;
    }
}

void reverseStack(Node **main){
    Node *temp1 = NULL, *temp2 = NULL;
    move(*main, &temp1);
    move(temp1, &temp2);
    deleteStack((main));
    move(temp2, main);
    deleteStack(&temp1);
    deleteStack(&temp2);
}
