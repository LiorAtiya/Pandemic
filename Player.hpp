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

            Board board_game;
            Player& drive(City c);
            virtual Player& fly_direct(City c);
            Player& fly_charter(City c);
            Player& fly_shuttle(City c);
            virtual Player& build();
            virtual Player& discover_cure(Color c);
            virtual Player& treat(City c);

            string role();
            Player& take_card(City c);
    };

}