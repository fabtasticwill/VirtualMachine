#include <iostream>
#include <map>
#include <string>
#include <fstream>

using namespace std;



bool is_number(const std::string& s)
{
    std::string::const_iterator it = s.begin();
    while (it != s.end() && std::isdigit(*it)) ++it;
    return !s.empty() && it == s.end();
}


string stringRange(string text, int start, int range)
{
    string temp;
    start +=1;
    temp[0]= text[start];

    for(int a = 0;a<range;a++)
        temp += text[start+a];
    return temp;
}

bool isVar(string text)
{
    if(text[0] == '\'')
        return false;
    if(is_number)
        return false;
    else return true;
}

int main()
{
    string EAX = "\0";
    string EBX = "\0";
    string ECX = "\0";
    string EDX = "\0";
    string temp;
    string content = " ";
    ifstream file("test.asm");
    int length = 0;
    while(file>>temp)
    {
        length+=temp.length()+1;
        content += temp + " ";
    }
    map<string, string> vars;
    //cout<<stringRange(content, 0, 3);
    for(int a = 0; a<length;a++)
    {
        if(stringRange(content, a, 3) == "MOV")
        {
                if(stringRange(content, a+4,3) == "EAX")
                {
                    EAX ="\0";
                    if(content[a+10] == '\'')
                    {
                        for(int b = 0;content[a+11+b] !='\'';b++)
                            EAX += content[a+11+b];
                    }

                    if(isdigit(content[a+10]))
                    {
                       for(int b = 0;content[a+10+b] != ' ';b++)
                            EAX += content[a+10+b];
                    }
                    else
                    {
                        //cout<<stringRange(content, a+9,3);
                        if (stringRange(content, a+9,3) == "EAX")
                            EAX = EAX;
                        if (stringRange(content, a+9,3) == "EBX")
                            EAX = EBX;
                        if (stringRange(content, a+9,3) == "ECX")
                            EAX = ECX;
                        if (stringRange(content, a+9,3) == "EDX")
                            EAX = EDX;
                    }
                }
                if(stringRange(content, a+4,3) == "EBX")
                {
                    EBX = "\0";
                    if(content[a+10] == '\'')
                    {
                        for(int b = 0;content[a+11+b] !='\'';b++)
                            EBX += content[a+11+b];
                    }

                    if(isdigit(content[a+10]))
                    {
                       for(int b = 0;content[a+10+b] != ' ';b++)
                            EBX += content[a+10+b];
                    }
                    else
                    {
                        //cout<<stringRange(content, a+9,3);
                        if (stringRange(content, a+9,3) == "EAX")
                            EBX = EAX;
                        if (stringRange(content, a+9,3) == "EBX")
                            EBX = EBX;
                        if (stringRange(content, a+9,3) == "ECX")
                            EBX = ECX;
                        if (stringRange(content, a+9,3) == "EDX")
                            EBX = EDX;
                    }
                }
                if(stringRange(content, a+4,3) == "ECX")
                {
                    ECX ="\0";
                    if(content[a+10] == '\'')
                    {
                        for(int b = 0;content[a+11+b] !='\'';b++)
                            ECX += content[a+11+b];
                    }

                    if(isdigit(content[a+10]))
                    {
                       for(int b = 0;content[a+10+b] != ' ';b++)
                            ECX += content[a+10+b];
                    }
                    else
                    {
                        //cout<<stringRange(content, a+9,3);
                        if (stringRange(content, a+9,3) == "EAX")
                            ECX = EAX;
                        if (stringRange(content, a+9,3) == "EBX")
                            ECX = EBX;
                        if (stringRange(content, a+9,3) == "ECX")
                            ECX = ECX;
                        if (stringRange(content, a+9,3) == "EDX")
                            ECX = EDX;
                    }
                }
                if(stringRange(content, a+4,3) == "EDX")
                {
                    EDX ="\0";
                    if(content[a+10] == '\'')
                    {
                        for(int b = 0;content[a+11+b] !='\'';b++)
                            EDX += content[a+11+b];
                    }

                    if(isdigit(content[a+10]))
                    {
                       for(int b = 0;content[a+10+b] != ' ';b++)
                            EDX += content[a+10+b];
                    }
                    else
                    {
                        //cout<<stringRange(content, a+9,3);
                        if (stringRange(content, a+9,3) == "EAX")
                            EDX = EAX;
                        if (stringRange(content, a+9,3) == "EBX")
                            EDX = EBX;
                        if (stringRange(content, a+9,3) == "ECX")
                            EDX = ECX;
                        if (stringRange(content, a+9,3) == "EDX")
                            EDX = EDX;
                    }
                }
        }
        if (stringRange(content, a, 3) == "ADD")
        {
            if(stringRange(content, a+4,3) == "EAX")
            {
                /**if (stringRange(content, a+9,3) == "EAX")
                    EAX += EAX;
                if (stringRange(content, a+9,3) == "EBX")
                    EAX += EBX;
                if (stringRange(content, a+9,3) == "ECX")
                    EAX += ECX;
                if (stringRange(content, a+9,3) == "EDX")
                    EAX += EDX;*/
            }
        }
    //cout<<EAX<<'\n';

    //cout<<ECX<<'\n';
   // cout<<EDX<<'\n';
    }
    cout<<EDX<<'\n';
    //cout<<EAX;
}
