#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    int number;
    cin>>number;
    float x,y;
    for (int i = 0; i < number; ++i) {
        cin>>x>>y;
        cout<<"Property "<<i+1<<": This property will begin eroding in year "<<(int)((x*x+y*y)*3.1415926/2/50)+1<<"."<<endl;
    }
    cout<<"END OF OUTPUT."<<endl;
    return 0;
}
