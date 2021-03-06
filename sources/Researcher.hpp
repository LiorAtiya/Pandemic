#include "Player.hpp"
#include "Board.hpp"
#include "City.hpp"

namespace pandemic {
    class Researcher: public Player{
        
        public:
            Researcher(Board& b, City c):Player(b,c){}
            Player& discover_cure(Color c);
            string role();
    };
}