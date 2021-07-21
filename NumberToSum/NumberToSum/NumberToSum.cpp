// This code idea is use recursion => is not the best way to solve this.
// INPUT: 5
// OUTPUT:
// 5 = 1 + 1 + 1 + 1 + 1
// 5 = 1 + 1 + 1 + 2
// 5 = 1 + 1 + 3
// 5 = 1 + 2 + 2
// 5 = 1 + 4
// 5 = 2 + 3
// 5 = 5


#include <iostream>

using namespace std;

int n;
int numbers[10000];
int results = 0;

int array_sum(int max_pos)
{
	int sum = 0;
	for (int i = 0; i <= max_pos; i++)
	{
		sum += numbers[i];
	}
	return sum;
}

void print(int max_pos)
{
	cout << n << " = " << numbers[0];
	if (max_pos > 0)
	{
		for (int i = 1; i <= max_pos; i++)
		{
			cout << " + " << numbers[i];
		}
	}	
	cout << endl;
	results++;
}

void extract(int pos)
{
	int a;
	if (pos < 1) a = 1; else a = numbers[pos - 1];

	for (int i = a; i <= n; i++)
	{
		numbers[pos] = i;
		int check = array_sum(pos);
		if (check < n)
		{
			extract(pos + 1);
		}
		else
		{
			if (check == n)
			{
				print(pos);
			}
		}
	}
}

int main()
{
	cout << "Type a number :";
	cin >> n;

	extract(0);

	cout << "Printed " << results << " results";
	return 0;
}

