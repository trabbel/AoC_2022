#include <iostream>
#include <fstream>

using namespace std;

int main(){
	fstream file;
	file.open("input.txt",ios::in);
	int points = 0;
	
	if (file.is_open()){
		string line;
		while(getline(file, line)){
			if (line == "A X"){
				points += 4;}
			else if (line == "A Y"){
				points += 8;}
			else if (line == "A Z"){
				points += 3;}
			else if (line == "B X"){
				points += 1;}
			else if (line == "B Y"){
				points += 5;}
			else if (line == "B Z"){
				points += 9;}
			else if (line == "C X"){    
				points += 7;}
			else if (line == "C Y"){
				points += 2;}
			else if (line == "C Z"){
				points += 6;}
		}
		file.close(); 
	}
	cout << points << endl;
	return 0;
}
