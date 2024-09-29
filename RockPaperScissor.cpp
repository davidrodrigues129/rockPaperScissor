#include <iostream>
#include <cstdlib>
#include <random>
#include <conio.h>

using namespace std;

int getHiddenInteger()
{
    std::string hiddenInput;
    char ch;

    while ((ch = _getch()) != '\r')
    { // Read input until Enter key is pressed
        if (isdigit(ch))
        {                      // Only accept digits
            hiddenInput += ch; // Store digit
            cout << '*';       // Display an asterisk for each digit
        }
    }

    return std::stoi(hiddenInput); // Convert string to integer
}

void printSimpleScoreboardPlayerVsBot(int score1, int score2)
{
    cout << "|-------------------|" << endl;
    cout << "| Player 1: " << score1 << "       |" << endl;
    cout << "| Bot: " << score2 << "            |" << endl;
    cout << "|-------------------|" << endl;
    cout << endl;
}

void printSimpleScoreboardPlayer1VsPlayer2(int score1, int score2)
{
    cout << "|-------------------|" << endl;
    cout << "| Player 1: " << score1 << "       |" << endl;
    cout << "| Player 2: " << score2 << "       |" << endl;
    cout << "|-------------------|" << endl;
    cout << endl;
}

int main()
{

    std::random_device rd;                      // Seed
    std::mt19937 gen(rd());                     // Mersenne Twister engine
    std::uniform_int_distribution<> dist(0, 2); // Range [0, 2]

    int botOrPerson = 0;
    int player1 = 0;
    int player2 = 0;
    int bot = 0;

    bool draw = false;

    bool player1Win = false;
    bool player2Win = false;
    bool botWin = false;

    char playAgain = 'y';

    cout << endl;
    cout << endl;
    cout << "Welcome to Rock-Paper-Scissor!" << endl;
    cout << endl;

    while (playAgain == 'y' || playAgain == 'Y')
    {

        int player1Score = 0;
        int player2Score = 0;
        int botScore = 0;

        int bestOf = -1;
        int wins = 0;

        cout << endl;
        cout << "Are you going to play vs a Bot or vs a Person? " << endl;
        cout << endl;
        cout << "0 - Bot" << endl;
        cout << "1 - Person" << endl;
        cout << endl;

        cout << ">> ";
        cin >> botOrPerson;
        cout << endl;

        if (botOrPerson < 0 || botOrPerson > 1)
        {
            cout << "Invalid answer! Please enter 0 or 1." << endl;
        }
        else
        {
            switch (botOrPerson)
            {
            case 0:
                cout << "You chose to play against the Bot!" << endl;
                cout << endl;

                cout << "Are you going to play a Best of 1, Best of 3 or Best of 5? " << endl;

                while (bestOf != 1 && bestOf != 3 && bestOf != 5)
                {
                    cout << endl;
                    cout << "1 - Best of 1" << endl;
                    cout << "3 - Best of 3" << endl;
                    cout << "5 - Best of 5" << endl;
                    cout << endl;

                    cout << ">> ";
                    cin >> bestOf;
                    cout << endl;

                    if (bestOf != 1 && bestOf != 3 && bestOf != 5)
                    {
                        cout << "Invalid answer! Please enter 1, 3 or 5" << endl;
                    }
                    else
                    {
                        switch (bestOf)
                        {
                        case 1:
                            wins = 1;
                            break;
                        case 3:
                            wins = 2;
                            break;
                        case 5:
                            wins = 3;
                            break;

                        default:
                            break;
                        }
                    }
                }

                while (botScore < wins && player1Score < wins)
                {

                    if (botScore == 0 && player1Score == 0 && draw == false)
                    {
                        cout << "Let's start! Choose Rock, Paper, or Scissor!" << endl;
                    }
                    else if (draw == true)
                    {
                        cout << "Let's go again! Choose Rock, Paper, or Scissor!" << endl;
                        draw = false;
                    }
                    else
                    {
                        cout << "Let's go again! Choose Rock, Paper, or Scissor!" << endl;
                    }

                    cout << endl;
                    cout << "0 - Rock" << endl;
                    cout << "1 - Paper" << endl;
                    cout << "2 - Scissor" << endl;
                    cout << endl;

                    cout << "Player >> ";
                    player1 = getHiddenInteger();
                    cout << endl;
                    cout << endl;

                    if (player1 < 0 || player1 > 2)
                    {
                        cout << "Invalid answer! Please enter 0, 1 or 2." << endl;
                    }
                    else
                    {
                        // Generate a single random number
                        bot = dist(gen); // Generate random number in range [0, 2]

                        switch (player1)
                        {
                        case 0:
                            cout << "Player played: Rock" << endl;
                            break;
                        case 1:
                            cout << "Player played: Paper" << endl;
                            break;
                        case 2:
                            cout << "Player played: Scissor" << endl;
                            break;

                        default:
                            break;
                        }

                        switch (bot)
                        {
                        case 0:
                            cout << "Bot played: Rock" << endl;
                            break;
                        case 1:
                            cout << "Bot played: Paper" << endl;
                            break;
                        case 2:
                            cout << "Bot played: Scissor" << endl;
                            break;

                        default:
                            break;
                        }

                        if (player1 == bot)
                        {
                            cout << endl;
                            cout << "Draw!" << endl;
                            cout << endl;

                            draw = true;

                            printSimpleScoreboardPlayerVsBot(player1Score, botScore);
                        }
                        else if (player1 == 0 && bot == 1)
                        {
                            cout << endl;
                            cout << "Bot Wins!!!" << endl;
                            cout << endl;

                            botScore++;

                            printSimpleScoreboardPlayerVsBot(player1Score, botScore);
                        }
                        else if (player1 == 0 && bot == 2)
                        {
                            cout << endl;
                            cout << "Player Wins!!!" << endl;
                            cout << endl;

                            player1Score++;

                            printSimpleScoreboardPlayerVsBot(player1Score, botScore);
                        }
                        else if (player1 == 1 && bot == 0)
                        {
                            cout << endl;
                            cout << "Player Wins!!!" << endl;
                            cout << endl;

                            player1Score++;

                            printSimpleScoreboardPlayerVsBot(player1Score, botScore);
                        }
                        else if (player1 == 1 && bot == 2)
                        {
                            cout << endl;
                            cout << "Bot Wins!!!" << endl;
                            cout << endl;

                            botScore++;

                            printSimpleScoreboardPlayerVsBot(player1Score, botScore);
                        }
                        else if (player1 == 2 && bot == 0)
                        {
                            cout << endl;
                            cout << "Bot Wins!!!" << endl;
                            cout << endl;

                            botScore++;

                            printSimpleScoreboardPlayerVsBot(player1Score, botScore);
                        }
                        else if (player1 == 2 && bot == 1)
                        {
                            cout << endl;
                            cout << "Player Wins!!!" << endl;
                            cout << endl;

                            player1Score++;

                            printSimpleScoreboardPlayerVsBot(player1Score, botScore);
                        }
                    }
                }

                if (botScore == wins)
                {
                    cout << endl;
                    cout << "Bot won the Series!!!" << endl;
                    cout << endl;

                    botWin = true;
                }
                else if (player1Score == wins)
                {
                    cout << endl;
                    cout << "Player won the Series!!!" << endl;
                    cout << endl;

                    player1Win = true;
                }

                break;

            case 1:
                cout << "You chose to play against a Person!" << endl;
                cout << endl;
                cout << "Let's start! Player 1, choose Rock, Paper, or Scissor!" << endl;

                while (player1Win == false && player2Win == false)
                {
                    bool validInput1 = false;
                    bool validInput2 = false;

                    while (!validInput1)
                    {
                        cout << endl;
                        cout << "0 - Rock" << endl;
                        cout << "1 - Paper" << endl;
                        cout << "2 - Scissor" << endl;
                        cout << endl;

                        cout << "Player 1 >> ";
                        player1 = getHiddenInteger();
                        cout << endl;
                        cout << endl;

                        if (player1 < 0 || player1 > 2)
                        {
                            cout << "Invalid answer Player 1! Please enter 0, 1, or 2." << endl;
                        }
                        else
                        {
                            validInput1 = true;
                        }
                    }

                    cout << "Now, Player 2, choose Rock, Paper, or Scissor!" << endl;

                    while (!validInput2)
                    {

                        cout << endl;
                        cout << "0 - Rock" << endl;
                        cout << "1 - Paper" << endl;
                        cout << "2 - Scissor" << endl;
                        cout << endl;

                        cout << "Player 2 >> ";
                        player2 = getHiddenInteger();
                        cout << endl;
                        cout << endl;

                        if (player2 < 0 || player2 > 2)
                        {
                            cout << "Invalid answer Player 2! Please enter 0, 1, or 2." << endl;
                        }
                        else
                        {
                            validInput2 = true;
                        }
                    }
                    switch (player1)
                    {
                    case 0:
                        cout << "Player 1 played: Rock" << endl;
                        break;
                    case 1:
                        cout << "Player 1 played: Paper" << endl;
                        break;
                    case 2:
                        cout << "Player 1 played: Scissor" << endl;
                        break;

                    default:
                        break;
                    }

                    switch (player2)
                    {
                    case 0:
                        cout << "Player 2 played: Rock" << endl;
                        break;
                    case 1:
                        cout << "Player 2 played: Paper" << endl;
                        break;
                    case 2:
                        cout << "Player 2 played: Scissor" << endl;
                        break;

                    default:
                        break;
                    }

                    if (player1 == player2)
                    {
                        cout << endl;
                        cout << "Draw! Let's play again! Player 1, choose Rock, Paper, or Scissor!" << endl;
                    }
                    else if (player1 == 0 && player2 == 1)
                    {
                        cout << endl;
                        cout << "Player 2 Wins!!!" << endl;
                        cout << endl;

                        player2Win = true;
                    }
                    else if (player1 == 0 && player2 == 2)
                    {
                        cout << endl;
                        cout << "Player 1 Wins!!!" << endl;
                        cout << endl;

                        player1Win = true;
                    }
                    else if (player1 == 1 && player2 == 0)
                    {
                        cout << endl;
                        cout << "Player 1 Wins!!!" << endl;
                        cout << endl;

                        player1Win = true;
                    }
                    else if (player1 == 1 && player2 == 2)
                    {
                        cout << endl;
                        cout << "Player 2 Wins!!!" << endl;
                        cout << endl;

                        player2Win = true;
                    }
                    else if (player1 == 2 && player2 == 0)
                    {
                        cout << endl;
                        cout << "Player 2 Wins!!!" << endl;
                        cout << endl;

                        player2Win = true;
                    }
                    else if (player1 == 2 && player2 == 1)
                    {
                        cout << endl;
                        cout << "Player 1 Wins!!!" << endl;
                        cout << endl;

                        player1Win = true;
                    }
                }
            }
        }

        if (player1Win == true || player2Win == true || botWin == true)
        {
            cout << "\nDo you want to play again? (y/n): ";
            cin >> playAgain;
            cout << endl;

            player1Win = false;
            player2Win = false;
            botWin = false;
        }
    }

    cout << "Thanks for playing!!!" << endl;
    cout << endl;
    return 0;
}
