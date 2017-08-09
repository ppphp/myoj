#include <iostream>
#include <map>
#include <cstdlib>

using namespace std;

int judge(char a);
int cmp(const void *a, const void *b);

int main(){
    int total;
    cin>>total;
//    int number_array[total];

    char buf;
    int number[7];
    int j;
    int number_int, multi;

    map<int, int> number_map;

    for (int i = 0; i < total; ++i) {
        j = 0;
        number_int = 0;
        while(j < 7){
            scanf("%c",&buf);
            if(buf == '-' or buf == '\n') continue;
            number[j] = judge(buf);
            j++;
        }
        for (int k = 0; k < 7; ++k) {
            multi = 1;
            for (int l = 0; l < 6 - k; ++l) {
                multi *= 10;
            }
            number_int += number[k] * multi;
        }
        number_map[number_int] += 1;
//        number_array[i] = number_int;
    }
//    qsort(number_array, total, sizeof(int), cmp);
    bool flag = false;
    for (map<int, int>::iterator it = number_map.begin(); it!= number_map.end(); ++it) {
        if (it->second > 1 ){
            printf("%d%d%d-%d%d%d%d %d\n",it->first / 1000000,it->first / 100000 % 10,it->first / 10000 % 10,it->first / 1000 % 10,it->first / 100 % 10,it->first / 10 % 10,it->first % 10,it->second);
            flag = true;
        }
    }
//    int index = 0;
//    int current = 0;
//    int dup = 0;
//    while(index < total){
//        cout<<number_array[index]<<endl;
//    }
    if(!flag) cout<<"No duplicates."<<endl;

    return 0;
}

int judge(char a){
    if(a >= '0' and a<='9') return a - '0';
    else if(a < 'Q') return (a - 'A' + 6) / 3;
    else return (a - 'A' + 5) / 3;
}

int cmp(const void *a, const void *b)
{
    int *x = (int *)a;
    int *y = (int *)b;
    return (*x) - (*y);
}