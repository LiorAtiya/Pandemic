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

const City all_citis[] = {City::Santiago, City::Lima, City::MexicoCity, City::LosAngeles ,
						City::SanFrancisco, City::Chicago, City::Atlanta, City::Miami,
						City::Bogota, City::BuenosAires, City::SaoPaulo, City::Lagos,
						City::Kinshasa, City::Johannesburg, City::Khartoum, City::Cairo,
						City::Riyadh, City::Karachi, City::Mumbai, City::Chennai,
						City::Jakarta, City::Sydney, City::Manila, City::Taipei, City::Osaka,
						City::Tokyo, City::Seoul, City::Beijing, City::Shanghai, City::HongKong,
						City::HoChiMinhCity, City::Bangkok, City::Kolkata, City::Delhi,
						City::Tehran, City::Baghdad, City::Istanbul, City::Moscow, 
						City::StPetersburg, City::Essen, City::Milan, City::Paris,
						City::Algiers,City::Madrid, City::London, City::NewYork, City::Washington,
						City::Montreal};

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

}

// OperationsExpert player1 {board_game, City::Atlanta};
// Dispatcher player2 {board_game, City::Atlanta};
// Scientist player3 {board_game, City::Atlanta,4};
// Researcher player4 {board_game, City::Atlanta};
// Medic player5 {board_game, City::Atlanta};
// Virologist player6 {board_game, City::Atlanta};
// GeneSplicer player7 {board_game, City::Atlanta};
// FieldDoctor player8 {board_game, City::Atlanta};

// TEST_CASE("Player - method: take_card()"){
// 	for(City c : all_citis){
// 		CHECK_NOTHROW(player1.take_card(c));
// 		// CHECK_NOTHROW(player2.take_card(c));
// 		// CHECK_NOTHROW(player3.take_card(c));
// 		// CHECK_NOTHROW(player4.take_card(c));
// 		// CHECK_NOTHROW(player5.take_card(c));
// 		// CHECK_NOTHROW(player6.take_card(c));
// 		// CHECK_NOTHROW(player7.take_card(c));
// 		// CHECK_NOTHROW(player8.take_card(c));
// 	}
// }

// TEST_CASE("Player - method: drive()"){    

// 	//Drive around the world
// 	for(int i=1 ; i < sizeof(all_citis)/sizeof(all_citis[0]) ; i++){
//         CHECK_NOTHROW(player1.drive(all_citis[i]));
// 		// CHECK_NOTHROW(player2.drive(all_citis[i]));
// 		// CHECK_NOTHROW(player3.drive(all_citis[i]));
// 		// CHECK_NOTHROW(player4.drive(all_citis[i]));
// 		// CHECK_NOTHROW(player5.drive(all_citis[i]));
// 		// CHECK_NOTHROW(player6.drive(all_citis[i]));
// 		// CHECK_NOTHROW(player7.drive(all_citis[i]));
// 		// CHECK_NOTHROW(player8.drive(all_citis[i]));
//     }

// 	//Travel back around the world
// 	for(int i=sizeof(all_citis)/sizeof(all_citis[0])-2 ; i >= 0 ; i--){
//         CHECK_NOTHROW(player1.drive(all_citis[i]));
// 		// CHECK_NOTHROW(player2.drive(all_citis[i]));
// 		// CHECK_NOTHROW(player3.drive(all_citis[i]));
// 		// CHECK_NOTHROW(player4.drive(all_citis[i]));
// 		// CHECK_NOTHROW(player5.drive(all_citis[i]));
// 		// CHECK_NOTHROW(player6.drive(all_citis[i]));
// 		// CHECK_NOTHROW(player7.drive(all_citis[i]));
// 		// CHECK_NOTHROW(player8.drive(all_citis[i]));
//     }
	
