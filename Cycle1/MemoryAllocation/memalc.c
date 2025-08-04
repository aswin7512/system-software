#include<stdio.h>


void ffit(int proc[], int block[], int np, int nb) {
    int alloc[np];
    printf("\nImplementing First Fit...\n");
    for (int i = 0; i < np; i++) {
        alloc[i] = -1;
        for (int j = 0; j < nb; j++) {
            if (proc[i] <= block[j]) {
                block[j] -= proc[i];
                alloc[i] = j+1;
                break;
            }
        }
    }

    printf("%6s%9s%9s\n", "Pno", "PSize", "Block");
    for (int i = 0; i < np; i++) {
        if (alloc[i] < 0)
            printf("%6d%9d%9s\n", i+1, proc[i], "NA");
        else
            printf("%6d%9d%9d\n", i+1, proc[i], alloc[i]);
    }
}


void bfit(int proc[], int block[], int np, int nb) {
    int alloc[np];
    printf("\nImplementing Best Fit...\n");
    for (int i = 0; i < np; i++) {
        alloc[i] = -1;
        for (int j = 0; j < nb; j++) {
            if (alloc[i] == -1) {
                if (proc[i] <= block[j])
                    alloc[i] = j;
            }
            else
                if (proc[i] <= block[j] && block[j] < block[alloc[i]])
                    alloc[i] = j;
        }
        if (alloc[i] != -1)
            block[alloc[i]] -= proc[i];
    }
    
    printf("%6s%9s%9s\n", "Pno", "PSize", "Block");
    for (int i = 0; i < np; i++) {
        if (alloc[i] < 0)
            printf("%6d%9d%9s\n", i+1, proc[i], "NA");
        else
            printf("%6d%9d%9d\n", i+1, proc[i], alloc[i]+1);
    }
}


void wfit(int proc[], int block[], int np, int nb) {
    int alloc[np];
    printf("\nImplementing Worst Fit...\n");
    for (int i = 0; i < np; i++) {
        alloc[i] = -1;
        for (int j = 0; j < nb; j++) {
            if (alloc[i] == -1) {
                if (proc[i] <= block[j])
                    alloc[i] = j;
            }
            else
                if (block[j] > block[alloc[i]])
                    alloc[i] = j;
        }
        if (alloc[i] != -1)
            block[alloc[i]] -= proc[i];
    }
    
    printf("%6s%9s%9s\n", "Pno", "PSize", "Block");
    for (int i = 0; i < np; i++) {
        if (alloc[i] < 0)
            printf("%6d%9d%9s\n", i+1, proc[i], "NA");
        else
            printf("%6d%9d%9d\n", i+1, proc[i], alloc[i]+1);
    }
}


int main() {
    int np, nb;
    printf("Enter No. of Processes and Memory Blocks: ");
    scanf("%d %d", &np, &nb);

    int proc[np], block[nb], probf[np], blocbf[nb], prowf[np], blocwf[nb];
    printf("Enter Size of Process\n");
    for (int i = 0; i < np; i++) {
        printf("P%d: ", i+1);
        scanf("%d", &proc[i]);
        probf[i] = prowf[i] = proc[i];
    }

    printf("Enter Size of Block\n");
    for (int i = 0; i < nb; i++) {
        printf("B%d: ", i+1);
        scanf("%d", &block[i]);
        blocbf[i] = blocwf[i] = block[i];
    }

    ffit(proc, block, np, nb);
    bfit(probf, blocbf, np, nb);
    wfit(prowf, blocwf, np, nb);
    return 0;
}




/*

Enter No. of Processes and Memory Blocks: 5 4
Enter Size of Process
P1: 130
P2: 100
P3: 90
P4: 400
P5: 200
Enter Size of Block
B1: 200
B2: 350
B3: 140
B4: 230

Implementing First Fit...
   Pno    PSize    Block
     1      130        1
     2      100        2
     3       90        2
     4      400       NA
     5      200        4

Implementing Best Fit...
   Pno    PSize    Block
     1      130        3
     2      100        1
     3       90        1
     4      400       NA
     5      200        4

Implementing Worst Fit...
   Pno    PSize    Block
     1      130        2
     2      100        4
     3       90        2
     4      400       NA
     5      200        1

*/