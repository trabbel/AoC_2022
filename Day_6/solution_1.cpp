#include <iostream>
#include <fstream>
#include <set>

using namespace std;


int main(){
	char preamble[4];

	fstream file;
	file.open("input.txt",ios::in);
	if (file.is_open()){
		string line;
		int size;
		while(getline(file, line)){
			size = line.length();
			for(int i = 0; i<size; i++){
				preamble[i%4] = line[i];
				if (i >3){
					set<char> message{begin(preamble), end(preamble)};
					if (message.size()==4){
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
