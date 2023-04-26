#include <algorithm>
#include <iostream>
#include <sstream>
#include "templates.h"
//First task
template <typename T>
T max (T a, T b)
{
    return (a>b)? a: b;
}

template <typename T>
T min(T a, T b){
    return (a<b)? a:b;
}

template <typename T>
void swap (T &a, T &b){
    auto x = a;
    a = b;
    b = x;
}

//Second task
template <typename T>
std::string even(const T arr[], int len){
    if (std::all_of(arr, arr+len, [](int x) {return x % 2 == 0;}))
    {
        return "All are even";
    }
    else{
        return "Not everything even";
    }
}

template <typename T>
std::string odd(const T arr[], int len){
    if (std::all_of(arr, arr+len, [](int x) {return x % 2 != 0;}))
    {
        return "All are odd";
    }
    else{
        return "Not everything odd";
    }
}
template <typename T>
std::string evenAny(const T arr[], int len){
    if (std::any_of(arr, arr+len, [](int x) {return x % 2 == 0;}))
    {
        return "there are even";
    }
    else{
        return "Not even";
    }
}
template <typename T>
std::string oddAny(const T arr[], int len){
    if (std::any_of(arr, arr+len, [](int x) {return x % 2 != 0;}))
    {
        return "there are odd";
    }
    else{
        return "Not odd";
    }
}
template <typename T>
std::string count_odd_even(const T *arr, std::size_t size){
    int even = std::count_if(arr, arr + size , [](int x) {return x % 2 == 0;});
    int odd = std::count_if(arr, arr+size,  [](int x) {return x % 2 != 0;});
    std::stringstream s;
    s << "there is " << even << " even numbers and " << odd << " odd number";
    return s.str();
}
template <typename T>
std::string find(const T *arr, std::size_t size, T value ){
    if (std::find_if(arr, arr+size, [value](T x) {return x == value;} ) != (arr + size))
    {
        return "there is value";
    }
    else{
        return "there is no value";
    }
}

//Third task
//template<typename T>
//void my_map(T* arr, T* end, std::function<T(const T&)> f){
//    std::for_each(arr, end, f);
//}

//TODO Understand what happens when i delete this 3 lines
template int max<int>(int, int);
template int min<int>(int, int);
template void swap<int>(int&, int&);
template std::string odd<int>(const int[], int);
template std::string even<int>(const int[], int);
template std::string count_odd_even<int>(const int*, std::size_t);
template std::string find(const int*, std::size_t, int );
//template void my_map(int*, int*, std::function<int(const int&)>);
