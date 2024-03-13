#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

using namespace std;

int Count(const char* s) {
    int k = 0;
    size_t pos = 0;
    while (s[pos] != '\0') {
        if (s[pos] == '*' && s[pos + 1] == '*' && s[pos + 2] == '*')
            k++;
        pos++;
    }
    return k;
}


char* Change(char* s) {
    size_t len = strlen(s);
    char* t = new char[len * 2 + 1];
    size_t pos1 = 0;
    size_t pos2 = 0;

    while (s[pos1] != '\0') {
        if (s[pos1] == '*' && s[pos1 + 1] == '*' && s[pos1 + 2] == '*') {
            t[pos2++] = '!';
            t[pos2++] = '!';
            pos1 += 3;
        }
        else {
            t[pos2++] = s[pos1++];
        }
    }
    t[pos2] = '\0';

    for (size_t i = 0; i <= pos2; ++i) {
        s[i] = t[i];
    }

    delete[] t;
    return s;
}


int main() {
    char str[101];
    cout << "Enter string:" << endl;
    cin.getline(str, 100);
    cout << "String contained " << Count(str) << " groups of '***'" << endl;
    Change(str);
    cout << "Modified string (param) : " << str << endl;
    return 0;
}
