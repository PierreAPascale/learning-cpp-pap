#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <fstream>
struct Cat {
    std::string name;
    std::string color;
    int age;
    int weight;
    Cat(std::string n = "", std::string c = "", int a =0, int w=0) : name(n), color(c), age(a), weight(w) {}
    //Cat(std::string n, std::string c, int a, int w) : name(std::move(n)), color(std::move(c)), age(a), weight(w) {}
};

void too_many_cats() {
  Cat houseCats[] = {{"Meowmix",    "black", 9, 12},
                     {"Thundercat", "grey",  4, 16}};
  std::cout << houseCats[0].name << std::endl;
  std::cout << houseCats[1].name << std::endl;
}

void write_file(const char *str) {
    char* buff = new char[12]; //c style string
    std::strncpy(buff, str,sizeof(buff)-2);
    buff[(sizeof(buff)-1)]= ('\0'); //End of string
    
    std::ofstream outFile;
    outFile.open("out.txt");

    if (outFile.fail())
        std::cout << "Issue encountered opening file"<<std::endl;

    else{
        std::string str(buff);
        outFile << str;
    }
    delete[] buff;
    outFile.close();
}

void vector_check() {
    std::vector<int> items;
    items.push_back(1);
    items.push_back(2);
    items.push_back(3);
    std::vector<int> filtered;
    std::copy_if(items.begin(),items.end(), back_inserter(filtered), [](int x){return x!=2;});
    /*
    std::vector<int>::iterator iter;
    for (iter = items.begin(); iter != items.end(); ++iter) {
        if (*iter == 2) {
        items.erase(iter);
        }
        
    }
    */
    auto it = filtered.begin();
    while (it != filtered.end()){
        std::cout<< *it << std::endl;
        it = std::next(it,1);
    }
}

int main() {
  too_many_cats();
  write_file(static_cast<const char *>("Hello World"));
  vector_check();
}
