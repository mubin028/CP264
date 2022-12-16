/*
 * graph_components.h
 *
 *  Created on: Dec. 7, 2021
 *      Author: mubin
 */


#define True 1
#define False 0
#ifndef GRAPH_COMPONENTS_H_
#define GRAPH_COMPONENTS_H_
typedef struct{
	int num; //unique number for the vertex
	char name[20]; //optional label

}Vertex;
Vertex* create_vertex(int n, char *s);
void print_vertex(Vertex *v);
void destroy_vertex(Vertex **v);
int is_equal_vertex(Vertex *v1, Vertex *v2);

typedef struct{

	Vertex *v1;
	Vertex *v2;
	int weight; //for non-weighted graphs set to 0;
	int directed; //for undirected graphs set to 0;

}Edge;

Edge* create_edge(Vertex *v1, Vertex *v2, int w, int d);
void destroy_edge(Edge **e);
void print_edge(Edge *e);
int is_equal_edge(Edge *e1, Edge *e2);


#endif /* GRAPH_COMPONENTS_H_ */
