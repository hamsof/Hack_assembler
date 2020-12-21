
//this program can only be used when you dont have symbols,labels and variables in
// hack assembly instrunctions

#include <iostream>
#include <fstream>
#include <cmath>
#include <sstream>
#include <string>
#include <cstring>
#include <map>

using namespace std;

string Result = "";

string removeComments(string s)
{
    string str = "";
    for (int i = 0; i < s.length(); i++)
    {
        if (!isspace(s[i]))
        {
            if (s[i] == '/' and s[i + 1] == '/')
            {
                return str;
            }
            else
            {
                str.push_back(s[i]);
            }
        }
    }
    return str;
}

int convertDecimalToBinary(int n)
{
    int binaryNumber = 0;
    int remainder, i = 1, step = 1;

    while (n != 0)
    {
        remainder = n % 2;
        n /= 2;
        binaryNumber += remainder * i;
        i *= 10;
    }
    return binaryNumber;
}

string A_instruction_binary(string str)
{
    string str2 = " ";
    string str3 = "";
    int binary_x;
    int i = 1;
    while (i != str.length())
    { // A-instruction Binary

        str2 = str2 + str[i];
        i++;
    }

    stringstream ss1(str2);
    int x = 0;
    ss1 >> x;
    binary_x = convertDecimalToBinary(x);
    stringstream ss2;
    ss2 << binary_x;
    string s1;
    ss2 >> s1;
    for (int i = 0; i != (16 - s1.length()); i++)
    {
        str3.append("0");
    }
    str3.append(s1);
    return str3;
}

string C_instruction_binary(string str)
{
    map<string, string> map_comp0;
    map<string, string> map_comp1;
    map<string, string> map_dest;
    map<string, string> map_jump;
    string c_in;
    string comp = "";
    string jump = "";
    string dest = "";
    bool check = false;
    bool jump_1 = false;
    map_comp0.insert(make_pair("0", "101010"));
    map_comp0.insert(make_pair("1", "111111"));
    map_comp0.insert(make_pair("-1", "111010"));
    map_comp0.insert(make_pair("D", "001100"));
    map_comp0.insert(make_pair("A", "110000"));
    map_comp0.insert(make_pair("!D", "001101"));
    map_comp0.insert(make_pair("!A", "110001"));
    map_comp0.insert(make_pair("-D", "001111"));
    map_comp0.insert(make_pair("-A", "110011"));
    map_comp0.insert(make_pair("D+1", "011111"));
    map_comp0.insert(make_pair("A+1", "110111"));
    map_comp0.insert(make_pair("D-1", "001110"));
    map_comp0.insert(make_pair("A-1", "110010"));
    map_comp0.insert(make_pair("D+A", "000010"));
    map_comp0.insert(make_pair("D-A", "010011"));
    map_comp0.insert(make_pair("A-D", "000111"));
    map_comp0.insert(make_pair("D&A", "000000"));
    map_comp0.insert(make_pair("D|A", "010101"));

    map_comp1.insert(make_pair("M", "110000"));
    map_comp1.insert(make_pair("!M", "110001"));
    map_comp1.insert(make_pair("-M", "110011"));
    map_comp1.insert(make_pair("M+1", "110111"));
    map_comp1.insert(make_pair("M-1", "110010"));
    map_comp1.insert(make_pair("D+M", "000010"));
    map_comp1.insert(make_pair("D-M", "010011"));
    map_comp1.insert(make_pair("M-D", "000111"));
    map_comp1.insert(make_pair("D&M", "000000"));
    map_comp1.insert(make_pair("D|M", "010101"));

    map_dest.insert(make_pair("0", "000"));
    map_dest.insert(make_pair("M", "001"));
    map_dest.insert(make_pair("D", "010"));
    map_dest.insert(make_pair("MD", "011"));
    map_dest.insert(make_pair("A", "100"));
    map_dest.insert(make_pair("AM", "101"));
    map_dest.insert(make_pair("AD", "110"));
    map_dest.insert(make_pair("AMD", "111"));

    map_jump.insert(make_pair("0", "000"));
    map_jump.insert(make_pair("JGT", "001"));
    map_jump.insert(make_pair("JEQ", "010"));
    map_jump.insert(make_pair("JGE", "011"));
    map_jump.insert(make_pair("JLT", "100"));
    map_jump.insert(make_pair("JNE", "101"));
    map_jump.insert(make_pair("JLE", "110"));
    map_jump.insert(make_pair("JMP", "111"));

    Result.append("111");
    //cout << str << "\n";
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == '=')
        {
            for (int j = ++i; j < str.length(); j++)
            {
                comp.push_back(str[j]);
            }
            break;
        }
        else if (str[i] == ';')
        {
            for (int j = 0; j < i; j++)
            {
                comp.push_back(str[j]);
            }
            break;
        }
    }
    for (int i = 0; i < comp.length(); i++)
    {
        if (comp[i] == 'M')
        {
            check = true;
        }
    }
    if (check)
    {
        Result.push_back('1');
        Result.append(map_comp1.find(comp)->second);
    }
    else
    {
        Result.push_back('0');
        Result.append(map_comp0.find(comp)->second);
    }
    //cout << Result << "\n";
    // destination

    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == '=')
        {
            //cout << str << "\n";
            for (int j = 0; j < i; j++)
            {
                //cout << "hamza";
                dest.push_back(str[j]);
                //cout << dest << "\n";
            }
            Result.append(map_dest.find(dest)->second);
        }
        else if (str[i] == ';')
        {
            Result.append("000");
            break;
        }
    }
    //cout << dest << "\n";
    //Result.append(map_dest.find(dest)->second);
    //cout << Result << "\n";

    // jump;

    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == ';')
        {
            jump_1 = true;
            //cout << str << "\n";
            for (int j = ++i; j < str.length(); j++)
            {
                //cout << "hamza";
                jump.push_back(str[j]);
                //cout << jump << "\n";
                //Result.append(map_jump.find(jump)->second);
            }
            Result.append(map_jump.find(jump)->second);
        }
    }
    if (!jump_1)
    {
        Result.append("000");
    }
    //cout << Result << "\n";
    c_in = Result;
    Result = "";
    return c_in;
}
int main()
{
    ifstream my_read_file("hamsof.asm");
    ofstream my_write_file("Binary.txt");
    while (!my_read_file.eof())
    {
        string str;
        getline(my_read_file, str);
        //cout << str << "\n";
        str = removeComments(str);
        if (str == "")
            continue;
        //cout << str << "\n";
        else if (str[0] == '@')
        {
            //cout << str << "\n";
            cout << A_instruction_binary(str) << "\n";
        }
        else
        {
            //cout << str << "\n";
            str = C_instruction_binary(str);
            cout << str << "\n";
        }
    }
    return 0;
}