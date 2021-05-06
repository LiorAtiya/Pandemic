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
        DetailsCity() : disease_level(0), research_stations(false), discover_cure(false){}
        int disease_level;
        bool research_stations;
        bool discover_cure;
        map<City, bool> neighbors;
        Color color;
    };

    class Board {
        private:
            map<City, DetailsCity> details_of_cities;
            map<Color, bool> cure_was_found;

        public:
            Board(){ read_cities(); init_cure(); }
            //Init neighbors & colors cities 
            void read_cities();
            void init_cure();

            //Getters & Setters of details maps
            map<City, DetailsCity>& get_details_of_cities(){ return details_of_cities; }
            map<Color, bool>& get_cure_was_found(){ return cure_was_found; }
            //Operators
            int& operator[] (City c);
            friend ostream& operator<< (ostream& os,Board& b);

            //Checks empty disease_level map
            bool is_clean();
            //Remove all discover_cure - JUST FOR TESTS
            void remove_cures();
    };
}
