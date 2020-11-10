#include "json_parser.h"
#include "json_scanner.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

extern vector<int> lex;
extern vector<string> text;

int cur_value;
string cur_text;
int position = 0;

void error()
{
    cout << endl << "wrong syntax: " << cur_text << endl;
    exit(1);
}

void advance()
{
    position++;
    cur_value = lex[position];
    cur_text = text[position];
    cout << cur_text;
}

void parser()
{
    cur_value = lex[position];
    cur_text = text[position];
    cout << cur_text;
    json();
}

void json()
{
    element();
}

void value()
{
    const vector<int> legal_value{STRING, NUMBER, J_TRUE, J_FALSE, J_NULL};
    for(const auto& lv : legal_value)
    {
        if (lv == cur_value) {
            advance();
            return ;
        }
    }
    if(cur_value == '[')
    {
        array();
    }
    else if(cur_value == '{')
    {
        object();
    }
    else error();
}

void object()
{
    if(cur_value == '{') {
        advance();
        if(cur_value == '}')
            advance();
        else if(cur_value == STRING)
        {
            members();
            if(cur_value == '}')
                advance();
            else error();
        }
        else error();
    }
    else error();
}

void members()
{
    member();
    while(cur_value == ',') {
        advance();
        member();
    }
}

void member()
{
    if(cur_value == STRING) {
        advance();
        if(cur_value == ':')
        {
            advance();
            element();
        }
        else error();
    }
    else error();
}

void array()
{
    if(cur_value == '[') {
        advance();
        if(cur_value == ']')
            advance();
        else elements();
    }
    else error();
}

void elements()
{
    element();
    while(cur_value == ',') {
        advance();
        element();
    }
}

void element()
{
    value();
}
