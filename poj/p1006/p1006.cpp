#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    int p,e,i,d,q;
    int count = 0;
    int init_p, init_e, init_i;
    while(true){
        cin>>p>>e>>i>>d;
        if((p == -1)&&(e == -1)&&(i == -1)&&(d == -1)) break;
        init_p = p % 23;
        init_e = e % 28;
        init_i = i % 33;
        for (q = 1; q <= 21252; ++q) {
            d++;
            if((d % 23 == init_p)&&(d % 28 == init_e)&&(d % 33 == init_i)) break;
        }
        cout<<"Case "<<++count<<": the next triple peak occurs in "<<q<<" days."<<endl;
    }
    return 0;
}
