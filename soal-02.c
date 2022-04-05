/*EL2208 Praktikum Pemecahan Masalah dengan C 2021/2022
*Modul            : 7 - Stacks and Queues
*Percobaan        : -
*Hari dan Tanggal : Rabu, 6 April 2022
*Nama (NIM)       : -
*Asisten (NIM)    : -
*Nama File        : soal-02.c
*Deskripsi        : -
*/

#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <string.h>

// A structure to represent a stack
struct StackNode {
	int data;
	char command[32];
	struct StackNode* next;
};
 
struct StackNode* newNode(int data, char command[32])
{
	struct StackNode* stackNode =
	  (struct StackNode*)
	  malloc(sizeof(struct StackNode));
	stackNode->data = data;
	strcpy(stackNode->command, command);   
	stackNode->next = NULL;
	return stackNode;
}
 
int isEmpty(struct StackNode* root)
{
	return !root;
}
 
void push(struct StackNode** root, int data, char command[32])
{
	struct StackNode* stackNode = newNode(data, command);
	stackNode->next = *root;
	*root = stackNode;
	// printf("%d %s pushed to stack\n", data, command);
	
}
 
int pop(struct StackNode** root)
{
	if (isEmpty(*root))
		return 0;
	struct StackNode* temp = *root;
	*root = (*root)->next;
	int popped = temp->data;
	//printf("popped %s", temp->command);
	free(temp);
	return popped;
}

int peek(struct StackNode* root)
{
	if (isEmpty(root))
		return INT_MIN;
	return root->data;
}
 
int main()
{
	// Deklarasi array dalam bentuk linked list
	struct StackNode* root = NULL;
	struct StackNode* root2 = NULL;
	char filename[32];
	int i = 0; int j = 0; 
	int nLine = 0; int found = 0;
	char line[32];
	printf("Nama file yang akan dibaca: ");
	scanf("%s", filename);
	// Inisialisasi file eksternal
	FILE* fp = fopen(filename, "r");
	if (fp == NULL) {
		printf("File tidak bisa dibuka\n");
		printf("Nama file yang akan dibaca: ");
		scanf("%s", filename);
		fp = fopen(filename, "r");
	}
	// Push isi dari file eksternal ke stack
	while (fgets(line, 32, fp)) {
		i ++;
		push(&root, i, line);
	}
	nLine = i;
	// Menerima input line
	printf("Line yang ingin dibaca: ");
	scanf("%d", &j);
	while ((j > nLine) || (j < 1)) {
		printf("Line tidak valid\n");
		printf("Line yang ingin dibaca: ");
		scanf("%d", &j);
	}
	// Mencari line ke-j
	i = peek(root);
	push(&root2, root->data, root->command);
	pop(&root);
	found = (i == j);
	while ((!found) && (i > 1)) {
		i = peek(root);
		push(&root2, root->data, root->command);
		pop(&root);
		found = (i == j);
	}
	// Program menemukan line yang dicari
	if (found) {
		printf("Line %d: %s", j, root2->command);
		if (j == nLine) {
			printf("\n");
		}
	}
	else {
		printf("Line tidak ditemukan\n");
	}

	int jump = 0;
	int nextLine = 0;
	char *token;
	char delim[] = " ";
	token = strtok(root2->command, delim);
	jump = !strcmp(token, "jump");
	//printf("%d %d", jump, nextLine);
	// Cek apakah melakukan jump ke line tertentu
	if (jump) {
		token = strtok(NULL, delim);
		nextLine = atoi(token);
	}
	else {
		nextLine = (j + 1) % (nLine + 1);
	}
	printf("Line selanjutnya: %d\n", nextLine);
	// Bebaskan memory
	while(pop(&root)) {
		// pop(&root);
	}
	// printf("finished");
	return 0;
}