// 	//Jump between 2 non-neighboring cities
// 	for(int i=1 ; i < sizeof(all_citis)/sizeof(all_citis[0]) ; i += 2){
// 		CHECK_THROWS(player1.drive(all_citis[i]));
// 		// CHECK_THROWS(player2.drive(all_citis[i]));
// 		// CHECK_THROWS(player3.drive(all_citis[i]));
// 		// CHECK_THROWS(player4.drive(all_citis[i]));
// 		// CHECK_THROWS(player5.drive(all_citis[i]));
// 		// CHECK_THROWS(player6.drive(all_citis[i]));
// 		// CHECK_THROWS(player7.drive(all_citis[i]));
// 		// CHECK_THROWS(player8.drive(all_citis[i]));
// 	}
// }

// TEST_CASE("Player - method: build()"){
// 	//Init all players
// 	player1 = OperationsExpert{Board(), all_citis[0]};
// 	// player2 = Dispatcher{Board(), all_citis[0]};
// 	// player3 = Scientist{Board(), all_citis[0],4};
// 	// player4 = Researcher{Board(), all_citis[0]};
// 	// player5 = Medic{Board(), all_citis[0]};
// 	// player6 = Virologist{Board(), all_citis[0]};
// 	// player7 = GeneSplicer{Board(), all_citis[0]};
// 	// player8 = FieldDoctor{Board(), all_citis[0]};

// 	for(int i=1 ; i < sizeof(all_citis)/sizeof(all_citis[0]); i++){

// 		//OperationsExpert - Can perform a "Build" operation in any 
// 		//city he is in, without throwing a suitable city card.
// 		CHECK_NOTHROW(player1.drive(all_citis[i]));
// 		CHECK_NOTHROW(player1.build());
// 		//--------------------------------------------------
// 		//Don't have a card of current place
// 		CHECK_THROWS(player2.build());
// 		// CHECK_THROWS(player3.build());
// 		// CHECK_THROWS(player4.build());
// 		// CHECK_THROWS(player5.build());
// 		// CHECK_THROWS(player6.build());
// 		// CHECK_THROWS(player7.build());
// 		// CHECK_THROWS(player8.build());

// 		CHECK_NOTHROW(player2.take_card(all_citis[i]));
// 		// CHECK_NOTHROW(player3.take_card(all_citis[i]));
// 		// CHECK_NOTHROW(player4.take_card(all_citis[i]));
// 		// CHECK_NOTHROW(player5.take_card(all_citis[i]));
// 		// CHECK_NOTHROW(player6.take_card(all_citis[i]));
// 		// CHECK_NOTHROW(player7.take_card(all_citis[i]));
// 		// CHECK_NOTHROW(player8.take_card(all_citis[i]));

// 		//Have a card of current place
// 		CHECK_NOTHROW(player2.build());
// 		// CHECK_NOTHROW(player3.build());
// 		// CHECK_NOTHROW(player4.build());
// 		// CHECK_NOTHROW(player5.build());
// 		// CHECK_NOTHROW(player6.build());
// 		// CHECK_NOTHROW(player7.build());
// 		// CHECK_NOTHROW(player8.build());

// 		CHECK_NOTHROW(player2.drive(all_citis[i]));
// 		// CHECK_NOTHROW(player3.drive(all_citis[i]));
// 		// CHECK_NOTHROW(player4.drive(all_citis[i]));
// 		// CHECK_NOTHROW(player5.drive(all_citis[i]));
// 		// CHECK_NOTHROW(player6.drive(all_citis[i]));
// 		// CHECK_NOTHROW(player7.drive(all_citis[i]));
// 		// CHECK_NOTHROW(player8.drive(all_citis[i]));
// 	}

// }

// TEST_CASE("Player - method: fly_direct()"){

