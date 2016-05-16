#include <iostream>
#include <string.h>

using namespace std;

int main(int argc, char const *argv[]){
	int num, index, j;
	string names[100];
	bool flag = true;

	cin >> num;

	for (int i = 0; i < num; ++i){
		cin >> names[i];
	}

	index = 0;

	while(flag){
		for (int i = 0; i < 4; ++i){
			for (j = 0; j < 4; ++j){
				switch(j){
					case 0:	
						cout << names[index++] << ": Happy" << endl;
						break;
					case 1: 
						cout << names[index++] << ": birthday" << endl;
						break;
					case 2:	
						cout << names[index++] << ": to" << endl;
						break;
					case 3:
						if(i == 2) cout << names[index++] << ": Rujia" << endl;
						else cout << names[index++] << ": you" << endl;
						break;
				}
				if(index >= num){
					index = 0;
					flag = false;
				}
			}
		}
	}

	return 0;
}