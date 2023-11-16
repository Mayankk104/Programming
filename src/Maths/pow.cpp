#include <chrono>
#include <iostream>

// TODOs: 1.) Learning intreative method    2.) Time and Space complexity

using namespace std;
using namespace std::chrono;

int pow(long x, int y, int mod) {
    if (y == 1) return x;

    long result = pow(x, y / 2, mod);
    result = (result % mod * result % mod) % mod;
    if (y % 2 == 1) result = (result % mod * x % mod) % mod;
    return result;
}

int pow2(long x, int y, int k) {
    long result = 1;
    while (y > 0) {
        if (y % 2 == 1) {
            result = (result * x) % k;
            y--;
        }
        y >>= 1;
        x = (x * x) % k;
    }
    return result;
}

int main() {
    auto start_time = high_resolution_clock::now();
    cout << pow2(2, 10000, 1000000007) << "\n";
    auto end_time = high_resolution_clock::now();
    auto execution_time = duration_cast<duration<double>>(end_time - start_time).count();
    cout << "Execution time: " << execution_time << " seconds" << endl;

    start_time = high_resolution_clock::now();
    cout << pow(2, 10000, 1000000007) << endl;
    end_time = high_resolution_clock::now();
    execution_time = duration_cast<duration<double>>(end_time - start_time).count();
    cout << "Execution time: " << execution_time << " seconds" << endl;

    return 0;
}