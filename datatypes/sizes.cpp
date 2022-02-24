#include <limits>   
#include <iostream>   

int main()
{
    const char min_char = std::numeric_limits<char>::min(); // -128
    const char max_char = std::numeric_limits<char>::max(); // +127
    const short min_shortInt = std::numeric_limits<short>::min(); // -
    const short max_shortInt = std::numeric_limits<short>::max(); // +
    const unsigned short min_unsignedShort = std::numeric_limits<unsigned short>::min(); // -
    const unsigned short max_unsignedShort = std::numeric_limits<unsigned short>::max(); // +
    const int min_int = std::numeric_limits<int>::min(); // -2147483648
    const int max_int = std::numeric_limits<int>::max(); // +2147483648
    const unsigned int min_unsignedInt = std::numeric_limits<unsigned int>::min(); // -2147483648
    const unsigned int max_unsignedInt = std::numeric_limits<unsigned int>::max(); // +2147483648
    const long int min_longInt = std::numeric_limits<long int>::min(); // -2147483648
    const long int max_longInt = std::numeric_limits<long int>::max(); // +2147483648
    const long long int min_longlongInt = std::numeric_limits<long long int>::min(); // -2147483648
    const long long int max_longlongInt = std::numeric_limits<long long int>::max(); // +2147483648

    const float min_float = std::numeric_limits<float>::min(); // 
    const float max_float = std::numeric_limits<float>::max(); // 
    const double min_double = std::numeric_limits<double>::min(); // 
    const double max_double = std::numeric_limits<double>::max(); // 
    const long double min_longDouble = std::numeric_limits<long double>::min(); // 
    const long double max_longDouble = std::numeric_limits<long double>::max(); // 

    std::cout << "size of min_char is " << (int)min_char << "." << std::endl;
    std::cout << "in bytes " << sizeof(min_char) << "." << std::endl;
    std::cout << "size of max_char is " << (int)max_char << "." << std::endl;
    std::cout << "in bytes " << sizeof(max_char) << "." << std::endl;
    std::cout << "size of min_shortInt is " << min_shortInt << "." << std::endl;
    std::cout << "in bytes " << sizeof(min_shortInt) << "." << std::endl;
    std::cout << "size of max_shortInt is " << max_shortInt << "." << std::endl;
    std::cout << "in bytes " << sizeof(max_shortInt) << "." << std::endl;
    std::cout << "size of min_unsignedShort is " << min_unsignedShort << "." << std::endl;
    std::cout << "in bytes " << sizeof(min_unsignedShort) << "." << std::endl;
    std::cout << "size of max_unsignedShort is " << max_unsignedShort << "." << std::endl;
    std::cout << "in bytes " << sizeof(max_unsignedShort) << "." << std::endl;
    std::cout << "size of int(min) is " << min_int << "." << std::endl;
    std::cout << "in bytes " << sizeof(min_int) << "." << std::endl;
    std::cout << "size of int(max) is " << max_int << "." << std::endl;
    std::cout << "in bytes " << sizeof(max_int) << "." << std::endl;
    std::cout << "size of min_unsignedInt is " << min_unsignedInt << "." << std::endl;
    std::cout << "in bytes " << sizeof(min_unsignedInt) << "." << std::endl;
    std::cout << "size of max_unsignedInt is " << max_unsignedInt << "." << std::endl;
    std::cout << "in bytes " << sizeof(max_unsignedInt) << "." << std::endl;
    std::cout << "size of min_longInt is " << min_longInt << "." << std::endl;
    std::cout << "in bytes " << sizeof(min_longInt) << "." << std::endl;
    std::cout << "size of max_longInt is " << max_longInt << "." << std::endl;
    std::cout << "in bytes " << sizeof(max_longInt) << "." << std::endl;
    std::cout << "size of min_longlongInt is " << min_longlongInt << "." << std::endl;
    std::cout << "in bytes " << sizeof(min_longlongInt) << "." << std::endl;
    std::cout << "size of max_longlongInt is " << max_longlongInt << "." << std::endl;
    std::cout << "in bytes " << sizeof(max_longlongInt) << "." << std::endl;

    std::cout << "size of min_float is " << min_float << "." << std::endl;
    std::cout << "in bytes " << sizeof(min_float) << "." << std::endl;
    std::cout << "size of max_float is " << max_float << "." << std::endl;
    std::cout << "in bytes " << sizeof(max_float) << "." << std::endl;
    std::cout << "size of min_double is " << min_double << "." << std::endl;
    std::cout << "in bytes " << sizeof(min_double) << "." << std::endl;
    std::cout << "size of max_double is " << max_double << "." << std::endl;
    std::cout << "in bytes " << sizeof(max_double) << "." << std::endl;
    std::cout << "size of min_longDouble is " << min_longDouble << "." << std::endl;
    std::cout << "in bytes " << sizeof(min_longDouble) << "." << std::endl;
    std::cout << "size of max_longDouble is " << max_longDouble << "." << std::endl;
    std::cout << "in bytes " << sizeof(max_longDouble) << "." << std::endl;




}
   