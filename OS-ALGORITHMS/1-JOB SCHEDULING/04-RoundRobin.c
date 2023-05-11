#include<stdio.h>

#define MAX_JOBS 10
#define TIME_QUANTUM 1

struct Job {
    char name[20];
    int burstTime;
    int remainingTime;
};
int calculate_waiting_time(struct Job jobs[], int numJobs, int waitingTime[]);

int main()
{
    int numJobs, i;
    int waitingTime[MAX_JOBS] = {0};
    struct Job jobs[MAX_JOBS];

    printf("Enter the number of jobs: ");
    scanf("%d", &numJobs);

 for (i = 0; i < numJobs; i++) {
        printf("\nEnter process name : ");
        scanf("%s",jobs[i].name);
        printf("Enter the burst time for job %d: ", i + 1);
        scanf("%d", &jobs[i].burstTime);
        jobs[i].remainingTime = jobs[i].burstTime;
 }

 int completion = calculate_waiting_time(jobs,numJobs,waitingTime);
    int c=0;
    printf("Process\tBurst Time\tWaiting Time\n");
    for (i = 0; i < numJobs; i++) {
        c += waitingTime[i];
        printf("%s\t%d\t\t%d\n", jobs[i].name, jobs[i].burstTime, waitingTime[i]);
    }

    printf("Total completion time: %d\n", c);

    return 0;
}
int calculate_waiting_time(struct Job jobs[], int numJobs, int waitingTime[]){

    int i,currentTime =0,remainingJobs = numJobs;
    while (remainingJobs > 0){
        for(i=0;i<numJobs;i++)
        {
            if(jobs[i].remainingTime > 0 ){
                if(jobs[i].remainingTime <=TIME_QUANTUM)
                {
                    currentTime+=TIME_QUANTUM;
                    jobs[i].remainingTime = 0;
                }
                else{
                    currentTime+=TIME_QUANTUM;
                    jobs[i].remainingTime -=TIME_QUANTUM;
                }
                if(jobs[i].remainingTime == 0)
                {
                    remainingJobs --;
                }

                waitingTime[i] = currentTime - jobs[i].burstTime;
                
            }

        }
    }
    return currentTime;

}