#include<stdio.h>
struct process
{
    char pname;
    int arrival_time,burst_time,ct,waiting_time,trnarnd_time,prior,burst_time1;
}p[10],p1[10];
void main()
{
	struct process temp;
    int i,time=0,t1,t2,bu_t=0,largest,num,count=0,k,pf2=0,limit2,n,pos,j,flag=0,y;
    float wait_time=0,turnaround_time= 0,average_waiting_time,average_turnaround_time;
    printf("\nEnter Number of Processes:\n");
    scanf("%d",&num);
    n=num;
    for(i=0;i<num;i++)
    {
    	printf("\nEnter process name:-");
    	fflush(stdin);
        scanf("%c",&p[i].pname);
        printf("Enter Arrival Time:-");
        scanf("%d",&p[i].arrival_time);
        printf("Enter Burst Time:-");
        scanf("%d",&p[i].burst_time);
        p[i].burst_time1=p[i].burst_time;
        printf("Enter Priority:\t");
        scanf("%d",&p[i].prior);
    }
    printf("\nEnter Time Quantum for Fixed priority queue:-");
    scanf("%d",&t1);
    printf("\nEnter Time Quantum for Round Robin queue:-");
    scanf("%d",&t2);
    printf("\n\nprocess\t|Turnaround Time|Waiting Time\n\n");
    for(i=0;i<num;i++)
    {
        pos=i;
        for(j=i+1;j<num;j++)
        {
            if(p[j].arrival_time<p[pos].arrival_time)
                pos=j;
        }
        temp=p[i];
        p[i]=p[pos];
        p[pos]=temp;
    }
    time=p[0].arrival_time;
    for(i=0;num!=0;i++)
    {
    	while(count!=t1)
    	{
    		count++;
    		if(p[i].arrival_time<=time)
    		{
    			for(j=i+1;j<num;j++)
    			{
    				if(p[j].arrival_time==time&&p[j].prior<p[i].prior)
    				{
    					p1[pf2]=p[i];
						pf2++;
    					for(k=i;k<num-1;k++)
    						p[k]=p[k+1];
    					num--;
						count=0;
    					i=j-1;
    					j--;
					}
				}
			}
			time++;
			p[i].burst_time--;
			if(p[i].burst_time==0)
			{
				p[i].trnarnd_time=time-p[i].arrival_time;
				p[i].waiting_time=p[i].trnarnd_time-p[i].burst_time1;
				printf("%c\t|\t%d\t|\t%d\n",p[i].pname,p[i].trnarnd_time,p[i].waiting_time);
				wait_time+=time-p[i].arrival_time-p[i].burst_time1; 
    			turnaround_time+=time-p[i].arrival_time;
    			for(k=i;k<num-1;k++)
    				p[k]=p[k+1];i--;
    			num--;
				count=t1;break;
			}
		}
		count=0;
		if(p[i].burst_time!=0)
		{
			p1[pf2]=p[i];
			pf2++;
			for(k=i;k<num-1;k++)
    			p[k]=p[k+1];
    		num--;
		}
			if(i==num-1)
				i=-1;
	}
	
	limit2=pf2;
	for(count=0;limit2!=0;) 
	{ 
		if(p1[count].burst_time<=t2&&p1[count].burst_time>0) 
    	{ 
    		time+=p1[count].burst_time; 
    		p1[count].burst_time=0; 
    		flag=1; 
    	} 
    	else if(p1[count].burst_time>0) 
    	{ 
    		p1[count].burst_time-=t2; 
    		time+=t2; 
    	} 
    	if(p1[count].burst_time==0&&flag==1) 
    	{ 
    		limit2--; 
    		p1[count].trnarnd_time=time-p1[count].arrival_time;
			p1[count].waiting_time=p1[count].trnarnd_time-p1[count].burst_time1; 
			printf("%c\t|\t%d\t|\t%d\n",p1[count].pname,p1[count].trnarnd_time,p1[count].waiting_time); 
    		turnaround_time+=time-p1[count].arrival_time; 
    		wait_time+=time-p1[count].arrival_time-p1[count].burst_time1;
    		for(k=count;k<limit2;k++)
    			p1[k]=p1[k+1];count--;
    		flag=0; 
    	} 

    	if(count==limit2-1) 
      		count=0; 
    	else 
    		count++; 
    }
    printf("\nAverage Waiting Time= %f\n",wait_time*1.0/n); 
    printf("Avg Turnaround Time = %f",turnaround_time*1.0/n);   
}
