#include <iostream>
#include <set>

using namespace std;

int judge(char a);

int main(){
    int total;
    cin>>total;

    char buf;
    int number[7];
    int j;
    int number_int, multi;

    set<int> number_set;
    multiset<int> number_multiset;

    for (int i = 0; i < total; ++i) {
        j = 0;
        number_int = 0;
        while(j < 7){
            cin>>buf;
            if(buf == '-') continue;
            number[j] = judge(buf);
            j++;
        }
        for (int k = 0; k < 7; ++k) {
//            cout<<number[k];
            multi = 1;
            for (int l = 0; l < 6 - k; ++l) {
                multi *= 10;
            }
            number_int += number[k] * multi;
        }//cout<<endl;
        number_set.insert(number_int);
        number_multiset.insert(number_int);
//        cout<<number_int<<endl;
    }
//    cout<<endl;

    unsigned long long times;
    for (set<int>::iterator it = number_set.begin(); it!= number_set.end(); ++it) {
        times = number_multiset.count(*it);
        if (times > 1 ) cout<<*it / 1000000<<*it / 100000 % 10<<*it / 10000 % 10<<"-"<<*it / 1000 % 10<<*it / 100 % 10<<*it / 10 % 10<<*it % 10<<" "<<times<<endl;
    }

    return 0;
}

int judge(char a){
    if((a == '0')) return 0;
    else if((a == '1')) return 1;
    else if((a == '2')||(a == 'A')||(a == 'B')||(a == 'C')) return 2;
    else if((a == '3')||(a == 'D')||(a == 'E')||(a == 'F')) return 3;
    else if((a == '4')||(a == 'G')||(a == 'H')||(a == 'I')) return 4;
    else if((a == '5')||(a == 'J')||(a == 'K')||(a == 'L')) return 5;
    else if((a == '6')||(a == 'M')||(a == 'N')||(a == 'O')) return 6;
    else if((a == '7')||(a == 'P')||(a == 'R')||(a == 'S')) return 7;
    else if((a == '8')||(a == 'T')||(a == 'U')||(a == 'V')) return 8;
    else if((a == '9')||(a == 'W')||(a == 'X')||(a == 'Y')) return 9;
}