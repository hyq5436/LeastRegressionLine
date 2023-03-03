// C++ program to find the
// regression line
#include<iostream>
#include<numeric>
using namespace std;

// Function to find the least regression line
// Y = a + b*X
// A regression line is given as Y = a + b*X where the formula of b and a are given as: 
// b = (nΣ(xiyi) – Σ(xi)Σ(yi)) / (nΣ(xi2) - Σ(xi)^2)
// a = ȳ – b*x̄
// where x̄ and ȳ are mean of x and y respectively.

struct Result{
	float slope;
	float offset;
};

Result least_regression_line(int x[], int y[], int n)
{
	int sx = accumulate(x, x + n, 0);	// sum of array x
	int sy = accumulate(y, y + n, 0);	// sum of array y
	int sxsy = 0;	// for sum of product of x and y
	int sx2 = 0;	// sum of square of x
	for (int i = 0; i < n; i++)
	{
		sxsy += x[i] * y[i];
		sx2 += x[i] * x[i];
	}

	float b = (float)(n * sxsy - sx * sy) /	(n * sx2 - sx * sx);
	float a = (sy - b * sx) / (float)n;

	return {a, b};
}

// Driver code
int main()
{
	// Statistical data
	int X[] = { 95, 85, 80, 70, 60 };
	int Y[] = { 90, 80, 70, 65, 60 };
	int n = sizeof(X) / sizeof(X[0]);
	least_regression_line(X, Y, n);

	int x2[] = { 100, 95, 85, 80, 70, 60 };
	int y2[] = { 90, 95, 80, 70, 65, 60 };
	least_regression_line(x2, y2, 6);

	int x3[] = { 100, 95, 85, 80, 70, 60 };
	int y3[] = { 90, 95, 80, 70, 65, 60 };
	least_regression_line(x3, y3, 6);

}

// This code is contributed by PrinciRaj1992
