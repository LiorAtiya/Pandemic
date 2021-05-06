#include "Player.hpp"
#include "Board.hpp"
#include <map>
#include <fstream>
#include <sstream>
#include<iostream>

namespace pandemic {
    
    Player& Player::drive(City c){
        if(board_game.get_details_of_cities()[this->current_place].neighbors.count(c)){
            current_place = c;
        }else{
            throw invalid_argument("Non-neighboring cities!");
        }
        return *this;
    }

    Player& Player::fly_direct(City c){

        //Card "c" in the player's list of cards
        if(my_cards[board_game.get_details_of_cities()[c].color][c] != 0U){
            current_place = c;
            //Remove card of city from my_card
            my_cards[board_game.get_details_of_cities()[c].color].erase(c);
        }else{
            throw invalid_argument("You do not have the card of this city!");
        }

        return *this;
    }

    Player& Player::fly_charter(City c){

        //Card "c" in the player's list of cards
        if(my_cards[board_game.get_details_of_cities()[this->current_place].color][this->current_place] != 0U){
            //Remove a card of the city in which the player is from the my_cards
            my_cards[board_game.get_details_of_cities()[this->current_place].color].erase(City::Khartoum);
            current_place = c;
        }else{
            throw invalid_argument("You do not have the card of this city!");
        }

        return *this;
    }

    Player& Player::fly_shuttle(City c){

        if(board_game.get_details_of_cities()[this->current_place].research_stations){
            if(board_game.get_details_of_cities()[c].research_stations){
                this->current_place = c;
            }else{
                throw invalid_argument("There is no research station in the city to which you want to fly!");
            }
        }else{
            throw invalid_argument("There is no research station in the current city!");
        }
        return *this;
    }

    Player& Player::build(){
        //There is a card of the current city
        if(my_cards[board_game.get_details_of_cities()[this->current_place].color].count(this->current_place)){
            //If there is not yet a research station in the current city
            if(!board_game.get_details_of_cities()[this->current_place].research_stations){
                board_game.get_details_of_cities()[this->current_place].research_stations = true;
                //Remove a card of the city in which the player is from the my_cards
                my_cards[board_game.get_details_of_cities()[this->current_place].color].erase(this->current_place);
            }
        }else{
            throw invalid_argument("you do not have the card of this city!");
        }
        return *this;
    }
    
    Player& Player::discover_cure(Color c){
        //If there is a research station in the city where the player is located
        if(board_game.get_details_of_cities()[current_place].research_stations){
            //If there are 5 cards of the same color
            if(my_cards[c].size() >= 5){
                //If no cure for the disease has yet been discovered
                if(!board_game.get_cure_was_found()[c]){
                    
                    //Remove 5 cards from my_cards
                    int count_delete = 0;
                    for (auto it = my_cards[c].cbegin(), next_it = it; it != my_cards[c].cend(); it = next_it){
                        ++next_it;
                        if (count_delete != 5){
                            my_cards[c].erase(it);
                            count_delete++;
                        }else{
                            break;
                        }
                    }
                    board_game.get_cure_was_found()[c] = true;

                }else{
                    throw invalid_argument("A cure for the disease has already been discovered!");
                }
            }else{
                throw invalid_argument("You do not have 5 cards of the same color!");
            }
        }else{
            throw invalid_argument("There is no research station in the current city!");
        }   
        return *this;
    }


    Player& Player::treat(City c){
    
        if(this->current_place == c){
            //If there is a disease in the current city
            if(board_game.get_details_of_cities()[this->current_place].disease_level > 0){
                //If there was a "discover_cure" in the current city
                if(board_game.get_cure_was_found()[board_game.get_details_of_cities()[c].color]){
                    board_game[this->current_place] = 0;
                }else{
                    board_game[this->current_place]--;
                }
            }else{
                throw invalid_argument("There is no air pollution in the current city!");
            }
        }else{
            throw invalid_argument("You are not in the city of input!");
        }

        return *this; 
    }

    Player& Player::take_card(City c){
        //Adding a card to the player's cashier
        my_cards[board_game.get_details_of_cities()[c].color][c] = true;
        return *this;
    }

}