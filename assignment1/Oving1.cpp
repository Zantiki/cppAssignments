//
// Created by sebastian on 17.08.2020.
//


#include <iostream>
#include <fstream>

using namespace std;

void read_temperatures(double temps[], int length){
    const char filename[] = "/home/sebastian/CLionProjects/cppAssignments/assignment1/temps.dat";
    ifstream data_file;
    data_file.open(filename);

    string line;
    int i = 0;

    if (!data_file) {
        cout << "Error on reading file." << endl;
        
    }
    double number;
    while (data_file >> number) {
        if(i > length-1) break;
        temps[i] = number;
        i++;
    }
    data_file.close();

}


int main(){
    const int period_length = 5;
    double temps[period_length];
    int input_count = 0;
    char mode;
    cout << "Read data from file? y/n ";
    cin >> mode;

    if(mode == 'y'){
        read_temperatures(temps, period_length);
    }else{
        while(input_count < period_length){
            int cur_temp = 0;
            cout << "Write temp nr " << input_count+1 << ": ";
            cin >> cur_temp;
            temps[input_count] = cur_temp;
            input_count++;
        }
    }


    int sub_ten_count = 0;
    int between_ten_twenty = 0;
    int over_twenty = 0;

    for(int i = 0; i < period_length; i++){
        if(temps[i] < 10) {
            sub_ten_count++;
            continue;
        }
        if(temps[i] >= 10 && temps[i] <= 20 ){
            between_ten_twenty++;
            continue;
        }
        if(temps[i] > 20){
            over_twenty++;
            continue;
        }
    }

    cout << sub_ten_count << " Numbers below ten." << endl;
    cout << between_ten_twenty << " Numbers between ten and twenty." << endl;
    cout << over_twenty << " Numbers above twenty." << endl;



}