#include<iostream>
#include<vector>
using namespace std;

const long long MAX_CAP = 1000001;
 
// is_prime[] : is_prime[i] is true if the number i is prime
// prime[] : stores all the prime number less than N
// SPF[] : stores the smallest prime factor of a number
// [for Exp : smallest prime factor of '4' and '20'
// is '2' so we put SPF[4] = 2 , SPF[20] = 2 ]
vector<long long >is_prime (MAX_CAP , true);
vector<long long >prime;
vector<long long >smallest_prime_factor (MAX_CAP);
 
// function that generates all prime numbers less than N in O(n) time
void Seive(int N)
{
    // 0 and 1 are not prime
    is_prime[0] = is_prime[1] = false ;
 
    // Fill the other entries
    for (long long int i = 2; i < N ; i++)
    {
        // If is_prime[i] == true, then i is a
        // prime number
        if (is_prime[i] == true)
        {
            // push i into the prime vector
            prime.push_back(i);
 
            // A prime number  itself is its own smallest
            // prime factor
            smallest_prime_factor[i] = i;
        }
 
        // Remove all multiples of i*prime[k] which are
        // not prime by making is_prime[i*prime[j]] = false
        // and set the smallest prime factor of i*prime[j] to prime[j]
        // this loop will run only once for the number which is not prime
        for (long long int k = 0;
             k < (int)prime.size() &&
             i*prime[k] < N && prime[k] <= smallest_prime_factor[i]; k++)
        {
            is_prime[i*prime[k]] = false;
 
            // put the smallest prime factor of i*prime[j]
            smallest_prime_factor[i*prime[k]] = prime[k];
        }
    }
}


int main(){
    
    Seive(10); 
    for (int i: prime) cout << i << " ";
    return 0;
}