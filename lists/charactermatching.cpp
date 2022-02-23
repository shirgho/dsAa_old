#include <iostream>
#include <string>
#include "stack_4.h"
#include <stack>

using namespace std;

void PrintError(char ch, int index)
{
    cout << " Error [E]: " << ch << " at " << index << "." << endl;
}

void ParseString(char *str, int size)
{
    // create stack (last in first out structure)
    // push opening char on to stack until first closing char
    // check to see if first closing char matches with last opening char (which should be on top of the stack as pushed last)

    if (str == NULL || size <= 0){
        cout << " Error with paramters!" << endl;
        return;
    }

    stack<char> charStack;
    char ch = 0;
    int errors = 0;

    for(int i = 0; i < size; i++){
        switch(str[i])
        {
            case '{':
            case '(':
            case '[':
                charStack.push(str[i]);
                break;
            case '}':
            case ')':
            case ']':
                if(charStack.empty() == false){
                    ch = charStack.top();
                    charStack.pop();
                    if (
                        (ch != '{' && str[i] == '}')
                        || (ch != '(' && str[i] == ')')
                        || (ch != '[' && str[i] == ']')
                    ) 
                    {
                        PrintError(ch, i + 1);
                        errors++;
                        
                    }
                }
                break;
        }
    }

    if (charStack.empty() && !errors){
        cout << " No Parsing Errors." << endl << endl;
    } else if(errors) {
        cout << " Unclosed Characters: " << errors << "." << endl;
    }

}

int main(int args, char **argc)
{
    cout << "Character Matching with Stacks" << endl;
    
    char str[] = { '{', '(', 'a', '[', '5', ']', ')', '}' };
    int size = char_traits<char>::length(str);
    cout << "Parsing string." << endl;
    ParseString(str, size);
    
    char str2[] = { '{', ')', 'b', '[', '1', ']', '}', '}' };
    size = char_traits<char>::length(str2);
    cout << "Parsing string 2." << endl;
    ParseString(str2, size);

    return 1;
}