#include <iostream>

using namespace std;

int main (void) {
	int arr[10001];
	bool label[10001];
	int i, len, lenR, lenL, min, max, median;

	if (cin >> arr[0]) cout << arr[0] << endl;

	if (cin >> arr[1]) {
		len = 2;
		lenL = 1;
		lenR = 1;
		if (arr[0] < arr[1]) {
			label[0] = false;
			label[1] = true;
			max = 0;
			min = 1;
		} else {
			label[0] = true;
			label[1] = false;
			max = 1;
			min = 0;	
		}

		median = (arr[0] + arr[1]) / 2;
		cout << median << endl;
	}

	while (cin >> arr[len++]) {
		if (arr[len - 1] <= median) {
			label[len - 1] = false;
			lenL ++;
			if (arr[len -1] > arr[max])
				max = len - 1;
		} else {
			label[len - 1] = true;
			lenR ++;
			if (arr[len - 1] < arr[min])
				min = len -1;
		}

		if (lenL == lenR + 2) {
			label[max] = true;
			lenR ++;
			lenL --;
			max = 0;
			while (label[max]) max ++;
			for (i = 0; i < len; ++i)
				if (!label[i] && arr[i] > arr[max])
					max = i;
				else if (label[i] && arr[i] < arr[min])
					min = i;
		} else if (lenR > lenL) {
			label[min] = false;
			lenR --;
			lenL ++;
			min = 0;
			while (!label[min]) min ++;
			for (i = 0; i < len; ++i)
				if (label[i] && arr[i] < arr[min])
					min = i;
				else if (!label[i] && arr[i] > arr[max])
					max = i;
		}

		median = lenL > lenR? arr[max]: (arr[max] + arr[min]) / 2;
		cout << median << endl;
	}

	return 0;
}
