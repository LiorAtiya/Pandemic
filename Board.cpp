#include "Board.hpp"
#include <fstream>
#include <sstream>
#include<iostream>

namespace pandemic {

    int& Board::operator[] (City c){ return details_of_cities[c].disease_level; }
    // int pandemic::Board::operator[] (pandemic::City c) const {return details_of_cities.at(c).disease_level; }

    ostream& operator<< (ostream& os,const Board& num){ return os; }

    bool Board::is_clean(){
        for (auto const &pair: details_of_cities) {
            cout << pair.second.disease_level << " ";
            if(pair.second.disease_level != 0) return false;
        }
        return true;
    }

    void Board::remove_cures(){

    }


    //convert from string to enum City
    std::map<std::string, City> string_2_City;
    //convert from string to enum Color
    std::map<std::string, Color> string_2_Color;

    void convert(){
		string_2_City["Algiers"] = City::Algiers;
        string_2_City["Atlanta"] = City::Atlanta;
        string_2_City["Baghdad"] = City::Baghdad;
        string_2_City["Bangkok"] = City::Bangkok;
        string_2_City["Beijing"] = City::Beijing;
        string_2_City["Bogota"] = City::Bogota;
        string_2_City["BuenosAires"] = City::BuenosAires;
        string_2_City["Cairo"] = City::Cairo;
        string_2_City["Chennai"] = City::Chennai;
        string_2_City["Chicago"] = City::Chicago;
        string_2_City["Delhi"] = City::Delhi;
        string_2_City["Essen"] = City::Essen;
        string_2_City["HoChiMinhCity"] = City::HoChiMinhCity;
        string_2_City["HongKong"] = City::HongKong;
        string_2_City["Istanbul"] = City::Istanbul;
        string_2_City["Jakarta"] = City::Jakarta;
        string_2_City["Johannesburg"] = City::Johannesburg;
        string_2_City["Karachi"] = City::Karachi;
        string_2_City["Khartoum"] = City::Khartoum;
        string_2_City["Kinshasa"] = City::Kinshasa;
        string_2_City["Kolkata"] = City::Kolkata;
        string_2_City["Lagos"] = City::Lagos;
        string_2_City["Lima"] = City::Lima;
        string_2_City["London"] = City::London;
        string_2_City["LosAngeles"] = City::LosAngeles;
        string_2_City["Madrid"] = City::Madrid;
        string_2_City["Manila"] = City::Manila;
        string_2_City["MexicoCity"] = City::MexicoCity;
        string_2_City["Miami"] = City::Miami;
        string_2_City["Milan"] = City::Milan;
        string_2_City["Montreal"] = City::Montreal;
        string_2_City["Moscow"] = City::Moscow;
        string_2_City["Mumbai"] = City::Mumbai;
        string_2_City["NewYork"] = City::NewYork;
        string_2_City["Osaka"] = City::Osaka;
        string_2_City["Paris"] = City::Paris;
        string_2_City["Riyadh"] = City::Riyadh;
        string_2_City["SanFrancisco"] = City::SanFrancisco;
        string_2_City["Santiago"] = City::Santiago;
        string_2_City["SaoPaulo"] = City::SaoPaulo;
        string_2_City["Seoul"] = City::Seoul;
        string_2_City["Shanghai"] = City::Shanghai;
        string_2_City["StPetersburg"] = City::StPetersburg;
        string_2_City["Sydney"] = City::Sydney;
        string_2_City["Taipei"] = City::Taipei;
        string_2_City["Tehran"] = City::Tehran;
        string_2_City["Tokyo"] = City::Tokyo;
        string_2_City["Washington"] = City::Washington;
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

            details_of_cities[s].color = c;
            // cities_color[s] = c;

            while(city >> neighbor){
                City n = string_2_City[neighbor];
                details_of_cities[s].neighbors[n] = true;
                // neighbor_cities[s][n] = true;
            }
        }

        // // Print the hashmap
        // for (auto const &pair: get_details_of_cities()) {
        //     cout << "City: " << ": ";
        //     for(auto const &pair2: get_details_of_cities()[pair.first].neighbors){
        //         std::cout << "{neib} ";
        //     }
        //     std::cout << '\n';
        // }
    }

}
