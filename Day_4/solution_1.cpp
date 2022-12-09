#include <iostream>
#include <fstream>

using namespace std;

int main(){
	fstream file;
	file.open("input.txt",ios::in);
	
	int points = 0;
	char del_1 = ',';
	char del_2 = '-';
	if (file.is_open()){
		string line;
		string temp = "";
		int size;
		int cnt;
		int inputs[4];
		while(getline(file, line)){
			size = line.length();
			cnt = 0;
			for(int i = 0; i<size; i++){
				if ((line[i] != del_1) && (line[i] != del_2)){
					temp += line[i];				
				}else{
					inputs[cnt] = stoi(temp);
					temp = "";
					cnt++;
				}
			}
			inputs[cnt] = stoi(temp);
			temp = "";
			
			if ((inputs[0]<=inputs[2] && inputs[1]>=inputs[3]) || (inputs[0]>=inputs[2] && inputs[1]<=inputs[3])){
				points++;
			}
		}
		file.close(); 
		}
	cout << points;
	return 0;
}
