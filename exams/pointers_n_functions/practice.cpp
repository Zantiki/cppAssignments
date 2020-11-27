//
// Created by sebastian on 23.11.2020.
//
#include "iostream"
#include "functional"
using namespace std;

int value_transfer(int a, int *b){
    for(auto i = 0; i < 4; i++){
        int *val = b + i;
        cout << i << ", " << *val + a << endl;
        b[i] = *val + a;
        //b = b + i;
    }
    cout << "\n" << endl;
    int *c = (b + 2);
    return *c;
}

int pointer_fun(){
    cout << "test" << endl;
    int list[10];
    list[0] = 5;
    list[1] = 3;
    int *test = list + 1;
    int *test_2 = test - 1;

    int another_one = *test_2;
    list[0] = 8;

    cout << another_one << endl;

    int &ref = another_one;
    another_one = 10;
    cout << *&ref << endl;

    int b[4];
    b[0] = 1;
    b[1] = 2;
    b[2] = 3;
    b[3] = 4;

    int c = value_transfer(2, b);

    cout << c << endl;
    return 0;
}

class List {
public:

    function<int(int*)>media3_res;

    function<int **(int*)>partition = [](int *_list) {
        int **partition_list;
        partition_list = (int **) malloc((*(&_list + 1) - _list));

        for(int i = 0; i < (*(&_list + 1) - _list) - 3; i+=3) {
            int temp_list[3] = {*(_list + 1), *(_list + 2), *(_list + 3)};
            partition_list[i] = temp_list;
            _list = _list + i;
        }

        return partition_list;
    };

    int *elements;

    List(int *_elements){
        elements = _elements;
    }

    void shit_sort(){
        cout << "Sorting" << endl;
        cout << *(elements + 1) << endl;
        int sorted[(*(&elements + 1) - elements)];
        auto *partitions = partition(elements);
        int i = 0;
        int prev_median = 0;
        while(*partitions){
            int new_median = media3_res(*partitions);

            if (prev_median > new_median){
                partitions[i] = *(partitions - 1);
                partitions[i-1]= *(partitions);
            }

            i++;
            partitions = partitions + i;
        }
        cout << **partitions << endl;
        free(partitions);


    }
};

int function_fun(){

    function<int(int*)> median_3_res = [](int *three_list){

        auto average = [](const int *list){
            return (*list + *(list + 1)) / 2;
        };

        if ( (*(&three_list + 1) - three_list) < 3){
            return average(three_list);
        }

        auto not_max_min = [](int max, int min, const int *list){
            int i = 0;
            int current = list[i];
            while (current == max || current == min){
                current = list[i];
                i++;
            }
            return current;
        };

        int max = *three_list;
        int min = *three_list;

        for(int i = 0; i < 3; i++){
            if (three_list[i] > max){
                max = three_list[i];
            }else if (three_list[i] < min){
                min = three_list[i];
            }
        }
        return not_max_min(max, min, three_list);

    };
    int elements[6];

    for (int i = 0; i < 7; i ++ ){
        elements[i] = i+3;
    }

    List list(reinterpret_cast<int *>(elements));
    list.media3_res = median_3_res;
    list.shit_sort();


    return 0;
}

int main(){
    function_fun();
    pointer_fun();
}