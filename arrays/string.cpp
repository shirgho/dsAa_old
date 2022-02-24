#include <iostream>
#include <string>
#include <algorithm>
#include <iterator>

/*
C++ standard strings
delete themselves, allocate, reallocate
can pass to functions expecting c type arrays
sequence container, can perform stl algorithms
and string container specific operations

istream& getLine (istream& is, string& str, char delim = '\n');
*/

using namespace std;

int main(int args, char **argc)
{
    cout << "C++ strings";

    string str("Hello World");
    cout << "String contents: " << str << endl;

    str.clear();
    cout << "String contents: " << str << endl;

    str = "Goodbye World";
    cout << "String contents: " << str << endl;

    str.push_back('!');
    cout << "String contents with iterators: " << str << endl;
    ostream_iterator<char> output(cout, "");
    copy(str.begin(), str.end(), output);
    cout << endl;

    cout << "Reserve Contents:";
    copy(str.rbegin(), str.rend(), output);
    cout << endl;

    cout << "Enter in a string and press enter:";
    getline(cin, str);
    cout << endl;

    cout << "You've entered: " << str << endl << endl;

    str.append("ButAisayKyun?");
    cout << str << endl;

    return 0;
}
