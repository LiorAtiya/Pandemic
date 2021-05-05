#include "Player.hpp"
#include "Board.hpp"
#include "City.hpp"

namespace pandemic {
    class GeneSplicer: public Player{
        
        public:
            GeneSplicer(Board b, City c){}
            Player& discover_cure(Color c){ return *this; }
            string role(){ return "GeneSplicer"; }
    };
}