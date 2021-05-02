#pragma once
#include <map>
#include "City.hpp"
#include "Color.hpp"
#include <fstream>
#include <sstream>
#include <iostream>
using namespace std;

namespace pandemic {
    
    class Board {
        private:
            map<City, int> disease_level;
            map<City, bool> research_stations;
            //list of neighbor cities
            map<City,map<City, bool>> neighbor_cities;
            //list of cities color
            map<City,Color> cities_color;

        public:
            //Init neighbors & colors cities 
            void read_cities();

            //Getters & Setters of details maps
            map<City,bool>& get_research_stations(){ return research_stations; }
            void set_research_stations(City c){ research_stations[c] = true; }

            map<City,map<City, bool>>& get_neighbor_cities(){ return neighbor_cities; }
            map<City,Color>& get_cities_color(){ return cities_color; }

            //Operators
            int& operator[] (const City c);
            friend ostream& operator<< (ostream& os,const Board& num);

            //Checks empty disease_level map
            bool is_clean();
    };
}
