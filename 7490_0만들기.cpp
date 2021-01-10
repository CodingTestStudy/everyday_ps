#include<iostream>
#include<string>
using namespace std;
int Num;
void solve(int sum, int sign, int num, int n, string str)
{
    if (n == Num)
    {
        sum += (num * sign);
        if (sum == 0)
        {
            cout << str << '\n';
        }
    }
    else
    {
        solve(sum, sign, num * 10 + (n + 1), n + 1, str + ' ' + char(n + 1 + '0'));
        solve(sum + (sign * num), 1, n + 1, n + 1, str + '+' + char(n + 1 + '0'));
        solve(sum + (sign * num), -1, n + 1, n + 1, str + '-' + char(n + 1 + '0'));
    }
}
int main()
{
    int test;
    cin >> test;
    while(test--){
       cin >> Num;
        solve(0, 1, 1, 1, "1");
        cout << "\n";
    }
}
