#include<stdio.h>


void ffit(int proc[], int block[], int np, int nb) {
    int alloc[np];
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


int main() {
    int np, nb;
    printf("Enter No. of Processes and Memory Blocks: ");
    scanf("%d %d", &np, &nb);

    int proc[np], block[nb];
    printf("Enter Size of Process\n");
    for (int i = 0; i < np; i++) {
        printf("P%d: ", i+1);
        scanf("%d", &proc[i]);
    }

    printf("Enter Size of Block\n");
    for (int i = 0; i < nb; i++) {
        printf("B%d: ", i+1);
        scanf("%d", &block[i]);
    }

    ffit(proc, block, np, nb);
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
   Pno    PSize    Block
     1      130        1
     2      100        2
     3       90        2
     4      400       NA
     5      200        4

*/