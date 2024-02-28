#include <thread>
#include <chrono>
#include <vector>
#include "GameContext.h"


using namespace chrono;
using namespace this_thread;
using namespace std; 

class GamePrinter{

  private:
    static GameContext gameContext;

  public: 
    GamePrinter(){
      gameContext = GameContext();
    }

    static void setDelay(int x){
      Delay = x;
    }

    static void GameWon(){
      cout << "🧨🧨🧨🧨🧨🧨🧨🧨🧨🧨🧨🧨🧨🧨🧨🧨🧨🧨🧨🧨🧨🧨" << endl;
      cout << BOLD << PURPLE << "🧨🧨🧨 CONGRATS YOU FINISHED THE GAME 🧨🧨🧨" << RESET << endl;
      cout << "🧨🧨🧨🧨🧨🧨🧨🧨🧨🧨🧨🧨🧨🧨🧨🧨🧨🧨🧨🧨🧨🧨" << endl;
    }

    static void GameLost(){
      cout << "🛢️🛢️🛢️🛢️🛢️🛢️🛢️🛢️🛢️🛢️🛢️🛢️🛢️🛢️🛢️🛢️🛢️🛢️🛢️🛢️🛢️🛢️" << endl;
      cout << "🛢️🛢️🛢️🛢️🛢️🛢️🛢️ YOU HAVE LOST  🛢️🛢️🛢️🛢️🛢️🛢️🛢️" << endl;
      cout << "🛢️🛢️🛢️🛢️🛢️🛢️🛢️🛢️🛢️🛢️🛢️🛢️🛢️🛢️🛢️🛢️🛢️🛢️🛢️🛢️🛢️🛢️" << endl;
    }
    static void Alert(){
      cout << RED << "!!! YOU CAN\'T GO THERE " << "🪵/💥" << " TRY OTHER DIRECTIONS !!!" << endl;
      return; 
    }

    static void Coordinates() 
    {
      cin.ignore();
      cout << "============== "<< PURPLE << "COORDINATES " << RESET << " ==============" << "\n";
      cout << "Player Coordinates : " << gameContext.Player << RESET << "\n"; 
      cout << "Box Coordinates : " ;
      for (auto box : gameContext.Boxes) 
        cout << PURPLE << box << " "; 

      cout << endl; 

      cout << RESET << "Points Coordinates : " ;
      for (auto point : gameContext.Meat)
        cout << PURPLE << point << " "; 
      cout <<endl <<  "============== "<< PURPLE << "COORDINATES " << RESET << " ==============" << "\n";
    }

    static int GameMenu(){
      cout << PURPLE << "===================================" << "\n";
      cout << "       CHOOSE THE GAME MODE"<< "\n"; 
      cout << "===================================" << "\n";
      cout << " 1. Human Mode" << endl;
      cout << " 2. Agent Mode" << endl;
      cout << "choice : " << RESET;
      int input; 
      cin >> input ; 
      return input; 
    }

    static void Welcome()
    {
      cout << "===================================" << "\n";
      cout << "WELCOME TO SOKOBAN GAME!!!" << "\n"; 
      cout << "===================================" << "\n";
    }

    static void PrintMap()
    {
      sleep_for(milliseconds(Delay));
      cout << "============== " << PURPLE << "CURRENT MAP STATE" << RESET <<  " ==============" << "\n";
      for (auto row : gameContext.getMap()) {
        for (auto index : row) 
          cout << index << " " ;
        cout << "\n";
      }
      cout << BOLD << PURPLE << "SCORE : " << gameContext.score <<  RESET << endl;
      cout << "============== " << PURPLE << "CURRENT MAP STATE" << RESET <<  " ==============" << "\n";
    };

};
