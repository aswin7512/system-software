#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define BUF 20


void run (FILE* optab, FILE* inter, FILE* symtab, char opcode[], char label[], char op[], int* start, int* locctr) {
	if (strcmp(opcode, "START") == 0);
	
}


int main() {
	FILE* src = fopen("input.sic", "r");
	FILE* optab = fopen("optab", "r");
	FILE* inter = fopen("intermediate", "w");
	FILE* symtab = fopen("symtab", "w+");
	if (!src) {
		printf("Couldnot Open File...\n");
		return 0;
	}
	char label[BUF], opcode[BUF], op[BUF];
	int start = 0, locctr = 0;
	printf("SIC Program...\n");
	printf("%10s%10s%10s\n", "LABEL", "OPCODE", "OPERAND");
	do {
		fscanf(src, "%s\t%s\t%s", &label, &opcode, &op);
		printf("%10s%10s%10s\n", label, opcode, op);
		run(optab, inter, symtab, opcode, label, op, &start, &locctr);
	} while (strcmp(opcode, "END") != 0);
	return 0;
}
