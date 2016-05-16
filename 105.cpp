#include <iostream>
#include <cstdlib>

using namespace std;

int main(int argc, char const *argv[]){
	int arr[20001], left, height, right, i, head, tail;

	for(i = 0; i < 20001; i++) arr[i] = 0;

	while(cin >> left >> height >> right){
		left *= 2;
		right *= 2;
		for(i = left; i <= right; i++)
			arr[i] = height > arr[i] ? height : arr[i];
	}

	head = 0;
	while(arr[head] < 1) head += 2;
	tail = 20000;
	while(arr[tail] < 1) tail -= 2;

	height = arr[head];
	cout << head / 2 << " " << height << " ";

	for(i = head + 1; i < tail; i++){
		if(arr[i] != height){
			height = arr[i];
			cout << i / 2 << " " << height << " ";
		}
	}
	cout << tail / 2 << " 0" << endl;

	return 0;
}
