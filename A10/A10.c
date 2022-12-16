/*
 * ---------------------------------
 * Student Name:Mubin Qureshi
 * Student ID:180181900
 * Student Email:qure1900@mylaurier.ca
 * ---------------------------------
 */
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <assert.h>
# include <math.h>
# include "heap.h"
# include "queue_array.h"
# include "stack_array.h"

Node* find_node_heap_aux(Node *n, Data *d);
int contains_heap_aux(Heap *h, Node *n, Data *d);
int is_full_heap_aux(Node *root);

//------------------------ A10 Task 1 -------------------------
/**
 * ------------------------------------------------------------
 * Parameters: 	d - 	a data item (Data*)
 * 				parent- pointer to parent (Node*)
 * 				left - 	pointer to left child (Node*)
 * 				right - pointer to right child (Node*)
 * Returns: 	node -	new heap node (Node*)
 * Description:	Creates a new heap node using the given data and pointers
 * Asserts:		data is not NULL
 * ------------------------------------------------------------
 */
Node* create_node(Data *d, Node *parent, Node *left, Node *right) {
	assert (d);
	Node* node = (Node*)malloc(sizeof(node));
	node->data=copy_data(d);
	node->left=left;
	node->right=right;
	node->parent=parent;
	return node;
}

/**
 * -------------------------------------------------------
 * Parameters: 	n - a node (Node*)
 * Returns: 	none
 * Description:	prints the contents of a heap node
 * 				invokes print_data, does not print parent, left and right
 * 				if node is NULL prints <NULL Node>
 * Assert:		None
 * -------------------------------------------------------
 */
void print_node(Node *n) {

	if (n ==NULL){
		printf("<NULL Node>");
		return;
	}
	print_data(n->data);

	return;
}

/**
 * --------------------------------------------------------
 * Parameters: 	n - 	a node (Node*)
 * Returns: 	n2 -	a copy node (Node*)
 * Description:	Creates a copy of the given heap node
 * 				The new node has a duplicate copy of data and
 * 				same parent, left and right child
 * Assert:		given node is not NULL
 * --------------------------------------------------------
 */
Node* copy_node(Node *n) {

	assert(n);

		return create_node(n->data,n->parent,n->left,n->right);

	return NULL;
}

/**
 * ---------------------------------------------------
 * Parameters:  n - a node (Node**)
 * Returns: 	none
 * Description:	destroys a heap node by:
 * 				- destroy the encompassed data
 * 				- setting parent, left and right to NULL
 * 				- free the node pointer, and set it to NULL
 * Assert:		n and *n are not NULL
 * --------------------------------------------------
 */
void destroy_node(Node **n) {


	assert(n&&*n);
	destroy_data(&(*n)->data);
	(*n)->parent=NULL;
	(*n)->left=NULL;
	(*n)->right=NULL;
	(*n)->data=NULL;
	//free(*n);
	(*n)=NULL;

	return;
}

//------------------------ A10 Task 2 -------------------------

/**
 * ------------------------------------------------------------
 * Parameters: 	type - heap type (max or min) (char*)
 * Returns: 	h - new heap (Heap*)
 * Description:	Creates a new heap of given type
 * 				Heap root is set to NULL and size to 0
 * 				if type is not "max" or "min" print error msg, set to "max"
 * Asserts:		none
 * ------------------------------------------------------------
 */
Heap* create_heap(char *type) {

//	Node *root;		//heap root
//		int size;		//number of items
//		char type[4];	//max or min

	Heap *h = (Heap*) malloc(sizeof(Heap));

	if (strcmp(type, "max") != 0 && strcmp(type, "min") != 0) {
		printf("Error(create_heap): invalid type, set to max\n");
		strncpy(h->type, "max", 4);
	} else
		strncpy(h->type, type, 4);
	h->size = 0;
	h->root = NULL;
	return h;
}

/**
 * ---------------------------------------------------
 * Parameters:  h - a heap (Heap**)
 * Returns: 	none
 * Description:	destroys a heap by:
 * 				- removing all items
 * 				- setting root to NULL and size to 0 and type to empty string
 * 				- free the heap pointer, and set it to NULL
 * Assert:		h and *h are not NULL
 * --------------------------------------------------
 */
void destroy_heap(Heap **h) {

	while (!is_empty_heap(*h))
		remove_heap(*h);
	(*h)->root = NULL;
	(*h)->size = 0;
	//free(*h);
	*h = NULL;
	return;

}

