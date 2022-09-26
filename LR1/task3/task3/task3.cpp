#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;

int main()
{
    ifstream file_in("input.txt");
    ofstream file_out("output.txt");
    string s;

    while (file_in)
    {
        string s;
        getline(file_in, s);
        string end;
        if (s.size() != 0)
        {
            for (int i = s.size() - 1; i >= 0; i--) // начинаем отсчет с конца 
            {
                end.push_back(s[i]);
            }
        }
        file_out << end << '\n';

    }

    file_out.close();
    file_in.close();

    system("pause");
}
