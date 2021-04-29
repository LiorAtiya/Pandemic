#pragma once
#include <map>
#include "City.hpp"
#include "Color.hpp"
using namespace std;

namespace pandemic {
    class Board {
        private:
            map<City, int> city_map;

        public:
            int& operator[] (const City c){
                return city_map[c]; 
            }

            friend ostream& operator<< (ostream& os,const Board& num){ return os; }
            
            bool is_clean(){
                for (auto const &pair: city_map) {
                    if(pair.second != 0) return false;
                }
                return true;
            }
    };
}
