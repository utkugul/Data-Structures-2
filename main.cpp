#include <stdio.h>
#include <string.h>
#include <fstream>

struct node {
	char adres[10];
	int sayac = 1;
	node* next;
	node* tail;
};
struct tree {
	int T = 5;
	int L = 4;
	node* head=NULL;
	void print();
	void sayac();
	void add_node(char x[4]);
	void remove_last();
	int length();
};
void tree::print() {
	if (head == NULL) {
		printf("Liste bos");
	}
	else {
		node* temp = new node();
		temp = head;
		while (temp) {
			printf("%s,%d",temp->adres,temp->sayac);
			if (temp->next) {
				printf(" <=> ");
			}
			temp = temp->next;
		}
	}
}
void tree::add_node(char x[4]) {
	if (head == NULL) {
		node* newnode = new node();
		newnode->next = NULL;
		newnode->tail = NULL;
		strcpy_s(newnode->adres, x);
		head = newnode;
	}
	else {
		node* temp = new node;
		temp = head;
		int found = 0;
		while (temp) {
			if (strcmp(temp->adres, x) == 0) {
				found = 1;
				if (head == temp) {
					temp->sayac++;
				}
				else if (temp->next == NULL) {
					temp->sayac++;
					if (temp->sayac > T) {
						temp->tail->next = NULL;
						temp->tail = NULL;
						temp->next = head;
						head->tail = temp;
						head = temp;
					}
				}
				else {
					temp->sayac++;
					if (temp->sayac > T) {
						temp->tail->next = temp->next;
						temp->next->tail = temp->tail;
						temp->next = head;
						head->tail = temp;
						temp = head;
					}
				}
			}
			else if(temp->next== NULL && !found){
				node* newnode = new node();
				strcpy_s(newnode->adres, x);
				head->tail = newnode;
				newnode->next = head;
				newnode->tail = NULL;
				head = newnode;
			}
			temp = temp->next;
		}
	}
	if (length() > L) {
		remove_last();
	}
}
int tree::length() {
	int counter = 0;
	node* temp = new node;
	temp = head;
	while (temp) {
		counter++;
		temp = temp->next;
	}
	return counter;
}
void tree::remove_last() {
	node* temp = new node;
	temp = head;
	while (temp->next) {
		temp = temp->next;
	}
	temp->tail->next = NULL;
	delete temp;
}

int main() {
	tree mytree;
	FILE* file;
	file = fopen("Input.txt", "r");
	char arr[20];
	fscanf_s(file, "%c" , &arr[0]);
	printf("%c", arr[0]);



	return 0;
}