#include <iostream>
#include<iomanip>
using namespace std;

class Anime
{
private:
    int Rank;
    int Hype;

public:
    void setData(int a, int b);
    void getData(){
        cout<<"Rank : "<<setw(2)<<Rank<<endl;
        cout<<"Hype : "<<setw(2)<<Hype<<endl;
    }
};

class OnePiece: public Anime{
    public:
    string name;
    string fillers;
    void setData(char e, char f);
};

void Anime ::setData(int a, int b)
{
    Rank = a;
    Hype = b;
}

int main()
{
    OnePiece obj;
    //obj.setData(1, 99);
    obj.name = "Zoro";
    obj.fillers = "yes";
    cout<<obj.fillers<<endl;
    cout<<obj.name<<endl;
    //obj.getData();
    return 0;
}