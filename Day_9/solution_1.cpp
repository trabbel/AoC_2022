#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>
#include <set>

using namespace std;


int cheb_dist(vector<int> a, vector<int> b){	
	return max(abs(a[0] - b[0]), abs(a[1] - b[1]));
	}


int main(){
	fstream file;
	file.open("input.txt",ios::in);
	
	unordered_map<char, vector<int>> moves;
	moves['U'] = vector<int> {1,0};
	moves['D'] = vector<int> {-1,0};
	moves['R'] = vector<int> {0,1};
	moves['L'] = vector<int> {0,-1};
	
	set<vector<int>> coordinates;
	vector<int> head{0,0};
	vector<int> tail{0,0};
	
	vector<int> direction;
	vector<int> oldPos;
	int steps;
	
	if (file.is_open()){
		string line;
		while(getline(file, line)){
			direction = moves[line[0]];
			steps = stoi(line.substr(2, line.size()-2));
			for(int i = 0; i<steps;i++){
				oldPos = head;
				
				head[0] += direction[0];
				head[1] += direction[1];
			
				if(cheb_dist(head, tail) > 1){
					tail[0] = oldPos[0];
					tail[1] = oldPos[1];
				}
				coordinates.insert(tail);
			}
		}
	}     

	file.close();	
	cout << coordinates.size() << endl;
	return 0;
}
