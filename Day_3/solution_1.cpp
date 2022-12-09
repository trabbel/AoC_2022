#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <iterator>

using namespace std;

int main(){
	fstream file;
	file.open("input.txt",ios::in);
	int prioritySum = 0;
	
	if (file.is_open()){
		string line;
		int size;

		while(getline(file, line)){
			string first = line.substr(0, line.size()/2);
			string second = line.substr(line.size()/2);
			sort(first.begin(), first.end());
			sort(second.begin(), second.end());
			string intersection;
			set_intersection(first.begin(), first.end(), second.begin(), second.end(), back_inserter(intersection));
			cout << intersection << "\n";
			int i = intersection[0] - 96;
			if (i<0){
				i+=58;
			}
			prioritySum += i;
		}
		file.close(); 
	}
	cout << prioritySum;
	return 0;
}
