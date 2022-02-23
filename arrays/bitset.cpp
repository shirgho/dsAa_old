#include<iostream>
#include<bitset>

using namespace std;

int main(int args, char **argc)
{
    bitset<16> bitArray;

    cout << "STL Bit Set Example" << endl;
    cout << "Data Structures for Game Developers" << endl;
    cout << "Allen Sherrod" << endl << endl;

    cout << "Number of bits: " << bitArray.size() << endl;
    cout << "Bits not set (T or F): " << bitArray.none() << endl;
    cout << endl;

    cout << "Initial bit values for 2, 3 and 14." << endl << endl;
    cout << "Bit  2 = " << bitArray[ 2] << "." << endl;
    cout << "Bit  3 = " << bitArray[ 3] << "." << endl;
    cout << "Bit 14 = " << bitArray.test(14) << "." << endl << endl;

    cout << "Set bits 2 and 14." << endl << endl;
    bitArray[ 2] = true;
    bitArray[14] = true;
    cout << "Bit  2 = " << bitArray[ 2] << "." << endl;
    cout << "Bit  3 = " << bitArray[ 3] << "." << endl;
    cout << "Bit 14 = " << bitArray.test(14) << "." << endl << endl;

    cout << "Set all bits" << endl << endl;
    bitArray.set();
    cout << "Bit  2 = " << bitArray[ 2] << "." << endl;
    cout << "Bit  3 = " << bitArray[ 3] << "." << endl;
    cout << "Bit 14 = " << bitArray.test(14) << "." << endl << endl;

    cout << "Clear all bits" << endl << endl;
    bitArray.reset();
    cout << "Bit  2 = " << bitArray[ 2] << "." << endl;
    cout << "Bit  3 = " << bitArray[ 3] << "." << endl;

    cout << "Bit 14 = " << bitArray.test(14) << "." << endl << endl;
    return 1;
}