// 	for(int i=1 ; i < sizeof(all_citis)/sizeof(all_citis[0]) ; i++){
// 		City fly_from = all_citis[i];
// 		player1 = OperationsExpert{board_game, fly_from};
// 		player2 = Dispatcher{board_game, fly_from};
// 		// player3 = Scientist{board_game, fly_from,4};
// 		// player4 = Researcher{board_game, fly_from};
// 		// player5 = Medic{board_game, fly_from};
// 		// player6 = Virologist{board_game, fly_from};
// 		// player7 = GeneSplicer{board_game, fly_from};
// 		// player8 = FieldDoctor{board_game, fly_from};

// 		for(int j=0 ; j < sizeof(all_citis)/sizeof(all_citis[0]) ; j++){
// 			City fly_to = all_citis[j];
// 			if(fly_from != fly_to){

// 				//Dispatcher - When in a research station, he can perform a "fly_direct" 
// 				//operation to any city he wants, without throwing a city card.
// 				CHECK_NOTHROW(player2.build());
// 				CHECK_NOTHROW(player2.fly_direct(fly_to));
// 				//Don't have a research station in this place
// 				CHECK_THROWS(player2.fly_direct(fly_from));
// 				CHECK_NOTHROW(player2.take_card(fly_from));
// 				CHECK_NOTHROW(player2.fly_direct(fly_from));
// 				//--------------------------------------------------
// 				CHECK_THROWS(player1.fly_direct(fly_to));
// 				player1.take_card(fly_to);
// 				player1.take_card(fly_from);
// 				CHECK_NOTHROW(player1.fly_direct(fly_to));
// 				CHECK_NOTHROW(player1.fly_direct(fly_from));

// 				// CHECK_THROWS(player3.fly_direct(fly_to));
// 				// player3.take_card(fly_to);
// 				// player3.take_card(fly_from);
// 				// CHECK_NOTHROW(player3.fly_direct(fly_to));
// 				// CHECK_NOTHROW(player3.fly_direct(fly_from));

// 				// CHECK_THROWS(player4.fly_direct(fly_to));
// 				// player4.take_card(fly_to);
// 				// player4.take_card(fly_from);
// 				// CHECK_NOTHROW(player4.fly_direct(fly_to));
// 				// CHECK_NOTHROW(player4.fly_direct(fly_from));

// 				// CHECK_THROWS(player5.fly_direct(fly_to));
// 				// player5.take_card(fly_to);
// 				// player5.take_card(fly_from);
// 				// CHECK_NOTHROW(player5.fly_direct(fly_to));
// 				// CHECK_NOTHROW(player5.fly_direct(fly_from));

// 				// CHECK_THROWS(player6.fly_direct(fly_to));
// 				// player6.take_card(fly_to);
// 				// player6.take_card(fly_from);
// 				// CHECK_NOTHROW(player6.fly_direct(fly_to));
// 				// CHECK_NOTHROW(player6.fly_direct(fly_from));

// 				// CHECK_THROWS(player7.fly_direct(fly_to));
// 				// player7.take_card(fly_to);
// 				// player7.take_card(fly_from);
// 				// CHECK_NOTHROW(player7.fly_direct(fly_to));
// 				// CHECK_NOTHROW(player7.fly_direct(fly_from));

// 				// CHECK_THROWS(player8.fly_direct(fly_to));
// 				// player8.take_card(fly_to);
// 				// player8.take_card(fly_from);
// 				// CHECK_NOTHROW(player8.fly_direct(fly_to));
// 				// CHECK_NOTHROW(player8.fly_direct(fly_from));
// 			}

// 		}
// 	}
// }

// TEST_CASE("Player - method: fly_charter()"){
// 	for(int i=1 ; i < sizeof(all_citis)/sizeof(all_citis[0]) ; i++){
// 		City fly_from = all_citis[i];
// 		player1 = OperationsExpert{board_game, fly_from};
// 		// player2 = Dispatcher{board_game, fly_from};
// 		// player3 = Scientist{board_game, fly_from,4};
// 		// player4 = Researcher{board_game, fly_from};
// 		// player5 = Medic{board_game, fly_from};
// 		// player6 = Virologist{board_game, fly_from};
// 		// player7 = GeneSplicer{board_game, fly_from};
// 		// player8 = FieldDoctor{board_game, fly_from};

