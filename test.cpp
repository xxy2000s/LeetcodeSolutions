#include <iostream>

using namespace std;

bool judge0(int a[][9], int b[][9], int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (a[i][j] != b[i][j]) {
				return false;
			}
		}
	}
	return true;
}

bool judge90(int a[][9], int b[][9], int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (a[i][j] != b[j][n - i - 1]) {
				return false;
			}
		}
	}
	return true;
}

bool judge180(int a[][9], int b[][9], int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (a[i][j] != b[n - i - 1][n - j - 1]) {
				return false;
			}
		}
	}
	return true;
}

bool judge270(int a[][9], int b[][9], int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (a[i][j] != b[n - j - 1][i]) {
				return false;
			}
		}
	}
	return true;
}


int main() {
	int n;
	int a[9][9], b[9][9];
	while (cin >> n) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> a[i][j];
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> b[i][j];
			}
		}
		if (judge0(a, b, n)) {
			cout << 0 << endl;
			break;
		}
		else if (judge90(a, b, n)) {
			cout << 90 << endl;
			break;
		}
		else if (judge180(a, b, n)) {
			cout << 180 << endl;
			break;
		}
		else if (judge270(a, b, n)) {
			cout << 270 << endl;
			break;
		}
		else {
			cout << -1 << endl;
		}
	}
	return 0;
}