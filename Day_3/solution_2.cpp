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
	string first;
	string second;
	string third;
	int c = 0;
	
	if (file.is_open()){
		string line;
		int size;

		while(getline(file, line)){
			switch(c){
				case 0:
					first = line;
					c++;
					break;
				case 1:
					second = line;
					c++;
					break;
				case 2:
					third = line;
					c = 0;
					sort(first.begin(), first.end());
					sort(second.begin(), second.end());
					sort(third.begin(), third.end());
					string intersection_1;
					string intersection_2;
					set_intersection(first.begin(), first.end(), second.begin(), second.end(), back_inserter(intersection_1));
					set_intersection(intersection_1.begin(), intersection_2.end(), third.begin(), third.end(), back_inserter(intersection_2));
					int i = intersection_2[0] - 96;
					if (i<0){
						i+=58;
					}
					prioritySum += i;
				break;
			}
		}
		file.close(); 
	}
	cout << prioritySum;
	return 0;
}
