#include<iostream>
#define MAXVERTEX 100

typedef struct vertex{
	int destination;
	struct vertex *Next;
}AdjList;
AdjList *Graph[MAXVERTEX];

int visit[MAXVERTEX], queue[MAXVERTEX];
int depan = 0, belakang = 0;

AdjList *addVertex(int number){
	AdjList *v = new AdjList;
	v->destination = number;
	v->Next = NULL;
	return v;
}

void createEdge(int node, int dest){
	AdjList *posNode, *baru;
	
	baru = addVertex(dest);
	posNode = Graph[node];
	
	if(posNode == NULL){
		Graph[node] = baru;
	}else{
		while(posNode->Next != NULL && posNode->destination != dest){
			posNode = posNode->Next;
		}
			if(posNode->destination != dest){
				posNode->Next = baru;
			}
	}
}

void addEdge(int node, int dest, int maxNode){
	if(node >= MAXVERTEX || dest >= maxNode){
		printf("Node tidak ada");
	}else{
		createEdge(node, dest);
		createEdge(dest, node); // Hapus baris ini jika derectional graph
	}
}

void printGraph(int maxNode){
	AdjList *posNode;
	
	for(int i = 0; i < maxNode; i++){
		posNode = Graph[i];
		if(posNode != NULL){
			printf("Destination Node ke %d", i);
			while(posNode != NULL){
				printf("-> %d", posNode->destination);
				posNode = posNode->Next;
			}
			printf("\n");
		}
	}
}

void setZero(int (*array)[MAXVERTEX]){
	for(int i = 0; i < MAXVERTEX; i++){
		(*array)[i] = 0;
	}
}

void DFS(int node){
	AdjList *pos;
	
	printf("%d ", node);
	pos = Graph[node];
	visit[node] = 1;
	while(pos != NULL){
		node = pos->destination;
		if(visit[node] == 0){
			DFS(node);
		}
		pos = pos->Next;
	}
}

void BFS(int node){
	AdjList *pos;
	
	printf("%d ", node);
	pos = Graph[node];
	visit[node] = 1;
	do{
		while(pos != NULL){
			node = pos->destination;
			if(visit[node] == 0){
				queue[belakang] = node;
				visit[node] = 1;
				belakang++;
			}
			pos = pos->Next;
		}
		printf("%d ", queue[depan]);
		pos = Graph[queue[depan]];
		depan++;
	}while(depan < belakang);
}

int main(){
	addEdge(1, 2, MAXVERTEX);
	addEdge(1, 3, MAXVERTEX);
	addEdge(2, 4, MAXVERTEX);
	addEdge(3, 4, MAXVERTEX);
	addEdge(3, 5, MAXVERTEX);
	addEdge(4, 6, MAXVERTEX);
	printGraph(MAXVERTEX);
	setZero(&visit);
	printf("\nDFS : ");DFS(4);
	setZero(&visit);
	printf("\nBFS : ");BFS(4);
	BFS(1);
	return 0;
}
