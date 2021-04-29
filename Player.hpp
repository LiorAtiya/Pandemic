#include "Color.hpp"
#include "City.hpp"

namespace pandemic {
    class Player{
        private:


        public:
            Player drive(City c){ return *this;}
            virtual Player fly_direct(City c){return *this; }
            void fly_charter(City c){}
            void fly_shuttle(City c){}
            virtual void build(){};
            virtual void discover_cure(Color c){}
            virtual Player treat(City c){return *this; }

            //FIX RETURN
            Player role();
            Player take_card(City c){
                return *this;
            }
    };

}