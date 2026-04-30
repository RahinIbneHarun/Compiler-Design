#include <iostream>
#include <fstream>
#include <string>
using namespace std;

string tokenValues[500];
string tokenTypes[500];
int tokenLines[500];
int tokenCount = 0;
string identifiers[100];
int firstLine[100];
int idCount = 0;
int keywordCount = 0;
int identifierCount = 0;
int constantCount = 0;
int operatorCount = 0;
int delimiterCount = 0;

bool isKeyword(string word) {
    if(word == "int" || word == "float" || word == "double" ||word == "char" || word == "void" || word == "if" ||word == "else" || word == "while" || word == "return") {
        return true;
    }
    return false;
}

bool isOperator(char ch) {
    if(ch == '+' || ch == '-' || ch == '*' || ch == '/' ||ch == '=' || ch == '<' || ch == '>') {
        return true;
    }
    return false;
}

bool isDelimiter(char ch) {
    if(ch == '(' || ch == ')' || ch == '{' || ch == '}' ||ch == '[' || ch == ']' || ch == ',' || ch == ';') {
        return true;
    }
    return false;
}

bool isDigit(char ch) {
    if(ch >= '0' && ch <= '9') return true;
    return false;
}

bool isLetter(char ch) {
    if((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || ch == '_') {
        return true;
    }
    return false;
}

bool isIntegerConstant(string token) {
    for(int i = 0; i < token.length(); i++) {
        if(!isDigit(token[i])) return false;
    }
    return true;
}

bool isValidIdentifier(string token) {
    if(token.length() == 0) return false;
    if(!isLetter(token[0])) return false;

    for(int i = 1; i < token.length(); i++) {
        if(!isLetter(token[i]) && !isDigit(token[i])) {
            return false;
        }
    }
    return true;
}
void addToken(string value, string type, int line) {
    tokenValues[tokenCount] = value;
    tokenTypes[tokenCount] = type;
    tokenLines[tokenCount] = line;
    tokenCount++;
}
void addToSymbolTable(string identifier, int line) {
    for(int i = 0; i < idCount; i++) {
        if(identifiers[i] == identifier) {
            return;
        }
    }
    identifiers[idCount] = identifier;
    firstLine[idCount] = line;
    idCount++;
}
void processToken(string token, int lineNo) {
    if(isKeyword(token)) {
        addToken(token, "Keyword", lineNo);
        keywordCount++;
    }
    else if(isIntegerConstant(token)) {
        addToken(token, "Integer Constant", lineNo);
        constantCount++;
    }
    else if(isValidIdentifier(token)) {
        addToken(token, "Identifier", lineNo);
        identifierCount++;
        addToSymbolTable(token, lineNo);
    }
}
int main() {
    ifstream inputFile("input.txt");
    if(!inputFile.is_open()) {
        cout << "Error: Cannot open input.txt" << endl;
        return 1;
    }

    string line;
    int lineNo = 0;
    while(getline(inputFile, line)) {
        lineNo++;
string currentToken = "";
for(int i = 0; i < line.length(); i++) {
    char ch = line[i];

    if(ch == ' ') {
    if(currentToken != "") {
    processToken(currentToken, lineNo);
    currentToken = "";
                }
    continue;
            }
    if(isOperator(ch)) {
        if(currentToken != "") {
            processToken(currentToken, lineNo);
                currentToken = "";
        }
    string op(1, ch);
        addToken(op, "Operator", lineNo);
            operatorCount++;
            continue;
    }

    if(isDelimiter(ch)) {
        if(currentToken != "") {
    processToken(currentToken, lineNo);
                currentToken = "";
            }

        string delim(1, ch);
        addToken(delim, "Delimiter", lineNo);
        delimiterCount++;
        continue;
            }

currentToken += ch;
        }

    if(currentToken != "") {
    processToken(currentToken, lineNo);
        }
    }

inputFile.close();
    ofstream tokenFile("tokens.txt");
    for(int i = 0; i < tokenCount; i++) {
        tokenFile << "Line " << tokenLines[i] << ": "<< tokenValues[i] << " -> " << tokenTypes[i] << endl;
    }
    tokenFile << "\nSummary:\n";
    tokenFile << "Keywords = " << keywordCount << endl;
    tokenFile << "Identifiers = " << identifierCount << endl;
    tokenFile << "Integer Constants = " << constantCount << endl;
    tokenFile << "Operators = " << operatorCount << endl;
    tokenFile << "Delimiters = " << delimiterCount << endl;
    tokenFile.close();
    ofstream symbolFile("symbol_table.txt");
    for(int i = 0; i < idCount; i++) {
        symbolFile << (i+1) << " " << identifiers[i] << " " << firstLine[i] << endl;
    }
    symbolFile.close();
    cout << "Done! tokens.txt and symbol_table.txt created successfully." << endl;
    cout << "Total tokens founding number : " << tokenCount << endl;
    cout << "Total identifiers number: " << idCount << endl;

    return 0;
}
