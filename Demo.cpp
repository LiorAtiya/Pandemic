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
#include <string>

using namespace pandemic;

#include <iostream>
#include <stdexcept>
using namespace std;

void init_disease(Board& board){
    board[City::Algiers] = 5;
    board[City::Atlanta] = 5;
    board[City::Baghdad] = 5;
    board[City::Bangkok] = 5;
    board[City::Beijing] = 5;
    board[City::Bogota] = 5;
    board[City::BuenosAires] = 5;
    board[City::Cairo] = 5;
    board[City::Chennai] = 5;
    board[City::Chicago] = 5;
    board[City::Delhi] = 5;
    board[City::Essen] = 5;
    board[City::HoChiMinhCity] = 5;
    board[City::HongKong] = 5;
    board[City::Istanbul] = 5;
    board[City::Jakarta] = 5;
    board[City::Johannesburg] = 5;
    board[City::Karachi] = 5;
    board[City::Khartoum] = 5;
    board[City::Kinshasa] = 5;
    board[City::Kolkata] = 5;
    board[City::Lagos] = 5;
    board[City::Lima] = 5;
    board[City::London] = 5;
    board[City::LosAngeles] = 5;
    board[City::Madrid] = 5;
    board[City::Manila] = 5;
    board[City::MexicoCity] = 5;
    board[City::Miami] = 5;
    board[City::Milan] = 5;
    board[City::Montreal] = 5;
    board[City::Moscow] = 5;
    board[City::Mumbai] = 5;
    board[City::NewYork] = 5;
    board[City::Osaka] = 5;
    board[City::Paris] = 5;
    board[City::Riyadh] = 5;
    board[City::SanFrancisco] = 5;
    board[City::Santiago] = 5;
    board[City::SaoPaulo] = 5;
    board[City::Seoul] = 5;
    board[City::Shanghai] = 5;
    board[City::StPetersburg] = 5;
    board[City::Sydney] = 5;
    board[City::Taipei] = 5;
    board[City::Tehran] = 5;
    board[City::Tokyo] = 5;
    board[City::Washington] = 5;
}

int main()
{
    Board b;
    Player p{b, City::NewYork};
    string city;
    string color;
    City c;
    Color co;

    bool end = false;
    while (!end)
    {
        cout << "\nWhat role of player would you like to be?\n" << endl;
        cout << "1 - Researcher"
             << endl;
        cout << "2 - Scientist"
             << endl;
        cout << "3 - FieldDoctor"
             << endl;
        cout << "4 - GeneSplicer"
             << endl;
        cout << "5 - OperationsExpert"
             << endl;
        cout << "6 - Dispatcher"
             << endl;
        cout << "7 - Medic"
             << endl;
        cout << "8 - Virologist"
             << endl;
        cout << "9 - Exit"
             << endl;
        cout << "Enter a number: ";
        int role;
        cin >> role;

        Board board;
        init_disease(board);
        bool again = false;

        switch (role)
        {
        case 1:
            p = Researcher(board, City::NewYork);
            break;
        case 2:
            p = Scientist{board, City::NewYork, 4};
            break;
        case 3:
            p = FieldDoctor{board, City::NewYork};
            break;
        case 4:
            p = GeneSplicer{board, City::NewYork};
            break;
        case 5:
            p = OperationsExpert{board, City::NewYork};
            break;
        case 6:
            p = Dispatcher{board, City::NewYork};
            break;
        case 7:
            p = Medic{board, City::NewYork};
            break;
        case 8:
            p = Virologist{board, City::NewYork};
            break;
        case 9:
            end = true;
            break;
        default:
            cout << "Invalid input";
            again = true;
            break;
        }

        if (!again && !end)
        {
            bool changed = false;
            while (!changed)
            {
                cout << "\nWhat would you like to do?\n"
                     << endl;
                cout << "1 - Drive to a neighboring city"
                     << endl;
                cout << "2 - Fly direct to another city"
                     << endl;
                cout << "3 - Fly charter to another city"
                     << endl;
                cout << "4 - Fly shuttle to another city with a research station"
                     << endl;
                cout << "5 - Build a research station"
                     << endl;
                cout << "6 - Discover cure for a disease of a certain color"
                     << endl;
                cout << "7 - Treat in disease"
                     << endl;
                cout << "8 - Take card"
                     << endl;
                cout << "9 - Role player"
                     << endl;
                cout << "10 - Another role"
                     << endl;
                cout << "Enter a number: ";
                int method;
                cin >> method;

                switch (method)
                {
                case 1:
                    cout << "Enter city to drive: ";
                    cin >> city;
                    if(b.get_string_2_City().count(city)){
                        c = b.get_string_2_City()[city];
                    }else{
                        break;
                    }
                    try {
                        p.drive(c);
                    }
                    catch(const std::exception& e) {
                        std::cerr << e.what() << '\n';
                    }
                    break;
                case 2:
                    cout << "Enter city to fly direct: ";
                    cin >> city;
                    if(b.get_string_2_City().count(city)){
                        c = b.get_string_2_City()[city];
                    }else{
                        break;
                    }
                    try {
                        p.fly_direct(c);
                    }
                    catch(const std::exception& e) {
                        std::cerr << e.what() << '\n';
                    }
                    break;
                case 3:
                    cout << "Enter city to fly charter: ";
                    cin >> city;
                    if(b.get_string_2_City().count(city)){
                        c = b.get_string_2_City()[city];
                    }else{
                        break;
                    }
                    try {
                        p.fly_charter(c);
                    }
                    catch(const std::exception& e) {
                        std::cerr << e.what() << '\n';
                    }
                    break;
                case 4:
                     cout << "Enter city to fly shuttle: ";
                    cin >> city;
                    if(b.get_string_2_City().count(city)){
                        c = b.get_string_2_City()[city];
                    }else{
                        break;
                    }
                    try {
                        p.fly_shuttle(c);
                    }
                    catch(const std::exception& e) {
                        std::cerr << e.what() << '\n';
                    }
                    break;
                case 5:
                    try {
                        p.build();
                    }
                    catch(const std::exception& e) {
                        std::cerr << e.what() << '\n';
                    }
                    break;
                case 6:
                    cout << "Enter city color to discover_cure: ";
                    cin >> color;
                    if(b.get_string_2_Color().count(color)){
                        co = b.get_string_2_Color()[color];
                    }else{
                        break;
                    }
                    try {
                        p.discover_cure(co);
                    }
                    catch(const std::exception& e) {
                        std::cerr << e.what() << '\n';
                    }
                    break;
                case 7:
                    cout << "Enter city to treat: ";
                    cin >> city;
                    if(b.get_string_2_City().count(city)){
                        c = b.get_string_2_City()[city];
                    }else{
                        break;
                    }
                    try {
                        p.treat(c);
                    }
                    catch(const std::exception& e) {
                        std::cerr << e.what() << '\n';
                    }
                    break;
                case 8:
                    cout << "Enter city to take card: ";
                    cin >> city;
                    if(b.get_string_2_City().count(city)){
                        c = b.get_string_2_City()[city];
                    }else{
                        break;
                    }
                    try {
                        p.take_card(c);
                    }
                    catch(const std::exception& e) {
                        std::cerr << e.what() << '\n';
                    }
                    break;
                case 9:
                    cout << "Role player is: " << p.role() << endl;
                    break;
                case 10:
                    changed = true;
                    break;
                default:
                    cout << "Invalid input";
                    break;
                }
            }
        }
    }

    return 0;
}