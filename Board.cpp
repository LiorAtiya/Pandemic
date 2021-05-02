#include "Board.hpp"
#include <fstream>
#include <sstream>
#include<iostream>

namespace pandemic {


    int& Board::operator[] (const City c){ return disease_level[c]; }
    ostream& operator<< (ostream& os,const Board& num){ return os; }

    bool Board::is_clean(){
        for (auto const &pair: disease_level) {
            if(pair.second != 0) return false;
        }
        return true;
    }






    //convert from string to enum City
    std::map<std::string, City> string_2_City;
    //convert from string to enum Color
    std::map<std::string, Color> string_2_Color;

    void convert(){
		string_2_City["Algiers"] = City::Algiers;
        //Add more...
    }

    void convert2(){
        string_2_Color["Black"] = Color::Black;
        string_2_Color["Yellow"] = Color::Yellow;
        string_2_Color["Red"] = Color::Red;
        string_2_Color["Blue"] = Color::Blue;
    }

    void Board::read_cities(){
        convert();
        convert2();
        string line;
        ifstream units_file{"cities_map.txt"};
        while (getline (units_file, line)) {
            istringstream city(line);
            string src, color, neighbor;
            city >> src >> color;

            City s = string_2_City[src];
            Color c = string_2_Color[color];
            cities_color[s] = c;

            while(city >> neighbor){
                City n = string_2_City[neighbor];
                neighbor_cities[s][n] = true;
            }
        }

        // // Print the hashmap
        // for (auto const &pair: neighbor_cities) {
        //     cout << pair.first << ": ";
        //     for(auto const &pair2: neighbor_cities[pair.first]){
        //         std::cout << "{" << pair2.first << ":" << pair2.second << "},";
        //     }
        //     std::cout << '\n';
        // }
    }

}