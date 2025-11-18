// NOTE: it is recommended to use this even if you don't understand the following code.

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    // uncomment the two following lines if you want to read/write from files
    // ifstream cin("input.txt");
    // ofstream cout("output.txt");

    int N, M;
    cin >> N >> M;

    vector<int> A(N);
    for (int i = 0; i < N; ++i)
        cin >> A[i];

    int B = 0;
    vector<int> R(B);


    // INSERT YOUR CODE HERE


    cout << B << endl;
    for (int i = 0; i < B; ++i)
        cout << R[i] << " ";
    cout << endl;

    return 0;
}
