#include <iostream>
#include<vector>

#include "node.h"
#include "queue.h"


void enqueue( customerP *head_Ptr, customerP *tail_Ptr,int cust,int serv,int arr)
        {
                customerP newP; newP = malloc( sizeof( customer ) );
                if ( newP != NULL )
                {
                        newP->cust = cust;
                        newP->serv = serv;
                        newP->arr = arr;
                        newP->nextP = NULL;
                        if ( isEmpty( *headPtr ) ) *head_Ptr = newP;
                        else ( *tail_Ptr )->nextP = newP;
                        *tail_Ptr = newP;
                }
                else
                printf("Empty.\n");
        };

void dequeue( customerP *head_Ptr, customerP *tail_Ptr )
        {
                customerP tempP;
                tempP = *head_Ptr;
                *head_Ptr = ( *head_Ptr )->nextP;
                if ( *head_Ptr == NULL ) *tail_Ptr = NULL;
                free( tempP );
        };
        
int isEmpty( customerP head_Ptr )
        {
                return head_Ptr == NULL;
        };
        
void printQueue( customerP currentP )
        {
                if ( currentP == NULL )
                printf( "Empty.\n\n" );
                else
                {
                        printf( "The queue is:\n" );
                        while ( currentP != NULL )
                        {
                                printf( "%d <-- ", currentt->cust );
                                currentP = currentP->nextP;
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
        
        customerP head_ptr = NULL,tail_ptr = NULL;
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

                printQueue(head_ptr);
                getchar();
                t_time++;
        }
        
        customer_n = (tail_ptr->cust_n - head_ptr->cust)+ 1;
        printf("average wait time = %d,max service time = %d,tot custs unserved %d\n\n",tot_wait_t/customer_n,MAX_SERV_TIME,customer_n);
        
        for(i = 0;i<customer_n;i++)
                {
                        printQueue(head_ptr);
                        getchar();
                        dequeue(&head_ptr,&tail_ptr); }
                }
       
}
