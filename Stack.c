#include "stdio.h"
#include "conio.h"
#include "stdlib.h"

struct st {
	int stack[3];
	int front;
};
int push(struct st *n){
	int d;
	printf("enter the value to push    ");
	scanf("%d",&d);
	if(n->front==-1){
		n->front = 0;
	}
	if(n->front == 3){
	printf("stack is full\n");
	}
	else{
		n->stack[n->front] = d;
		n->front = n->front +1 ;
	}
	return 0;
};
void pop(struct st *p){
	if(p->front == 0){
		printf("stack is empty \n");
	}
	else{
		p->front--;
		printf("poped \n");
	}
}

void disp(struct st *p){
	int i;
	for(i = 0;i< p->front;i++){
		printf("%d   ",p->stack[i]);
	}
	printf("\n");
}

int main() {
	struct st *p,b;
	p = &b;
	p->front = -1;
	push(p);
	push(p);
	push(p);
	push(p);
	push(p);
	disp(p);
	pop(p);
	pop(p);
	disp(p);
	pop(p);
	pop(p);
	disp(p);
	pop(p);
	pop(p);
	
	

    return 0;
} 
