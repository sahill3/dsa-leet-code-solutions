//2353. Design a Food Rating System

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

class FoodRatings {
public:
    vector<string> foods;
    vector<string> cuisines;
    vector<int> ratings;

    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        this->foods = foods;
        this->cuisines = cuisines;
        this->ratings = ratings;
    }
    
    void changeRating(string food, int newRating) {
        int index = getIndex(foods, food);
        this->ratings[index] = newRating;
    }

    string highestRated(string cuisine) {
        int n = sizeof(ratings);
        int max = 0;
        int cnt;

        for (int i = 1; i < n; i++){
            if(ratings[i] > ratings[max] && cuisines[i] == cuisine)
                max = i;
        }
        cnt = count(foods.begin(), foods.end(), ratings[max]);
        
        int m = 0;
        if (cnt > 1){
            for(int i = 0; i < n; i++){
                    if(cuisines[i] == cuisine){
                    string temp = foods[i];
                    if(temp[0] < m){
                        m = i;
                    }
                }
            }
        }

        return foods[m];
        // return "sahil";
    }

    int getIndex(vector<string> v, string K) {

        auto it = find(v.begin(), v.end(), K); 
        if (it != v.end()){ 
            int index = it - v.begin(); 
            return index; 
        } 
        else{ 
            return -1; 
        } 
    } 
};

int main(){
    vector<string> f {"pavbhaji", "Aizza", "burger"};
    vector<string> c {"Indian", "Italian", "USA"};
    vector<int> r {10, 9, 5};

    FoodRatings* obj = new FoodRatings(f, c, r);
    cout << obj->ratings[0];
    obj->changeRating("pavbhaji", 0);
    obj->changeRating("Aizza", 10);
    string dish = obj->highestRated("Italian");                                                                                   
    cout << dish;
    return 0;
}