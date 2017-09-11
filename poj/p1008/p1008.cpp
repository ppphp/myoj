
#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    int n;
    cin>>n;
    int haab_year, haab_date, j, day;
    char haab_month[6], dot;
    const char haab_enum[19][7] = {"pop", "no", "zip", "zotz", "tzec", "xul", "yoxkin", "mol", "chen", "yax", "zac", "ceh", "mac", "kankin", "muan", "pax", "koyab", "cumhu", "Haab"};
    const char tzolkin_enum[20][9] = {"imix", "ik", "akbal", "kan", "chicchan", "cimi", "manik", "lamat", "muluk", "ok", "chuen", "eb", "ben", "ix", "mem", "cib", "caban", "eznab", "canac", "ahau"};
    for (int i = 0; i < n; ++i) {
        cin>>haab_year>>dot>>haab_month>>haab_date;
        cout<<haab_year<<haab_month<<endl;
        for (j = 0; j < 19; ++j) {
            if(haab_month == haab_enum[j]) break;
        }
        day = 365 * haab_year + 20 * j + haab_date;
        cout<<day / 260 <<" "<<tzolkin_enum[day % 20]<<" "<<day % 13<<endl;
        cout<<day<<endl;
    }

    return 0;
}
