#include <iostream>
#include <algorithm>

using namespace std;

int Result(int n) {
    if (n > 2)
    {if (n % 2 == 0)  { return (n * Result(n - 1) - 1); }else { return (n * Result(n - 1) + 1); }}
    else
    { return 1; }
}

bool ProvPer(int* allBallz, int size) {
    for (int i = 1; i <= size; i++) {
        if (allBallz[i - 1] == i){return true;}
    }
    return false;
}

int main() {
    setlocale(LC_ALL, "Rus");
    int n, result = 0, allPer = 1;

    cout << "Введите кол-во шариков" << endl;
    cin >> n;

    for (int i = 2; i < n + 1; i++){ allPer *= i;}

    int* allBallz = new int[n];
    for (int i = 0; i < n; i++) {allBallz[i] = i+1;}

    for (int i = 0; i < allPer; i++) {
        next_permutation(allBallz, allBallz + n);
        if (ProvPer(allBallz, n)) { result++;}
    }

    cout << endl << result << endl << Result(n) << endl;
}