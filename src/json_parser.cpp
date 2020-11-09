//
// Created by HP on 11/6/2020.
//
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
    object();
}

void object()
{
    if(cur_value == '{') {
        advance();
        object_a();
    }
    else error();
}

void object_a()
{
    if(cur_value == ' ')
    {
        advance();
        object_b();
    }
    else error();
}

void object_b()
{
    if(cur_value == '}')
        advance();
    else if(cur_value == STRING)
    {
        advance();
        if(cur_value == ' ')
        {
            advance();
            if(cur_value == ':')
            {
                advance();
                value();
                members_a();
                if(cur_value == '}')
                    advance();
                else error();
            }
            else error();
        }
        else error();
    }
    else error();
}

void members()
{
    member();
    members_a();
}

void members_a()
{
    if(cur_value == ',')
    {
        advance();
        members();
    }
    else ;
}

void member()
{
    if(cur_value == ' ')
    {
        advance();
        if(cur_value == STRING) {
            advance();
            if(cur_value == ' ')
            {
                advance();
                if(cur_value == ':')
                {
                    advance();
                    value();
                }
                else error();
            }
            else error();
        }
        else error();
    }
}

void value()
{
    if(cur_value == STRING)
        advance();
    else if(cur_value == NUMBER)
        advance();
    else error();
}
