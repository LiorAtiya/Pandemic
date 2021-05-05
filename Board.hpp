#pragma once
#include <map>
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
            // map<City, int> disease_level;
            // map<City, bool> research_stations;
            // map<City,map<City, bool>> neighbor_cities;
            // map<City,Color> cities_color;
            map<City, DetailsCity> details_of_cities;

        public:
            Board(){ read_cities(); }
            //Init neighbors & colors cities 
            void read_cities();

            //Getters & Setters of details maps
            // map<City,bool>& get_research_stations(){ return research_stations; }
            // void set_research_stations(City c){ research_stations[c] = true; }

            // map<City,map<City, bool>>& get_neighbor_cities(){ return neighbor_cities; }
            // map<City,Color>& get_cities_color(){ return cities_color; }

            map<City, DetailsCity>& get_details_of_cities(){ return details_of_cities; }

            //Operators
            int& operator[] (const City c);
            friend ostream& operator<< (ostream& os,const Board& num);

            //Checks empty disease_level map
            bool is_clean();
            //Remove all discover_cure - JUST FOR TESTS
            void remove_cures();
    };
}
