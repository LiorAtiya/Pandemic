#pragma once
#include <string>
#include "Board.hpp"
#include "Color.hpp"
#include "City.hpp"

using namespace std;


namespace pandemic {
    void convert();
    void read_cities();
    class Player{
        private:
            City current_place;
            map<Color, map<City,bool>> my_cards;

        public:
            Player(){read_cities(); }
            City get_current_place(){ return this->current_place; }
            void set_current_place(City c){this->current_place = c; }

            Player& drive(City c);
            virtual Player& fly_direct(City c);
            void fly_charter(City c){}
            void fly_shuttle(City c){}
            virtual void build(){};
            virtual void discover_cure(Color c){}
            virtual Player treat(City c){return *this; }

            string role(){return ""; }
            Player& take_card(City c);
    };

}