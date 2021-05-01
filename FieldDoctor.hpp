#pragma once
#include "Player.hpp"
#include "Board.hpp"
#include "City.hpp"

namespace pandemic {
    class FieldDoctor: public Player{
        
        public:
            FieldDoctor(Board b, City c){}
            Player& treat(City c){ return *this; }
    };
}