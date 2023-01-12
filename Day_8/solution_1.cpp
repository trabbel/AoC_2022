#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>

using namespace std;

int main(){
	int forest[99][99];
	int visible[99][99] = {};
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
	
	
	int biggest;
	
	//right
	for(int i = 1; i<98; i++){
		biggest = forest[i][0];
		for(int j = 1; j<98; j++){
			if(forest[i][j] > biggest){
				visible[i][j] = 1;
				biggest = forest[i][j];
				if(biggest == 9){
					break;
				}
			}
		}
	}
	
	//left
	for(int i = 1; i<98; i++){
		biggest = forest[i][98];
		for(int j = 98; j>1; j--){
			if(forest[i][j] > biggest){
				visible[i][j] = 1;
				biggest = forest[i][j];
				if(biggest == 9){
					break;
				}
			}
		}
	}
	
	//down
	for(int i = 1; i<98; i++){
		biggest = forest[0][i];
		for(int j = 1; j<98; j++){
			if(forest[j][i] > biggest){
				visible[j][i] = 1;
				biggest = forest[j][i];
				if(biggest == 9){
					break;
				}
			}
		}
	}
	
	//up
	for(int i = 1; i<98; i++){
		biggest = forest[98][i];
		for(int j = 98; j>1; j--){
			if(forest[j][i] > biggest){
				visible[j][i] = 1;
				biggest = forest[j][i];
				if(biggest == 9){
					break;
				}
			}
		}
	}
	
	int solution = 99+99+97+97;
	for(int i = 1; i<98; i++){
		for(int j = 1; j<98; j++){
			solution += visible[i][j];
		}
	}
	cout << solution << endl;
	return 0;
}
