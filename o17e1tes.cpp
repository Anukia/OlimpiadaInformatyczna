#include<cstdio>
#include<vector>
using namespace std;

#define MAX_M 1000000 
#define MAX_A 1000000 

int m, n, k, inNumber;
vector<int> countNumbers[MAX_A];

int main()
{
	scanf("%d", &m);
	for(int i = 0; i < m; ++i) {
		scanf("%d", &inNumber);
		countNumbers[inNumber - 1].push_back(i);
	}

	scanf("%d", &n);
	for(int i = 0; i < n; ++i) {
		scanf("%d", &k);
		int index = -1;
		bool ok = true;
		for(int j = 0; j < k; ++j) {
			scanf("%d", &inNumber);
			--inNumber;
			if(!ok || countNumbers[inNumber].empty()) {
				ok = false;
				continue;
			}
			int left = 0, center, right = countNumbers[inNumber].size();
			while(left < right) {
				center = (left + right) / 2;
				if(countNumbers[inNumber][center] <= index)
					left = center + 1;
				else
					right = center;
			}
			if(left == (int)countNumbers[inNumber].size())
				ok = false;
			else
				index = countNumbers[inNumber][left];
		}
		printf("%s\n", (ok ? "TAK" : "NIE"));
	}
}
