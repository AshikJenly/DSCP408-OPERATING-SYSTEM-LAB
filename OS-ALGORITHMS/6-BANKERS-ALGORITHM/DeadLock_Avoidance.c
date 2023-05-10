#include<stdio.h>
#include<string.h>
void main(){

    int no_process,no_resource,i,j;


    printf("Enter the number of processes: ");
    scanf("%d",&no_process);

    printf("Enter the number of resources: ");
    scanf("%d",&no_resource);

    //Declaring available ,allocated and requested data
    int avail[no_resource],
    allocated[no_process][no_resource],
    request[no_process][no_resource],
    completed[no_process],
    needResource[no_process][no_resource];
    char process_names[no_process][20];

    char safeway[no_process][20];int safe_ind =0;

    printf("\nEnter Process Names  ");
    for(i=0;i<no_process;i++)
        scanf("%s",process_names[i]);


    printf("Enter the available resources:\n");
    for(i=0;i<no_resource;i++)
        scanf("%d",&avail[i]);

    
    printf("\nEnter the allocation resource matrix with space separated rows:\n");
    for(i=0;i<no_process;i++){
        printf("%s : ",process_names[i]);
        for(j=0;j<no_resource;j++)
            scanf("%d",&allocated[i][j]);
    }

    
    printf("Enter the requests resource matrix with space separated rows :\n");
    for(i=0;i<no_process;i++){
        printf("%s : ",process_names[i]);
        for(j=0;j<no_resource;j++)
            scanf("%d",&request[i][j]);
    }

    
    //need matrix = request - allocated
    for(i=0;i<no_process;i++)
    {
     for(j=0;j<no_resource;j++)
     {
        needResource[i][j] = request[i][j] - allocated[i][j];
        if (needResource[i][j] < 0)
            needResource[i][j] = 0;
     }
    }    
NEED:
    for(i=0;i<no_process;i++)
            completed[i]=0;
    
    printf("\nNeed Resources => \n");
    for(i=0;i<no_process;i++)
    {
    printf("%s : ",process_names[i]);
     for(j=0;j<no_resource;j++)
     {
        printf(" %d ",needResource[i][j]);
     }
     printf("\n");
    }   

    int k,y,flag=0,is_newReq;
    char new_reqName[20];

        for(i=0;i<no_process;i++)
        {
           
            if(completed[i] == 0)
            {
             flag=0;
             for(j=0;j<no_resource;j++)
              {
                if(needResource[i][j] > avail[j])
                {
                    flag=1;
                    printf("\nThe System is in DeadLock state because of process %s ",process_names[i]);
                    return;
                }
              }
              if(!flag)
              {
                strcpy(safeway[safe_ind++],process_names[i]);
                completed[i]=1;
                for(y=0;y<no_resource;y++)
                    avail[y]+=allocated[i][y];
              }
            }
        }
    printf("\n\tSafe Sequence =>\n");
    for(i=0;i<no_process;i++)
        printf("%s -> ",safeway[i]);
        printf("\n");
   
    printf("\nAny Request for resources? [1/0] : ");
    scanf("%d",&is_newReq);
     if(is_newReq)
     {
            printf("\nEnter process name : ");
            scanf("%s",new_reqName);
            for(i=0;i<no_process;i++)
            {
                if(strcmp(new_reqName,process_names[i])==0)
                {
                    
                    
                    printf("Enter the requests resource :");
                    for(j=0;j<no_resource;j++)
                    {
                        scanf("%d",&needResource[i][j]);
                    }
                }
            }
        goto NEED;        
     }
     else
        return;
}