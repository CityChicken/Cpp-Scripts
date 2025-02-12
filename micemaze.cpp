# include<iostream>
#define NUM_CELLS 100
using namespace std;

//Sample input
/* 

4 4 10 5
1 2 2
1 3 5
1 4 16
3 4 1
2 4 6

*/

struct edge {
	int toCell;
	int cost;
	edge *next;
};

struct track {
	int cost;
	bool solved;
};

void insert_edge(edge *mazeCells[NUM_CELLS], edge *newEdge, int fromCell){
	newEdge->next = mazeCells[fromCell];
	mazeCells[fromCell] = newEdge;
	return;
}

int min(int a, int b){
	if (a < b) return a;
	return b;
}


int min_cost(edge *mazeCells[NUM_CELLS], int numCells, int fromCell, int toCell) {
	track tracker[NUM_CELLS];
	for (int i = 0; i < numCells; i++) {
		tracker[i].cost = -1;
		tracker[i].solved = false;
	}
	
	int tempCell = fromCell;
	tracker[fromCell].cost = 0;
	tracker[fromCell].solved = true;
	
	while (tracker[toCell].solved == false) {
		edge *tempEdge = mazeCells[tempCell];
		while ( tempEdge != NULL) {
			if ( tracker[tempEdge->toCell].cost == -1 || tracker[tempCell].cost + tempEdge->cost < tracker[tempEdge->toCell].cost) {
				tracker[tempEdge->toCell].cost = tracker[tempCell].cost + tempEdge->cost; 
			}
			tempEdge = tempEdge->next;
		}
		
		int min_cost = -1;
		int min_idx = -1;
		for (int i = 0; i < numCells; i++) {
			if (min_cost == -1 && tracker[i].solved == false) {
				min_cost = tracker[i].cost;
				min_idx = i;
			} else if (tracker[i].solved == false && tracker[i].cost < min_cost ) {
				min_cost = tracker[i].cost;
				min_idx = i;
			}
		}
		tracker[min_idx].solved = true;
		tempEdge = mazeCells[min_idx];
	}
	
	return tracker[toCell].cost;
}

int main(){
	int n,e,t,m;
	cin>>n>>e>>t>>m;
	edge *mazeCells[NUM_CELLS];
	
	for (int i = 0; i < m; i++) {
		edge *newEdge = new edge;
		int fromCell;
		cin>>fromCell>>newEdge->toCell>>newEdge->cost;
		insert_edge(mazeCells, newEdge, fromCell);
	}
	
	cout<<min_cost(mazeCells, n, 0, 3)<<endl;
	
	
	return 0;
}
