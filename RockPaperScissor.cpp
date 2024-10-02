#include <iostream>
#include <cstdlib>
#include <random>
#include <conio.h>

using namespace std;

char getHiddenChar()
{
    char ch;

    do
    {
        ch = _getch(); // Get a single character

        if (!isalpha(ch)) // Check if it's an alphabetic character
        {
            std::cout << "\nInvalid input. Please enter an alphabetic character.\n\nPlayer >> ";
        }
        else
        {
            std::cout << '*'; // Display an asterisk for the entered character
        }

    } while (!isalpha(ch)); // Repeat until an alphabetic character is entered

    return ch; // Return the valid character
}

void printSimpleScoreboardPlayerVsBot(int score1, int score2)
{
    cout << "|-------------------|" << endl;
    cout << "| Player: " << score1 << "         |" << endl;
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
    char player1Choise = '0';
    char player2Choise = '0';
    int bot = 0;

    bool draw = false;

    bool exit = false;

    bool invalid = false;

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

                    if (botScore == 0 && player1Score == 0 && draw == false && invalid == false)
                    {
                        cout << "Let's start! Choose Rock, Paper, or Scissor!" << endl;
                    }
                    else if (draw == true && invalid == false)
                    {
                        cout << "Let's go again! Choose Rock, Paper, or Scissor!" << endl;
                        draw = false;
                    }
                    else if (invalid == false)
                    {
                        cout << "Let's go again! Choose Rock, Paper, or Scissor!" << endl;
                    }

                    cout << endl;
                    cout << "r/R - Rock" << endl;
                    cout << "p/P - Paper" << endl;
                    cout << "s/S - Scissor" << endl;
                    cout << endl;

                    cout << "Player >> ";
                    player1Choise = getHiddenChar();
                    cout << endl;
                    cout << endl;

                    if (player1Choise != 'r' && player1Choise != 'R' && player1Choise != 'p' && player1Choise != 'P' && player1Choise != 's' && player1Choise != 'S')
                    {
                        cout << "Invalid answer! Please enter r/R, p/P or s/S." << endl;
                        invalid = true;
                    }
                    else
                    {
                        invalid = false;

                        // Generate a single random number
                        bot = dist(gen); // Generate random number in range [0, 2]

                        switch (player1Choise)
                        {
                        case 'r':
                            cout << "Player played: Rock" << endl;
                            break;
                        case 'R':
                            cout << "Player played: Rock" << endl;
                            break;
                        case 'p':
                            cout << "Player played: Paper" << endl;
                            break;
                        case 'P':
                            cout << "Player played: Paper" << endl;
                            break;
                        case 's':
                            cout << "Player played: Scissor" << endl;
                            break;
                        case 'S':
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

                        if ((player1Choise == 'r' || player1Choise == 'R') && bot == 0)
                        {
                            cout << endl;
                            cout << "Draw!" << endl;
                            cout << endl;

                            draw = true;

                            printSimpleScoreboardPlayerVsBot(player1Score, botScore);
                        }
                        else if ((player1Choise == 'p' || player1Choise == 'P') && bot == 1)
                        {
                            cout << endl;
                            cout << "Draw!" << endl;
                            cout << endl;

                            draw = true;

                            printSimpleScoreboardPlayerVsBot(player1Score, botScore);
                        }
                        else if ((player1Choise == 's' || player1Choise == 'S') && bot == 2)
                        {
                            cout << endl;
                            cout << "Draw!" << endl;
                            cout << endl;

                            draw = true;

                            printSimpleScoreboardPlayerVsBot(player1Score, botScore);
                        }
                        else if ((player1Choise == 'r' || player1Choise == 'R') && bot == 1)
                        {
                            cout << endl;
                            cout << "Bot Wins!!!" << endl;
                            cout << endl;

                            botScore++;

                            printSimpleScoreboardPlayerVsBot(player1Score, botScore);
                        }
                        else if ((player1Choise == 'r' || player1Choise == 'R') && bot == 2)
                        {
                            cout << endl;
                            cout << "Player Wins!!!" << endl;
                            cout << endl;

                            player1Score++;

                            printSimpleScoreboardPlayerVsBot(player1Score, botScore);
                        }
                        else if ((player1Choise == 'p' || player1Choise == 'P') && bot == 0)
                        {
                            cout << endl;
                            cout << "Player Wins!!!" << endl;
                            cout << endl;

                            player1Score++;

                            printSimpleScoreboardPlayerVsBot(player1Score, botScore);
                        }
                        else if ((player1Choise == 'p' || player1Choise == 'P') && bot == 2)
                        {
                            cout << endl;
                            cout << "Bot Wins!!!" << endl;
                            cout << endl;

                            botScore++;

                            printSimpleScoreboardPlayerVsBot(player1Score, botScore);
                        }
                        else if ((player1Choise == 's' || player1Choise == 'S') && bot == 0)
                        {
                            cout << endl;
                            cout << "Bot Wins!!!" << endl;
                            cout << endl;

                            botScore++;

                            printSimpleScoreboardPlayerVsBot(player1Score, botScore);
                        }
                        else if ((player1Choise == 's' || player1Choise == 'S') && bot == 1)
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

                while (player1Score < wins && player2Score < wins)
                {
                    if (player1Score == 0 && player2Score == 0 && draw == false)
                    {
                        cout << "Let's start! Player 1, choose Rock, Paper, or Scissor!" << endl;
                    }
                    else if (draw == true)
                    {
                        cout << "Let's go again! Player 1, choose Rock, Paper, or Scissor!" << endl;
                        draw = false;
                    }
                    else
                    {
                        cout << "Let's go again! Player 1, choose Rock, Paper, or Scissor!" << endl;
                    }

                    bool validInput1 = false;
                    bool validInput2 = false;

                    while (!validInput1)
                    {
                        cout << endl;
                        cout << "r/R - Rock" << endl;
                        cout << "p/P - Paper" << endl;
                        cout << "s/S - Scissor" << endl;
                        cout << endl;

                        cout << "Player 1 >> ";
                        player1Choise = getHiddenChar();
                        cout << endl;
                        cout << endl;

                        if (player1Choise != 'r' && player1Choise != 'R' && player1Choise != 'p' && player1Choise != 'P' && player1Choise != 's' && player1Choise != 'S')
                        {
                            cout << "Invalid answer! Please enter r/R, p/P or s/S." << endl;
                            invalid = true;
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
                        cout << "r/R - Rock" << endl;
                        cout << "p/P - Paper" << endl;
                        cout << "s/S - Scissor" << endl;
                        cout << endl;

                        cout << "Player 2 >> ";
                        player2Choise = getHiddenChar();
                        cout << endl;
                        cout << endl;

                        if (player2Choise != 'r' && player2Choise != 'R' && player2Choise != 'p' && player2Choise != 'P' && player2Choise != 's' && player2Choise != 'S')
                        {
                            cout << "Invalid answer! Please enter r/R, p/P or s/S." << endl;
                            invalid = true;
                        }
                        else
                        {
                            validInput2 = true;
                        }
                    }

                    switch (player1Choise)
                    {
                    case 'r':
                        cout << "Player 1 played: Rock" << endl;
                        break;
                    case 'R':
                        cout << "Player 1 played: Rock" << endl;
                        break;
                    case 'p':
                        cout << "Player 1 played: Paper" << endl;
                        break;
                    case 'P':
                        cout << "Player 1 played: Paper" << endl;
                        break;
                    case 's':
                        cout << "Player 1 played: Scissor" << endl;
                        break;
                    case 'S':
                        cout << "Player 1 played: Scissor" << endl;
                        break;

                    default:
                        break;
                    }

                    switch (player2Choise)
                    {
                    case 'r':
                        cout << "Player 2 played: Rock" << endl;
                        break;
                    case 'R':
                        cout << "Player 2 played: Rock" << endl;
                        break;
                    case 'p':
                        cout << "Player 2 played: Paper" << endl;
                        break;
                    case 'P':
                        cout << "Player 2 played: Paper" << endl;
                        break;
                    case 's':
                        cout << "Player 2 played: Scissor" << endl;
                        break;
                    case 'S':
                        cout << "Player 2 played: Scissor" << endl;
                        break;

                    default:
                        break;
                    }

                    if (player1Choise == player2Choise)
                    {
                        cout << endl;
                        cout << "Draw!" << endl;
                        cout << endl;

                        draw = true;

                        printSimpleScoreboardPlayer1VsPlayer2(player1Score, player2Score);
                    }
                    else if ((player1Choise == 'r' || player1Choise == 'R') && (player2Choise == 'p' || player2Choise == 'P'))
                    {
                        cout << endl;
                        cout << "Player 2 Wins!!!" << endl;
                        cout << endl;

                        player2Score++;

                        printSimpleScoreboardPlayer1VsPlayer2(player1Score, player2Score);
                    }
                    else if ((player1Choise == 'r' || player1Choise == 'R') && (player2Choise == 's' || player2Choise == 'S'))
                    {
                        cout << endl;
                        cout << "Player 1 Wins!!!" << endl;
                        cout << endl;

                        player1Score++;

                        printSimpleScoreboardPlayer1VsPlayer2(player1Score, player2Score);
                    }
                    else if ((player1Choise == 'p' || player1Choise == 'P') && (player2Choise == 'r' || player2Choise == 'R'))
                    {
                        cout << endl;
                        cout << "Player 1 Wins!!!" << endl;
                        cout << endl;

                        player1Score++;

                        printSimpleScoreboardPlayer1VsPlayer2(player1Score, player2Score);
                    }
                    else if ((player1Choise == 'p' || player1Choise == 'P') && (player2Choise == 's' || player2Choise == 'S'))
                    {
                        cout << endl;
                        cout << "Player 2 Wins!!!" << endl;
                        cout << endl;

                        player2Score++;

                        printSimpleScoreboardPlayer1VsPlayer2(player1Score, player2Score);
                    }
                    else if ((player1Choise == 's' || player1Choise == 'S') && (player2Choise == 'r' || player2Choise == 'R'))
                    {
                        cout << endl;
                        cout << "Player 2 Wins!!!" << endl;
                        cout << endl;

                        player2Score++;

                        printSimpleScoreboardPlayer1VsPlayer2(player1Score, player2Score);
                    }
                    else if ((player1Choise == 's' || player1Choise == 'S') && (player2Choise == 'p' || player2Choise == 'P'))
                    {
                        cout << endl;
                        cout << "Player 1 Wins!!!" << endl;
                        cout << endl;

                        player1Score++;

                        printSimpleScoreboardPlayer1VsPlayer2(player1Score, player2Score);
                    }
                }
                if (player1Score == wins)
                {
                    cout << endl;
                    cout << "Player 1 won the Series!!!" << endl;
                    cout << endl;

                    player1Win = true;
                }
                else if (player2Score == wins)
                {
                    cout << endl;
                    cout << "Player 2 won the Series!!!" << endl;
                    cout << endl;

                    player2Win = true;
                }

                break;
            }
        }

        if (player1Win == true || player2Win == true || botWin == true)
        {
            cout << "\nDo you want to play again? (y/n): " << endl;
            cout << endl;
            cout << ">> ";
            cin >> playAgain;
            cout << endl;

            if (playAgain != 'y' && playAgain != 'Y' && playAgain != 'n' && playAgain != 'N')
            {
                while (exit == false)
                {
                    cout << "\nWrong value! You should enter either y/Y or n/N! Do you want to play again? (y/n): " << endl;
                    cout << endl;
                    cout << ">> ";
                    cin >> playAgain;
                    cout << endl;

                    if (playAgain == 'y' || playAgain == 'Y' || playAgain == 'n' || playAgain == 'N')
                    {
                        exit = true;
                    }
                }
            }

            player1Win = false;
            player2Win = false;
            botWin = false;
        }
    }

    cout << "Thanks for playing!!!" << endl;
    cout << endl;
    return 0;
}
