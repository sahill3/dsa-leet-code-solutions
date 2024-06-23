#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class F1
{
    string name;
    int rank;

public:
    int points;

    void setName(void)
    {
        rank = 0;
        cout << "Enter the name: ";
        cin >> name;
    }

    void setPoints(void)
    {
        cout << "Enter the points: ";
        cin >> points;
    }

    void getInfo(void)
    {
        cout << setw(3) << rank << "  " << setw(15) << name << "  " << setw(9) << points << endl;
    }
};

int largest(int arr[], int n)
{
    int i;
    int max = arr[0];

    for (i = 1; i < n; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
        return max;
    }
}

int main()
{

    int list[10];
    int fin[10];
    int count = 10;
    F1 ob[10];
    for (int i = 0; i < 10; i++)
    {
        ob[i].setName();
        ob[i].setPoints();
    }

    for (int i = 0; i < 10; i++)
    {
        list[i] = ob[i].points;
    }

    while (count != 0)
    {
        int n = sizeof(list) / sizeof(list[0]);
        int x = 0;
        while (sizeof(list) != 0)
        {
            fin[x] = largest(list, n);
            x++;
            count--;   
        }
    }

    int m = 0;
    int s = 0;
    
    while(m < 10){
        cout<<list[m];
        m++;
    }
    while(s < 10){
        cout<<fin[s];
        s++;
    }
    
        // cout << "Rank"
    //      << " " << setw(5) << "     Constructor "
    //      << "      Points" << endl;

    // for (int i = 0; i < 10; i++)
    // {
    //     ob[i].getInfo();
    // }

    return 0;
}