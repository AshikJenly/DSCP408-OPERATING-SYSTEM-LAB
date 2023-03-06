#include<stdio.h>
#include<malloc.h>
typedef struct process{
  char name[10];
  int hr,min,sec,burst,wait,arrival,exit;
}process;
void read_process_details(process *,int );
void print_details(process *,int );
int calculate_waiting_time(process *,int n);
void main(){

  int n,total;
  process * p;
  printf("Enter the number of process : ");
  scanf("%d",&n);
  p=(process *)malloc(n*sizeof(process));

  read_process_details(p,n);
  total=calculate_waiting_time(p,n);
  print_details(p,n);
  printf("\n\nTotal waiting time : %d",total);
  printf("\nAverage waiting Time : %f",(total/(float)n));
}

void read_process_details(process * p,int n){

    int i=0;
    for(i=0;i<n;i++){
      printf("\nProcess %d : ",i+1);
      printf("\nEnter process name : ");
      scanf("%s",&p[i].name);
      printf("Enter arrival time: ");

      hour:
        printf("\n\tEnter Hour: ");
        scanf("%d",&p[i].hr);

        if(p[i].hr<=24){
           minute:
               printf("\nEnter Minute : ");
               scanf("%d",&p[i].min);
               if(p[i].min<=60){
                second:
                    printf("\nEnter second : ");
                    scanf("%d",&p[i].sec);

                    if(p[i].sec<=60){
                        printf("Enter burst time :(in seconds) ");
                        scanf("%d",&p[i].burst);
                    }
                    else{
                        printf("\nEnter seconds <=60");
                        goto second;
                    }

                }
                else{
                    printf("\nEnter minute <= 60");
                    goto minute;
                }
        }
        else{
            printf("\nEnter hour <=24 : ");
            goto hour;
        }

        p[i].arrival=p[i].sec+(p[i].min*60)+(p[i].hr*3600);       
    }
}

void print_details(process *p ,int n){
    int i=0;
    printf("\nProcessName\tArrivalTime\tBurstTime\tWaiting Time");
    for(i=0;i<n;i++)
    {
        // printf("\nProcess %d ",i+1);
        printf("\n%s\t\t%d:%d:%d\t\t%d\t\t%d",p[i].name,p[i].hr,p[i].min,p[i].sec,p[i].burst,p[i].wait);
    }
}
int calculate_waiting_time(process * p,int n){
    process temp;
    int i,j,total=0;
    
    for(i=0;i<n;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(p[j].arrival>p[j+1].arrival)
            {
                temp=p[j];
                p[j]=p[j+1];
                p[j+1]=temp;
            }
        }
    }
    p[0].exit=p[0].arrival+p[0].burst;

    for(i=0;i<n;i++){
        if(i==0)
            p[i].wait=0;
        // if 2nd process comes after exit time of 1st
        else if(p[i].arrival>p[i-1].exit){
            p[i].wait=0;
            p[i].exit=p[i].arrival+p[i].burst;
        }

        else if(p[i].arrival<p[i-1].exit)
            {
                int t=p[i].arrival-p[i-1].arrival;
                p[i].wait=p[i-1].wait-t+p[i-1].burst;
                p[i].exit=p[i].arrival+p[i].wait+p[i].burst;
            }
        else
            {
                p[i].wait=p[i-1].wait+p[i-1].burst;
                p[i].exit=p[i].arrival+p[i].wait+p[i].burst;
            }
        total+=p[i].wait;

    }
    return total;
}