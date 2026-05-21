#include <iostream>
#include <fstream>
#include <string>
#include <cctype>

using namespace std;

bool isIdentifier(string s)
{
    if (s.empty()) return false;
    if (!(isalpha(s[0]) || s[0] == '_')) return false;
    for (int i = 1; i < s.length(); i++)
    {
    if (!(isalnum(s[i])||s[i] == '_')) return false;
    }
    return true;
}
bool isVariable(string line)
{
    string type, id;
    int pos = line.find(' ');
    if (pos == -1) return false;
    type = line.substr(0, pos);
    id = line.substr(pos + 1);

    if (id.back() != ';') return false;
    id.pop_back();

    if (!(type == "int" || type == "float" || type == "double" || type == "char"))
        return false;

    return isIdentifier(id);
}
bool isFunction(string line)
{
    string type;
    int pos = line.find(' ');
    if (pos == -1) return false;
    type = line.substr(0, pos);
    string rest = line.substr(pos + 1);
if (!(type == "int" || type == "float" || type == "double" || type == "char" || type == "void"))
        return false;

int p1 = rest.find('(');
int p2 = rest.find(')');

    if (p1 == -1 ||p2 ==-1) return false;

    string fname = rest.substr(0, p1);

    if (rest.substr(p1) != "();") return false;

    return isIdentifier(fname);
}
int main()
{
    ifstream input("input.txt");
    ofstream report("report.txt");
    ofstream valid("valid_code.txt");

    if (!input.is_open())
    {
        cout << "input.txt open korte problem!" << endl;
        return 1;
    }
    string line;
    int lineNo = 0;
    int varCount = 0, funCount = 0, invalid = 0;

    while (getline(input, line))
    {
        lineNo++;
if (isVariable(line))
        {
            report << "Line " << lineNo << ": Variable Declaration\n";
            valid << line << endl;
            varCount++;
        }
    else if (isFunction(line))
        {
        report << "Line " << lineNo << ": Function Declaration\n";
        valid << line << endl;
        funCount++;
        }
    else
        {
        report << "Line " << lineNo << ": Invalid\n";
        invalid++;
        }
    }
    report << "\nSummary:\n";
    report << "Total lines = " << lineNo << endl;
    report << "Variable Declarations = " << varCount << endl;
    report << "Function Declarations = " << funCount << endl;
    report << "Invalid = " << invalid << endl;
    input.close();
    report.close();
    valid.close();
    cout << "report.txt and valid_code.txt successfully created!" << endl;
    return 0;
}
