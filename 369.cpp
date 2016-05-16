#include <iostream>
#include <cstdlib>
#include <cstdio>

using namespace std;

#define BASE 1000000000000LL
#define LEN 20

long long C[LEN];

void Mult(int x){
	for (int i = LEN - 1; i > 0; i--)
		C[i] = (C[i] * x) % BASE + C[i - 1] * x / BASE;
	C[0] = (C[0] * x) % BASE;
}

void Div(int x){
	for (int i = LEN - 1; i > 0; i--){
		C[i - 1] += BASE * (C[i] % x);
		C[i] /= x;
	}
	C[0] /= x;
}

int main(int argc, char const *argv[]){
	int N, M;
	bool flag;
	
	while(cin >> N >> M && N > 0 && M > 0){
		for (int i = 0; i < LEN; ++i) C[i] = 0;
		C[0] = 1;
		cout << N << " things taken " << M << " at a time is ";
		M = N - M < M ? N - M : M;

		for (int i = 0; i < M; ++i) Mult(N - i);
		for (int i = 0; i < M; ++i) Div(i + 1);

		flag = false;
		for (int i = LEN - 1; i >= 0; --i){
			if(flag) printf("%011lld", C[i]);
			else if(!flag && C[i] > 0){
				flag = true;
				cout << C[i];
			}
		}
		cout << " exactly." << endl;
	}

	return 0;
}