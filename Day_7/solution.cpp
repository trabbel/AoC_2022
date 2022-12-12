#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>

using namespace std;

int main(){
	vector<string> path;
	unordered_map<string, int> sizes;
	int total = 0;
	
	fstream file;
	file.open("input.txt",ios::in);
	if (file.is_open()){
		sizes["/"] = 0;
		string line;
		int size;
		string tmp="";
		vector<string> inputs;
		while(getline(file, line)){
			inputs.clear();
			tmp="";
			size = line.length();
			for(int i = 0; i<size; i++){
				if (line[i] != ' '){
					tmp += line[i];				
				}else{			
					inputs.push_back(tmp);
					tmp = "";
				}
			}
			inputs.push_back(tmp);


			if (inputs[0] == "$"){
				if (inputs[1] == "cd"){
					if (inputs[2] == "/"){
						path.clear();
						path.push_back("/");
					}else if(inputs[2] == ".."){
						path.pop_back();
					}else{
						path.push_back(inputs[2]);			
					}
				}

			}else if (inputs[0] == "dir"){
				continue;
			}else{
				int pathSize = path.size();
				tmp = "";
				for(int i = 0;i<pathSize; i++){
					tmp += path[i];
					sizes[tmp] += stoi(inputs[0]);
				}
			}

		}
	}     
	int needed = 30000000 - (70000000 - sizes["/"]);
	int min = sizes["/"];

	for (const auto & [ key, value ] : sizes) {
		if (value <= 100000){
			total += value;
		}
		if (value >= needed && value < min){
			min = value;
		}
	}
	cout << total << endl; // Task 1
	cout << min << endl; // Task 2

	file.close();
	return 0;
}
