#include <iostream>
#include <iomanip>

using namespace std;

int main(int argc, char const *argv[])
{
    float total = 0;
    float now = 0;
    for (int i = 0; i < 12; ++i) {
        cin>>now;
        total += now;
    }
    cout<<"$" <<setprecision(2) <<fixed <<total / 12<<endl;
    return 0;
}
