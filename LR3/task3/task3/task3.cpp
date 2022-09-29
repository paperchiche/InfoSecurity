#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
using namespace std;


void fStrCut(const string s, string& g)
{
	int flg = 0;
	int lS = s.length();
	int lG = g.length();
	int minLen = (lS > lG) ? lG : lS;
	for (int i = minLen - 1; i > -1; --i)
	{
		string sSub = s.substr(lS - 1 - i, i + 1); // возвращает подстроку данной строки начиная с символа с индексом pos количеством count
		string gSub = g.substr(0, i + 1);  // или до конца строки, если pos + count > S.
		if (sSub == gSub)
		{
			flg = 1;
			g = s + g.erase(0, i + 1);  // удаляет элементы из диапазона, на начало и конец которого указывают итераторы
			break;
		}
	}
	if (flg == 0)
		g = s + g;
}

bool help(string s, int count, int n)
{
	bool flag = true;
	int mas[26];
	while (flag && n + 1 < s.size())
	{
		for (int i = 0; i < 26; ++i)
		{
			mas[i] = 0;
		}
		for (int i = 0 + count; i < n + 1; ++i)
		{
			if (s[i] >= 65)
			{
				mas[s[i] - 65] = mas[s[i] - 65] + 1;
			}
		}
		int sum = 0;
		for (int i = 0; i < 26; ++i)
		{
			if (mas[i] == 0)
			{
				for (int j = i; j < 26; ++j)
				{
					if (mas[j] != 0)
					{
						flag = false;
						break;
					}
				}
			}
			else
			{
				mas[i] -= 1;
				sum += mas[i];
			}
			if (!flag)
			{
				break;
			}
		}
		if (sum == 1 || sum == 0)
		{
			count++;
			n++;
		}
		else
		{
			flag = false;
			break;
		}
	}
	if (flag)
	{
		return true;
	}
	else
		return false;
}

int main()
{
	ifstream f("input.txt");
	ofstream f2("output.txt");
	if (!f.is_open())
	{
		cout << "Error";
	}
	else
	{
		cout << "File open" << endl;
		int n = 0;
		string s1, s2;
		while (!f.eof())
		{
			f >> n;
			f >> s1;
			f >> s2;
		}
		f.close();

		int count = 0;
		int i = 0;

		string all[5];
		string s3 = s1 + s2;
		string s4 = s2 + s1;
		string moi = s2;
		fStrCut(s1, s2);
		fStrCut(s1, moi);

		if (help(s3, count, n))
		{
			all[i] = s3;
			++i;
		}
		if (help(s4, count, n))
		{
			all[i] = s4;
			++i;
		}
		if (help(s2, count, n))
		{
			all[i] = s2;
			++i;
		}
		if (help(moi, count, n))
		{
			all[i] = moi;
			++i;
		}
		string prov = all[0];
		for (i = 0; i < 4; ++i)
		{
			if (all[i].size() < prov.size())
			{
				prov = all[i];
			}
		}
		f2 << prov;
		f2.close();
		cout << "Completed";
	}
}