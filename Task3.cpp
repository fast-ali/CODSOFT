#include<iostream>
#include<string>

using namespace std;

#define GRID_SIZE 3

class Game {
		public:
	
			char grid[GRID_SIZE][GRID_SIZE];

		void check_for_wins () {
			const char* winning_moves[8]= {
			"123",
			"456",
			"789",
			"147",
			"258",
			"369",
			"159",
			"753",
			};
			
			for (int i=0; i<8; i++){
				bool winner= true;
				char new_grid= '0';
				const char*winning_move= winning_moves[i];
				
				for (int index=0; index<3; index++) {
					char character= winning_move[index];
					int entered_number= character - '0';
					int grid_space= entered_number - 1;
					
					int row= grid_space/3;
					int col= grid_space%3;
					char grid_char= grid[row][col];
					
					if (new_grid=='0') {
						new_grid=grid_char;
					} else if (new_grid== grid_char){
						continue;
					} else{
						winner= false;
						break; 
					}
				}
				if (winner) {
					puts("You are our Winner!!!");
					
					exit(0);
					break;
				}
				
			}
		}
		void ask_turn () {
			string input;
			while (true) {
				puts("Select your Place");
				getline(cin, input);
				
				if (input != " ") {
					
					char entered= input.c_str()[0];
					
					if (entered >= '1' && entered <= '9') {
					int entered_number= entered - '0';
					int index= entered_number - 1;
					 
					 int row= index/3;
					 int col= index%3;
					 
					 char grid_position= grid[row][col];
					 
					 if (grid_position=='X'|| grid_position=='O'){
					 	puts("Grid position is already occupied");
					 } else {
					 	grid[row][col]='X';
					 	break;
					 }
					 
					} else {
						puts("Enter the correct range");
					}
					
				} else { 
				puts("Please share some value"); }
			}
		}
		
		void Ai_turn () {
			while (true) {
			
			int Ai_turn= ( rand()%9) +1;
			printf("Computer chose %d it's turn\n",Ai_turn);
			int row= (Ai_turn-1)/3;
			int col=(Ai_turn-1)%3;
			
			char grid_position= grid[row][col];
			
			if(grid_position=='X'||grid_position=='0') {
				continue; //position is already acquired, hence try somewhere else
			} else {
				printf("Computer will play at %d.\n",Ai_turn);
				grid[row][col]='O';
				break; 
			}
		  } 
		}
		void generate_gird () {
	
		int num=1;
	
	for (int x=0; x<GRID_SIZE; x++) {
		
		for ( int y=0; y<GRID_SIZE; y++) {
			grid[x][y]= to_string(num).c_str()[0];
			num +=1;
		}
	}
		}
		void show_grid () {
			
			
	printf("\n-------------\n");
	for (int x=0; x<GRID_SIZE; x++){
		
		for (int y=0; y<GRID_SIZE; y++) {
			printf (" %c |", grid[x][y]);
		}
			printf("\n-------------\n");
				
	}
	
		}
		
		Game () {
			generate_gird ();
			
			show_grid(); 
			check_for_wins();
			while (true){
			ask_turn (); 
			check_for_wins();
			
		
			Ai_turn();
			show_grid(); 
			check_for_wins();
			}
			
		}
};

int main ( int argc, char *argv [] )  {
	
          Game game;

	return 0;
}
