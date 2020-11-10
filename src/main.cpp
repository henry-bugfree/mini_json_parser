#include <iostream>
#include <string>
#include <vector>
#include "json_scanner.h"
#include "json_parser.h"
using namespace std;

extern vector<string> text;

int main() {
    cout << "啊UTF8!" << endl;
    scanner("../json.txt");
    parser();
    return 0;
}

