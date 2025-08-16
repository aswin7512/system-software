#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define BUF 20
#define MAX 100

typedef struct tab {
    char symbol[BUF];
    int address;
} tab;

typedef struct inter {
	int addr;
	char label[BUF];
	char opcode[BUF];
	char opnd[BUF];
} inter;

int otsize = 0, stsize = 0, lcnt = 0;;
tab optab[BUF];
tab symtab[BUF];
inter itr[MAX];


void pass2(FILE* out, FILE* list) {
	fprintf(out, "H %6s %6X %6X\n", itr[0].label, itr[0].addr, itr[lcnt].addr - itr[0].addr);
	fprintf(list, "%X\t%s\t%s\t%s\t**\n", itr[0].addr, itr[0].label, itr[0].opcode, itr[0].opnd);
	int trec = 0;
	for (int i = 1; i < lcnt; i++) {
		int found = -1;
		for (int j = 0; j < otsize; j++) {
			if (!strcmp(optab[j].symbol, itr[i].opcode)) {
				found = j;
				break;
			}
		}
		if (found != -1) {
			char obj[6], tmp[4];
			sprintf(obj, "%X", optab[found].address);
			if (strcmp(itr[i].opnd, "**")) {
				int stf = -1;
				for (int j = 0; j < stsize; j++) {
					if (strcmp(symtab[j].symbol, itr[i].opnd)) {
						stf = j;
						break;
					}
				}
				if (stf != -1)
					sprintf(tmp, "%X", symtab[stf].address);
				else {
					printf("Undefined Symbol!!!\n");
					exit(1);
				}
			} else {
				sprintf(tmp, "%X", 0000);
			}
			strcat(obj, tmp);		//done till object code formation for opcode operand pair and need to form the text record....
		}
	}
}


int main() {
    FILE* inter = fopen("intermediate.sic", "r");
    FILE* otab = fopen("optab", "r");
    FILE* stab = fopen("symtab", "r");
	FILE* out = fopen("output", "w");
	FILE* list = fopen("listfile.sic", "2");
    if (!inter || !otab || !stab || !out || !list) {
        printf("Couldnot Open Files...\n");
        return 1;
    }

    while (fscanf(otab, "%s\t%d", optab[otsize].symbol, &optab[otsize++].address) > 0);			//read optab to memory...
	while (fscanf(stab, "%s\t%d", symtab[stsize].symbol, &symtab[stsize++].address) > 0);		//read symtab to memory...
	while (fscanf(inter, "%X\t%s\t%s\t%s\t", &itr[lcnt].addr, itr[lcnt].label, itr[lcnt].opcode, itr[lcnt].opnd) > 0);		//read intermediate file to memory...

	pass2(out, list);
}