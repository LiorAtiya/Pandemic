#include "Player.hpp"
#include "Board.hpp"
#include "City.hpp"

namespace pandemic {
    class Medic: public Player{
        
        public:
            Medic(Board b, City c){}
            Player treat(City c){ return *this; }
    };
}