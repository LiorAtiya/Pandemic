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
            Board board_game;

        public:
            //Get & Set of the board game
            Board& get_board(){ return board_game; }
            void set_board(Board& b){ board_game = b; }

            City get_current_place(){ return current_place; }
            void set_current_place(City c){ current_place = c; }

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
            virtual string role() = 0;
    };

}