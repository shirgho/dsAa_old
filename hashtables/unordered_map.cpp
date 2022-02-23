#include <iostream>
#include <cstring>
#include <string>
#include <unordered_map>

using namespace std;

struct cmp
{
    bool operator()(const char *str1, const char *str2) const
    {
        return strcmp(str1, str2) == 0;
    }
};

int main(int arfs, char **argc)
{
    cout << "Hash tables - unordered set" << endl;

    unordered_map<const char*, int, hash<const char*>, cmp> hashTable;

    hashTable["Hello"] = 30;
    hashTable["No Hello"] = 60;
    hashTable["Why Hello"] = 90;
    hashTable["What"] = 300;
    hashTable["Okay"] = 3000;


    cout << "The Hash table has " << hashTable.size() << " items after insertions."
    << endl;

    cout << "Hello - " << hashTable["DVD"] << endl;
    cout << "Hello - " << hashTable["Apple"] << endl;
    cout << "Hello - " << hashTable["No Hello"] << endl;
    cout << "Hello - " << hashTable["Hello"] << endl;
    cout << "Hello - " << hashTable["What"] << endl;

    cout << endl;

    unordered_map<int, string> map = {
        {200, "Not 200"},
        {300, "Not 300"},
        {400, "Not 400"},
    };

     map.insert(unordered_map<int, string>::value_type(600, "Test 6"));

    // Helper lambda function to print key:value pairs
    auto print_key_value = [](int const& key, std::string const& value) {
        std::cout << "Key:[" << key << "] Value:[" << value << "]\n";
    };

    for(auto it = map.begin(); it != map.end(); it++){
        print_key_value(it->first, it->second);
    }

    for(const auto &it : map){
        print_key_value(it.first, it.second);
    }


   
    
    for(const auto it : map){
        print_key_value(it.first, it.second);
    }

    int i = 700;
    // find returns iterator. So can first store in
    // map<int, string>::iterator it = map.find(700);
    if (map.find(700) != map.end()){
        cout << map[i];
    } else {
        map[i] = "Test 7";
        cout << "Added " << map[i] << endl;
    }

    if (map.find(600) != map.end()){
        map.erase(600);
    } 
     
  for(const auto it : map){
        print_key_value(it.first, it.second);
    }
    //contains is in c++20
    /*if (map.contains(i)){
        cout << map[i];
    } else {
        map[i] = "Test 7";
        cout << "Added " << map[i] << endl;
    }*/




    return 0;
}

