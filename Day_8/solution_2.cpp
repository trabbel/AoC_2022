#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>

using namespace std;

int main(){
	int forest[99][99];
	int score[99][99] = {};
	for(int i = 1; i<98; i++){
		for(int j = 1; j<98; j++){
			score[i][j] = 1;
		}
	}
	fstream file;
	string line;
	file.open("input.txt",ios::in);
	int lineCnt = 0;
	int lineSize = 99;
	if (file.is_open()){
		while(getline(file, line)){
			for(int i = 0; i<lineSize; i++){
				forest[lineCnt][i] = line.at(i)-48;
			}
			lineCnt++;
		}
	}
	file.close();
	
	int maxTrees;
	int height;
	int oneDirection;
	
	//Go through each tree
	for(int i = 1; i<98; i++){
		for(int j = 1; j<98; j++){
			height = forest[i][j];
			
			//right
			oneDirection = 1;
			maxTrees = 97-j;
			for(int l = 1; l<=maxTrees; l++){
				if(forest[i][j+l] < height){
					oneDirection++;
				}else{
					break;
				}
			}
			score[i][j] *= oneDirection;
			
			//left
			oneDirection = 1;
			maxTrees = j-1;
			for(int l = 1; l<=maxTrees; l++){
				if(forest[i][j-l] < height){
					oneDirection++;
				}else{
					break;
				}
			}
			score[i][j] *= oneDirection;
			
			//down
			oneDirection = 1;
			maxTrees = 97-i;
			for(int l = 1; l<=maxTrees; l++){
				if(forest[i+l][j] < height){
					oneDirection++;
				}else{
					break;
				}
			}
			score[i][j] *= oneDirection;
			
			//up
			oneDirection = 1;
			maxTrees = i-1;
			for(int l = 1; l<=maxTrees; l++){
				if(forest[i-l][j] < height){
					oneDirection++;
				}else{
					break;
				}
			}
			score[i][j] *= oneDirection;
			
			
		}
	}
	int solution = 0;
	for(int i = 1; i<98; i++){
		for(int j = 1; j<98; j++){
			if(score[i][j]>solution){
				solution = score[i][j];
			}
		}
	}
	cout << solution << endl;
	return 0;
}
