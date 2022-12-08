#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

int main(){
	fstream file;
	file.open("input.txt",ios::in);
	int maxCal[4] = {};
	
	if (file.is_open()){
		string line;
		while(getline(file, line)){
			if (line.size() == 0) {
				sort(maxCal, maxCal+4);
				maxCal[0] = 0;
			}else{      	
				maxCal[0] += stoi(line);
			}
		}
		file.close(); 
		sort(maxCal, maxCal+4);
		maxCal[0] = 0;
	}
	// Task 1
	cout << maxCal[3] << endl;
	// Task 2
	cout << maxCal[1] + maxCal[2] + maxCal[3] << endl;
	return 0;
}
