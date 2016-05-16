#include <iostream>
#include <cstdlib>

using namespace std;

int main(int argc, char const *argv[]){
	char sum[205], tmp[101];
	int index, i;

	for(index = 0; index < 202; index++) sum[index] = 0;

	while(true){
		cin >> tmp;
		if(tmp[0] == '0') break;
		index = 0;
		while(tmp[index] != '\0') tmp[index++] -= '0';
		for(i = 0; i < index; i++){
			sum[i] += tmp[index - i - 1];
			if(sum[i] > 9){
				sum[i] -= 10;
				sum[i + 1] ++;
			}
		}
	}

	for(index = 1; index < 202; index++){
		while(sum[index - 1] > 9){
		 	sum[index - 1] -= 10;
			sum[index] ++;
		}
	}

	i = 201;

	while(sum[i] < 1) i --;

	for(; i >= 0; i--)
		cout << (char)(sum[i] + '0');
	cout << endl;
	
	return 0;
}