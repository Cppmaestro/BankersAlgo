// Banker's Algorithm
#include <stdio.h>

const int n = 6; // Total umber of processes
const int m = 5; // Total number of resources  types

int main()
{
	// P0, P1, P2, P3, P4, P5 are the Process names here

	int i, j, k;

	// Current Resource Allocation
	int alloc[n][m] = { { 2, 1, 0, 0, 0 }, // P0
						{ 0, 1, 0, 1, 1 }, // P1
						{ 1, 0, 1, 0, 2 }, // P2
						{ 0, 0, 0, 1, 1 }, // P3
						{ 0, 2, 0, 1, 1 },  // P4
						{ 0, 1, 1, 0, 1 }  // P5
					  };

	// MAX resource request that can be made by each process
	int max[n][m] = { { 7, 5, 3, 0, 0 }, // P0
					  { 3, 2, 2, 0, 0 }, // P1
					  { 9, 0, 2, 0, 0 }, // P2
					  { 2, 2, 2, 0, 0 }, // P3
					  { 2, 2, 2, 0, 0 }, // P4
					  { 4, 3, 3, 0, 0 }  // P5
	                };

	int avail[m] = { 3, 3, 2, 0, 0 };		// current Available Resources

	int f[n], ans[n], ind = 0;
	for (k = 0; k < n; k++) {
		f[k] = 0;
	}

	int need[n][m];
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++)
			need[i][j] = max[i][j] - alloc[i][j];
	}

	int y = 0;
	for (k = 0; k < 5; k++) {
		for (i = 0; i < n; i++) {
			if (f[i] == 0) {

				int flag = 0;
				for (j = 0; j < m; j++) {
					if (need[i][j] > avail[j]) {
						flag = 1;
						break;
					}
				}

				if (flag == 0) {
					ans[ind++] = i;
					for (y = 0; y < m; y++)
						avail[y] += alloc[i][y];
					f[i] = 1;
				}
			}
		}
	}

	printf("Following is the SAFE Sequence\n");
	for (i = 0; i < n - 1; i++)
		printf(" P%d ->", ans[i]);
	printf(" P%d", ans[n - 1]);

	return (0);

	// This code is contributed by Deep Baldha (CandyZack)
}