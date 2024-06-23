#include<iostream>
#include<iomanip>
using namespace std;

class Anime{
    private:
    int Rank;
    char Hype;
    
    public:
    void setData(int a, char b);
    void getData(){
        cout<<"Rank : "<<setw(2)<<Rank<<endl;
        cout<<"Hype : "<<setw(2)<<Hype<<endl;
    }
};

void Anime :: setData(int a, char b){
     Rank = a;
     Hype = b;
}

int main(){
    Anime obj;
    obj.setData(1, 'm');
    obj.getData();
    return 0;
}