// 		for(int j=0 ; j < sizeof(all_citis)/sizeof(all_citis[0]) ; j++){
// 			City fly_to = all_citis[j];
// 			if(fly_from != fly_to){
// 				// CHECK_THROWS(player1.fly_charter(fly_to));
// 				player1.take_card(fly_from);
// 				player1.take_card(fly_to);
// 				CHECK_NOTHROW(player1.fly_charter(fly_to));
// 				CHECK_NOTHROW(player1.fly_charter(fly_from));
				
// 				// CHECK_THROWS(player2.fly_charter(fly_to));
// 				// player2.take_card(fly_from);
// 				// player2.take_card(fly_to);
// 				// CHECK_NOTHROW(player2.fly_charter(fly_to));
// 				// CHECK_NOTHROW(player2.fly_charter(fly_from));

// 				// CHECK_THROWS(player3.fly_charter(fly_to));
// 				// player3.take_card(fly_from);
// 				// player3.take_card(fly_to);
// 				// CHECK_NOTHROW(player3.fly_charter(fly_to));
// 				// CHECK_NOTHROW(player3.fly_charter(fly_from));

// 				// CHECK_THROWS(player4.fly_charter(fly_to));
// 				// player4.take_card(fly_from);
// 				// player4.take_card(fly_to);
// 				// CHECK_NOTHROW(player4.fly_charter(fly_to));
// 				// CHECK_NOTHROW(player4.fly_charter(fly_from));

// 				// CHECK_THROWS(player5.fly_charter(fly_to));
// 				// player5.take_card(fly_from);
// 				// player5.take_card(fly_to);
// 				// CHECK_NOTHROW(player5.fly_charter(fly_to));
// 				// CHECK_NOTHROW(player5.fly_charter(fly_from));

// 				// CHECK_THROWS(player6.fly_charter(fly_to));
// 				// player6.take_card(fly_from);
// 				// player6.take_card(fly_to);
// 				// CHECK_NOTHROW(player6.fly_charter(fly_to));
// 				// CHECK_NOTHROW(player6.fly_charter(fly_from));

// 				// CHECK_THROWS(player7.fly_charter(fly_to));
// 				// player7.take_card(fly_from);
// 				// player7.take_card(fly_to);
// 				// CHECK_NOTHROW(player7.fly_charter(fly_to));
// 				// CHECK_NOTHROW(player7.fly_charter(fly_from));

// 				// CHECK_THROWS(player8.fly_charter(fly_to));
// 				// player8.take_card(fly_from);
// 				// player8.take_card(fly_to);
// 				// CHECK_NOTHROW(player8.fly_charter(fly_to));
// 				// CHECK_NOTHROW(player8.fly_charter(fly_from));
// 			}

// 		}
// 	}
// }

// TEST_CASE("Player - method: fly_shuttle()"){
// 	Board board_for_shuttle;
// 	player1 = OperationsExpert{board_for_shuttle, all_citis[0]};
// 	// player2 = Dispatcher{board_for_shuttle, all_citis[0]};
// 	// player3 = Scientist{board_for_shuttle, all_citis[0],4};
// 	// player4 = Researcher{board_for_shuttle, all_citis[0]};
// 	// player5 = Medic{board_for_shuttle, all_citis[0]};
// 	// player6 = Virologist{board_for_shuttle, all_citis[0]};
// 	// player7 = GeneSplicer{board_for_shuttle, all_citis[0]};
// 	player8 = FieldDoctor{board_for_shuttle, all_citis[0]};

// 	player1.build();

