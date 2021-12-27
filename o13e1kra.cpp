#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int main() {
	int n, m, tmp;
	bool result = true;
	std::ios_base::sync_with_stdio(false);
	cin >> n;
	cin >> m;
	vector <int> wejscie;

	cin >> tmp;
	wejscie.push_back(tmp);
	for (int i = 1; i < n; i++) {
		cin >> tmp;
		wejscie.push_back(min(wejscie[i - 1], tmp));
	}

	int d = n-1;
	for (int i = 0; i < m; i++) {
		cin >> tmp;
		while (d > 0 && tmp > wejscie[d])
		{
			d--;
		}
		d--;
	}
	if (d >= 0) {
		d += 2;
	}
	else {
		d = 0;
	}
	cout << d << endl;
}