/**
 * ---------------------------------------------------
 * Parameters:  h - a heap (Heap*)
 * Returns: 	True/False
 * Description:	check if heap is empty
 * Assert:		h is not NULL
 * --------------------------------------------------
 */
int is_empty_heap(Heap *h) {
	assert(h);
	return (h->size==0);
}

/**
 * ---------------------------------------------------
 * Parameters:  h - a heap (Heap*)
 * Returns: 	copy of data at the heap root
 * Description:	Returns a duplicate copy of the data item at the root
 * 				if heap is empty prints error msg, returns NULL
 * Assert:		h is not NULL
 * --------------------------------------------------
 */
Data* peek_heap(Heap *h) {
	assert(h);
	if ( is_empty_heap(h)){
		printf("Error(peek_heap): heap is empty\n");
		return NULL;
	}

	return (copy_data(h->root->data));
}

//------------------------ A10 Task 3 -------------------------

/**
 * ---------------------------------------------------
 * Parameters:  h - a heap (Heap*)
 * 				d - a data item (Data*)
 * Returns: 	pointer to a node
 * Description:	Returns a pointer to the node that contains given data
 * 				if not found returns NULL
 * Assert:		h and are not NULL
 * --------------------------------------------------
 */
Node* find_node_heap(Heap *h, Data *d) {
	assert(h && d);

	if (h->root==NULL){
		return NULL;
	}


	return find_node_heap_aux(h->root, d);

}

/**
 * ---------------------------------------------------
 * Parameters:  n - a node (Node*)
 * Returns: 	a pointer to  a node
 * Description:	private helper function for find_node_heap
 * 				Uses recursion.
 * 				Search through given node and recurse to other nodes
 * Assert:		None
 * --------------------------------------------------
 */
Node* find_node_heap_aux(Node *n, Data *d) {
	if (compare_data(d, n->data) == 0) {
		//print_node(n);
		return copy_node(n);

	} else if (n == NULL)
		return NULL;
	else {
		if (n->left != NULL)
			find_node_heap_aux(n->left, d);
		if (n->right != NULL)
			find_node_heap_aux(n->right, d);
			return n;
	}
	return n;

}

//------------------------ A10 Task 4 -------------------------

/**
 * ---------------------------------------------------
 * Parameters:  h - a heap (Heap*)
 * Returns: 	None
 * Description:	Prints contents of a heap
 * 				if heap is empty prints <empty heap>
 * 				if heap is NULL prints <NULL Heap>
 * 				prints type and size of heap, then prints items in levelorder
 * 				Uses a queue.
 * 				items are separated by a space
 * Asserts:		None
 * --------------------------------------------------
 */
void print_heap(Heap *h) {

	if (h==NULL){
		printf("<NULL Heap>\n");
		return;
	}

	if (is_empty_heap(h)){
		printf("heap type = %s, size = %d\n",h->type,h->size);
		printf("<empty heap>\n");
		return;
	}
	printf("heap type = %s, size = %d\n",h->type,h->size);


	Queue* q = NULL;
	q = create_queue(h->size);

	Node* temp = h->root;

	while (temp!=NULL){
		print_node(temp);
		printf(" ");
		if (temp->left!=NULL)
			insert_queue(q,copy_data(temp->left->data));
		if (temp->right!=NULL)
					insert_queue(q,copy_data(temp->right->data));
		temp = find_node_heap(h,remove_queue(q));
		//temp = temp->left;
	}
	printf("\n");
	return;
}

//------------------------ A10 Task 5 -------------------------

/**
 * ---------------------------------------------------
 * Parameters:  h - a heap (Heap*)
 * 				d - data to search for (Data*)
 * Returns: 	True/False
 * Description:	Check if a heap contains a data item
 * 				recurse through all nodes to check
 * 					if any node contains the data
 * 				returns True if found and False otherwise
 * Asserts:		h and d are not NULL
 * --------------------------------------------------
 */
int contains_heap(Heap *h, Data *d) {

	assert(h && d);
	return contains_heap_aux(h, h->root, d);
}

/**
 * ---------------------------------------------------
 * Parameters:  h - a heap (Heap*)
 * 				n - current node to check if it contains the data (Node*)
 * 				d - data to search for (Data*)
 * Returns: 	True/False
 * Description:	Private helper function for contains_heap
 * 				recurse through all nodes to check if node contains data
 * 				returns True if found and False otherwise
 * Asserts:		None
 * --------------------------------------------------
 */
