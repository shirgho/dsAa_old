#include<iostream>
#include<map>
#include<string>
#include<algorithm>

using namespace std;

int main(int args, char **argc)
{
    cout << "STL Map" << endl;

    // Helper lambda function to print key:value pairs
    auto print_key_value = [](std::string const& key, std::string const& value) {
        std::cout << "Key:[" << key << "] Value:[" << value << "]\n";
    };

    map<int, string> mapPair;

    mapPair.insert(map<int, string>::value_type(300, "Test 1"));
    mapPair.insert(map<int, string>::value_type(150, "Test 2"));
    mapPair.insert(map<int, string>::value_type(400, "Test 3"));
    mapPair.insert(map<int, string>::value_type(600, "Test 4"));

    mapPair[100] = "One hundred";

    cout << "Displaying 400:" << mapPair[400] << endl << endl;

    cout << "Dispaying all items: " << endl;

    for(map<int, string>::iterator it = mapPair.begin(); it != mapPair.end(); it++){
        cout << "Key: " << (*it).first << "Value: " << (*it).second << "." << endl;
    }

    cout << endl;

    map<int, string>::iterator itPos = mapPair.find(150);

    if(itPos != mapPair.end())
        cout << "Found Key 150!" << endl;

    cout << endl;

    return 0;
}