#include <iostream>
#define NUM_TOWNS
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
}


struct state{
	int cost;
	bool solved;
}

int min_array(int *array, int size){
	int min = array[0];
	for (int i = 1; i < size ;i++) {
		if (array[i] < min) min = array[i];
	}
	return min;
}

int shortest_path(edge *townMap[NUM_TOWNS], int numTowns, int fromTown, int toTown){
	return 1;
}


int main(){
	int n;
	cin>>n;
	int townMap[NUM_TOWNS][NUM_TOWNS];

	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++) {
			cin>>townMap[i][j];
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
		totals[i] = shortest_path() + shortest_path() 	
	}

	cout<<min_array(totals, m)<<endl;

	return 0;
}
