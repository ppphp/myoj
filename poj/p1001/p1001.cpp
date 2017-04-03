//
// Created by dell on 2017/3/6.
//

#include <iostream>
#include <sstream>
#include <vector>

using namespace std;
struct num{
    vector<int> value;//from high to low
    unsigned long long int dot;// from right to dot
};
struct sum{
    int value;
    int carry;
};

void exponential(num number, int times, num &ans);
void reverse_vector(vector<int> result_rev, vector<int> &result);
void multiply(num a, num b, num &ans);
void multiply_digit(vector<int> a, int b, vector<int> &result);
void add_long(vector<int> a, vector<int> &result);
sum add_digit(int a, int b, int carry);
void print_num(num a);

int main(int argc, char const *argv[])
{
    string line, numbers;
    int times;
    stringstream ss;
    num number, ans;
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
//        print_num(number);
        exponential(number,times, ans);
        print_num(ans);
        number.value.clear();
        ans.value.clear();
        ans.dot = 0;
    }
    return 0;
}


//done
void exponential(num number, int times, num &ans){
    ans=number;
    num b;
    for (int i = 0; i < times - 1; ++i) {
        b = ans;
        ans.value.clear();
        multiply(number, b, ans);
    }
}


void multiply(num a, num b, num &ans){
    vector<int> temp;
    for (int i = (int) b.value.size() - 1; i >= 0; --i) {
        multiply_digit(a.value, b.value[i], temp);
        for (int j = 0; j <b.value.size() - 1 - i; ++j) {
            temp.push_back(0);
        }
//        cout<<"ans";
//        for (int k = 0; k < temp.size(); ++k) {
//            cout<<temp[k];
//        }cout<<endl;
        add_long(temp, ans.value);
//        cout<<"now";
//        for (int k = 0; k < ans.value.size(); ++k) {
//            cout<<ans.value[k];
//        }cout<<endl;
    }
//    cout<<"multiply: "<<result.size()<<endl;
//    num result_num;
//    result_num.value = result;
//    result_num.dot = a.dot + b.dot;
    ans.dot = a.dot + b.dot;
//    return result_num;
//    return a;
}


//done
void multiply_digit(vector<int> a, int b, vector<int> &result){
    vector<int> temp;
    int carry = 0;
    for (int i = (int)a.size() - 1; i >= 0; --i) {
        temp.push_back((a[i] * b + carry) % 10);
        carry = (a[i] * b +carry) / 10;
    }
    if(carry != 0) temp.push_back(carry);
    result.clear();
    reverse_vector(temp, result);
//    cout<<"multiply";
//    for (int k = 0; k < a.size(); ++k) {
//        cout<<a[k];
//    }cout<<"times"<<b<<'=';
//    for (int j = 0; j < result.size(); ++j) {
//        cout<<result[j];
//    }cout<<endl;
}


//done
sum add_digit(int a, int b, int carry){
    sum ans;
    ans.carry = (a + b + carry) >= 10 ? 1 : 0;
    ans.value = (a + b + carry) % 10;
    return ans;
}


void add_long(vector<int> a, vector<int> &result){
//    cout<<"add";
//    for (int i = 0; i <result.size(); ++i) {
//        cout<<result[i];
//    }cout<<endl;
    vector<int> result_rev;
    sum digit_sum;
    int a_index, b_index, a_elt, b_elt;
    digit_sum.carry = 0;
    a_index = (int)a.size() - 1;
    b_index = (int)result.size() - 1;
    while(a_index >= 0 || b_index >= 0 || digit_sum.carry != 0){
        if(a_index >= 0) a_elt = a[a_index];
        else a_elt = 0;
        if(b_index >= 0) b_elt = result[b_index];
        else b_elt = 0;
        digit_sum = add_digit(a_elt, b_elt, digit_sum.carry);
        result_rev.push_back(digit_sum.value);
        a_index--;
        b_index--;
    }
    result.clear();
    reverse_vector(result_rev, result);
}


//done
void reverse_vector(vector<int> result_rev, vector<int> &result){
    result.clear();
    for (int i = 0; i < result_rev.size(); ++i) {
        result.push_back(result_rev[result_rev.size() - i - 1]);
    }
}


//done
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
