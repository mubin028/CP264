/*
 * ---------------------------------
 * Student Name:Mubin Qureshi
 * Student ID:180181900
 * Student Email:qure1900@mylaurier.ca
 * ---------------------------------
 */

# include <stdio.h>
# include <stdlib.h>
# include <assert.h>
# include <assert.h>
#include "list.h"

//---------------- Node Implementation ------------------------

Node* create_node(Data *d, Node *n) {
	assert(d);
	Node* node = (Node*)malloc(sizeof(node));
	node->data = copy_data(d);
	node->next = n;
	return node;
}

void print_node(Node *n) {
	assert(n);
	print_data(n->data);

	return;
}

Node* copy_node(Node *n) {

	assert(n);

	return create_node(n->data,n->next);
}

void destroy_node(Node **n) {

	assert(n&&*n);
	destroy_data(&(*n)->data);
	(*n)->data=NULL;
	(*n)->next=NULL;
	free(*n);
	return;
}

//---------------- Linked List Implementation ------------------------

List* create_list() {
	List *list = (List*)malloc(sizeof(list));
	list->head=NULL;
	list->size=0;
	return list;
}

int is_empty_list(List *list) {
	assert(list);
	return (list->head==NULL);

}

void print_list(List *list) {
	assert(list);
	Node *current_node = list->head;
	while(current_node!=NULL){
		print_node(current_node);
		printf("-->");
		current_node=current_node-> next;
	}
	printf("NULL\n");
	return;
}

void append_list(List *list, Data *d) {
	assert(list && d);
	Node *new_node = create_node(d, NULL);
	if (is_empty_list(list))
		list->head = new_node;
	else {
		Node *current_node = list->head;
		while (current_node->next != NULL)
			current_node = current_node->next;
		current_node->next = new_node;

	}
	list->size++;
	return;
}

void insert_front_list(List *list, Data *d) {
	assert(list && d);
	Node *new_node = create_node(d, list->head);
	list->head = new_node;
	list->size++;
	return;
}

Data* get_data_list(List *list, int index) {
	assert(list);
	return get_node_list(list,index)->data;
}

Node* get_node_list(List *list, int index) {
	assert(list);
	if (index <0||index >= list->size){
		printf("Error(get_node_list): index out of range\n");
		return NULL;
	}
	Node *current_node = list->head;
	int i=0;
	while (i <index){
		current_node = current_node->next;
		i++;
	}
	return copy_node(current_node);
}

void destroy_list(List **list) {

	while (!is_empty_list(*list))
	    remove_rear_list(*list);
	(*list)->head=NULL;
	(*list)->size=0;
	free(*list);
	*list = NULL;
	return;
}

Data* remove_rear_list(List *list) {
	assert(list);
	if (is_empty_list(list)){
		printf("Error(remove_rear_list): list is empty\n");
		return NULL;
	}

	Node *previous = NULL;
	Node *current = list->head;
	while (current->next!=NULL){
		previous =current;
		current = current->next;
	}
	Data *item = copy_data(current->data);

	if (list->size==1)
		list->head=NULL;
	else
		previous->next=NULL;

	destroy_node(&current);
	list->size--;
	return item;
}

void reverse_list(List *list) {
	assert(list);
	if (is_empty_list(list))
		return;


	Node *previous_node,*current_node,*next_node;
	previous_node = NULL;
	current_node = list->head;
	next_node = current_node->next;

	while(current_node->next!=NULL){
		current_node->next=previous_node;//reverse link
		previous_node=current_node;
		current_node = next_node;
		next_node = next_node->next;

	}
	current_node->next=previous_node;

	list->head=current_node;
	return;
}

List* array_to_list(Data *array, const int size) {

	assert(array);
	List* list = NULL;

	if(size<=0){
		printf("Error(array_to_list): invalid array sioze\n");
		return list;
	}
	int i;
	list = create_list();
	for(i =0;i<size;i++){
		append_list(list,&array[i]);
	}


	return list;
}

