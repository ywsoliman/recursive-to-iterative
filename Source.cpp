#include <iostream>

using namespace std;

int F(int n)
{
    if (n <= 1) return 1;
    int a = n + F(n - 1);
    int b = n * F(n / 2);
    int c = n - 2 - (a + b) % 2;
    int d = F(c);
    return a + b + d;
}

int main()
{
	for (int i = 1; i <= 20; i++)
		cout << F(i) << endl;
}