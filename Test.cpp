#include "doctest.h"
#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"
#include "Player.hpp"

#include "Researcher.hpp"
#include "Scientist.hpp"
#include "FieldDoctor.hpp"
#include "GeneSplicer.hpp"
#include "OperationsExpert.hpp"
#include "Dispatcher.hpp"
#include "Medic.hpp"
#include "Virologist.hpp"

#include <iostream>
#include <random>

using namespace pandemic;
using namespace std;

const City all_citis[] = {City::Algiers, 
		City::Atlanta, 
		City::Baghdad, 
		City::Bangkok, 
		City::Beijing,
		City::Bogota, 
		City::BuenosAires, 
		City::Cairo, 
		City::Chennai, 
		City::Chicago,
		City::Delhi, 
		City::Essen,
		City::HoChiMinhCity, 
		City::HongKong,
		City::Istanbul, 
		City::Jakarta, 
		City::Johannesburg,
		City::Karachi,
		City::Khartoum,
		City::Kinshasa,
		City::Kolkata,
		City::Lagos,
		City::Lima,
		City::London,
		City::LosAngeles,
		City::Madrid,
		City::Manila,
		City::MexicoCity,
		City::Miami,
		City::Milan,
		City::Montreal,
		City::Moscow,
		City::Mumbai,
		City::NewYork,
		City::Osaka,
		City::Paris,
		City::Riyadh,
		City::SanFrancisco,
		City::Santiago,
		City::SaoPaulo,
		City::Seoul,
		City::Shanghai,
		City::StPetersburg,
		City::Sydney,
		City::Taipei,
		City::Tehran,
		City::Tokyo,
		City::Washington};

Board board_game;

TEST_CASE("Checks - Disease cubes & Operator[]"){

    random_device rd; // obtain a random number from hardware
    mt19937 gen(rd()); // seed the generator
    uniform_int_distribution<> distr(1, 40); // define the range

    CHECK_FALSE(board_game.is_clean());

    for(int i= 0 ; i < sizeof(all_citis)/sizeof(all_citis[0])-1 ; i++){
        board_game[all_citis[i]] = distr(gen);
        CHECK_FALSE(board_game.is_clean());
    }

    board_game[all_citis[47]] = distr(gen);
    CHECK(board_game.is_clean());


    // for(City c : all_citis){
    //     board_game[c] = distr(gen);
    // }
}

TEST_CASE("Player - method: drive()"){

    OperationsExpert player1 {board_game, City::Atlanta};
    Dispatcher player2 {board_game, City::Atlanta};
    Scientist player3 {board_game, City::Atlanta,4};
    Researcher player4 {board_game, City::Atlanta};
    Medic player5 {board_game, City::Atlanta};
    Virologist player6 {board_game, City::Atlanta};
    GeneSplicer player6 {board_game, City::Atlanta};
    FieldDoctor player7 {board_game, City::Atlanta};
    

}

TEST_CASE("Player - method: fly_direct()"){

}

TEST_CASE("Player - method: fly_charter()"){

}

TEST_CASE("Player - method: fly_shuttle()"){

}

TEST_CASE("Player - method: build()"){

}

TEST_CASE("Player - method: discover_cure()"){

}

TEST_CASE("Player - method: treat()"){

}

TEST_CASE("Player - method: role()"){

}

TEST_CASE("Player - method: take_card()"){

}