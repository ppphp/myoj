#include <iostream>
#include <algorithm>

using namespace std;
struct dna{
    char series[100];
    int unsorted;
};

void qs(dna* d, int begin, int end){
    if(begin >= end) return;
    int p,q;
    p = begin + 1;
    q = end;
    dna b;
    while((p <= end)&&(q >= begin + 1)&&(p < q)){
        while((p<q)&&(d[p].unsorted < d[begin].unsorted)) p++;
        while(d[q].unsorted > d[begin].unsorted) q--;
        if(d[q].unsorted < d[p].unsorted && p < q){
            b = d[q];
            d[q] = d[p];
            d[p] = b;
        }
    }
    if(d[p].unsorted < d[begin].unsorted){
        b = d[p];
        d[p] = d[begin];
        d[begin] = b;
    }
    qs(d,begin, p - 1);
    qs(d, p, end);
}
int cmp(const void* a,const void* b)
{
    dna* x=(dna*)a;
    dna* y=(dna*)b;
    return (x->unsorted)-(y->unsorted);
}
int main(int argc, char const *argv[])
{
    int m, n;
    cin>>m>>n;
    dna* dnas = new dna[n];
    int unsorted;
    int a,c,g;
    for (int i = 0; i < n; ++i) {
        cin>>dnas[i].series;
        unsorted = 0;
        a=c=g=0;
        for (int k = m-1; k >= 0; --k) {
            switch(dnas[i].series[k]){
                case 'A':
                    a++;
                    break;
                case 'T':
                    unsorted += (a + c + g);
                    break;
                case 'C':
                    c++;
                    unsorted += a;
                    break;
                case 'G':
                    g++;
                    unsorted += (a + c);
                    break;
            }
        }
        dnas[i].unsorted = unsorted;
    }
    qsort(dnas,n,sizeof(dna),cmp);
//    qs(dnas, 0, n - 1);
    for (int i = 0; i < n; ++i) {
        cout<<dnas[i].series<<endl;
    }
    return 0;
}