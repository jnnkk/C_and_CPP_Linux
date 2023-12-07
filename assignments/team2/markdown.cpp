#include <iostream>
#include <string>

using namespace std;

string makeHTMLTag(string tag, string content) {
    return "<" + tag + ">" + content + "</" + tag + ">";
}

string makeHTMLTag(string tag1, string tag2, string content) {
    content = makeHTMLTag(tag2, content);
    return makeHTMLTag(tag1, content);
}

string honetag(string content) {
    return makeHTMLTag("h1", content);
}

string htwotag(string content) {
    return makeHTMLTag("h2", content);
}

string hthreetag(string content) {
    return makeHTMLTag("h3", content);
}

string litag(string content) {
    return makeHTMLTag("li", content);
}

string ptag(string content) {
    return makeHTMLTag("p", content);
}


int main() {
    bool isOrder = false;
    bool isUnorder = false;

    while (true)
    {
        string input;
        getline(cin, input);
        if (input == "") {
            if (isOrder == true)
            {
                isOrder = false;
                cout << "</ol>";
            }
            else if (isUnorder == true)
            {
                isUnorder = false;
                cout << "</ul>";
            }
            break;
        }
            

        if (input.find(". ") != string::npos)
        {
            if (isOrder == false)
            {
                isOrder = true;
                cout << "<ol>" << endl;
            }
        }
        else if (input[0] == '*' && input[1] == ' ')
        {
            if (isUnorder == false)
            {
                isUnorder = true;
                cout << "<ul>" << endl;
            }
        }
        else
        {
            if (isOrder == true)
            {
                isOrder = false;
                cout << "</ol>" << endl;
            }
            else if (isUnorder == true)
            {
                isUnorder = false;
                cout << "</ul>" << endl;
            }
        }

        
        
        if (input[0] == '#' && input[1] == ' ') {
            input = input.substr(2);
            cout << honetag(input) << endl;
        }
        else if (input[1] == '#' && input[2] == ' ')
        {
            input = input.substr(3);
            cout << htwotag(input) << endl;
        }
        else if (input[2] == '#' && input[3] == ' ')
        {
            input = input.substr(4);
            cout << hthreetag(input) << endl;
        }
        else if (input.find(". ") != string::npos)
        {
            input = input.substr(input.find(". ") + 2);
            cout << litag(input) << endl;
        }
        else if (input[0] == '*' && input[1] == ' ')
        {
            input = input.substr(2);
            cout << litag(input) << endl;
        }
        else if (input.find("---") != string::npos && input.find(" ") == string::npos)
        {
            cout << "<hr />" << endl;
        }
        else
        {
            cout << ptag(input) << endl;
        }
    }
}