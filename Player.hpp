
namespace pandemic {
    class Player{
        private:


        public:
            void drive(City c);
            virtual void fly_direct(City c);
            void fly_charter(City c);
            void fly_shuttle(City c);
            virtual void build();
            virtual void discover_cure(Color c);
            virtual void treat(City c);

            //FIX RETURN
            void role();
            void take_card(City c);
    };

}