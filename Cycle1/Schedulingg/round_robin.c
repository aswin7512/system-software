//round robin process scheduling...

#include<stdio.h>

typedef struct process {
	int pid;	int at;		int bt;
	int tat;	int wt;		int ct;
	int rbt;
}proc;


void proc_in(proc pr[], int n) {
	int i;
	printf("Enter Arrival Time, Burst Time of,\n");
	for (i = 0; i < n; i++) {
		printf("P%d: ", i);
		scanf("%d %d",&pr[i].at, &pr[i].bt);
		pr[i].rbt = pr[i].bt;
		pr[i].pid = i;
		pr[i].ct = -1;
	}
}


void display(proc pr[], int n) {
	int i;
	float awt = 0, atat = 0;
	printf("%4s%4s%4s%4s%4s\n", "PId", "AT", "BT", "WT", "TAT");
	for (i = 0; i < n; i++) {
		printf("%4d%4d%4d%4d%4d\n", pr[i].pid, pr[i].at, pr[i].bt, pr[i].wt, pr[i].tat);
		awt += pr[i].wt;
		atat += pr[i].tat;
	}
	printf("Average Waiting time: %.2f\n", awt/n);
	printf("Average Turn Around time: %.2f\n", atat/n);
}


void round_robin(proc pr[], int n, int tq) {
	int cur_t = 0, tm, comp = 0, wqp = 0, wqt = 0, wqn = 0, wq[n];
	for (int i = 0; i < n; i++) {
		if (pr[i].at <= cur_t) {
			wq[wqp] = i;
			wqp = (wqp + 1)% n;
			wqn++;
		}
	}
	while (comp < n) {
		if (tq < pr[wq[wqt]].rbt)
			tm = tq;
		else
			tm = pr[wq[wqt]].rbt;
		
		for (int i = 0; i < n; i++) {
			if (pr[i].at <= cur_t+tm && pr[i].at > cur_t && pr[i].ct < 0) {
				wq[wqp] = i;
				wqp = (wqp + 1)% n;
				wqn++;
			}
		}
		if (tq < pr[wq[wqt]].rbt) {
			tm = tq;
			wq[wqp] = wqt;
			wqp = (wqp + 1)% n;
		} else {
			tm = pr[wq[wqt]].rbt;
			comp++;
			pr[wq[wqt]].ct = cur_t + tm;
			wqn--;
		}
		pr[wq[wqt]].rbt -= tm;
		wqt = (wqt + 1)% n;
		cur_t += tm;
		
	}
	for (int i = 0; i < n; i++) {
		pr[i].tat = pr[i].ct - pr[i].at;
		pr[i].wt = pr[i].tat - pr[i].bt;
	}
}


int main() {
	int n, tq;
	printf("Enter No. of Processes: ");
	scanf("%d", &n);
	proc pr[n];
	proc_in(pr, n);
	printf("Enter Time Quantum: ");
	scanf("%d", &tq);
	round_robin(pr, n, tq);
	display(pr, n);
	return 0;
}
