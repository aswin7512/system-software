// To implement Bankers Algorithm to find the safe sequence if exists...
#include<stdio.h>

typedef struct process {
    int alloc[10];
    int max[10];
    int need[10];
    int exec;
} proc;


void p_in(int np, int nr, proc pr[], int avl[]) {
    for (int i = 0; i < np; i++) {
        printf("Allocation of P%d: ", i+1);
        for (int j = 0; j < nr; j++) {
            scanf("%d", &pr[i].alloc[j]);
        }

        printf("Max Need of P%d: ", i+1);
        for (int j = 0; j < nr; j++) {
            scanf("%d", &pr[i].max[j]);
            pr[i].need[j] = pr[i].max[j] - pr[i].alloc[j];
            pr[i].exec = 0;
        }
    }
    printf("Enter Resource Availability: ");
    for (int i = 0; i < nr; i++)
        scanf("%d", &avl[i]);
}


void bankers (int np, int nr, proc pr[], int avl[]) {
    int comp = 0, dl = 0;
    int safe[np], sp = 0;

    while (comp < np && !dl) {
        dl = 1;
        for (int i = 0; i < np; i++) {
            int exe = 1;
            for (int j = 0; j < nr; j++) {
                if (pr[i].need[j] > avl[j] || pr[i].exec) {
                    exe = 0;
                    break;
                }
            }
            if (exe) {
                safe[sp++] = i+1;
                comp++;
                pr[i].exec = 1;
                dl = 0;
                for (int j = 0; j < nr; j++) {
                    avl[j] += pr[i].alloc[j];
                }
            }
        }
    }

    printf("\nNeed Matrix...\n");
    for(int i = 0; i < np; i ++) {
        printf("P%d: ", i+1);
        for(int j = 0; j < nr; j++) {
            printf("%d ", pr[i].need[j]);
        }
        printf("\n");
    }

    if (dl)
        printf("System is not in Safe State...\n");
    else {
        printf("Safe Sequence: ");
        for(int i = 0; i < np; i++) {
            printf("P%d -> ", safe[i]);
        }
        printf("Halt\n");
    }

}


int main() {
    int np, nr;
    printf("Enter No. of Processes and Resources: ");
    scanf("%d %d", &np, &nr);
    proc pr[np];
    int avl[nr];
    p_in(np, nr, pr, avl);
    bankers(np, nr, pr, avl);
    return 0;
}



/*

Enter No. of Processes and Resources: 5 3
Allocation of P1: 0
1
0
Max Need of P1: 7 5 3
Allocation of P2: 2 0 0 
Max Need of P2: 3 2 2
Allocation of P3: 3 0 2
Max Need of P3: 9 0 2
Allocation of P4: 2 1 1
Max Need of P4: 2 2 2
Allocation of P5: 0 0 2
Max Need of P5: 4 3 3
Enter Resource Availability: 3 3 2

Need Matrix...
P1: 7 4 3 
P2: 1 2 2 
P3: 6 0 0 
P4: 0 1 1 
P5: 4 3 1 
Safe Sequence: P2 -> P4 -> P5 -> P1 -> P3 -> Halt

*/