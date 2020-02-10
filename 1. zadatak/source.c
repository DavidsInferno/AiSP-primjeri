#include<stdio.h>
#include<stdlib.h>

typedef struct cvor* position;
typedef struct cvor {
	int el;

	position next;
}Cvor;

int randomNumber(int min, int max);
position createNode();
void ispisliste(position head);
void insertEnd(position head, position p);
void readFile(position head, int broj);

int main() {
	srand(time(0));
	FILE* fp1;
	FILE* fp2;
	int broj = 0;

	position head1 = createNode();
	position head2 = createNode();

	fp1 = fopen("prvaDatoteka.txt", "w");
	fp2 = fopen("drugaDatoteka.txt", "w");

	for (int i = 0;i < 10;i++) {
		fprintf(fp1, "%d\n", randomNumber(20, 35));
		fprintf(fp2, "%d\n", randomNumber(20, 35));
	}
	fclose(fp1);
	fclose(fp2);

	readFile(head1, 1);




	fclose(fp1);
	fclose(fp2);
	system("PAUSE");
	return 0;
}


int randomNumber(int min, int max) {
	return rand() % (max + 1 - min) + min;
}

position createNode() {
	position q = NULL;
	q = (position)malloc(sizeof(Cvor));
	if (q == NULL) {
		printf("Allocation unsucesfull!");
		return NULL;
	}
	q->next = NULL;
	return q;
}

void insertEnd(position head, position p) {
	while (head->next!=NULL) {
		head = head->next;
	}
	head->next = p;
	p->next = NULL;
}

void ispisliste(position head) {
	while (head->next != NULL) {
		printf("%d\n", head->el);
		head = head->next;
	}

}


void readFile(position head,int broj) {
	FILE* fp = NULL;
	position s = NULL;
	if(broj==1)
		fp = fopen("prvaDatoteka.txt", "r");
	else
		fp = fopen("drugaDatoteka.txt", "r");


	if (fp == NULL) {
		printf("nije se otvorilo");
		return;
	}

	while (!feof(fp)) {
		s = createNode();
		fscanf(fp, "%d\n", s->el);																										

		insertEnd(head, s);
	}
	ispisliste(head);
	fclose(fp);
}
