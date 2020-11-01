#include <iostream>
using namespace std;

int main()
{
	double a, b, k, n,m,l,j;
	cin >> a >> b;
	m = (2 * a - b) / 3;
	n = (2 * b - a) / 3;
	if ((m - int(m) == 0) && (n - int(n) == 0))
		cout << int(m) << " " << int(n);
	else
		cout << "-1";

	
}

