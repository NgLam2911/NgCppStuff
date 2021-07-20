// This code idea is use recursion => is not the best way to solve this.
// INPUT: 5
// OUTPUT:


#include <iostream>

using namespace std;

int n;
int numbers[10000];

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
}

void extract(int pos)
{
	for (int i = 1; i <= n; i++)
	{
		if (i >= numbers[pos - 1])
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
}

int main()
{
	cout << "Type a number :";
	cin >> n;

	extract(0);
	return 0;
}

