#include "Player.hpp"
#include "Board.hpp"
#include "City.hpp"
#include <map>
#include <fstream>
#include <sstream>
#include<iostream>

namespace pandemic {

    //Drive from the current city to a nearby city
    Player& Player::drive(City c){
        if(board_game.get_details_of_cities()[this->current_place].neighbors.contains(c) && c != this->current_place){
            current_place = c;
        }else{
            string exp = get_board().get_City_2_string()[c] + " is not connected to " + get_board().get_City_2_string()[this->current_place];
            throw invalid_argument(exp);
        }
        return *this;
    }

    //Fly from the current city to the city of some card in his hand
    Player& Player::fly_direct(City c){
        //Input the same of current city
        if(c != this->current_place){
            //Card "c" in the player's list of cards
            if(my_cards[board_game.get_details_of_cities()[c].color].contains(c)){
                current_place = c;
                //Remove card of city from my_card
                my_cards[board_game.get_details_of_cities()[c].color].erase(c);
            }else{
                string exp = "You do not have the card " + get_board().get_City_2_string()[c];
                throw invalid_argument(exp);
            }
        }else{
            string exp = "You're already in the city of " + get_board().get_City_2_string()[c];
            throw invalid_argument(exp);
        }

        return *this;
    }

    //Fly from the current city to any city.
    Player& Player::fly_charter(City c){
        if(c != this->current_place){
            //Card "c" in the player's list of cards
            if(my_cards[board_game.get_details_of_cities()[this->current_place].color].contains(this->current_place)){
                //Remove a card of the city in which the player is from the my_cards
                my_cards[board_game.get_details_of_cities()[this->current_place].color].erase(City::Khartoum);
                current_place = c;
            }else{
                string exp = "You do not have the card of " + get_board().get_City_2_string()[this->current_place];
                throw invalid_argument(exp);
            }
        }else{
            string exp = "You're already in the city of " + get_board().get_City_2_string()[c];
            throw invalid_argument(exp);
        }

        return *this;
    }

    //If there is a research station in the current city, 
    //you can fly to any other city that has a research station
    Player& Player::fly_shuttle(City c){
        //Input the same of current city
        if(c != this->current_place){
            //There is a research station in the current city
            if(board_game.get_details_of_cities()[this->current_place].research_stations){
                //There is a research station in the city to which you want to fly
                if(board_game.get_details_of_cities()[c].research_stations){
                    this->current_place = c;
                }else{
                    string exp = "There is no research station in " + get_board().get_City_2_string()[c];
                    throw invalid_argument(exp);
                }
            }else{
                string exp = "There is no research station in " + get_board().get_City_2_string()[this->current_place];
                throw invalid_argument(exp);
            }
        }else{
            string exp = "You're already in the city of " + get_board().get_City_2_string()[c];
            throw invalid_argument(exp);
        }
        return *this;
    }

    //Builds a research station in the city in which they are located.
    Player& Player::build(){
        //There is a card of the current city
        if(my_cards[board_game.get_details_of_cities()[this->current_place].color].contains(this->current_place)){
            //If there is not yet a research station in the current city
            if(!board_game.get_details_of_cities()[this->current_place].research_stations){
                board_game.get_details_of_cities()[this->current_place].research_stations = true;
                //Remove a card of the city in which the player is from the my_cards
                my_cards[board_game.get_details_of_cities()[this->current_place].color].erase(this->current_place);
            }
        }else{
            string exp = "You do not have the card of " + get_board().get_City_2_string()[this->current_place]; 
            throw invalid_argument(exp);
        }
        return *this;
    }
    
    //Discover a cure for a disease of a certain color.
    Player& Player::discover_cure(Color c){
        //If there is a research station in the city where the player is located
        if(board_game.get_details_of_cities()[current_place].research_stations){
            //If there are 5 cards of the same color
            const int min_cards = 5;
            if(my_cards[c].size() >= min_cards){
                //If no cure for the disease has yet been discovered
                if(!board_game.get_cure_was_found()[c]){
                    
                    //Remove 5 cards from my_cards
                    int count_delete = 0;
                    for (auto it = my_cards[c].cbegin(), next_it = it; it != my_cards[c].cend(); it = next_it){
                        ++next_it;
                        if (count_delete != min_cards){
                            my_cards[c].erase(it);
                            count_delete++;
                        }else{
                            break;
                        }
                    }
                    board_game.get_cure_was_found()[c] = true;
                }
            }else{
                string exp = "You only have "+to_string(my_cards[c].size())+" "+ get_board().get_Color_2_string()[c] +" cards remaining";
                throw invalid_argument(exp);
            }
        }else{
            string exp = "There is no research station in " + get_board().get_City_2_string()[this->current_place];
            throw invalid_argument(exp);
        }   
        return *this;
    }

    //Decrease one disease cube from the city you are in.
    Player& Player::treat(City c){
        //Input the same of current city
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
                string exp = "There is no air pollution in " + get_board().get_City_2_string()[this->current_place];
                throw invalid_argument(exp);
            }
        }else{
            string exp = "You are not in " + get_board().get_City_2_string()[c];
            throw invalid_argument(exp);
        }

        return *this; 
    }

    //Taking a city card from the box cards
    Player& Player::take_card(City c){
        //Adding a card to the player's cashier
        my_cards[board_game.get_details_of_cities()[c].color].insert(c);
        return *this;
    }

    string Player::role(){ return "Player"; }

    //Remove all my_card - JUST FOR TESTS
    void Player::remove_cards(){
        my_cards.erase(Color::Black);
        my_cards.erase(Color::Yellow);
        my_cards.erase(Color::Red);
        my_cards.erase(Color::Black);
    }
}