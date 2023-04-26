//
// Created by Admin on 4/23/2023.
//


template <typename T>
T min(T a, T b);

template <typename T>
T max(T a, T b);

template <typename T>
void swap(T &a, T &b);

template <typename T>
std::string even(const T arr[], int len);
template <typename T>
std::string odd(const T arr[], int len);


template <typename T>
std::string count_odd_even(const T *arr, std::size_t size);
template <typename T>
std::string find(const T *arr, std::size_t size, T value );
//template<typename T>
//void my_map(T* arr, T* end, std::function<T(const T&)> f);
