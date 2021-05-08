#pragma once
#include <map>
#include <unordered_map>
#include "City.hpp"
#include "Color.hpp"
#include <fstream>
#include <sstream>
#include <iostream>
using namespace std;

namespace pandemic {

    struct DetailsCity {
        DetailsCity() : disease_level(0), research_stations(false){}
        int disease_level;
        bool research_stations;
        map<City, bool> neighbors;
        Color color;
    };

    class Board {
        private:
            map<City, DetailsCity> details_of_cities;
            map<Color, bool> cure_was_found;

            map<City, string> City_2_string;
            map<Color, string> Color_2_string;

        public:
            Board(){ read_cities(); init_cure(); }
            //Init neighbors,colors,cures cities 
            void read_cities();
            void init_cure();
            void convert_reverse();

            //Getters & Setters of details maps
            map<City, DetailsCity>& get_details_of_cities(){ return details_of_cities; }
            map<Color, bool>& get_cure_was_found(){ return cure_was_found; }
            map<City, string>& get_City_2_string() { return City_2_string; }
            map<Color, string>& get_Color_2_string(){ return Color_2_string; }

            //Operators
            int& operator[] (City c);
            friend ostream& operator<< (ostream& os,Board& b);

            //Checks empty disease_level map
            bool is_clean();
            //Remove all discover_cure & stations - JUST FOR TESTS
            void remove_cures();
            void remove_stations();
    };
}