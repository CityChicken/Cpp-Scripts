#include <iostream>
#define NUM_TOWNS 100
using namespace std;

// DMOJ problem saco08p3

/* 
Input:
	n (the number of towns)
	n lines of n integers (the distances between all towns)
	m (the number of cookie towns)
	m lines of 1 integer (each cookie town)
Output:
	d the minimum distance from 1 to n with a cookie stop
	k the number of ways a minimum path can be achieved
*/

struct edge{
	int toTown;
	int cost;
};


struct state{
	int cost;
	bool solved;
};

int min_array(int *array, int size, bool retIdx = true){
	int idx = -1;
	int min = -1;
	for (int i = 0; i < size ;i++) {
		if (min == -1) {
			min = array[i];
			idx = i;
		}
		else if (array[i] < min && array[i] > -1) {
			min = array[i];
			idx = i;
		}
	}
	
	if (retIdx)
		return idx;
	return min;
}


int min_array_state(state *array, int size, bool retIdx = true){
	int idx = -1;
	int min = -1;
	for (int i = 0; i < size ;i++) {
		if (min == -1 && array[i].solved == false ) {
			min = array[i].cost;
			idx = i;
		}
		else if (array[i].cost < min && array[i].cost > 0 && array[i].solved == false) {
			min = array[i].cost;
			idx = i;
		}
	}
	
	if (retIdx)
		return idx;
	return min;
}

int shortest_path(int townMap[NUM_TOWNS][NUM_TOWNS], state townMins[NUM_TOWNS][NUM_TOWNS],  int numTowns, int fromTown, int toTown){
	int tempCost = 0;
	int tempTown = fromTown;
	int iterations = 0;
	while (townMins[fromTown][toTown].solved == false) {
		for (int i = 0; i < numTowns; i++) {
			if ( i != fromTown && townMins[fromTown][i].solved == false ) {
				int tempCostNew = tempCost + townMap[tempTown][i];
				if ( townMins[fromTown][i].cost < 0 || tempCostNew < townMins[fromTown][i].cost) {
					townMins[fromTown][i].cost = tempCostNew;
				}
			}
		}
		int minIdx = min_array_state(townMins[fromTown], numTowns);
		if (minIdx > -1) {
				townMins[fromTown][minIdx].solved = true;
				tempCost = townMins[fromTown][minIdx].cost;
				tempTown = minIdx;
				cout<<"Minimum path is at town: "<<minIdx<<endl;
		} else {
			break;
		}
		iterations++;
		if (iterations > 1000000) {
			cout<<"Loop is not terminating"<<endl;
			break;
		}
	}
	
	return townMins[fromTown][toTown].cost;
}


int main(){
	int n;
	cin>>n;
	int townMap[NUM_TOWNS][NUM_TOWNS];
	state townMins[NUM_TOWNS][NUM_TOWNS];
	
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++) {
			cin>>townMap[i][j];
			townMins[i][j].solved = false;
			townMins[i][j].cost = -1;
		}
	}
	
	int m;
	cin>>m;
	int cookies[m];

	for (int i = 0; i < m; i++){
		cin>>cookies[i];		
	}

	int totals[m];
	for (int i = 0; i < m; i++){
		totals[i] = shortest_path(townMap, townMins, n, 0, cookies[i] - 1) + shortest_path(townMap, townMins, n, cookies[i] - 1, n-1); 	
	}

	cout<<min_array(totals, m)<<endl;

	return 0;
}
