/*-------------------------------------------------------
 * Tarea de Analisis de Algoritmos: 231 - Testing the CATCHER
 * Fecha: 20-04-2016
 * Autor:
 *      A01064215 Rodrigo Reyes Murillo
 */

#include <stdio.h>
#include <vector>
using namespace std;

int n, m, i, j, s, Max;
int Case = 1;

int main(int argc, char const *argv[])
{
	while(scanf("%d", &n) && n != -1) {
        if (Case != 1)
            printf("\n");
	    vector<int> Set;
		Set.push_back(n);

		while(scanf("%d", &m) && m != -1) {
			Set.push_back(m);
		}

		s = Set.size();
		int q[s];
		q[0] = 1;

		for (i = 1; i < s; i++) {
			Max = 0;
			for (j = 0; j < i; j++) {
				if (Set[j] >= Set[i])
					if (q[j] > Max)
						Max = q[j];
			}
			q[i] = Max + 1;
		}

		Max = 0;
		for (i = 0; i < s; i++) {
			if (q[i] > Max)
				Max = q[i];
		}
		printf("Test #%d:\n", Case++);
        printf("  maximum possible interceptions: %d\n", Max);
	}
    return 0;
}
