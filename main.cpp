#include <iostream>
#include <fstream>
class Adress{
public:
    std::string city;
    std::string street;
    int number_house;
    int number_flat;

};

class Read{

    int cicle = 0;
public:
    void work_to_files(std::string file_in, std::string file_out){
        std::ifstream in;
        std::ofstream out;
        out.open(file_out);
        in.open(file_in);
        in >> cicle;
        Adress* adress = new Adress[cicle];
        for(int i = 0; i < cicle; i++){
            in >> adress[i].city;
            in >> adress[i].street;
            in >> adress[i].number_house;
            in >> adress[i].number_flat;
        }
        out  << cicle << "\n";
        for(int i = cicle - 1; i >= 0; i--){
            out << adress[i].city << ", ";
            out << adress[i].street << ", ";
            out << adress[i].number_house << ", ";
            out << adress[i].number_flat << "\n";
        }
        delete[] adress;
    }

};
int main() {

    Read read;
    read.work_to_files("in.txt", "out.txt");

    return 0;
}
