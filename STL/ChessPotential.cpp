#include<deque>
#include<vector>
#include<iostream>

using namespace std;

int Winner(int n, vector<int> potential, int k){

    deque<int> Deque;

    for(auto &i: potential)
        Deque.push_back(i);

    int winnerPotential = 0;
    int consecutiveWins = 0;

    while(consecutiveWins < k){

        int player1 = Deque.front();
        Deque.pop_front();
        int player2 = Deque.front();
        Deque.pop_front();

        if (player1 - player2 > 0){
            Deque.push_front(player1);
            Deque.push_back(player2);
            consecutiveWins++;
            winnerPotential = player1;
        }
        else{
            Deque.push_back(player1);
            Deque.push_front(player2);
            consecutiveWins = 1;
            winnerPotential = player2;
        }
    }
    return winnerPotential;
}

int main(){
    

    vector<int> potential = {1};

    cout << Winner(4, potential, 1);

    return 0;
}