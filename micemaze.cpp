#include <iostream>
#include <queue>
define NUM_CELLS 100;


struct edge {
	int cost, toCell;  
	edge *next;

};

struct space {
	int minCost;
	bool solved;
};

void insert_edge(edge *cells[NUM_CELLS], edge *newEdge, int fromCell){

}

int main() {
	edge *cells[NUM_CELLS];
	
	int n,t,m;
	cin>>n>>t>>m;

	for (int i = 0; i < m; i++){
		edge *newEdge = new edge;
		int fromCell;
		cin>>fromCell>>edge.toCell>>edge.cost;
		insert_edge(cells, newEdge, fromCell);
	}

	space exploredSpace[NUM_CELLS];

	cout<<"Hello world!"<<endl;
	return 0;
}