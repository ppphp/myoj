#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    float length;
    float n = 0;
    float now = 0;
    while(cin>>length&&length != 0){
        n = 2;
        now = 0;
        while(now < length){
            now += 1/n;
            n++;
        }
        printf("%d card(s)\n", int(n - 2));
    }
    return 0;
}
