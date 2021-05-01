#pragma once
#include <map>
#include "City.hpp"
#include "Color.hpp"
#include <fstream>
#include <sstream>
#include <iostream>
using namespace std;

namespace pandemic {

    // void read_cities();
    
    class Board {
        private:
            map<City, int> disease_level;
            map<City, bool> research_stations;

        public:
            // Board(){ read_cities(); }

            map<City,bool>& get_research_stations(){
                return research_stations;
            }

            void set_research_stations(City c){
                research_stations[c] = true;
            }

            int& operator[] (const City c){
                return disease_level[c]; 
            }

            friend ostream& operator<< (ostream& os,const Board& num){ return os; }
            
            bool is_clean(){
                for (auto const &pair: disease_level) {
                    if(pair.second != 0) return false;
                }
                return true;
            }
    };
}
