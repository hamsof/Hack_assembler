#include <iostream>
#include <fstream>
#include <string.h>
#include <map>           // for string class
#include <sstream>       //for char to string convert
#include <bits/stdc++.h> //for decimal to binary
#include <cstdio>
using namespace std;
class Cintrunstion
{
    string s;
    string temp = "";

public:
    Cintrunstion(string s)
    {
        this->s = s;
        //cout << s;
    }
    void opcode()
    {
        temp.append("111");
    }
    void com()
    {
        bool check = false;
        string comp = "";
        int des, sem;
        // getting composition after =
        for (int i = 0; i < s.length(); i++)
        {
            // we have to get the string after =
            if (s[i] == '=')
            {
                for (des = ++i; des < s.length(); des++)
                    comp.push_back(s[des]);
            }

            if (s[i] == ';')
            {
                // we have to get the string before of ;
                for (sem = 0; sem < i; sem++)
                    comp.push_back(s[sem]);
            }
        }
        //cout << dest;

        // setting opcode a
        //for (int i = 0; i < comp.length(); i++)
        //{
        if (comp[0] == 'M')
        {
            check = true;
        }
        //}

        if (check)
            temp.push_back('1');
        else
            temp.push_back('0');
        //cout << comp << "\n";
        if ((comp[0] == 'D' and comp[1] == '|' and comp[2] == 'A') or (comp[0] == 'D' and comp[1] == '|' and comp[2] == 'M'))
        {
            temp.append("010101");
        }
        else if ((comp[0] == 'D' and comp[1] == '&' and comp[2] == 'A') or (comp[0] == 'D' and comp[1] == '&' and comp[2] == 'M'))
        {
            temp.append("000000");
        }
        else if (comp[0] == 'D' and comp[1] == '+' and comp[2] == 'M')
        {
            temp.append("000010");
        }
        else if ((comp[0] == 'D' and comp[1] == '-' and comp[2] == 'A') or (comp[0] == 'D' and comp[1] == '-' and comp[2] == 'M'))
        {
            temp.append("010011");
        }
        else if ((comp[0] == 'A' and comp[1] == '-' and comp[2] == 'D') or (comp[0] == 'M' and comp[1] == '-' and comp[2] == 'D'))
        {
            temp.append("000111");
        }
        else if (comp == "A+1" or comp == "M+1")
        {
            //cout << "hafiz ad";
            temp.append("110111");
        }
        else if ((comp[0] == '!' and comp[1] == 'A') or (comp[0] == '!' and comp[1] == 'M'))
        {
            temp.append("110001");
        }
        else if (comp[0] == '-' and comp[1] == '1')
        {
            temp.append("111010");
        }
        else if (comp[0] == 'A' or comp[0] == 'M')
        {
            //cout << "numa";
            temp.append("110000");
        }
        else if (comp[0] == '!' and comp[1] == 'D')
        {
            temp.append("001101");
        }

        else if (comp[0] == '-' and comp[1] == 'D')
        {
            temp.append("001111");
        }
        else if ((comp[0] == '-' and comp[1] == 'A') or (comp[0] == '-' and comp[1] == 'M'))
        {
            temp.append("110011");
        }
        else if (comp[0] == 'D' and comp[1] == '+' and comp[2] == '1')
        {
            temp.append("011111");
        }

        else if (comp[0] == 'D' and comp[1] == '-' and comp[2] == '1')
        {
            temp.append("001110");
        }
        else if ((comp[0] == 'A' and comp[1] == '-' and comp[2] == '1') or (comp[0] == 'M' and comp[1] == '-' and comp[2] == '1'))
        {
            temp.append("110010");
        }
        else if (comp[0] == '0') //0
        {
            temp.append("101010");
        }
        else if (comp[0] == '1')
        {
            temp.append("111111");
        }

        else if (comp[0] == 'D')
        {
            temp.append("001100");
        }
        else if (comp[0] == 'M')
        {
            temp.append("101010");
        }

        else
        {
            /* code */
        }
    }
    void destination()
    {
        string dest = "";
        bool check = true;
        int des;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '=')
            {
                check = false;
                for (des = 0; des < i; des++)
                    dest.push_back(s[des]);
            }
        }
        if (check)
        {
            temp.append("000");
        }
        if (dest == "null")
        {
            temp.append("000");
        }
        if (dest == "M")
        {
            temp.append("001");
        }
        if (dest == "D")
        {
            temp.append("010");
        }
        if (dest == "MD")
        {
            temp.append("011");
        }
        if (dest == "A")
        {
            temp.append("100");
        }
        if (dest == "AM")
        {
            temp.append("101");
        }
        if (dest == "AD")
        {
            temp.append("110");
        }
        if (dest == "AMD")
        {
            temp.append("111");
        }
    }
    void jump()
    {
        string semi = "";
        bool check = true;
        int sem;
        //cout << s;
        for (int i = 0; i < s.length(); i++)
        {

            if (s[i] == ';')
            {
                // we have to get the string before of ;
                for (sem = ++i; sem < s.length(); sem++)
                    semi.push_back(s[sem]);
                check = false;
            }
        }
        //cout << semi;
        if (check)
        {
            temp.append("000");
        }
        if (semi == "null")
        {
            temp.append("000");
        }
        if (semi == "JGT")
        {
            temp.append("001");
        }
        if (semi == "JEQ")
        {
            temp.append("010");
        }
        if (semi == "JGE")
        {
            temp.append("011");
        }
        if (semi == "JLT")
        {
            temp.append("100");
        }
        if (semi == "JNE")
        {
            temp.append("101");
        }
        if (semi == "JLE")
        {
            temp.append("110");
        }
        if (semi == "JMP")
        {
            temp.append("111");
        }
    }
    string get_binary_C()
    {
        opcode();
        com();
        destination();
        jump();
        return temp;
    }
};
int get_intiger_A(string c)
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
    return a;
}
string get_binary(int value)
{
    string temp, binary = "";
    char a[1000];
    temp = itoa(value, a, 2);
    //cout << temp << " ";
    for (int i = 0; i < 16 - temp.length(); i++)
    {
        binary.push_back('0');
    }
    binary.append(temp);
    //cout << " binary : " << binary << " lenghth : " << binary.length() << " int : " << value << " \n";
    return binary;
}
string removeComments(string c)
{
    string str = "";
    for (int i = 0; i < c.length(); i++)
    {
        if (!isspace(c[i])) // that will remove empty spaces in the string that we dont
        {
            if (c[i] == '/' and c[i + 1] == '/')
            {
                return str;
            }
            else
                //str.append(1, c[i]);
                str.push_back(c[i]);
        }
    }
    return str;
}

