#pragma once
#include "Player.hpp"
#include "Board.hpp"
#include "City.hpp"

namespace pandemic {
    class Virologist: public Player{
        
        public:
            Virologist(Board& b, City c):Player(b,c){}
            // void treat();
            string role(){ return "Virologist"; }
    };
}