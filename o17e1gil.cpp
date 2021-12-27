#include <vector>
#include <iostream>

using namespace std;

int main () {
	ios_base::sync_with_stdio(false);
	int n, m, a, b;
	cin >> n;
	cin >> m;
	vector<int> guilds(n + 1, 0);
	
	for(int i = 0; i < m; i++) {
		cin >> a;
		cin >> b;
		if(guilds[a] != 0 && guilds[b] == 0) {
			guilds[b] = 3 - guilds[a];
		}
		if(guilds[a] == 0 && guilds[b] != 0) {
			guilds[a] = 3 - guilds[b];
		}
		if(guilds[a] == 0 && guilds[b] == 0) {
			guilds[a] = 1;
			guilds[b] = 2;
		}
	}
	
	for(int i = 1; i < n + 1; i++) {
		if(guilds[i] == 0) {
			cout<<"NIE"<<"\n";
			return 0;
		}
	}
	
	cout<<"TAK"<<"\n";
	for(int i = 1; i<n +1 ; i++) {
		if(guilds[i] == 1) {
			cout << "K" << "\n";
		}
		else {
			cout << "S" << "\n";
		}
	}
	return 0;
}