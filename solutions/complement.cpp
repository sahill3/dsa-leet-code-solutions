#include <iostream>
#include <string>

using namespace std;

class binary
{
    string s;

public:
    void ones(void);
};

void binary ::ones(void)
{
    cout << "Enter a binary number: ";
    cin >> s;

    for (int i = 0; i < s.length(); i++)
    {
        if (s.at(i) != '0' && s.at(i) != '1')
        {
            cout << "Incorrect binary format" << endl;
            exit(0);
        }
    }

    for (int x = 0; x < s.length(); x++)
    {
        if (s.at(x) == '1')
        {
            s.at(x) = '0';
        }
        else if (s.at(x) == '0')
        {
            s.at(x) = '1';
        }
    }
    cout<<"Ones complement is: "<<s;
}
int main()
{
    binary b;
    b.ones();
    return 0;
}