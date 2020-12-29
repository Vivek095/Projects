#include <iostream>
#include <string>
#include <cstdlib>     // For rand and srand
#include <ctime>      // For the time function
using namespace std;


class Die
{
public:
Die(int numSides) //constructor
{
setSides(numSides);
}

void setSides(int numSides)
{
 if(numSides>0) //input validation
 {
   sides=numSides;
 }
roll();
}

void roll()
{
value=1+rand()%sides;
}

int getSides()
{
return sides;
}

int getValue()
{
return value;
}


private:
int sides;
int value;

};


int main()
{
srand(time(0));

Die PlayerDie(6);
Die CompDie(6);

int playerScore=0,compScore=0;
char response;
cout << "Let's play a game of 21!" << endl << endl;
cout << "------------------------" << endl;

do
{
 cout << "Would you like to roll the Dice?" << endl;
 cout << "Enter Y for yes and N for no: ";
 cin >> response;


    cout << endl;
   if(response=='Y' || response=='y') //If user entered Y or y Game started
   {
    PlayerDie.roll();
    int rolledOne=PlayerDie.getValue();
    PlayerDie.roll();
    int rolledTwo=PlayerDie.getValue();
    playerScore = playerScore+rolledOne+rolledTwo; //count player score
    cout << "You have " << playerScore << " points" << endl << endl;  //display player score

    CompDie.roll();
    rolledOne=CompDie.getValue();
    CompDie.roll();
    rolledTwo=CompDie.getValue();
    compScore = compScore+rolledOne+rolledTwo; //count computer score
   }
   else if(response=='N' || response=='n')  //game ends after user enter N or n
   {
    break;
   }
   else            //if user enter anything other than Y,y,N or n
   {
    cout << "Invalid entry" << endl;
    return 0;
   }
}while(playerScore<=21);

                            //display the points
cout << "------------------------" << endl;
cout << "The computer had " << compScore << " points" << endl;
cout << "You had " << playerScore << " points" << endl << endl;

                        //display who's the winner based on the points
  if(playerScore==compScore && playerScore>0 && compScore>0) // if both scores are equal
  {
    cout << "Its a tie. No one wins" << endl;
    cout << "Game Over" << endl;
    cout << "------------------------" << endl;
  }
  else if(playerScore > 21 && compScore > 21) //check if both player and computer went over 21

  {
    cout << "Its a tie. No one wins" << endl;
    cout << "Game Over" << endl;
    cout << "------------------------" << endl;
  }
  else if(playerScore > 21)   //check if only player went over 21
  {
    cout << "Computer won. Better luck next time." << endl;
    cout << "Game Over" << endl;
    cout << "------------------------" << endl;
  }
  else if(compScore > 21)   //check if only computer went over 21
  {
    cout << "Congratulations You won!" << endl;
    cout << "Game Over" << endl;
    cout << "------------------------" << endl;
  }
  else if(playerScore > compScore) //After checking nobody went over 21,
                                   //check if player has more points
  {
   cout << "Congratulations You won!" << endl;
   cout << "Game Over" << endl;
   cout << "------------------------" << endl;
  }
  else if(compScore > playerScore) //After checking nobody went over 21,
                                   //check if computer has more points
  {
    cout << "Computer won. Better luck next time." << endl;
    cout << "Game Over" << endl;
    cout << "------------------------" << endl;
  }
  else
  {
    cout << "No points.Game Over" << endl;
    cout << "------------------------" << endl;
  }

  return 0;
}







