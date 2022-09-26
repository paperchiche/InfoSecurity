#include <iostream>
#include <string>
#include <iostream>
#include <fstream>
using namespace std;


int main()
{
    const int N = 30000;
    ifstream f_in("input.txt");
    ofstream f_out("output.txt");

    if (!f_in.is_open())
    {
        cout << "Error";
    }
    else
    {
        cout << "File open" << endl;
        int n, m, d, c;
        int b[N], k[N];

        while (!f_in.eof())
        {
            f_in >> n;
            f_in >> m;
            f_in >> d;
            f_in >> c;
            for (int i = 0; i < m + 1; ++i)
            {
                f_in >> b[i];
                if (b[i] > n)
                {
                    f_out << "NO";
                    cout << "Completed";
                    f_in.close();
                    f_out.close();
                    exit(0);
                }
            }
        }
        for (int j = 0; j < m + 1; ++j)
        {
            for (int i = 0; i < n; ++i)
            {
                int l = 1;
                l = (l + i) * d + c;
                if (l < 13)
                {
                    if (l == b[j])
                    {
                        k[j] = i + 1;
                        break;
                    }
                }
                else
                {
                    l = l % 13;
                    if (l == b[j])
                    {
                        k[j] = i + 1;
                        break;
                    }
                }
            }
        }
        f_out << "YES" << endl;
        for (int j = 0; j < m; ++j)
        {
            f_out << k[j] << " ";
        }
    }

    cout << "Completed";
    f_in.close();
    f_out.close();
}