int contains_heap_aux(Heap *h, Node *n, Data *d) {

	if (n==NULL)
	    return 0;


	if (compare_data(d, n->data)==0)
	    return 1;


	else{
	    if (n->left != NULL)
	        find_node_heap_aux(n->left, d);
	    if (n->right != NULL)
	        find_node_heap_aux(n->right, d);

	 }
	return 0;
}
//------------------------ A10 Task 6 -------------------------

/**
 * ---------------------------------------------------
 * Parameters:  h - a heap (Heap*)
 * 				start - a node for starting the search, normally the root (Node*)
 * 				node - the node to search for its level (Node*)
 * 				level - keeps track for level so far (int)
 * Returns: 	node_level - level of "node" in the heap (int)
 * Description:	Private helper method. Uses recursion.
 * 				Finds the level of a given node in a heap
 * 				if not found returns -1
 * Asserts:		heap is not NULL
 * --------------------------------------------------
 */
int find_node_level_heap_aux(Node *start, Node *node, int level) {
	if (node == NULL)
		return -1;

	if (compare_data(node->data, node->data) == 0)
		return level;
	else {
		find_node_level_heap_aux(node->left, node, level + 1);
		find_node_level_heap_aux(node->right, node, level + 1);
	}

	return level;
}

/**
 * ---------------------------------------------------
 * Parameters:  h - a heap (Heap*)
 * 				node - the node to search for its level (Node*)
 * Returns: 	node_level - level of "node" in the heap (int)
 * Description:	Finds the level of a given node in a heap
 * 				if not found returns -1
 * 				Root is assumed to be at level 1
 * Asserts:		heap is not NULL
 * --------------------------------------------------
 */
int find_node_level_heap(Heap *h, Node *node) {

	assert(h);
	return find_node_level_heap_aux(h->root, node, 1);
}

//------------------------ A10 Task 7 -------------------------

/**
 * ---------------------------------------------------
 * Parameters:  root - pointer to root node (Node*)
 * Returns: 	True/False
 * Description:	A private helper function for is_full_heap function
 * 				Uses recursion
 * 				Returns True if heap is full and False otherwise
 * Asserts:		heap is not None
 * --------------------------------------------------
 */
int is_full_heap_aux(Node *root) {


	if (root == NULL)
	        return True;

	    if (root->left == NULL && root->right == NULL)
	        return True;


	    if ((root->left) && (root->right))
	        return (is_full_heap_aux(root->left) && is_full_heap_aux(root->right));

	    return False;
	}


/**
 * ---------------------------------------------------
 * Parameters:  h - pointer to a heap (Heap*)
 * Returns: 	True/False
 * Description:	Returns True if heap is full and False otherwise
 * 				A full heap is a heap in which each node has 0 or 2 children
 * 				An empty heap is considered a full heap
 * Asserts:		heap is not None
 * --------------------------------------------------
 */
int is_full_heap(Heap *h) {
	assert(h);
	return is_full_heap_aux(h->root);
}

//------------------------ A10 Task 8 -------------------------
/**
 * ---------------------------------------------------
 * Parameters:  h - a heap (Heap*)
 * Returns: 	d - copy of data with max data
 * Description:	Returns a duplicate copy of maximum item in heap
 * 				steps are different depending on max/min heap
 * 				if heap is empty, print error msg and return NULL
 * Asserts:		heap is not None
 * --------------------------------------------------
 */
Data* find_max_heap(Heap *h) {
	assert(h);
	if (strcmp(h->type,"max"))
		return peek_heap(h);
	else{

		Node* current = h->root;
		while (current->left != NULL) {
		    current = current->left;
		  }

		return copy_data(current->data);
	}

}

/**
 * ---------------------------------------------------
 * Parameters:  h - a heap (Heap*)
 * Returns: 	d - copy of data with min data
 * Description:	Returns a duplicate copy of minimum item in heap
 * 				steps are different depending on max/min heap
 * 				if heap is empty, print error msg and return NULL
 * Asserts:		heap is not None
 * --------------------------------------------------
 */
Data* find_min_heap(Heap *h) {
	assert(h);
	if (strcmp(h->type,"min"))
		return peek_heap(h);
	else{

		Node* current = h->root;
		while (current->left != NULL) {
		    current = current->left;
		  }

		return copy_data(current->data);
	}

}

//------------------------ Do not change these -------------------------
void insert_heap(Heap *h, Data *d) {
	return;
}

void remove_heap(Heap *h) {
	return;
}