// 	for(int i=1 ; i < sizeof(all_citis)/sizeof(all_citis[0]) ; i++){
// 		//Before the build a research station
// 		// CHECK_THROWS(player2.fly_shuttle(all_citis[i]));
// 		// CHECK_THROWS(player3.fly_shuttle(all_citis[i]));
// 		// CHECK_THROWS(player4.fly_shuttle(all_citis[i]));
// 		// CHECK_THROWS(player5.fly_shuttle(all_citis[i]));
// 		// CHECK_THROWS(player6.fly_shuttle(all_citis[i]));
// 		// CHECK_THROWS(player7.fly_shuttle(all_citis[i]));
// 		CHECK_THROWS(player8.fly_shuttle(all_citis[i]));

// 		//OperationsExpert Build without throw card
// 		CHECK_NOTHROW(player1.drive(all_citis[i]));
// 		player1.build();

// 		//Fly to city with research station
// 		// CHECK_NOTHROW(player2.fly_shuttle(all_citis[i]));
// 		// CHECK_NOTHROW(player3.fly_shuttle(all_citis[i]));
// 		// CHECK_NOTHROW(player4.fly_shuttle(all_citis[i]));
// 		// CHECK_NOTHROW(player5.fly_shuttle(all_citis[i]));
// 		// CHECK_NOTHROW(player6.fly_shuttle(all_citis[i]));
// 		// CHECK_NOTHROW(player7.fly_shuttle(all_citis[i]));
// 		CHECK_NOTHROW(player8.fly_shuttle(all_citis[i]));

// 		//Back to home
// 		// CHECK_NOTHROW(player2.fly_shuttle(all_citis[0]));
// 		// CHECK_NOTHROW(player3.fly_shuttle(all_citis[0]));
// 		// CHECK_NOTHROW(player4.fly_shuttle(all_citis[0]));
// 		// CHECK_NOTHROW(player5.fly_shuttle(all_citis[0]));
// 		// CHECK_NOTHROW(player6.fly_shuttle(all_citis[0]));
// 		// CHECK_NOTHROW(player7.fly_shuttle(all_citis[0]));
// 		CHECK_NOTHROW(player8.fly_shuttle(all_citis[0]));
// 	}
// }

// void take_five_red_cards(Player& player) {
// 	player.take_card(City::Sydney)
// 	      .take_card(City::HoChiMinhCity)
// 	      .take_card(City::HongKong)
// 	      .take_card(City::Bangkok)
// 		  .take_card(City::Beijing);
// }

// void take_five_black_cards(Player& player) {
// 	player.take_card(City::Algiers)
// 	      .take_card(City::Baghdad)
// 	      .take_card(City::Cairo)
// 	      .take_card(City::Chennai)
// 		  .take_card(City::Delhi);
// }

// void take_five_blue_cards(Player& player) {
// 	player.take_card(City::Atlanta)
// 	      .take_card(City::Chicago)
// 	      .take_card(City::Essen)
// 	      .take_card(City::Johannesburg)
// 		  .take_card(City::London);
// }

// void take_five_yellow_cards(Player& player) {
// 	player.take_card(City::Bogota)
// 	      .take_card(City::BuenosAires)
// 	      .take_card(City::Lima)
// 	      .take_card(City::Lagos)
// 		  .take_card(City::LosAngeles);
// }

// TEST_CASE("Player - method: discover_cure() & treat()"){
// 	Board board_for_discover_cure;
// 	player1 = OperationsExpert{board_for_discover_cure, all_citis[0]};
// 	player2 = Dispatcher{board_for_discover_cure, all_citis[0]};
// 	player3 = Scientist{board_for_discover_cure, all_citis[0],2};
// 	player4 = Researcher{board_for_discover_cure, all_citis[0]};
// 	// player5 = Medic{board_for_discover_cure, all_citis[0]};
// 	// player6 = Virologist{board_for_discover_cure, all_citis[0]};
// 	// player7 = GeneSplicer{board_for_discover_cure, all_citis[0]};
// 	// player8 = FieldDoctor{board_for_discover_cure, all_citis[0]};

