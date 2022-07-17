#include<stdio.h>
#define SIZE 5
 int  item[SIZE];
 int front = -1,rear =-1;
 int isFull(){
     if ((front == rear +1) ||(front == 0 && rear  == SIZE -1)) return 1;
     return 0;
} 
int isEmpty()
{
    if (front == -1) return 1;
    return 0;
}
void enQueue(int element)
{
    if (isFull())
    printf("\n Queue is  full \n");
    else
    {
        if (front == -1) front = 0;
        rear = (rear +1) % SIZE;
        item[rear] = element;
        printf("\n Inserted -> %d",element);
    }
}
int deQueue()
{
    int element;
    if (isEmpty()) 
    {
        printf("\n Queue is empty !! \n");
        return (-1);
    }
    else
    {
        element = item[front];
        if (front == rear){
            front =-1;
            rear = -1;
        }
        else 
        {
            front = (front +1) % SIZE;

        }
        printf("\n  Deleted element -> %d\n",element);
        return (element);

    }
}
void display()
{
    int i;
    if (isEmpty())
    printf("\n empty queue\n");
    else
    {
        printf("\n front -> %d",front);
        printf("\n Item ->");
        for (i = front; i !=rear; i = (i+1) % SIZE){
            printf("%d",item[i]);

        }
        printf("%d",item[i]);
        printf("\n Rear -> %d \n ", rear);
    }
}
int main()
{
    printf("ashima\n");
deQueue();
enQueue(1);
enQueue(2);
enQueue(3);
enQueue(4);
enQueue(5);
enQueue(6);
display();
deQueue();
display();
deQueue(7);
display();
enQueue(8);
return 0;
}