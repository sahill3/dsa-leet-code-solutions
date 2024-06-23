#include<iostream>
using namespace std;

class character{
    private:
    int health;
    
    public:

    character(int health){
        this->health = health;
    }

    void getHealth(){
        cout << health;
    }
};

int main(){

    character geto(100); 
    geto.getHealth(); 
    return 0;
}