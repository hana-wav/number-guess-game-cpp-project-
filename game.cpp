#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

void startmsg()
{
    cout << "Welcome to the Number Guess!" << endl << "A game where I think of a number and you try to guess it!"; 
    cout << endl << "The number is between 1 and 100." << endl << "Pick your game mode by typing a number in the console: " << endl << endl;
}

void gamemode()
{
    cout << "\n> 1. Easy - 10 tries\n> 2. Medium - 5 tries\n> 3. Hard - 3 tries\n> 4 END GAME";
    cout << endl << endl << "Game mode: ";
}

int generator()
{
    int x = rand()%100+1;
    return x;
}

void game(int m);

int main()
{
    srand(time(0));
    int mode;
    int m;

    startmsg();
    gamemode();
    cin >> mode;
    while( mode != 4)
    {
        switch(mode)      //turns on the game in chosen mode
        {
            case 1 :
                m = 10;
                game(m);
                break;

            case 2 :
                m = 5;
                game(m);
                break;

            case 3 :
                m = 3;
                game(m);
                break;

            default : cout << endl << "Invalid mode, pick again.";
        }
        gamemode();
        cin >> mode;
    }


}

void game(int m)
{
    int y = generator();
    int guess;

    for(int i = 0; i<m; i++)
    {
        cout << "\n" << m-i << " chances left. ";
        cout << endl << "Your guess: ";

        cin >> guess;

        if(guess == y)
        {
            cout << endl << "Wow, how did you know that ;)" << "\nYou guessed the number in " << i+1 << " attempts";
            break;
        }
        else if(guess > y)
        {
            cout << endl << "The number is lower. ";
        }
        else
        {
            cout << endl << "The number is higher. ";
        }
    }
    cout << endl << "Not this time cowboy";

}