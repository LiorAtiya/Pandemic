#include "Player.hpp"
#include "Board.hpp"
#include <map>
#include <fstream>
#include <sstream>
#include<iostream>

namespace pandemic {

    Player& Player::drive(City c){
        if(get_board().get_neighbor_cities()[this->current_place][c] == 0U){
            throw invalid_argument("not connected!");
        }
        current_place = c;
        return *this;
    }

    Player& Player::fly_direct(City c){
        
        //Card "c" is not on the player's list of cards
        if(my_cards[get_board().get_cities_color()[c]][c] == 0U){
            throw invalid_argument("not connected!");
        }
        //Change place of player and remove card of city from my_card
        current_place = c;
        my_cards[get_board().get_cities_color()[c]].erase(c);

        return *this;
    }

    Player& Player::fly_charter(City c){
        return *this;
    }

    Player& Player::fly_shuttle(City c){
        if(board_game.get_research_stations()[current_place]){
            this->current_place = c;
        }
        return *this;
    }

    Player& Player::build(){
        board_game.set_research_stations(current_place);
        return *this;
    }
    
    Player& Player::discover_cure(Color c){
        // //If there is a research station in the city where the player is located
        // if(board_game.get_research_stations()[current_place]){
        //     //If there are 5 cards of the same color
        //     if(my_cards[c].size() >= 5){

        //     }
        // }
        return *this;
    }
    Player& Player::treat(City c){
        return *this; 
    }

    string role(){
        return ""; 
    }

    Player& Player::take_card(City c){

        //Adding a card to the player's cashier
        my_cards[get_board().get_cities_color()[c]][c] = true;
        return *this;
    }

}