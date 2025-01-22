// C++ implementation​​​​​​‌‌​​‌​​​​‌‌​​‌​‌​​‌‌‌‌​​‌ below
#include <iostream>
#include <cstdint>
#include <vector>
#include <deque>
#include <string>
#include <utility>

// Uncomment these macros to control whether you see
// the expected result and/or hints.
//#define showExpectedResult
//#define showHints

template <typename T> using deque = std::deque<T>;
template <typename T> using vector = std::vector<T>;
template <typename T1, typename T2> using pair = std::pair<T1, T2>;
using string = std::string;

// Enum class for operations
enum class Operation{
    ADD_FRONT,
    ADD_BACK,
    REMOVE_FRONT,
    REMOVE_BACK
};

deque<pair<string, int>> ManagePetSchedule(
        const deque<pair<string, int>>& initialActivities, 
        const vector<pair<Operation, pair<string, int>>>& operations){
    deque<pair<string, int>> schedule;
    //schedule.push_back(initialActivities);
    schedule = initialActivities;
    auto it = operations.begin();
    while(it != operations.end()){
        switch(static_cast<int>((*it).first)){
            case 0: //ADD_FRONT
            {
                schedule.push_front((*it).second);
                break;
            }
            case 1: // ADD_BACK
            {
                schedule.push_back((*it).second);
                break;
            }
            case 2: //REMOVE_FRONT
            {
                schedule.pop_front();
                break;
            }
            case 3: //REMOVE_BACK
            {
                schedule.pop_back();
                
                break;
            }
        }
        it = next(it,1);
    }
    // Write your code here.
    
    return schedule;
}

int main(){
    deque<pair<string, int>> initialActivities = {{"Photograph",20},{"Play",45},{"Sleep",60}};
    vector<pair<Operation, pair<string, int>>> operations = {
        {Operation::REMOVE_FRONT, {"", 0}}, 
        {Operation::ADD_FRONT, {"Eat", 15}}, 
        {Operation::ADD_BACK, {"Groom", 45}} 
    };

    deque<pair<string, int>> learnerResult = ManagePetSchedule(initialActivities, operations);
    for( pair<string,int>& activity : learnerResult){
        std::cout<<activity.first<<std::endl<<std::flush;
    }
    return 0;
}
