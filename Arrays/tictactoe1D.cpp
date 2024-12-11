#include <iostream>
using namespace std;

void board(char *spaces)
{
    cout << spaces[0] << " | " << spaces[1] << " | " << spaces[2] << endl;
    cout << "__|___|__" << endl;
    cout << spaces[3] << " | " << spaces[4] << " | " << spaces[5] << endl;
    cout << "__|___|__" << endl;
    cout << spaces[6] << " | " << spaces[7] << " | " << spaces[8] << endl;
    cout << "  |   |  " << endl;
};

void plyr1move(char *spaces, char player1, char player2)
{
    int number;
    do
    {
        cout << "Player 1 Turn" << endl;
        cout << "Enter spot number (1-9) : ";
        cin >> number;
        number--;
        if (spaces[number] == ' ')
        {
            spaces[number] = player1;
            break;
        }
 else if (spaces[number]==player1 || spaces[number]==player2){

            cout << "Space already filled" << endl;

        }

       
       
    } while (!number > 0 || !number < 9);
}

void plyr2move(char *spaces, char player2, char player1)
{
    int number;
    do
    {
        cout << "PLAYER 2 Turn" << endl;
        cout << "Enter spot number (1-9) : ";
        cin >> number;
        number--;
        if (spaces[number] == ' ')
        {
            spaces[number] = player2;
            break;
        }
        else if (spaces[number]==player1 || spaces[number]==player2){

            cout << "Space already filled" << endl;

        }

        
    } while (!number > 0 || !number < 9);
};

bool checkwinner(char *spaces, char player1, char player2)
{

    if ((spaces[0] != ' ') && (spaces[0] == spaces[1]) && (spaces[1] == spaces[2]))
    {

        spaces[0] == player1 ? cout << "Player1 Won" : cout << "Player2 Won";
    }
    else if ((spaces[3] != ' ') && (spaces[3] == spaces[4]) && (spaces[4] == spaces[5]))
    {

        spaces[3] == player1 ? cout << "Player1 Won" : cout << "Player2 Won";
    }
    else if ((spaces[6] != ' ') && (spaces[6] == spaces[7]) && (spaces[7] == spaces[8]))
    {

        spaces[6] == player1 ? cout << "Player1 Won" : cout << "Player2 Won";
    }
    else if ((spaces[0] != ' ') && (spaces[0] == spaces[3]) && (spaces[3] == spaces[6]))
    {

        spaces[0] == player1 ? cout << "Player1 Won" : cout << "Player2 Won";
    }
    else if ((spaces[1] != ' ') && (spaces[1] == spaces[4]) && (spaces[4] == spaces[7]))
    {

        spaces[1] == player1 ? cout << "Player1 Won" : cout << "Player2 Won";
    }
    else if ((spaces[2] != ' ') && (spaces[2] == spaces[5]) && (spaces[5] == spaces[8]))
    {

        spaces[2] == player1 ? cout << "Player1 Won" : cout << "Player2 Won";
    }
    else if ((spaces[0] != ' ') && (spaces[0] == spaces[4]) && (spaces[4] == spaces[8]))
    {

        spaces[0] == player1 ? cout << "Player1 Won" : cout << "Player2 Won";
    }
    else if ((spaces[2] != ' ') && (spaces[2] == spaces[4]) && (spaces[4] == spaces[6]))
    {

        spaces[2] == player1 ? cout << "Player1 Won" : cout << "Player2 Won";
    }
    else
    {
        return false;
    }
    return true;
};
bool tie(char *spaces)
{
    for (int i = 0; i < 9; i++)
    {

        if (spaces[i] == ' ')
        {

            return false;
        }
    }
    cout << "ITS A TIE \n";
    return true;
}

int main()
{

    char spaces[] = {
        ' ',
        ' ',
        ' ',
        ' ',
        ' ',
        ' ',
        ' ',
        ' ',
        ' ',
    };
    char player1 = 'X';
    char player2 = 'O';
    bool running = true;

    board(spaces);

    while (running)
    {
        plyr1move(spaces, player1, player2);
        board(spaces);
        if (checkwinner(spaces, player1, player2))
        {
            return false;
            break;
        }
        plyr2move(spaces, player2, player1 );
        board(spaces);
        if (checkwinner(spaces, player1, player2))
        {
            return false;
            break;
        }
        if (tie(spaces))
        {
            return false;
            break;
        }
    }
}