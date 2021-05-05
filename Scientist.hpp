#include "Player.hpp"
#include "Board.hpp"
#include "City.hpp"

namespace pandemic {
    class Scientist: public Player{
        
        public:
            Scientist(Board b, City c, int n){}
            Player& discover_cure(Color c){ return *this; }
            string role(){ return "Scientist"; }
    };
}