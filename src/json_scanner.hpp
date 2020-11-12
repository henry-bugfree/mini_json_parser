#ifndef JSON_INTERPRETER_JSON_SCANNER_H
#define JSON_INTERPRETER_JSON_SCANNER_H
#include <string>
using namespace std;
enum {
    STRING = 258, NUMBER, J_TRUE, J_FALSE, J_NULL
};

bool isNumber(const string &str);
int check_value(const string& token);
void scanner(const string &nameOfFile);

#endif //JSON_INTERPRETER_JSON_SCANNER_H
