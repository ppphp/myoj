#include <iostream>

using namespace std;

struct dna{
    string series;
    int unsorted;
};

void qs(dna* d, int begin, int end){
    if(begin == end) return;
    int p,q;
    p = begin + 1;
    q = end;
    dna b;
    while((p <= end)&&(q >= begin + 1)&&(p < q)){
        while((p<=end)&&(d[p].unsorted < d[begin].unsorted)) p++;
        while(d[q].unsorted > d[begin].unsorted) q--;
        if(d[q].unsorted < d[begin].unsorted){
            b = d[q];
            d[q] = d[begin];
            d[begin] = b;
        }
    }
}

int main(int argc, char const *argv[])
{
    int m, n;
    cin>>m>>n;
    dna* dnas = new dna[n];
    int unsorted;
    char buffer[m];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin>>buffer[j];
        }
        unsorted = 0;
        for (int k = 0; k < m; ++k) {
            for (int j = k + 1; j < m; ++j) {
                if(buffer[j] < buffer[k]) unsorted++;
            }
        }
        dnas[i].series = buffer;
        dnas[i].unsorted = unsorted;
    }
    for (int i = 0; i < n; ++i) {
        cout<<dnas[i].series<<" "<<dnas[i].unsorted<<endl;
    }
    // qsort
    qs(dnas, 0, n - 1);
    cout<<dnas<<endl;
    for (int i = 0; i < n; ++i) {
        cout<<dnas[i].series<<" "<<dnas[i].unsorted<<endl;
    }
    return 0;
}
