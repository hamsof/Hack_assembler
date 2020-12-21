
//hafiz abdulmanan
//hamsof

//using map dsa and and functions and a global variable Result for c_inis
//less lines of code
// thats a smarter way

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

string get_A(string c)
{
    int a = 0;
    string w = "";
    //cout << "come";
    for (int i = 1; i < c.length(); i++)
    {
        w.push_back(c[i]);
    }
    //cout << w;
    stringstream hamsof(w);
    hamsof >> a;
    string temp, binary = "";
    char b[1000];
    temp = itoa(a, b, 2);
    //cout << temp << " ";
    for (int i = 0; i < 16 - temp.length(); i++)
    {
        binary.push_back('0');
    }
    binary.append(temp);
    //cout << " binary : " << binary << " lenghth : " << binary.length() << " int : " << value << " \n";
    return binary;
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
    ifstream my_read_file("if.asm");
    //
    map<string, string> Map_for_var;
    map<string, string>::iterator y;
    map<string, string> Map_for_predefined;
    map<string, string>::iterator x;
    Map_for_predefined.insert(make_pair("@SCREEN", "@16384"));
    Map_for_predefined.insert(make_pair("@KBD", "@24576"));
    Map_for_predefined.insert(make_pair("@SP", "@0"));
    Map_for_predefined.insert(make_pair("@LCL", "@1"));
    Map_for_predefined.insert(make_pair("@ARG", "@2"));
    Map_for_predefined.insert(make_pair("@THIS", "@3"));
    Map_for_predefined.insert(make_pair("@THAT", "@4"));
    Map_for_predefined.insert(make_pair("@R0", "@0"));
    Map_for_predefined.insert(make_pair("@R1", "@1"));
    Map_for_predefined.insert(make_pair("@R2", "@2"));
    Map_for_predefined.insert(make_pair("@R3", "@3"));
    Map_for_predefined.insert(make_pair("@R4", "@4"));
    Map_for_predefined.insert(make_pair("@R5", "@5"));
    Map_for_predefined.insert(make_pair("@R6", "@6"));
    Map_for_predefined.insert(make_pair("@R7", "@7"));
    Map_for_predefined.insert(make_pair("@R8", "@8"));
    Map_for_predefined.insert(make_pair("@R9", "@9"));
    Map_for_predefined.insert(make_pair("@R10", "@10"));
    Map_for_predefined.insert(make_pair("@R11", "@11"));
    Map_for_predefined.insert(make_pair("@12", "@12"));
    Map_for_predefined.insert(make_pair("@R13", "@13"));
    Map_for_predefined.insert(make_pair("@R14", "@14"));
    Map_for_predefined.insert(make_pair("@R15", "@15"));
    int line = 0;
    while (!my_read_file.eof())
    {
        string str;
        string w = "";
        string co = "";
        getline(my_read_file, str);
        //cout << str << "\n";
        str = removeComments(str);
        if (str == "")
            continue;
        if (str[0] != '(')
        {
            //cout << "hamza";
            line++;
            //cout << line << "\n";
        }
        if (str[0] == '(')
        {
            for (int i = 0; i < str.length(); i++)
            {
                w.push_back('@');
                co.push_back('@');
                for (int j = 1; j < str.length() - 1; j++)
                {
                    w.push_back(str[j]);
                }
                co.append(to_string(line));
                Map_for_predefined.insert(make_pair(w, co));
                break;
            }
        }
    }
    my_read_file.close();

    ifstream my_read_file_1("if.asm");
    ofstream my_write_file("symbol.txt");

    int var = 16;
    string var_1 = "";
    while (!my_read_file_1.eof())
    {
        string str;
        getline(my_read_file_1, str);
        //cout << str << "\n";
        str = removeComments(str);
        if (str == "")
            continue;
        //cout << str << "\n";
        if (str[0] == '(')
            continue;
        if (str[0] == '@')
        {
            //cout << str << "\n";
            x = Map_for_predefined.find(str);
            if (x == Map_for_predefined.end())
            {
                //cout << str << "\n";
                y = Map_for_var.find(str);
                if (y == Map_for_var.end())
                {
                    //cout << str << "\n";
                    var_1.push_back('@');
                    var_1.append(to_string(var));
                    //cout << var_1 << "\n";
                    Map_for_var.insert(make_pair(str, var_1));
                    str = var_1;
                    var++;
                    var_1 = "";
                }
                else
                {
                    //cout << str << "\n";
                    str = Map_for_var.find(str)->second;
                }
                my_write_file << str << "\n";
            }
            else
            {
                //cout << str << "\n";
                str = Map_for_predefined.find(str)->second;
                my_write_file << str << "\n";
            }
        }
        else
        {

            my_write_file << str << "\n";
        }
    }
    //cout << Map_for_var["hamza"] << "\n";
    my_read_file_1.close();
    my_write_file.close();

    ifstream my_read_file_2("symbol.txt");
    ofstream my_write_file_2("file.txt");

    while (!my_read_file_2.eof())
    {
        string str;
        getline(my_read_file_2, str);
        //cout << str << "\n";
        str = removeComments(str);
        if (str == "")
            continue;
        //cout << str << "\n"

        else if (str[0] == '@')
        {
            //cout << str << "\n";
            my_write_file_2 << get_A(str) << "\n";
        }
        else
        {
            //cout << str << "\n";
            str = C_instruction_binary(str);
            my_write_file_2 << str << "\n";
        }
    }
    my_read_file_2.close();
    my_write_file_2.close();
    remove("symbol.txt");
    return 0;
}