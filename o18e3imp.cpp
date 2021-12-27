#include <vector>
#include <iostream>

using namespace std;

int main () {
	ios_base::sync_with_stdio(false);
	int n, m, a, b;
	cin >> n;
	cin >> m;
	int result = n/3;
	vector<int> erased(n, 0);
	vector<vector<int>> matrix;
	
	for (int i = 0; i < n; i++) {
		vector<int> tmp;
		for (int j = 0; j < n; j++) {
			tmp.push_back(0);
		}
		matrix.push_back(tmp);
	}
	
	for(int i = 0; i < m; i++) {
		cin >> a;
		cin >> b;
		matrix[a-1][b-1] = 1;
		matrix[b-1][a-1] = 1;
	}
	
	for (int i = 0; i < n; i++) {
		for(int j = i+1; j < n && erased[i] == 0; j++) {
			if(matrix[i][j] == 0 && erased[j] == 0) {
				erased[i] = 1;
				erased[j] = 1;
				//break;
			}
		}
	}

	for(int i = 0; i<n && result > 0; i++) {
		if(erased[i] == 0) {
			cout << i+1 << " ";
			result--;
		}
	}
	cout<<"\n";			
}