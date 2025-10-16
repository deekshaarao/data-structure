#include <stdio.h>
#include <stdlib.h>
#define SIZE 5
struct queue{
    int f;
    int r;
    int data[SIZE];
};
typedef struct queue QUEUE ;
void enqueue(QUEUE *q , int item){
    if(q->r == SIZE -1)
        printf("\nQUEUE IS FULL\n");
    else{
        q->data[++(q->r)] = item ;
        if(q->f == -1)
            q->f += 1 ;
    }
}

void dequeue(QUEUE *q){
    if(q->f == -1)
        printf("\nQUEUE IS EMPTY\n");
    else{
        printf("\nElement deleted is %d" , q->data[(q->f)]);
        if(q->f ==  q->r){
            q->f = -1 ;
            q->r = -1 ;
        }
        else
            q->f += 1;
    }
}
void display(QUEUE q){
    int i ;
    if(q.f == -1)
        printf("\nQUEUE IS EMPTY");
    else{
        printf("\nThe queue elements are :");
        for(i = q.f ; i <= q.r ; i++)
            printf("\n%d" , q.data[i]);
  }
}
int main()
{
    int ch , item ;
    QUEUE q;
    q.f = -1;
    q.r = -1 ;
    while(1){
        printf("\n1.INSERT ELEMENT\n2.DELETE ELEMENT\n3.DISPLAY ELEMENTS\n4.EXIT\n");
        printf("\nEnter the choice :");
        scanf("%d" , &ch);
        switch(ch){
            case 1:
                printf("\nEnter element to insert to queue:");
                scanf("%d", &item);
                enqueue(&q , item);
                break ;
            case 2:
                dequeue(&q);
                break;
            case 3:
                display(q);
                break;
            default :
                printf("\nEXITING....\n");
                exit(0);
                break ;
        }
    }
    return 0;
}
