#include <iostream>
#include <string.h>

using namespace std;

int main(int argc, char const *argv[]){
	int number, count, total, deliver, money[10], give_index, whom_index;
	string people[10], name;
	bool flag;

	flag = false;

	while(cin >> number){
		if(flag) cout << endl;
		else flag = true;

		for (int i = 0; i < number; ++i){
			cin >> people[i];
			money[i] = 0;
		}
			
		for (int i = 0; i < number; ++i){
			cin >> name >> total >> deliver;

			for (int j = 0; j < number; ++j){
				if(name.compare(people[j]) == 0){
					give_index = j;
					break;
				}
			}

			if(deliver > 0)
				money[give_index] += total % deliver - total;

			for (int k = 0; k < deliver; ++k){
				cin >> name;
				for (int j = 0; j < number; ++j){
					if(name.compare(people[j]) == 0){
						whom_index = j;
						break;
					}
				}

				money[whom_index] += total / deliver;
			}
		}

		for (int i = 0; i < number; ++i){
			cout << people[i] << " " << money[i] << endl;
		}
	}
	
	return 0;
}