//
// Created by dell on 2017/3/6.
//

#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;
struct num{
    vector<int> value;//from high to low
    unsigned long long int dot;// from right to dot
};
struct sum{
    int sum;
    int carry;
};

num exponential(num number, int times);
vector<int> reverse_vector(vector<int> a);
num multiply(num a, num b);
vector<int> multiply_digit(vector<int> a, int b);
vector<int> add_long(vector<int> a, vector<int> b);
sum add_digit(int a, int b, int carry);
void print_num(num a);

int main(int argc, char const *argv[])
{
    string line, numbers;
    int times;
    stringstream ss;
    num number;
    int digit;
    while(cin>>numbers>>times){
        for (int i = 0; i < numbers.length(); ++i) {
            if(numbers[i] == '.') number.dot = numbers.length() - i - 1;
            else {
                ss<<numbers[i];
                ss>>digit;
                ss.str("");
                ss.clear();
                number.value.push_back(digit);
            }
        }
        print_num(number);
        print_num(exponential(number,times));
        number.value.clear();
    }
    return 0;
}

num exponential(num number, int times){
    if(times == 0){
        num p;
        p.dot = 0;
        p.value.push_back(1);
        return p;
    }
    return multiply(number, exponential(number, times - 1));//exponential(number, times - 1));
}

sum add_digit(int a, int b, int carry){
    sum ans;
    ans.carry = (a + b + carry) >= 10 ? 1 : 0;
    ans.sum = (a + b + carry) % 10;
    return ans;
}

vector<int> reverse_vector(vector<int> result_rev){
    vector<int> result;
    for (int i = 0; i < result_rev.size(); ++i) {
        result.push_back(result_rev[result_rev.size() - i - 1]);
    }
    return result;
}

vector<int> add_long(vector<int> a, vector<int> b){
    vector<int> result_rev;
    sum digit_sum;
    int a_index, b_index, a_elt, b_elt, carry;
    digit_sum.carry = 0;
    a_index = (int)a.size() - 1;
    b_index = (int)b.size() - 1;
    while(a_index >= 0 && b_index >= 0 && digit_sum.carry == 0){
        if(a_index >= 0) a_elt = a[a_index];
        else a_elt = 0;
        if(b_index >= 0) b_elt = b[b_index];
        else b_elt = 0;
        digit_sum = add_digit(a_elt, b_elt, digit_sum.carry);
        result_rev.push_back(digit_sum.sum);
        a_index--;
        b_index--;
    }
    return reverse_vector(result_rev);
}

vector<int> multiply_digit(vector<int> a, int b){
    vector<int> temp;
    int carry = 0;
    for (int i = (int)a.size() - 1; i >= 0; ++i) {
        temp.push_back((a[i] * b + carry) % 10);
        carry = (int) (a[i] * b +carry) / 10;
    }
    if(carry != 0) temp.push_back(carry);
    return reverse_vector(temp);
}

num multiply(num a, num b){
    vector<int> result, temp;
    for (int i = (int) b.value.size() - 1; i >= 0; ++i) {
        temp = multiply_digit(a.value, b.value[i]);
        for (int j = 0; j <b.value.size() - 1 - i; ++j) {
            temp.push_back(0);
        }
        result = add_long(result, temp);
    }
    num result_num;
    result_num.value = result;
    result_num.dot = a.dot + b.dot;
    return result_num;
}

void print_num(num a){
    while(a.value[a.value.size() - 1] == 0 && a.dot >= 0){
        a.value.pop_back();
        a.dot --;
    }

    int j = 0;
    bool zero = true;
    for (int i = 0; i < a.value.size() + 1; ++i) {
        if(a.value.size() - a.dot == i && j != a.value.size()) {
            cout<<'.';
            zero = false;
            continue;
        } else if(a.value.size() - a.dot == i && j == a.value.size()){
            cout<<endl;
            return;
        } else if (a.value[j] == 0 && zero){
            j++;
            continue;
        }
        cout<<a.value[j];
        zero = false;
        j++;
    }
    cout<<endl;
}