// 	for(int i=1 ; i < sizeof(all_citis)/sizeof(all_citis[0]) ; i++){
// 		//Before the build a research station
// 		CHECK_THROWS(player1.discover_cure(Color::Black));
// 		// CHECK_THROWS(player1.discover_cure(Color::Red));
// 		// CHECK_THROWS(player1.discover_cure(Color::Yellow));
// 		// CHECK_THROWS(player1.discover_cure(Color::Blue));

// 		//Researcher - Can perform a "discover_cure" operation in any city
// 		// - does not have to be at a research station
// 		take_five_black_cards(player4);
// 		CHECK_NOTHROW(player4.discover_cure(Color::Black));
// 		board_for_discover_cure.remove_cures();

// 		CHECK_NOTHROW(player1.build());
// 		//Scientist - Can perform a "discover_cure" operation using only n cards (instead of 5)
// 		//, where the parameter n is passed in the constructor.
// 		CHECK_NOTHROW(player3.take_card(City::LosAngeles).take_card(City::Lagos));
// 		CHECK_NOTHROW(player3.discover_cure(Color::Yellow));
// 		board_for_discover_cure.remove_cures();


// 		take_five_black_cards(player1);
// 		take_five_red_cards(player2);
// 		take_five_yellow_cards(player5);
// 		take_five_blue_cards(player6);
// 		take_five_black_cards(player7);
// 		take_five_red_cards(player8);

// 		CHECK_NOTHROW(player1.discover_cure(Color::Black));
// 		board_for_discover_cure.remove_cures();
// 		CHECK_NOTHROW(player2.discover_cure(Color::Red));
// 		// board_for_discover_cure.remove_cures();
// 		// CHECK_NOTHROW(player5.discover_cure(Color::Yellow));
// 		// board_for_discover_cure.remove_cures();
// 		// CHECK_NOTHROW(player6.discover_cure(Color::Blue));
// 		// board_for_discover_cure.remove_cures();
// 		// CHECK_NOTHROW(player7.discover_cure(Color::Black));
// 		// board_for_discover_cure.remove_cures();
// 		// CHECK_NOTHROW(player8.discover_cure(Color::Red));


// 		//Treat()
// 		CHECK_NOTHROW(player1.treat(all_citis[i-1]));
// 		//Don't treat again city with 0 cube disease
// 		CHECK_THROWS(player1.treat(all_citis[i-1]));
// 		board_for_discover_cure.remove_cures();

// 		//Medic - When he performs a "disease treatment" operation, 
// 		//he removes all the disease cubes from the city he is in, and not just one
// 		CHECK_NOTHROW(player1.treat(all_citis[i-1]));
// 		//Don't treat again city with 0 cube disease
// 		CHECK_THROWS(player1.treat(all_citis[i-1]));

// 		CHECK_NOTHROW(player1.drive(all_citis[i]));
// 		CHECK_NOTHROW(player2.drive(all_citis[i]));
// 		CHECK_NOTHROW(player3.drive(all_citis[i]));
// 		CHECK_NOTHROW(player4.drive(all_citis[i]));
// 		// CHECK_NOTHROW(player5.drive(all_citis[i]));
// 		// CHECK_NOTHROW(player6.drive(all_citis[i]));
// 		// CHECK_NOTHROW(player7.drive(all_citis[i]));
// 		// CHECK_NOTHROW(player8.drive(all_citis[i]));
// 	}
// }

// TEST_CASE("Player - method: role()"){
// 	CHECK(player1.role() == "OperationsExpert");
// 	CHECK(player2.role() == "Dispatcher");
// 	CHECK(player3.role() == "Scientist");
// 	CHECK(player4.role() == "Researcher");
// 	// CHECK(player5.role() == "Medic");
// 	// CHECK(player6.role() == "Virologist");
// 	// CHECK(player7.role() == "GeneSplicer");
// 	// CHECK(player8.role() == "FieldDoctor");
// }