#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

/*Input starts with a line containing two integers (n,m) indicating the number of target languages 
 and the number of translators at your disposal (1<=n<=100, 1<=m<=4500). The second line will contain 
 (n) strings specifying the target (n) languages. After this line are (m) lines of the form (L_1, L_2, c) 
 where (L_1) and (L_2) are two different languages and (c) is a positive integer specifying the cost to 
 translate between them (in either direction). The languages (L_1) and (L_2) are always either English or one of the 
 target languages, and any pair of languages will appear at most once in the input. The initial book is 
 always written in English.
*/
//Sample Input
/*
4 6
Pashto French Amheric Swedish
English Pashto 1
English French 1
English Amheric 5
Pashto Amheric 1
Amheric Swedish 5
French Swedish 1
-- 8

2 1
A B
English B 1
--Impossible
*/

struct trl {
	int indexL;
	int cost;
	trl *next = NULL;
};


void insertTrl(trl *translators[1000], int indexL, trl *newTrl){
	trl *tempTrl = translators[indexL];
	if (translators[indexL] == NULL)
	{
		translators[indexL] = newTrl;
	} 
	else if (newTrl->cost < translators[indexL]->cost)
	{
		newTrl->next = tempTrl;
		translators[indexL] = newTrl;
	}
	else 
	{
		trl *tempTrl2 = tempTrl->next;
		while(tempTrl2 != NULL) 
		{
			if (newTrl->cost > tempTrl->cost && newTrl->cost < tempTrl2->cost) {
				tempTrl->next = newTrl;
				newTrl->next = tempTrl2;
				return;
			}
			tempTrl = tempTrl->next;
			tempTrl2 = tempTrl->next;
		}
		tempTrl->next = newTrl;
	}
}

int main(){
	int n,m;
	string languages[1000];
	unordered_map<string, int> L;
	static trl *translators[1000] = {NULL};
	int explored[1000];
	//for (int i = 0; i < 1000; i++)
	//{
	//	translators[i] = NULL;
	//}
	
	//collect size parameters
	cin>>n>>m;
	languages[0] = "English";
	L[languages[0]] = 0;
	explored[0] = 1;
	for (int i = 1; i <= n; i++) 
	{
		cin>>languages[i] ;
		L[languages[i]] = i;
		explored[i] = 0;
	}
	//build the ordered tree as we go
	for (int i = 0; i < m; i++) 
	{
		string inL, outL;
		int cost;
		cin>>inL>>outL>>cost;
		trl *newTrl = new trl;
		newTrl->cost = cost;
		newTrl->indexL = L[outL];
		insertTrl(translators, L[inL], newTrl); 
	}
	
	
	//search the tree
	trl *searchTrl = translators[0];
	
	
	cout<<"SUCCESS!"<<endl;
	return 0;
}