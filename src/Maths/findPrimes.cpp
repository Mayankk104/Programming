

#include <bits/stdc++.h>
using namespace std;

vector<int> findPrime(int N) {
    vector<int> result;
    vector<int> numbers(N, 0);

    for (int i = 2; i * i <= N; i++)
        for (int j = i * i; j <= N; j += i)
            numbers[j - 1] = 1;

    for (int i = 1; i < N; i++)
        if (numbers[i] == 0) result.push_back(i + 1);

    return result;
}

int main() {
    vector<int> result = findPrime(100);

    for (auto prime : result) cout << prime << " ";
}