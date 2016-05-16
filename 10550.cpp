#include <iostream>

using namespace std;

int main(int argc, char const *argv[]){
	int arr[4], sum, tmp;

	sum = 0;
	for (int i = 0; i < 4; ++i){
		cin >> arr[i];
		sum += arr[i];
	}

	while(sum > 0){
		sum = arr[0] - arr[1];
		if(arr[0] < arr[1]) sum += 40;
		sum += arr[2] - arr[1];
		if(arr[2] < arr[1]) sum += 40;
		sum += arr[2] - arr[3];
		if(arr[2] < arr[3]) sum += 40;

		cout << sum*9 + 1080 << endl;

		sum = 0;
		for (int i = 0; i < 4; ++i){
			cin >> arr[i];
			sum += arr[i];
		}
	}



	return 0;
}