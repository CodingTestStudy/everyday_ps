#include <iostream>

using namespace std;

int main() {
    int a, b; cin >> a >> b;
    int temp = b;
    int tempa = a;
    int sum = 1;
    while (temp--) {
        sum *= tempa--;
    }
    for (int i = 1; i < b; i++) {
        sum /=i;
    }
    cout << sum;
}