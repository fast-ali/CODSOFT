#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int main() {

  srand(time(nullptr));
      
  int targetNumber = rand() % 100 + 1;
  int guess;
  int attempts = 0;
    
  cout<<"I have selected a number between 1 and 100. Can you guess it?"<<endl<<endl;
    
  while (true) {
     cout<<"Enter your guess : ";
     cin>>guess;
     attempts++;
     cout<<endl;
        
     if (guess==targetNumber) {
        cout<<"Congratulations! You've guessed the number " <<targetNumber<<" correctly in "<<attempts<<" attempts."<<endl<<endl;
        break;
        } 
    else if (guess>targetNumber) {
    	if (guess-targetNumber >= 10) {
        cout<<"Too High! Try again."<<endl<<endl;
   	 } else {
        cout<<"Little High! Try again."<<endl<<endl;
    }
}
    else if (guess<targetNumber) {
   	 if (targetNumber-guess>=10) {
        cout<<"Too Low! Try again."<<endl<<endl;
          } else {
        cout<<"Little Low! Try again."<<endl<<endl;
    }
}

 }
    
    
return 0;
}

