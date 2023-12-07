#include <iostream>
#include <string>

using namespace std;

int overload_word(string word, string find_str){
    int fs_len = find_str.length();
    int find_index = 0;
    int count = 0;

    while (word.find(find_str, find_index) != string::npos){
        find_index = word.find(find_str, find_index) + fs_len;
        count++;
    }

    return count;
}

int main(){
	string word;
    string find_str;

    getline(cin, word);
    getline(cin, find_str);

    cout << overload_word(word, find_str) << endl;
	
	return 0;
}