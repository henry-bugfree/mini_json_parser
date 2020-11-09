//
// Created by HP on 11/6/2020.
//
#include "json_scanner.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> lex;
vector<string> text;

bool isNumber(const string &str)
{
    return all_of(str.begin(), str.end(), ::isdigit);
}

int check_value(const string& token)
{
    if(isNumber(token))
        return NUMBER;
    else
        throw std::runtime_error(token);
}

void scanner(const string &nameOfFile)
{
    char ch;
    string buffer;

    std::fstream file(nameOfFile, std::fstream::in);
    if (!file.is_open())
        throw std::runtime_error("error while opening the file\n");

    while (file >> std::noskipws >> ch)
    {
        if(ch == '"')
        {
            if(!buffer.empty()) {
                lex.push_back(check_value(buffer));
                text.push_back(buffer);
                buffer = "";
            }
            buffer+=ch;
            while (file >> std::noskipws >> ch)
            {
                buffer+=ch;
                if(ch == '"') break;
            }
            text.push_back(buffer);
            lex.push_back(STRING);
            buffer = "";
            continue;
        }

        if(ch == ' ')
        {
            if(!buffer.empty())
            {
                lex.push_back(check_value(buffer));
                text.push_back(buffer);
                buffer = "";
            }
            lex.push_back(' ');
            text.emplace_back(1,ch);
            continue;
        }

        if(ch == '\n')
        {
            if(!buffer.empty())
            {
                lex.push_back(check_value(buffer));
                text.push_back(buffer);
                buffer = "";
            }
            continue;
        }

        if(ch == '{')
        {
            if(!buffer.empty())
            {
                lex.push_back(check_value(buffer));
                text.push_back(buffer);
                buffer = "";
            }
            lex.push_back('{');
            text.emplace_back(1,ch);
            continue;
        }

        if(ch == '}')
        {
            if(!buffer.empty())
            {
                lex.push_back(check_value(buffer));
                text.push_back(buffer);
                buffer = "";
            }
            lex.push_back('}');
            text.emplace_back(1,ch);
            continue;
        }

        if(ch == ':')
        {
            if(!buffer.empty())
            {
                lex.push_back(check_value(buffer));
                text.push_back(buffer);
                buffer = "";
            }
            lex.push_back(':');
            text.emplace_back(1,ch);
            continue;
        }

        if(ch == ',')
        {
            if(!buffer.empty())
            {
                lex.push_back(check_value(buffer));
                text.push_back(buffer);
                buffer = "";
            }
            lex.push_back(',');
            text.emplace_back(1,ch);
            continue;
        }

        buffer += ch;
    }
    file.close();
}