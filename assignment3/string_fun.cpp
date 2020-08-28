//
// Oppgave 5
// Created by sebastian on 27.08.2020.
//

#include <iostream>
#include <string>

using namespace std;

int main(){
    string word1;
    string word2;
    string word3;
    cout << "Write three words" << endl;
    cin >> word1;
    cin >> word2;
    cin >> word3;

    string sentence = word1 + " " + word2 + " " +word3 + ".";
    cout << sentence << endl;

    cout << "word1: " << word1.length() << endl;
    cout << "word2: " << word2.length() << endl;
    cout << "word3: " << word3.length() << endl;
    cout << "sentence: " << sentence.length() << endl;
    string sentence2 = sentence;


    if (sentence.length() < 13){
        cout << "sentence too short for changing char 10-12" << endl;
        return 1;
    }

    for(int i = 10; i < 13; i++ ){
        sentence2[i] = 'x';
    }
    sentence2[10] = 'x';
    cout << "sentence: " << sentence << endl;
    cout << "sentence2: " << sentence2 << endl;

    if (sentence.length() < 6){
        cout << "sentence too short for storing char 0-5" << endl;
        return 1;
    }

    string sentence_start = sentence.substr(0, 5);
    cout << "sentence: " << sentence << endl;
    cout << "sentence_start: " << sentence_start << endl;

    if (sentence.find_first_of("hallo") > -1){
        cout << "sentence has no occurrences of 'hallo'" << endl;
    }else{
        cout << "sentence has occurrences of 'hallo'" << endl;
    }

    int sub_str_reference = sentence.find("er");
    int found_instances = 0;

    while(sub_str_reference > -1){
        found_instances++;
        sentence.erase(sub_str_reference, 2);
        sub_str_reference = sentence.find("er");
    }

    cout << "Found " << found_instances << " instances of 'er' in sentence" << endl;

    return 0;
}
