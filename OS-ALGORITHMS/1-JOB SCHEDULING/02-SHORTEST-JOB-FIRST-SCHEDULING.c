#include<stdio.h>

typedef struct process{
    char name[30];
    int wait,burst;
}process;

process PRCS[10];
int N,TOTAL=0;
int i,j;//For iteration
void read_process();
void calculate_waiting_time();
void print_details();

void main(){
    read_process();
    calculate_waiting_time();
    print_details();

    printf("\nTOTAL : %d",TOTAL);
    printf("\nAVERAGE %0.2f :",(TOTAL/N*1.0));
    return;
}
void read_process()
{
    
    printf("\nEnter number of process : ");
    scanf("%d",&N);

    for(i=0;i<N;i++)
    {
        
        printf("Process %d\n\tEnter process name : ",i);
        scanf("%s",PRCS[i].name);
        printf("\tEnter the burst time : ");
        scanf("%d",&PRCS[i].burst);
    }
    
}
void calculate_waiting_time()
{
    process temp;
    for(i=0;i<N;i++)
        for(j=0;j<N-i-1;j++)
            if(PRCS[j].burst>PRCS[j+1].burst)
            {
                temp=PRCS[j];
                PRCS[j]=PRCS[j+1];
                PRCS[j+1]=temp;
                
            }
        
    for(i=0;i<N;i++)
    {
        if(i==0)
            PRCS[i].wait=0;
        else
            PRCS[i].wait = PRCS[i-1].wait + PRCS[i-1].burst;
        TOTAL += PRCS[i].wait;
    }
}
void print_details()
{     
    printf("\nNAME\t\tBURST\t\tWAIT");
    for(i=0;i<N;i++)
    {
        printf("\n%s\t\t%d\t\t%d",PRCS[i].name,PRCS[i].burst,PRCS[i].wait);

    }
}