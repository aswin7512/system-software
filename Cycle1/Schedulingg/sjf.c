//sjf process Scheduling...

#include<stdio.h>

typedef struct process {
	int pid;	int bt;
	int tat;	int wt;
}proc;


void proc_in(proc pr[], int n) {
	int i;
	printf("Enter Burst Time of,\n");
	for (i = 0; i < n; i++) {
		printf("P%d: ", i);
		scanf("%d", &pr[i].bt);
		pr[i].pid = i;
	}
}


void display(proc pr[], int n) {
	int i;
	float awt = 0, atat = 0;
	printf("%4s%4s%4s%4s\n", "PId", "BT", "WT", "TAT");
	for (i = 0; i < n; i++) {
		printf("%4d%4d%4d%4d\n", pr[i].pid, pr[i].bt, pr[i].wt, pr[i].tat);
		awt += pr[i].wt;
		atat += pr[i].tat;
	}
	printf("Average Waiting time: %.2f\n", awt/n);
	printf("Average Turn Around time: %.2f\n", atat/n);
}


void sjf(proc pr[], int n) {
	int cur_t = 0, i, j;
	for (i = 0; i < n; i++) {
		for (j = 0; j < n-i-1; j++) {
			if (pr[j].bt > pr[j+1].bt) {
				proc temp = pr[j];
				pr[j] = pr[j+1];
				pr[j+1] = temp;
			}
		}
	}
	for (i = 0; i < n; i++) {
		pr[i].wt = cur_t;
		cur_t += pr[i].bt;
		pr[i].tat = cur_t;
	}
}


int main() {
	int n;
	printf("Enter No. of Processes: ");
	scanf("%d", &n);
	proc pr[n];
	proc_in(pr, n);
	sjf(pr, n);
	display(pr, n);
	return 0;
}

/*

Enter No. of Processes: 3
Enter Burst Time of,
P0: 5
P1: 2
P2: 4
 PId  BT  WT TAT
   1   2   0   2
   2   4   2   6
   0   5   6  11
Average Waiting time: 2.67
Average Turn Around time: 6.33

*/