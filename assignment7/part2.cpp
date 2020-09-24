//
// Created by sebastian on 24.09.2020.
//
# include <vector>
# include <string>

class Set{
public:
    std::vector<int> set_vector;

    Set(std::vector<int> init_vector){
    // Create unique vector;
    }
    Set operatorU(const Set &other) const {
        std::vector<int> result_vector;
        return other;
    }

    std::string str() const{
        //return std::string str(this->set_vector.begin(), this->set_vector.end());
    }

};

int main(){
    Set set1 = Set({1,2,3});
    Set set2 = Set({4,5,6});
}