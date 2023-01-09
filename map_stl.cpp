#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {

    map<string, int> marksMap;

    //insertion in map 1st method
    marksMap["Harry"] = 98;
    marksMap["Arvind"] = 54;
    marksMap["Rohan"] = 23;

    //2nd method of insertion in map
    marksMap.insert({{"Kozume", 67}, {"Kuro", 23}});

    //iterating the map
    map<string, int> :: iterator iter;
    for(iter = marksMap.begin(); iter!=marksMap.end(); iter++){
        cout<<(*iter).first<<" "<< (*iter).second<<endl;
    }

    //size of map
    cout<<"The size is "<<marksMap.size()<<endl;
    cout<<"The max size is "<<marksMap.max_size()<<endl;

    return 0;
}