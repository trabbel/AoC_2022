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
	
	int ropeLength = 10;
	
	set<vector<int>> coordinates;
	vector<int> rope[ropeLength];
	for(int i = 0; i<ropeLength; i++){
		rope[i] = vector<int> {0,0};
	}
	
	vector<int> direction;
	int steps;
	
	if (file.is_open()){
		string line;
		while(getline(file, line)){
			direction = moves[line[0]];
			steps = stoi(line.substr(2, line.size()-2));
			//cout << moves[direction][0] << endl;
			for(int i = 0; i<steps;i++){
				rope[0][0] += direction[0];
				rope[0][1] += direction[1];
					
				for(int j = 1; j<ropeLength; j++){	
					if(cheb_dist(rope[j-1], rope[j]) > 1){
						if(rope[j-1][0]-rope[j][0] > 0){
							rope[j][0] += 1;
						}else if(rope[j-1][0]-rope[j][0] < 0){
							rope[j][0] -= 1;
						} 
						if(rope[j-1][1]-rope[j][1] > 0){
							rope[j][1] += 1;
						}else if(rope[j-1][1]-rope[j][1] < 0){
							rope[j][1] -= 1;
						}
					}else{
						break;
					}							
				}	
				coordinates.insert(rope[ropeLength-1]);
			}	
		}
	}     

	file.close();	
	cout << coordinates.size() << endl;
	return 0;
}
