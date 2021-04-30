#include "Board.hpp"
#include <fstream>
#include <sstream>
#include<iostream>

namespace pandemic {

    //// list of neighbor cities
    // map<string,map<string, bool>> neighbor_cities;

    // void read_cities(){
    //     string line;
    //     ifstream units_file{"cities_map.txt"};
    //     while (getline (units_file, line)) {
    //         istringstream city(line);
    //         string src, color, neighbor;
    //         city >> src >> color;
    //         while(city >> neighbor){
    //             neighbor_cities[src][neighbor] = true;
    //         }
    //     }

    //     // // Print the hashmap
    //     // for (auto const &pair: neighbor_cities) {
    //     //     cout << pair.first << ": ";
    //     //     for(auto const &pair2: neighbor_cities[pair.first]){
    //     //         std::cout << "{" << pair2.first << ":" << pair2.second << "},";
    //     //     }
    //     //     std::cout << '\n';
    //     // }
    // }

}