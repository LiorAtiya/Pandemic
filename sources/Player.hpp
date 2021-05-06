#pragma once
#include <string>
#include "Board.hpp"
#include "Color.hpp"
#include "City.hpp"

using namespace std;

namespace pandemic {

    class Player{
        private:
            City current_place;
            map<Color, map<City,bool>> my_cards;
            Board& board_game;

        public:
            Player(Board& b, City c):board_game(b),current_place(c){}

            Board& get_board(){ return board_game; }
            City get_current_place(){ return current_place; }
            void set_current_place(City c){ current_place = c; }
            map<Color, map<City,bool>>& get_my_cards(){ return my_cards; }

            //Actions of player
            Player& drive(City c);
            virtual Player& fly_direct(City c);
            Player& fly_charter(City c);
            Player& fly_shuttle(City c);
            virtual Player& build();
            virtual Player& discover_cure(Color c);
            virtual Player& treat(City c);
            Player& take_card(City c);
            
            //Role of player
            virtual string role();
            //Remove all my_card - JUST FOR TESTS
            void remove_cards();
    };

}