string from_label_value(int line)
{

    // yaha se mujhey @ ke sath number mil jaey gha
    string label = "";
    label.push_back('@');
    string temp = to_string(line);
    //cout << temp;
    label.append(temp);
    //cout << label;
    return label;
}

int main()
{
    int value;
    string temp, temp_1;
    string s;
    int line = 0;
    string w = "";
    string z;
    string t = "";
    string a;
    int var = 16;
    bool check = false;
    map<string, string> Map_for_label;
    map<string, string> Map_for_variable;
    //Map_for_predefined.insert(make_pair())
    map<string, string> Map_for_predefined;

    map<string, string>::iterator x;
    map<string, string>::iterator y;
    map<string, string>::iterator f;

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

    cout << "\n\n..................Welcome to Hack Aseembler Task_2.....................\n\n";
    cout << "Enter file name\n";
    string file_name;
    cin >> file_name;
    cout << "\n\nHack assembly code is givem below and also .hack file is placed in the dirctory \n\n";
    ifstream file_1(file_name);        //read mode
    ofstream file_2("for_task_2.txt"); //write mode

    string file_name_hack = "";
    for (int i = 0; i < file_name.length() - 4; i++)
    {
        file_name_hack.push_back(file_name[i]);
    }
    file_name_hack.append(".hack");

    //to remove comments and and empty spaces
    while (!file_1.eof())
    {
        getline(file_1, s);
        //cout << s;
        s = removeComments(s);
        if (s != "")
        {
            file_2 << s;
            file_2 << "\n";
        }
    }

    file_1.close();
    file_2.close();

    //setting label_map
    ifstream file_4("for_task_2.txt");
    while (!file_4.eof())
    {
        getline(file_4, s);
        if (s == "")
            continue;
        if (s[0] != '(')
            line++;
        if (s[0] == '(')
        {
            w.push_back('@');
            for (int i = 1; i < s.length() - 1; i++)
            {
                w.push_back(s[i]);
                z = from_label_value(line);
            }
            //cout << w << " " <<
            Map_for_label.insert(make_pair(w, z));
            w = "";
        }
    }

    file_4.close();

    ifstream file_5("for_task_2.txt");
    ofstream file_7("if_task_2.txt");

    //setting_map for predefined labels
    while (!file_5.eof())
    {

        getline(file_5, s);
        if (s == "")
            continue;
        if (s[0] == '(')
            continue;
        if (s[0] == '@')
        {
            y = Map_for_predefined.find(s);
            if (y == Map_for_predefined.end())
            {
            }
            else
            {
                s = Map_for_predefined.find(s)->second;
            }

            if (s[1] == '0' or s[1] == '1' or s[1] == '2' or s[1] == '3' or s[1] == '4' or s[1] == '5' or s[1] == '6' or s[1] == '7' or s[1] == '8' or s[1] == '9')
            {
            }
            else
            {
                //for varibales
                x = Map_for_label.find(s);
                if (x == Map_for_label.end())
                {
                    //cout << s << "\n";
                    y = Map_for_variable.find(s);
                    if (y == Map_for_variable.end())
                    {
                        t.push_back('@');
                        a = to_string(var);
                        t.append(a);
                        Map_for_variable.insert(make_pair(s, t));
                        //cout << t;
                        s = t;
                        var++;
                        t = "";
                        //cout << s << "\n";
                    }
                    else
                    {
                        s = Map_for_variable.find(s)->second;
                        //cout << s << "\n";
                    }
                }
                else
                {
                    s = Map_for_label.find(s)->second;
                    //cout << s << "\n";
                }
            }
            //cout << s << "\n";
            file_7 << s << "\n";
        }
        else
        {
            //cout << s << "\n";
            file_7 << s << "\n";
        }
    }

    file_5.close();
    file_7.close();

    ifstream file_8("if_task_2.txt");
    ofstream file_9(file_name_hack);

    //binary code for a instrunction
    while (!file_8.eof())
    {
        getline(file_8, s);
        //empty string ko remove karo
        if (s == "")
            continue;
        //A instrunction
        if (s[0] == '@')
        {
            value = get_intiger_A(s);
            temp = get_binary(value);
            file_9 << temp << "\n";
            cout << temp << "\n";
        }
        else
        {
            //binary code for c type
            //file_3 << s << "\n";

            //Cinstrunctions has been sent to class
            Cintrunstion c_value(s);
            temp_1 = c_value.get_binary_C();
            file_9 << temp_1 << "\n";
            cout << temp_1 << " \n";
        }
    }
    //finally end
    file_8.close();
    file_9.close();
    cout << "\n\n............Thankyou for using us.....................\n\n";

    return 0;
}