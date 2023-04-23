

#include<bits/stdc++.h>

using namespace std;

int a[2][4];
bool dfs() {
	bool all1 = true;
	for(int i = 0; i < 2; i++) {
		for(int j = 0; j < 4; j++) {
			if(!a[i][j]) all1 = false;
		}
	}
	if(all1) return true;
	bool res = false;
	for(int i = 0; i < 2; i++) {
		for(int j = 0; j < 4; j++) {
			if(!a[i][j]) {
				a[i][j] = 1;
				if(!dfs()) res = true;
				if(j < 4 && !a[i][j + 1]) {
					a[i][j + 1] = 1;
					if(!dfs()) res = true;
					a[i][j + 1] = 0;	
				}
				a[i][j] = 0;
			}
		}
	}
	return res;
}

int main() {
	a[0][0] = 1;
	cout << dfs();
	a[0][0] = 0;
	
	a[0][1] = 1;
	cout << dfs();
	a[0][1] = 0;
	
	a[0][0] = a[0][1] = 1;
	cout << dfs();
	a[0][0] = a[0][1] = 0;
	
	a[0][1] = a[0][2] = 1;
	cout << dfs();
	a[0][1] = a[0][2] = 0;
    system("pause");
}