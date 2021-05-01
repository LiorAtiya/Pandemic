#include "Player.hpp"
#include "Board.hpp"
#include <map>
#include <fstream>
#include <sstream>
#include<iostream>

namespace pandemic {

    //convert from string to enum City
    std::map<std::string, City> string_2_City;
    //convert from string to enum Color
    std::map<std::string, Color> string_2_Color;
    //list of neighbor cities
    map<City,map<City, bool>> neighbor_cities;

    map<City,Color> cities_color;

    void convert(){
		string_2_City["Algiers"] = City::Algiers;
        //Add more...
    }

    void convert2(){
        string_2_Color["Black"] = Color::Black;
        string_2_Color["Yellow"] = Color::Yellow;
        string_2_Color["Red"] = Color::Red;
        string_2_Color["Blue"] = Color::Blue;
    }

    void read_cities(){
        convert();
        convert2();
        string line;
        ifstream units_file{"cities_map.txt"};
        while (getline (units_file, line)) {
            istringstream city(line);
            string src, color, neighbor;
            city >> src >> color;

            City s = string_2_City[src];
            Color c = string_2_Color[color];
            cities_color[s] = c;

            while(city >> neighbor){
                City n = string_2_City[neighbor];
                neighbor_cities[s][n] = true;
            }
        }

        // // Print the hashmap
        // for (auto const &pair: neighbor_cities) {
        //     cout << pair.first << ": ";
        //     for(auto const &pair2: neighbor_cities[pair.first]){
        //         std::cout << "{" << pair2.first << ":" << pair2.second << "},";
        //     }
        //     std::cout << '\n';
        // }
    }


    Player& Player::drive(City c){
        if(neighbor_cities[this->current_place][c] == 0U){
            throw invalid_argument("not connected!");
        }
        current_place = c;
        return *this;
    }

    Player& Player::fly_direct(City c){
        
        //Card "c" is not on the player's list of cards
        if(my_cards[cities_color[c]][c] == 0U){
            throw invalid_argument("not connected!");
        }
        //Change place of player and remove card of city from my_card
        current_place = c;
        my_cards[cities_color[c]].erase(c);

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
        my_cards[cities_color[c]][c] = true;
        return *this;
    }

}