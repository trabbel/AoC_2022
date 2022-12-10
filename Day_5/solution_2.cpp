#include <iostream>
#include <fstream>
#include <stack>

using namespace std;

stack<char> stacks[9];
stack<char> tempStack;

int main(){
	stacks[0].push('N');
	stacks[0].push('C');
	stacks[0].push('R');
	stacks[0].push('T');
	stacks[0].push('M');
	stacks[0].push('Z');
	stacks[0].push('P');

	stacks[1].push('D');
	stacks[1].push('N');
	stacks[1].push('T');
	stacks[1].push('S');
	stacks[1].push('B');
	stacks[1].push('Z');

	stacks[2].push('M');
	stacks[2].push('H');
	stacks[2].push('Q');
	stacks[2].push('R');
	stacks[2].push('F');
	stacks[2].push('C');
	stacks[2].push('T');
	stacks[2].push('G');

	stacks[3].push('G');
	stacks[3].push('R');
	stacks[3].push('Z');

	stacks[4].push('Z');
	stacks[4].push('N');
	stacks[4].push('R');
	stacks[4].push('H');

	stacks[5].push('F');
	stacks[5].push('H');
	stacks[5].push('S');
	stacks[5].push('W');
	stacks[5].push('P');
	stacks[5].push('Z');
	stacks[5].push('L');
	stacks[5].push('D');

	stacks[6].push('W');
	stacks[6].push('D');
	stacks[6].push('Z');
	stacks[6].push('R');
	stacks[6].push('C');
	stacks[6].push('G');
	stacks[6].push('M');

	stacks[7].push('S');
	stacks[7].push('J');
	stacks[7].push('F');
	stacks[7].push('L');
	stacks[7].push('H');
	stacks[7].push('W');
	stacks[7].push('Z');
	stacks[7].push('Q');

	stacks[8].push('S');
	stacks[8].push('Q');
	stacks[8].push('P');
	stacks[8].push('W');
	stacks[8].push('N');

	fstream file;
	file.open("input.txt",ios::in);
	
	if (file.is_open()){
		string line;
		int size;
		string temp = "";
		int cnt;
		int inputs[3];

		while(getline(file, line)){
			size = line.length();
			cnt = -1;
			for(int i=0;i<size;i++){
				if(line[i] != ' '){
					temp += line[i];
				}else{
					if(cnt%2==0){
						inputs[cnt/2] = stoi(temp); 
					}
					temp = "";
					cnt++;
				}
			}
			inputs[cnt/2] = stoi(temp); 
			temp = "";

			for(int i = 0; i<inputs[0]; i++){
				tempStack.push(stacks[inputs[1]-1].top());
				stacks[inputs[1]-1].pop();
			}

			for(int i = 0; i<inputs[0]; i++){
				stacks[inputs[2]-1].push(tempStack.top());
				tempStack.pop();
			}
		}
	}
	file.close();
	for(int i = 0; i<9; i++){
		cout << stacks[i].top();
	}
	return 0;
}
