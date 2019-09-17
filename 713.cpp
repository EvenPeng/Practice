#include <cstdio>
#include <cstring>

using namespace std;

int main(void)
{
    bool flag;
    int  times, i, lenA, lenB;
    char A[100001], B[100001];

    scanf("%d\n", &times);

    while (times-- > 0) {
        scanf("%s %s", A, B);

        lenA = strlen(A);
        lenB = strlen(B);

        for (i = 0; i < lenA; ++i)
            A[i] -= '0';
        for (i = 0; i < lenB; ++i)
            B[i] -= '0';

        flag = true;

        if (lenA > lenB) {
            for (i = 0; i < lenA - 1; ++i) {
                if (i < lenB) A[i] += B[i];
                if (A[i] > 9) {
                    A[i + 1]++;
                    A[i] -= 10;
                }
            }
            if (A[i] > 9) {
                lenA++;
                A[i + 2] = A[i + 1];
                A[i + 1] = 1;
                A[i] -= 10;
            }
            for (i = 0; i < lenA; ++i) {
                if (A[i] == 0) {
                    if (!flag) printf("%d", A[i]);
                }
                else {
                    flag = false;
                    printf("%d", A[i]);
                }
            }
        }
        else if (lenA < lenB) {
            for (i = 0; i < lenB - 1; ++i) {
                if (i < lenA) B[i] += A[i];
                if (B[i] > 9) {
                    B[i + 1]++;
                    B[i] -= 10;
                }
            }
            if (B[i] > 9) {
                lenB++;
                B[i + 2] = B[i + 1];
                B[i + 1] = 1;
                B[i] -= 10;
            }
            for (i = 0; i < lenB; ++i) {
                if (B[i] == 0) {
                    if (!flag) printf("%d", B[i]);
                }
                else {
                    flag = false;
                    printf("%d", B[i]);
                }
            }
        }
        else {
            for (i = 0; i < lenA - 1; ++i) {
                A[i] += B[i];
                if (A[i] > 9) {
                    A[i + 1]++;
                    A[i] -= 10;
                }
            }
            A[i] += B[i];
            if (A[i] > 9) {
                lenA++;
                A[i + 2] = A[i + 1];
                A[i + 1] = 1;
                A[i] -= 10;
            }
            for (i = 0; i < lenA; ++i) {
                if (A[i] == 0) {
                    if (!flag) printf("%d", A[i]);
                }
                else {
                    flag = false;
                    printf("%d", A[i]);
                }
            }
        }

        printf("\n");
    }

    return 0;
}
