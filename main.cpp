#include <iostream>
#include "./Homework1/templates.h"
#include <functional>

struct my_struct{
    int i;
    double d;
    std::string s;

};
//why it is working only in class
class Func{
public:
//    template <typename T>
    static void my_mapper(int* arr, int* end, std::function<int(const int&)> f){

         std::transform(arr, end, arr, f );
         std::for_each(arr, end, [](int a) {std::cout<< a << " ";});

    }
    static int my_reduce(int* b, int* e, std::function<int(int& accum, const int& v)> f){
        if (b == e) {
            return *b;
        }
        int accum = *b;
        for (int* p = b + 1; p != e; ++p) {
            accum = f(accum, *p);
        }
        return accum;

}
};

int main() {
int a = 5;
int b = 4;
std::cout << max<int>(a, b) << " " << min<int>(a, b) << " " ;
swap<int>(a,b);
std::cout<<a<< std::endl;
int c[5]{2, 2, 6, 4, 7};
std::cout<<even(c, 5)<<std::endl;
std::cout<<odd(c, 5)<< std::endl;
std::cout << count_odd_even(c, sizeof (c)/ sizeof(c[0])) << std::endl;
std::cout << find(c, 5, 7) << std::endl;
//Func::my_mapper(c, std::end(c), [](auto c) {return c*c;});
auto v = Func::my_reduce(c, c + 5, [](auto acc, auto a) {return acc + a;});
std::cout << v << std::endl;

int idx[] = {0, 1, 2};
my_struct test_array []= {{1, 2, "b"}, {2, 4, "a"}, {1, 3, "c"}};
//std::sort(test_array, test_array + sizeof (test_array) / sizeof(test_array[0]), [](my_struct& i1, my_struct& i2) -> bool
//{return i1.d > i2.d;});

std::sort(idx, idx + sizeof (idx) / sizeof(idx[0]), [&test_array](auto i1, auto i2) -> bool
    {return test_array[i1].d > test_array[i2].d ;});
std::for_each(idx, std::end(idx),
              [&test_array](auto i)
              {std::cout << test_array[i].i << " "<< test_array[i].d << " "<< test_array[i].s << " ";});
return 0;
}
