#include <cstdio>

using namespace std;

int sqre[10], condition[730];

int check(int x)
{
    int sum = 0;
    if (condition[x] == 0) {
        while (x > 0) {
            sum += sqre[x % 10];
            x /= 10;
        }
    }
    return condition[sum];
}

int main(void)
{
    int times, index, n, i, sum, org;

    for (i = 0; i < 10; ++i)
        sqre[i] = i * i;
    for (i = 0; i < 730; ++i)
        condition[i] = 0;
    condition[0]   = -1;
    condition[2]   = -1;
    condition[3]   = -1;
    condition[4]   = -1;
    condition[1]   = 1;
    condition[10]  = 1;
    condition[100] = 1;

    for (i = 5; i < 730; ++i)
        check(i);

    scanf("%d", &times);

    for (index = 1; index <= times; ++index) {
        scanf("%d", &n);
        org = n;
        while (true) {
            sum = 0;
            while (n > 0) {
                sum += sqre[n % 10];
                n /= 10;
            }
            if (condition[sum] == 1) {
                printf("Case #%d: %d is a Happy number.\n", index, org);
                break;
            }
            else if (condition[sum] == -1) {
                printf("Case #%d: %d is an Unhappy number.\n", index, org);
                break;
            }
            else
                n = sum;
        }
    }
}
