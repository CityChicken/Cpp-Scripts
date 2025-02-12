# include<iostream>
#define NUM_CELLS 101
using namespace std;

//Sample input
/* 
1

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
	for (int i = 1; i <= numCells; i++) {
		tracker[i].cost = -1;
		tracker[i].solved = false;
	}
	
	int tempCell = fromCell;
	tracker[fromCell].cost = 0;
	tracker[fromCell].solved = true;
	
	while (tracker[toCell].solved == false) {
		//cout<<"Outer loop: "<<tempCell<<endl;
		edge *tempEdge = mazeCells[tempCell];
		while ( tempEdge != NULL) {
			//cout<<"Inner loop: "<<tempEdge->toCell<<" - "<<tempEdge->cost<<endl;

			if ( tracker[tempEdge->toCell].cost == -1 || 
				(tracker[tempCell].cost + tempEdge->cost < tracker[tempEdge->toCell].cost && tracker[tempEdge->toCell].solved == false))  {
				//cout<<"Condition met: From cost->"<<tracker[tempCell].cost<<" To cost->"<<tempEdge->cost<<endl;
				tracker[tempEdge->toCell].cost = tracker[tempCell].cost + tempEdge->cost; 
			}
			tempEdge = tempEdge->next;
		}
		
		int min_cost = -1;
		int min_idx = -1;
		for (int i = 1; i <= numCells; i++) {
			if (tracker[i].cost > 0){
				if (min_cost == -1 && tracker[i].solved == false) {
					min_cost = tracker[i].cost;
					min_idx = i;
				} else if (tracker[i].cost < min_cost &&  tracker[i].solved == false  ) {
					min_cost = tracker[i].cost;
					min_idx = i;
				}
			}

		}
		if (min_idx == -1) break;
		tempCell = min_idx;
		tracker[min_idx].solved = true;
	}
	
	return tracker[toCell].cost;
}

int main(){
	int cases;
	cin>>cases;
	int output[cases];

	for(int k = 0; k < cases; k++) {
		int n,e,t,m;
		cin>>n>>e>>t>>m;
		edge *mazeCells[NUM_CELLS] = {NULL};
		
		for (int i = 0; i < m; i++) {
			edge *newEdge = new edge;
			int fromCell;
			cin>>fromCell>>newEdge->toCell>>newEdge->cost;
			//cout<<"Inserting Edge "<<i<<endl;
			insert_edge(mazeCells, newEdge, fromCell);
		}
		
		int total = 0;
		for (int i = 1; i <= n; i++) {
			int minimum = min_cost(mazeCells, n, i, e);
			//cout<<"Min cost for cell "<<i<<" to cell "<<e<<" is "<<minimum<<endl;
			if (minimum <= t && minimum > -1) total++;
		}
		output[k] = total;
		//cout<<output[k]<<endl;
		//if (k < cases-1) cout<<endl;
	}	

	for(int k = 0; k < cases; k++) {
		cout<<output[k]<<endl;
		if (k < cases-1) cout<<endl;
	}

	return 0;
}
