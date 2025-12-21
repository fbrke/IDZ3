#include <iostream>

using namespace std;

bool raspoloshenie(int a1, int b1, int X1, int Y1, int X2, int Y2) {
	if (X1 + X2 + 1 <= a1 && max(Y1, Y2) <= b1)
		return true;
	if (Y1 + Y2 + 1 <= b1 && max(X1, X2) <= a1) 
		return true;
	return false;
}

int main() {
	int a, b, x1, y1, x2, y2, a1, b1;
	cout << "Vvedite razmer uchastka i dvuh domov:";
	cin >> a >> b >> x1 >> y1 >> x2 >> y2;

	a1 = a - 2;
	b1 = b - 2;

	if (a1 <= 0 || b1 <= 0) {
		cout << "NO";
		return 0;
	}
	int dom1[2][2] = { { x1,y1 }, { y1 , x1 } };
	int dom2[2][2] = { {x2,y2}, {y2,x2} };

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			if (raspoloshenie(a1, b1, dom1[i][0], dom1[i][1], dom2[j][0], dom2[j][1])) {
				cout << "Yes";
				return 0;
			}
		}
	}
	cout << "No";
	return 0;
}