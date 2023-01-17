//  : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//-----------------------------------------------------------------------
//  Header      : -
//  Created     :   17.01.2023
//  Author      :   Vladimir Lapshov
//  Description :   Skillfactory C++ 12.7 home work: IsKPeriodic function realisation. 
//                  Checks, wheather a string is k-periodic or not.
//                  Algorithm splits the input string into two halves and compares them
//                  every time until one halve becomes k-length prefix of the input string.
// ------------------------------------------------------------------------------------
//              k-length prefix
//                  /  \
//                  |abc|abc|abc|abc|abc|abc|abc|
//                  i1         i2   i3          i4
//                   1st halve  /   \  2-nd halve
//                      middle k-length substr
// 
//-------------------------------------------------------------------------------------
#include <string>
#include <iostream>
#include <windows.h> // for "SetConsoleOutputCP(1251)" as setlocale(LC_ALL, "Russian") doesn't work on my machine

using namespace std;

bool IsKPeriodic(const string& str, int k) {
    int strLen = str.length();
    // if k is not a devider for strLen:
    if (k <= 0 || strLen % k != 0) return false;
    // k length prefix of the string:
    string substrK = str.substr(0, k);
    // indexes for deviding the str into two halves: substr1[0 ... i2], substr2[i3 ... strLen - 1]
    int index2 = k, index3; // index0 = 0; index3 = strLen - 1
    // while the str is two times or more longer then k, it is possible 
    // to split it into two halves and compare them more quick:
    while (strLen >= 2 * k) {
        if (strLen % (2 * k) == 0) {
            index2 = strLen / 2 - 1;
            index3 = strLen / 2;
        }
        // if the str couldn't be devided by 2 * k, let's make a middle k-length substring str.substr(index2 + 1, k:
        else {
            index2 = (strLen - k) / 2 - 1;
            index3 = index2 + k + 1;
            // middle k-length part of the string
            if (str.substr(index2 + 1, k) != substrK) {
                return false;
            }
        }
        // now compare two halves of the str:
        if (str.substr(0, index2 + 1) != str.substr(index3, strLen - index3)) {
            return false;
        }
        // if they're equal, continue to work with the one half of them:
        else {
            strLen = ++index2;
        }    
    }
    return true;// (substrK == str.substr(0, index2));
}

// *** naive algorithm ***
/*
bool IsKPeriodic(const string& str, int k) {
    int strLen = str.length();
    // if k is not a devider for strLen:
    if (k <= 0 || strLen % k != 0) return false;
    // k length prefix of the string:
    string substr = str.substr(0, k);
    // check if all k-length substrings from str[k] position are equal:
    for (int substrPos = k; substrPos < strLen; substrPos += k) {
        if (substr != str.substr(substrPos, k)) return false;
    }
    return true;
}
*/

// main - for testing:
int main()
{
    //setlocale(LC_ALL, "Russian"); 
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    string str1 = "abcabcabcabc";
    string str2 = "abcabcabcab";
    string str3 = "abcdefgcabcde";
    string str4 = "abbabbabbabba";
    string str5 = "aaaaaaaaaaaa";
    cout << "\"" << str1 << "\" is " << (IsKPeriodic(str1, 3) ? "" : "not ") << "3-periodic." << endl;
    cout << "\"" << str1 << "\" is " << (IsKPeriodic(str1, 5) ? "" : "not ") << "5-periodic." << endl;
    cout << "\"" << str1 << "\" is " << (IsKPeriodic(str1, 6) ? "" : "not ") << "6-periodic." << endl;
    cout << "\"" << str1 << "\" is " << (IsKPeriodic(str1, 7) ? "" : "not ") << "7-periodic." << endl;
    cout << "\"" << str1 << "\" is " << (IsKPeriodic(str1, 12) ? "" : "not ") << "12-periodic." << endl;
    cout << "\"" << str2 << "\" is " << (IsKPeriodic(str2, 3) ? "" : "not ") << "3-periodic." << endl;
    cout << "\"" << str3 << "\" is " << (IsKPeriodic(str3, 5) ? "" : "not ") << "5-periodic." << endl;
    cout << "\"" << str4 << "\" is " << (IsKPeriodic(str4, 4) ? "" : "not ") << "4-periodic." << endl;
    cout << "\"" << str4 << "\" is " << (IsKPeriodic(str4, 0) ? "" : "not ") << "0-periodic." << endl;
    cout << "\"" << str4 << "\" is " << (IsKPeriodic(str4, 1) ? "" : "not ") << "1-periodic." << endl;
    cout << "\"" << str5 << "\" is " << (IsKPeriodic(str5, 1) ? "" : "not ") << "1-periodic." << endl;
}

