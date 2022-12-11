#include <iostream>
#include <fstream>
#include <set>

using namespace std;


int main(){
	char preamble[14];

	fstream file;
	file.open("input.txt",ios::in);
	if (file.is_open()){
		string line;
		int size;
		while(getline(file, line)){
			size = line.length();
			for(int i = 0; i<size; i++){
				preamble[i%14] = line[i];
				if (i >13){
					set<char> message{begin(preamble), end(preamble)};
					if (message.size()==14){
						cout << i+1 << endl;
					return 0;
					}
				}
			}
		}
	}
	file.close();
	return 0;
}
