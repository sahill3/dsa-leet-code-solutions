#include <iostream>
using namespace std;

class Shop
{
private:
    int itemId[100];
    int itemPrice[100];
    int counter;

public:
    void initCounter(void)
    {
        counter = 0;
    }

    void setPrice(void);
    void displayPrice(void);
};

void Shop :: setPrice(void){
    cout<<"Enter the item ID for item "<<counter + 1<<": ";
    cin>>itemId[counter]; 
    cout<<"Enter the item Price: ";
    cin>>itemPrice[counter];
    counter++;
}

void Shop :: displayPrice(void){
    for(int i = 0; i < counter; i++){
        cout<<"The price of item "<<itemId[i]<<" is "<<itemPrice[i]<<endl;
    }
}

int main()
{   
    Shop medical;
    medical.initCounter();
    medical.setPrice();
    medical.setPrice();
    medical.setPrice();
    medical.displayPrice();
    return 0;
}