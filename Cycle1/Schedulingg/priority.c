//priority process Scheduling...

#include<stdio.h>

typedef struct process {
	int pid;	int bt;		int pri;
	int tat;	int wt;
}proc;


void proc_in(proc pr[], int n) {
	int i;
	printf("Enter Burst Time and Priority of,\n");
	for (i = 0; i < n; i++) {
		printf("P%d: ", i);
		scanf("%d %d", &pr[i].bt, &pr[i].pri);
		pr[i].pid = i;
	}
}


void display(proc pr[], int n) {
	int i;
	float awt = 0, atat = 0;
	printf("%4s%4s%4s%4s%4s\n", "PId", "BT", "Pri", "WT", "TAT");
	for (i = 0; i < n; i++) {
		printf("%4d%4d%4d%4d%4d\n", pr[i].pid, pr[i].bt, pr[i].pri, pr[i].wt, pr[i].tat);
		awt += pr[i].wt;
		atat += pr[i].tat;
	}
	printf("Average Waiting time: %.2f\n", awt/n);
	printf("Average Turn Around time: %.2f\n", atat/n);
}


void priority(proc pr[], int n) {
	int cur_t = 0, i, j;
	for (i = 0; i < n; i++) {
		for (j = 0; j < n-i-1; j++) {
			if (pr[j].pri > pr[j+1].pri) {
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
	priority(pr, n);
	display(pr, n);
	return 0;
}

/*

Enter No. of Processes: 3
Enter Burst Time and Priority of,
P0: 4 2
P1: 2 1
P2: 6 3
 PId  BT Pri  WT TAT
   1   2   1   0   2
   0   4   2   2   6
   2   6   3   6  12
Average Waiting time: 2.67
Average Turn Around time: 6.67

*/