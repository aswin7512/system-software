#include<stdio.h>


int found (int f[], int w, int key) {
    for (int i = 0; i < w; i++)
        if (f[i] == key)
            return 1;
    return 0;
}


void fifo (int rs[], int n, int w) {
    int f[w];
    for (int i = 0; i < w; i++)
        f[i] = -1;
    printf("\nImplementing FIFO...\n");
    int fp = 0, h;
    int hc = 0, fc = 0;
    printf("%10s%20s%20s\n\n", "Access", "Page in Memory", "Fault / Hit");
    for (int i = 0; i < n; i++) {
        if (found(f, w, rs[i])) {
            hc++;
            h = 1;
        }
        else {
            f[fp] = rs[i];
            fc++;
            fp = (fp + 1)% w;
            h = 0;
        }
        char fs[2*w];
        for (int j = 0, frp = 0; j < (2*w); j+=2, frp++) {
            if (f[frp] != -1)
                fs[j] = f[frp] + '0';
            else 
                fs[j] = '*';
            fs[j+1] = ' ';
        }
        if(h)
            printf("%10d%20s%20s\n", rs[i], fs, "Hit");
        else
            printf("%10d%20s%20s\n", rs[i], fs, "Falult");
    }
    printf("Hits: %d\n", hc);
    printf("Faults: %d\n", fc);
}


void lru (int rs[], int n, int w) {
    int f[w], lat[w];
    for (int i = 0; i < w; i++) {
        f[i] = -1;
        lat[i] = -1;
    }
    
    printf("\nImplementing LRU...\n");
    int fp = 0, h;
    int hc = 0, fc = 0;
    printf("%10s%20s%20s\n\n", "Access", "Page in Memory", "Fault / Hit");
    for (int i = 0; i < n; i++) {
        int min = w, min_in = 0;
        if (h = found(f, w, rs[i])) {
            hc++;
            lat [h-1] = i;
        }
        else {
            for (int j = 0; j < w; j++)
                if (min > lat[j]) {
                    min = lat[j];
                    min_in = j;
                }
            f[min_in] = rs[i];
            lat[min_in] = i;
            fc++;
        }
        char fs[2*w];
        for (int j = 0, frp = 0; j < (2*w); j+=2, frp++) {
            if (f[frp] != -1)
                fs[j] = f[frp] + '0';
            else 
                fs[j] = '*';
            fs[j+1] = ' ';
        }
        if(h)
            printf("%10d%20s%20s\n", rs[i], fs, "Hit");
        else
            printf("%10d%20s%20s\n", rs[i], fs, "Falult");
    }
    printf("Hits: %d\n", hc);
    printf("Faults: %d\n", fc);
}


int main() {
    int n, w;
    printf("Enter lenghth of Reference String and Frame Width: ");
    scanf("%d %d", &n, &w);
    int rs[n];

    printf("Enter reference String: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &rs[i]);
    fifo(rs, n, w);
    lru(rs, n, w);
    return 0;
}






/*

Enter lenghth of Reference String and Frame Width: 10 3
Enter reference String: 1 5 3 8 5 9 8 4 2 0

Implementing FIFO...
    Access      Page in Memory         Fault / Hit

         1              1 * *               Falult
         5              1 5 *               Falult
         3              1 5 3               Falult
         8              8 5 3               Falult
         5              8 5 3                  Hit
         9              8 9 3               Falult
         8              8 9 3                  Hit
         4              8 9 4               Falult
         2              2 9 4               Falult
         0              2 0 4               Falult
Hits: 2
Faults: 8

Implementing LRU...
    Access      Page in Memory         Fault / Hit

         1              1 * *               Falult
         5              1 5 *               Falult
         3              1 5 3               Falult
         8              8 5 3               Falult
         5              8 5 3                  Hit
         9              8 9 3               Falult
         8              8 9 3                  Hit
         4              8 9 4               Falult
         2              2 9 4               Falult
         0              0 9 4               Falult
Hits: 2
Faults: 8

*/