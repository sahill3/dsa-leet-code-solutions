#include <bits/stdc++.h>
using namespace std;

vector<string> v;
vector<string> :: iterator it; 

int main() {
	int num;
	cin >> num;    
	string s;
	int k;
	for(int i = 0; i < num; i++){
		cin >> s;
		k = 0;
		for(it = v.begin(); it != v.end(); it++)
			k += (s > *it);
		cout << k << endl;
		v.push_back(s);
	}

	return 0;
}