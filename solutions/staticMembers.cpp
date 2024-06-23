#include <iostream>
using namespace std;

class Employee
{
private:
    static int count;
    int id;

public:
    void setData(void)
    {
        cout << "Enter the id: " << endl;
        cin >> id;
    }

    void getData(void)
    {
        cout << "Employee " << count + 1 << " ID: " << id << endl;
        count++;
    }

    static void getCount(){
        cout<<"The value of count: "<<count<<endl;
    }
};

int Employee ::count;

int main()
{

    Employee sam, george, fin;
    sam.setData();
    george.setData();
    fin.setData();

    sam.getData();
    Employee :: getCount();
    george.getData();
    Employee :: getCount();
    fin.getData();
    Employee :: getCount();
    return 0;
}