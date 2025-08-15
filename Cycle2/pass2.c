#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define BUF 20
#define MAX 50

typedef struct rec {
	char tag;
	int len;
	char rec[60];
} record;

typedef struct tab{
    char symbol[BUF];
    int address;
} tab;

int otsize = 0, stsize = 0;
tab optab[BUF];
tab symtab[BUF];



void pass2(int addr, char label[], char ocode[], char opnd[]) {
	if (strcmp(ocode, "START"));
}


int main() {
    FILE* inter = fopen("intermediate.sic", "r");
    FILE* otab = fopen("optab", "r");
    FILE* stab = fopen("symtab", "r");
	FILE* rec = fopen("record", "w");
    if (!inter || !otab || !stab || !rec) {
        printf("Couldnot Open Files...\n");
        return 1;
    }
    char opcode[BUF], op, symbol[BUF];
	int opint, sint;
    while (fscanf(otab, "%s\t%d", opcode, &opint) > 0) {
		strcpy(optab[otsize].symbol, opcode);
		optab[otsize++].address = opint;
	}
	while (fscanf(stab, "%s\t%d", symbol, &sint) > 0) {
		strcpy(symtab[stsize].symbol, symbol);
		symtab[stsize++].address = sint;
	}
	char label[BUF], ocode[BUF], opnd[BUF];
	int addr;


	do {
		fscanf(inter, "%X\t%s\t%s\t%s\n", &addr, label, ocode, opnd);
		pass2(addr, label, ocode, opnd);
	} while (strcmp(ocode, "END"));
	for (int i = 0; i < otsize; i++)
		printf("%s: %X\n", optab[i].symbol, optab[i].address);
    return 0;
}