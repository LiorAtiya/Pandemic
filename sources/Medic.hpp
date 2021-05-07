#pragma once
#include "Player.hpp"

namespace pandemic {
    class Medic: public Player{
        
        public:
            Medic(Board& b, City c):Player(b,c){}
            Player& treat(City c);
            Player& drive(City c);
            Player& fly_direct(City c);
            Player& fly_charter(City c);
            Player& fly_shuttle(City c);
            string role();
    };
}