#include "Player.hpp"

namespace pandemic {
    class OperationsExpert: public Player{
        private: 
            Board board;
            City city;

        public:
            // OperationsExpert(Board b, City c):board(b),city(c){};
            void build();
            // OperationsExpert take_card(City c){
            //     take_card(c);
            //     return *this;
            // }

            // OperationsExpert drive(City c){
            //     drive(c);
            //     return *this;
            // }
    };
}