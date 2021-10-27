/*   Implementation of  queue with linked list. Menu driven options  have enque, deque, show_rear , show _Front and count_size .*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define True 1
#define False 0
#define Queue_max 100  

typedef struct node 
{
    int data;
    struct node * next;
} Queue;    // Queue is a typedef of struct node

int size =0;
int enqueue(Queue ** rear, Queue ** front, int data);
int dequeue(Queue ** front);
int show_Rear(Queue * rear);
int show_Front(Queue * front);
int isEmpty();
int isFull();

int main()
{
    int ch, data;
    Queue *rear, *front;

    rear  = NULL;
    front = NULL;
    
     while (True)
    {
        /* Queue menu */
        printf(" PAC1 QUESTION 7 QUEUE LINKED LIST  \n");
        printf("--------------------------------------------\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Count Size\n");
        printf("4. See the the Rear end\n");
        printf("5. See the front end \n");
        printf("0. Exit\n");
        printf("--------------------------------------------\n");
        printf("Select an option: ");

        scanf("%d", &ch);
     switch (ch)
        {
            case 1:
                printf("\nEnter data to enqueue: ");
                scanf("%d", &data);

                // Enqueue function returns 1 on success
                // otherwise 0
                if (enqueue(&rear, &front, data))
                    printf("Element added successfully to queue.");
                else
                    printf("Dequeue First ");

                break;

            case 2:
                data = dequeue(&front);

                // on success dequeue returns element removed
                // otherwise returns INT_MIN
                if (data == INT_MIN)
                    printf("Queue is empty.");
                else
                    printf("Data = %d", data);

                break;

            case 3: 

                // isEmpty() function returns 1 if queue is emtpy 
                // otherwise returns 0
                if (isEmpty())
                    printf("Queue is empty.");
                else 
                    printf("Queue size = %d", size);

                break;

            case 4: 
                data = show_Rear(rear);

                if (data == INT_MIN)
                    printf("Queue is empty.");
                else 
                    printf("Rear = %d", data);

                break;

            case 5: 

                data = show_Front(front);

                if (data == INT_MIN)
                    printf("Queue is empty.");
                else 
                    printf("Front = %d", data);

                break;
           
            case 0:
                printf("Exiting ......\n");
                exit(1);
        
            default:
                printf("Invalid choice, please input number between (0-5).");
                break;
        }

        printf("\n \n");
    }
    return 0;
}


int enqueue(Queue ** rear, Queue ** front, int data)
{
    Queue * newNode = NULL;

    if (isFull())
    {
        return 0;
    }
    newNode = (Queue *) malloc (sizeof(Queue));

    newNode->data = data;

    newNode->next = NULL;

    // Link new node with existing last node 
    if ( (*rear) )
    {
        (*rear)->next = newNode;
    }
    

    *rear = newNode;

    // Link first node to front if its NULL
    if ( !( *front) )
    {
        *front = *rear;
    }

    size++;

    return True;
}
    
   int dequeue(Queue ** front)
{
    Queue *toDeq = NULL;
    int data = INT_MIN;
    if (isEmpty())
    {
        return INT_MIN;
    }

    // Get element and data to dequeue
    toDeq = *front;
    data = toDeq->data;

   
    *front = (*front)->next;   // Move front ahead
    size--;
    free(toDeq);

    return data;
}

int show_Rear(Queue * rear)
{
                // Return INT_MIN if queue is empty 
    return (isEmpty())
            ? INT_MIN
            : rear->data;
}






 int show_Front(Queue * front)
{
    return (isEmpty())
            ? INT_MIN
            : front->data;
}
    
   int isEmpty()
{  if (size <= 0)
    return True;
  else
  return False;
} 

int isFull()
{if(size> Queue_max)
 return True;
 else 
 return False;
}
