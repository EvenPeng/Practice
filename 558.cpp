#include <cstdio>
#include <cstring>
#include <climits>

using namespace std;

int V, E, min[1001];

struct e {
	int u, v, w;
} list[2001];

int main (void) {
	bool flag;
	int times, i, j;

	scanf("%d", &times);

	while (times--) {
		scanf("%d %d", &V, &E);

		for (i = 0; i < V; ++i) min[i] = 1001;
		for (i = 0; i < E; ++i) scanf("%d %d %d", &list[i].u, &list[i].v ,&list[i].w);

		flag = false;
		min[0] = 0;
		for (i = 0; i < V - 1; ++i) 
		for (j = 0; j < E; ++j)
			if (min[list[j].v] > min[list[j].u] + list[j].w)
				min[list[j].v] = min[list[j].u] + list[j].w;

		for (j = 0; j < E; ++j) {
			if (min[list[j].v] > min[list[j].u] + list[j].w)
				flag = true;
		}

		if (!flag) printf("not possible\n");
		else printf("possible\n");
	}

	return 0;
}
