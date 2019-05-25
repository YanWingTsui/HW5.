#include <iostream>
#include<vector>

#include "node.h"
#include "queue.h"


void enqueue( customerPtr *headPtr, customerPtr *tailPtr,int cust_n,int serv_t,int arr_t)
        {
                customerPtr newPtr; newPtr = malloc( sizeof( customer ) );
                if ( newPtr != NULL )
                {
                        newPtr->cust_n = cust_n;
                        newPtr->serv_t = serv_t;
                        newPtr->arr_t = arr_t;
                        newPtr->nextPtr = NULL;
                        if ( isEmpty( *headPtr ) ) *headPtr = newPtr;
                        else ( *tailPtr )->nextPtr = newPtr;
                        *tailPtr = newPtr;
                }
                else
                printf("Empty.\n");
        };

void dequeue( customerPtr *headPtr, customerPtr *tailPtr )
        {
                customerPtr tempPtr;
                tempPtr = *headPtr;
                *headPtr = ( *headPtr )->nextPtr;
                if ( *headPtr == NULL ) *tailPtr = NULL;
                free( tempPtr );
        };
        
int isEmpty( customerPtr headPtr )
        {
                return headPtr == NULL;
        };
        
void printQueue( customerPtr currentPtr )
        {
                if ( currentPtr == NULL )
                printf( "Queue is empty.\n\n" );
                else
                {
                        printf( "The queue is:\n" );
                        while ( currentPtr != NULL )
                        {
                                printf( "%d <-- ", currentPtr->cust_n );
                                currentPtr = currentPtr->nextPtr;
                        }
        printf( "NULL\n\n" );
        };
                
int main()
{
        int i; int t_time = 0;
        int t_arrival = 0;
        int t_depart = -1;
        int customer_n = 0;
        int serv_time = 0;
        int MAX_SERV_TIME = serv_time;
        int tot_wait_t = 0;
        
        customerPtr headptr = NULL,tailptr = NULL;
        srand((unsigned int)time(NULL));
        
        while(t_time != 10)
        {
                        printf("TIME = %d,MAX_SERV_TIME = %d,TOT WAIT TIME = %d\n",t_time,MAX_SERV_TIME,tot_wait_t);
                        if(t_time == t_depart && !isEmpty(headptr))
                {
                                printf("customer %d ON\n\n",headptr->cust_n);
                                serv_time = headptr->serv_t;
                                service time tot_wait_t += (t_time - headptr->arr_t);
                                dequeue(&headptr,&tailptr);
                                if(!isEmpty(headptr))
                                        t_depart = serv_time + t_time;
                }

                if(t_time == t_arrival)
                {   
                        serv_time = rand()%4 + 1;
                        MAX_SERV_TIME = (serv_time>MAX_SERV_TIME?serv_time:MAX_SERV_TIME);
                        if(isEmpty(headptr))
                                t_depart = t_time + serv_time;
                        enqueue(&headptr,&tailptr,customer_n,serv_time,t_arrival);
                        t_arrival += rand()%4 + 1;
                        printf("customer %d joins at %d,serv_time %d,new_cust %d\n",tailptr->cust_n,tailptr->arr_t,tailptr->serv_t,t_arrival);
                }

                printQueue(headptr);
                getchar();
                t_time++;
        }
        
        customer_n = (tailptr->cust_n - headptr->cust_n)+ 1;
        printf("average wait time = %d,max service time = %d,tot custs unserved %d\n\n",tot_wait_t/customer_n,MAX_SERV_TIME,customer_n);
        
        for(i = 0;i<customer_n;i++)
                {
                        printQueue(headptr);
                        getchar();
                        dequeue(&headptr,&tailptr); }
                }
       
}
