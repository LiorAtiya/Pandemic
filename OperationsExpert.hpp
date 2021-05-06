#pragma once
#include "Player.hpp"

namespace pandemic {
    class OperationsExpert: public Player{
        private: 

        public:
            OperationsExpert(Board& b,City c):Player(b,c){}

            Player& build();
            string role();
    };
}