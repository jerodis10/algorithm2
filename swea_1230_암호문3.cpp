#include<iostream>
#include<list>
using namespace std;

int testCase;
list<int> v;

int main() 
{
	int n, orderN;
	for (int t = 1; t <= 10; t++) 
	{
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			int ori_sec;
			cin >> ori_sec;
			v.push_back(ori_sec);
		}
		cin >> orderN;
		for (int i = 0; i < orderN; i++)
		{
			char a;
			cin >> a;
			int x, y;
			cin >> x >> y;
			list<int> plus;
			if (a == 'I')
			{
				for (int j = 0; j < y; j++)
				{
					int z;
					cin >> z;
					plus.push_back(z);
				}
				list<int>::iterator iter;
				iter = v.begin();
				while (x > 0)
				{
					iter++;
					x--;
				}
				v.splice(iter, plus);
			}

			else if (a == 'D')
			{
				list<int>::iterator iter;
				iter = v.begin();
				while (x > 0)
				{
					iter++;
					x--;
				}
				for (int i = 0; i < y; i++)
				{
					v.erase(iter++);
				}
			}

			else if (a == 'A')
			{
				int y, s;
				cin >> y;
				for (int i = 0; i < y; i++)
				{
					cin >> s;
					v.push_back(s);
				}

			}
			
		}
		cout << "#" << t << " " << endl;
		for (int i = 0; i < 10; i++)
		{
			cout << v.front() << " ";
			v.pop_front();
		}
		cout << endl;
		v.clear();
	}

	return 0;
}
