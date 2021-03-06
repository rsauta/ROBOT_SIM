#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
//Creates a struct for Robot that will hold the arrays.
typedef struct Robot
{
	int Robot_Number;
	char Robot_Name[20];
	int Year_Manufactured;
	float Top_Speed;
	float Mass;
    float Best_score;
}Robot;
//Creates a struct for the results of the combat.
typedef struct Results
{
    int test_id, Robot_Number, strength, combat_1;
	char Robot_Name[20];
	int Year_Manufactured;
	float Top_Speed, Mass, Best_score, finish_line_distance, finish_line_time;

}Results;


void print_Robot(Robot Robot_info){
        // Prints out all Robot numbers -> Robot Name -> Robot year manufactured -> Robot Top speed -> Robot Mass -> Best Score for line.
        printf("    %-8d |", Robot_info.Robot_Number);
        printf("    %-12s|", Robot_info.Robot_Name);
        printf("           %-14d|", Robot_info.Year_Manufactured);
        printf("     %-12.2f|", Robot_info.Top_Speed);
        printf("    %-10.2f|", Robot_info.Mass);
        printf("       %-10.2f|\n", Robot_info.Best_score);
	}

// Prints out all of the robots result info in a line
void print_results(Results* Res, int test_id){
    int i;
    i= test_id;
    
    printf("%-10d| %-10d| %-17s| %-10d| %-9.2f|  %-9.2f| %-10.2f| %-20.2f| %-17.2f| %-8.2d| %-20.2d|  \n", Res[i].test_id, Res[i].Robot_Number, Res[i].Robot_Name, Res[i].Year_Manufactured, Res[i].Top_Speed, Res[i].Mass, Res[i].Best_score, Res[i].finish_line_distance, Res[i].finish_line_time, Res[i].strength, Res[i].combat_1);

}
// Function to display the results of all of the simulations run.
void display_results(Results* Res, int Check1){
    int i;
            printf("Simulation Results (Wide Screen console)\n");
            printf("-----------------------------------------------------------------------------------------------------------------------------------------------------------------\n"); // Bar for aesthetic's 
            printf("------------------------------------------------------------------------------------------------------------------------------------------------------------------\n"); // Bar for aesthetic's 
            printf("Test_Id   |Robot_Id   |Robot_Name        |Year       |Top_speed |Mass       |Best_score |finish_line_distance | finish_line_time |Strength |combat effectiveness |\n");
            printf("----------|-----------|------------------|-----------|----------|-----------|-----------|---------------------|------------------|---------|---------------------|\n"); // Bar for aesthetic's 
        for (i = 0; i < Check1; i++) // for loop to print out each result in a line, check
        {

            printf("%-10d| %-10d| %-17s| %-10d| %-9.2f|  %-9.2f| %-10.2f| %-20.2f| %-17.2f| %-8.2d| %-20.2d|  \n", Res[i].test_id, Res[i].Robot_Number, Res[i].Robot_Name, Res[i].Year_Manufactured, Res[i].Top_Speed, Res[i].Mass, Res[i].Best_score, Res[i].finish_line_distance, Res[i].finish_line_time, Res[i].strength, Res[i].combat_1);
        }
        printf("-----------------------------------------------------------------------------------------------------------------------------------------------------------------\n"); // Bar for aesthetic's 
}

// Function to edit a existing robot.
void edit_robot(Robot* Rob, int check){
    check= check-1; // sets check to account for the first robot being at 0 on struct not at 1
    printf("Please enter Robot Name, Year Manufactured, Top Speed, Mass: \n");
    scanf("%s %d %f %f", Rob[check].Robot_Name, &Rob[check].Year_Manufactured, &Rob[check].Top_Speed, &Rob[check].Mass); // scanes user input for new info on existing robot.
    
}
//function to add new robot to struct
void enter_new_robot(Robot* Rob, int number_of_robots){
    int check, r_numb;
        check = number_of_robots; // assings robots number to correct value
        printf("Please enter Robot Name, Year Manufactured, Top Speed, Mass: \n");
        scanf("%s %d %f %f", Rob[check].Robot_Name, &Rob[check].Year_Manufactured, &Rob[check].Top_Speed, &Rob[check].Mass); // scans user input to 
        r_numb = check + 1; // Changes robot number to account for arracy starting at 0 not at 1
        Rob[check].Robot_Number = r_numb; // sets the robots number to correct 
        Rob[check].Best_score = 0.0; //sets best score to 0.0 instead of no value
}

// Function to find robots info by searching name, if all is enter displays all robots and if robots name was not found displays error message.
void search_robot(Robot* rob, int number_of_robots){
        char Name1[20], Name2[20], Name3[4]= "All"; //intros name checking variables
        int  i; // checks 

        printf("Enter your Robot Name: (Type All for all Robots) "); // prompts user to enter name for robot.
        scanf("%s", Name1); //scans users input

        for (i=0; i<number_of_robots; i++){ //for loop to go through all existing robots
        strcpy(Name2, rob[i].Robot_Name); // copies the string to the variable from the struct
        if ((strcmp(Name1,Name2)==0)) // checks if name1 name2 variable are the same if answer is yes will print out the robot
        {

            printf("------------------------------------------------------------------------------------------------------------\n"); // Bar for aesthetic's 
            printf("------------------------------------------------------------------------------------------------------------\n"); // Bar for aesthetic's 
            printf("Robot Number |   Robot Name   |    Year_Manufactured    |    Top Speed    |    Mass      |   Best_Score    |\n");
            printf("-------------|----------------|-------------------------|-----------------|--------------|-----------------|\n"); // Bar for aesthetic's 
            print_Robot(rob[i]); // prints out the robot that name matched the users entered
            printf("-------------|----------------|-------------------------|-----------------|--------------|-----------------|\n");
        } 
        
    }
           if (strcmp(Name1,Name3)==0) { //checks if user entered all 
            printf("------------------------------------------------------------------------------------------------------------\n"); // Bar for aesthetic's 
	        printf("------------------------------------------------------------------------------------------------------------\n"); // Bar for aesthetic's 
            printf("Robot Number |   Robot Name   |    Year_Manufactured    |    Top Speed    |    Mass      |   Best_Score    |\n");
            printf("-------------|----------------|-------------------------|-----------------|--------------|-----------------|\n"); // Bar for aesthetic's 
            for (i=0; i<number_of_robots; i++){ //prints all of the robots in the list
                print_Robot(rob[i]);
                printf("-------------|----------------|-------------------------|-----------------|--------------|-----------------|\n");
                }
        }else{ 
              printf("\nNo other robot found\n\n"); // if no robots found by the name the user entered prints error message
        }
}

// Function that searchs the result array for all the robots tested with user inputed name
void search_results(Results* res, int test_id){
        char Name1[20], Name2[20], Name3[4]= "All";
        int  i;

        printf("Enter your Robot Name: (Type All for all Robots) "); //prompts user to enter name of robot that has been tested
        scanf("%s", Name1);
        printf("-----------------------------------------------------------------------------------------------------------------------------------------------------------------\n"); // Bar for aesthetic's 
        printf("------------------------------------------------------------------------------------------------------------------------------------------------------------------\n"); // Bar for aesthetic's 
        printf("Test_Id   |Robot_Id   |Robot_Name        |Year       |Top_speed |Mass       |Best_score |finish_line_distance | finish_line_time |Strength |combat effectiveness |\n");
        printf("----------|-----------|------------------|-----------|----------|-----------|-----------|---------------------|------------------|---------|---------------------|\n"); // Bar for aesthetic's 

        for (i=0; i<test_id; i++){ // for loop to go through all of the robots results
        strcpy(Name2, res[i].Robot_Name); 
        if ((strcmp(Name1,Name2)==0)) // checks if name of robot the user has entered has any results by checking name
        {
            print_results(res, i); //prints all the results of the robot that user has entered. Multiple results will be printed
            printf("-----------------------------------------------------------------------------------------------------------------------------------------------------------------\n"); // Bar for aesthetic's             }
        }

    }
        if (strcmp(Name1,Name3)==0) { // checks if user enters all. If user enters All prints all robot 
        for (i=0; i<test_id; i++){ // for loop to print all robots results
            print_results(res, i); // calls function to print the robots result
            }
        printf("-----------------------------------------------------------------------------------------------------------------------------------------------------------------\n"); // Bar for aesthetic's             }
        }
        if (test_id == 0) // checks if simulations have occured.
        {
            printf("\nNo simulations have occurred.\n\n"); // error message if no simulations have occured 
        }
} 


//Calculate_speed to check the values entered are in correct and to calculate the speed
float calculate_speed(float finish_line_distance, float finish_line_time)
{   float speed; // sets the valuable for speed
		while(finish_line_distance < 0 || finish_line_time < 0){ // sets up loop until the values for speed and time are valid.
		printf("Please input the correct finish time of the robot in seconds: \n"); ////Prompt user for the correct distance.
		scanf("%f", &finish_line_time);  //set the new variables finish_time.
		printf("Please input the correct distance in meters to the finish line: \n"); // sets uo loop until the values for speed and time are valid.
		scanf("%f", &finish_line_distance); //set the new variables distance
		}
		speed = finish_line_distance/finish_line_time; //calculation for the speed
        printf("Robot Speed is equal to: %.2f\n", speed);
	return speed;
}

int calculate_strength()
{	int strength; // introduces strength variable.
    while(strength < 0 || strength > 100){ // sets up loop until a value between 0 and 100 is given
            printf("How many objects can the robot lift:  \n"); //set the variables finish_time
            scanf("%d", &strength); //Prompt user for distance
        }
    return strength; 
}

int calculate_combat(float speed, int strength)
{  int i, combat_effectiveness=0, simulation_number=100, random_num, maxrange, minrange, gap_range, random_win; // introduces new variables
	srand(time(NULL)); //sets seed for random number

	printf("The Combat is about to start!\n"); // pauses the program
	system("pause");
// Check the speed and if its over 50 set it to 50
	if (speed > 50){
		speed = 50;
	}
	// sets the max range and min range for winning. Calculations for the ranges
	maxrange = speed + ((strength*50)/100)+10;
	minrange = speed + ((strength*50)/100)-10;
	gap_range = maxrange - minrange;

//Loop for i = 1 to i = 100 to simulate 100 rounds of combat
	for (i=1; i<=simulation_number; i++){ // increases the number of i by 1 every round
			random_num = rand()%100+0; // gets a random number between 0 and 100
			random_win=rand()%gap_range+ minrange;	// generates a random number between the min chance of winning and max range.
			if (random_win > random_num){       //checks if the random number is is range for win.
				printf("Robot won!\n"); //prints loss
				combat_effectiveness++; // increase the count of total wins
			}
			else{
				printf("robot lost\n"); //Prints win
			}
		
		}
		printf(" Number of simulation: %d; Robot wins %d of times!\n", simulation_number, combat_effectiveness); //prints the number of times the robot has won
        
	return combat_effectiveness;
	}
//Function to print a
void result_table(Robot* rob, int check, int combat_1, float finish_line_distance, float finish_line_time, int strength, int test_id){
        printf("\n\n\n----------------------------------------\n"); // Bar for aesthetic's 
        printf("----------------------------------------\n"); // Bar for aesthetic's 
        printf("|     Robot test/ Simulation results   |\n"); // Bar for aesthetic's 
        printf("|--------------------------------------|\n"); // Bar for aesthetic's 
        printf("|----------------------|---------------|\n"); // Bar for aesthetic's 
        printf("|        Test ID       |      %-9d|\n",test_id); // prints test id
        printf("|----------------------|---------------|\n"); // Bar for aesthetic's 
        printf("|  Robot infomation    |---------------|\n"); // Bar for aesthetic's 
        printf("|--------------------------------------|\n"); // Bar for aesthetic's 
        printf("|    Robot_number      |   %-12d|\n",rob[check].Robot_Number); // Prints robot number
        printf("|    Robot_name        |   %-12s|\n",rob[check].Robot_Name); // Prints robot name
        printf("|    Year_manufactured |   %-12d|\n",rob[check].Year_Manufactured); // prints robot year manufactured
        printf("|    Top_speed         |   %-12.2f|\n",rob[check].Top_Speed); // prints top speed
        printf("|    Mass              |   %-12.2f|\n",rob[check].Mass); // prints mass of robot
        printf("|    Best_score        |   %-12.2f|\n",rob[check].Best_score); // prints best score 
        printf("|--------------------------------------|\n"); // Bar for aesthetic's 
        printf("|    Test conditions   |---------------|\n"); // Bar for aesthetic's 
        printf("|--------------------------------------|\n"); // Bar for aesthetic's 
        printf("| finish_line_distance |   %-6.2f      |\n",finish_line_distance); // prints finish line distance 
        printf("|   finish_line_time   |   %-6.2f      |\n",finish_line_time); // prints finish line time
        printf("|       Strength       |   %-6d      |\n",strength); // prints strength
        printf("|--------------------------------------|\n"); // Bar for aesthetic's 
        printf("|  Simulation results  |---------------|\n"); // Bar for aesthetic's 
        printf("|--------------------------------------|\n"); // Bar for aesthetic's 
        printf("| combat_effectiveness |   %-6d      |\n", combat_1); // prints combat_1 
        printf("----------------------------------------\n"); // Bar for aesthetic's 
        printf("----------------------------------------\n\n\n\n"); // Bar for aesthetic's 

}

//Function to find the robots with the highest speed strength and combat then displays the results
void display_winner(Results* res, int test_id){

    int win1=0, win2=0, win3=0, i; // sets new variables for each win conditions 

    for ( i = 0; i < test_id; i++) // for loop to check all the robots speed to see which is the highest speed
    {
        if (res[i].Top_Speed > res[win1].Top_Speed) // checks the robots top speed compared with new top speed
        {
            win1=i; // changes win1 when top speed is greater
        }
    }
    for ( i = 0; i < test_id; i++) // for loop to check all the robots strength to see which is the highest strength 
    {
        if (res[i].strength > res[win2].strength) //checks if new strenght is greater than current strength 
        {
            win2=i; //changes win2 when strength is greater
        }
    }
    for ( i = 0; i < test_id; i++) // for loop to check which robots combat effectiveness is greatest
    {
        if (res[i].combat_1 > res[win3].combat_1) //checks if combat is highter
        {
            win3=i;
        }
    }
        printf("\n\n %s won in terms of speed. Speed of %.1f\n", res[win1].Robot_Name, res[win1].Top_Speed); //prints the robot with the highest top speed
        printf(" %s won in terms of strength. Strength of %d\n", res[win2].Robot_Name, res[win2].strength); //prints the robot with the highest strength
        printf(" %s won in terms of combat effectiveness. Combat effectiveness of %d\n\n", res[win3].Robot_Name, res[win3].combat_1); // Prints the robobt with the highest combat effectiveness
};



int main(){
    //Sets new variables 
    Robot Robot_info[10]; //sets struct for the robot
    Results Results1[10]; // sets struct for the info

    float Top_S, Mass_R, Best_score_R;
    int  ID_R, Year_R, number_of_robots, i; // variables used in main
    char Name_R[20];

    FILE* Robot_file = fopen("Robot.txt", "r"); // calls/opens robot.txt file to read 
	if(Robot_file == NULL) //checks if robot file exist
	{
		printf("ERROR! the file failed to open\n"); //exits if no file found
		exit(-1);
	}

    i=0;
    while(fscanf(Robot_file, "%d %s %d %f %f %f", &ID_R, Name_R, &Year_R, &Top_S, &Mass_R, &Best_score_R) ==6){ //scans the robot.txt for 6 variables  
        Robot_info[i].Robot_Number =ID_R; 
        strcpy(Robot_info[i].Robot_Name, Name_R);
        Robot_info[i].Year_Manufactured =Year_R; // saves 6 variables from the robot.txt to the robot struct 
        Robot_info[i].Top_Speed =Top_S;
        Robot_info[i].Mass = Mass_R;
        Robot_info[i].Best_score =Best_score_R;
        i++; // bumps the count to store in different array
    }
    number_of_robots=i;
    fclose(Robot_file); // closes file

    printf("Assignment 2 - 10495873_Robert Sauta\n"); //greeting text
	printf("Welcome to the 2019 ECU robot tournament simulator\n"); //greeting text
    printf("Here are the current contestants:\n"); //greeting text
    printf("------------------------------------------------------------------------------------------------------------\n"); // Bar for aesthetic's 
	printf("------------------------------------------------------------------------------------------------------------\n"); // Bar for aesthetic's 
	printf("Robot Number |   Robot Name   |    Year_Manufactured    |    Top Speed    |    Mass      |   Best_Score    |\n"); // 
	printf("-------------|----------------|-------------------------|-----------------|--------------|-----------------|\n"); // Bar for aesthetic's 
    for (i=0; i<number_of_robots; i++){ //for to print all of the robot info
	print_Robot(Robot_info[i]); // prints the robot info speciftic to robot i
    printf("-------------|----------------|-------------------------|-----------------|--------------|-----------------|\n");
    }
    printf("------------------------------------------------------------------------------------------------------------\n"); // Bar for aesthetic's 


int choice, check, strength, combat_1, test_id=0, Check1=0, save1;
float finish_line_distance, finish_line_time, speed;                    //variables used in do loop
char  answer;


	do{ // do loop for program to repeat.
        printf("1. Search Robots, 2. Input/Update Robot, 3. Simulate Combat, 4. Display Results, 5. Display Winners, 6. Save Robot Infomation, 7. Save all Results, 8. Exit\n"); // Menu text 
        printf("Enter your choice (1~8): "), // Prompts user for choice and scans users input
		scanf("%d", &choice); 

		switch (choice) // Switch for programs menu
		{
		case 1: //Search a robot
               
            search_robot(Robot_info, number_of_robots); // calls for search robot function 
			break; // break to return to menu
		case 2: //Input/update a robot
            printf("Enter your robots id number: "), // Prompts user for robots Id and scans user input
		    scanf("%d", &check); 
            if (check<=number_of_robots) // Checks if robot id entered exisit if it doesnt will allow user to enter new robot info
            {
                edit_robot(Robot_info, check); // edits the robot info for robot with user inputed id
            }else 
            {
                printf("No Robot exists with that ID\n"); // reveals to user that robot of user inputed id doesnt exist
                printf("Enter in new Robot details:\n");
                enter_new_robot(Robot_info, number_of_robots); // calls function to enter new robot info
                number_of_robots++; //increases the number of robots
            }
			break; // break to return to menu
		case 3: // Simulate a robot against a human opponent

                printf("Robot Rumble is about begin\n"); // Tells user a simulation is going to occur
                printf("Please enter your Robots ID: "), // ask user for robot id for simulation
                    scanf("%d", &check); // scans for robot id
                    check = check-1; // accounts for Robot 1 being at robot_info[0]
                while (check > number_of_robots){ //checks if robots id exist 
                    printf("Please enter an existing Robot ID: "),
                        scanf("%d", &check); // scans user input for robot id
                }
                printf("Enter finish line distance: \n"), // ask user to input distance
                    scanf("%f", &finish_line_distance); // scan user input for distance
                printf("Enter finish line time: \n"), // ask user to input time
                    scanf("%f", &finish_line_time); // scans user for time

                    speed = calculate_speed(finish_line_distance, finish_line_time); //  Calls for fucntion to calculate speed

                    strength = calculate_strength(); // Calls for fucntion to calculate strength

                    combat_1 = calculate_combat(speed, strength); // calls for function to start combat simulation 

                if (combat_1 >= Robot_info[check].Best_score) // Checks if new combat score is better than robot best score stored in struct
                {
                printf("The robot performed better than its previous attempt would you like to replace its current best score? (Y/N) "), // ask user if they want to replace best score
                scanf("%s", &answer); // scans users answer
                        if (answer == 'y' || answer == 'Y') // if answer is y or Y
                        {
                            Robot_info[check].Best_score = combat_1; // changes old best score to new best score
                            answer= 1;
                        }
                        
                }
                test_id++;//bumbs count for test id
                result_table(Robot_info, check, combat_1, finish_line_distance, finish_line_time, strength, test_id); //calls for function to print out results of the most recent combat simulation 

                printf("Press 1 to save the keep the results in array: "), // prompts user if they want to save result of simulation to 
                scanf("%d", &save1);
                if (save1==1)
                {
                    Results1[Check1].test_id = test_id;
                    Results1[Check1].Robot_Number = Robot_info[check].Robot_Number;
                    strcpy( Results1[Check1].Robot_Name, Robot_info[check].Robot_Name); //copies name to struct results
                    Results1[Check1].Year_Manufactured = Robot_info[check].Year_Manufactured;
                    Results1[Check1].Top_Speed = speed;                                             // saves results to struct results
                    Results1[Check1].Mass = Robot_info[check].Mass;
                    Results1[Check1].Best_score = Robot_info[check].Best_score;

                    Results1[Check1].finish_line_distance = finish_line_distance;
                    Results1[Check1].finish_line_time = finish_line_time;
                    Results1[Check1].strength = strength;
                    Results1[Check1].combat_1 = combat_1;
                    Check1++;
                    printf("Saved\n"); // tells user that info is saved
                }
			break; // break to return to menu
		case 4: // Display simulation results
                if (test_id == 0) //checks if simulation has occoured
                {
                    printf("\nNo simulations have occurred.\n\n"); 
                }else
                {
                    search_results(Results1, Check1);
                }
			break; // break to return to menu
		case 5: // Display winners
                if (test_id == 0) //checks if simulation has occoured
                {
                    printf("\nNo simulations have occurred.\n\n");
                }else
                {
                    display_winner(Results1, Check1);
                }
			break;
		case 6: // Save robot Infomation
            Robot_file = fopen("Robot.txt", "w"); //re open robot.txt to save new info
                if(Robot_file == NULL) //checks if file exist
                {
                    printf("ERROR! the file failed to open\n"); // error message if file doesnt exist 
                    exit(-1); // exits
                }
                for (i=0; i<number_of_robots; i++){ // for loop to save all robots new and old
		        fprintf(Robot_file, "%d %s %d %.2f %.2f %.2f\n", Robot_info[i].Robot_Number, Robot_info[i].Robot_Name, Robot_info[i].Year_Manufactured, Robot_info[i].Top_Speed, Robot_info[i].Mass, Robot_info[i].Best_score); // writes robot info to robot.txt file
                }
                printf("Robots saved to robot.txt file\n");  // prompts user that file has been updated
                fclose(Robot_file); // closes file
			break; // break to return to menu
		case 7: // Save all result
                if (test_id == 0) //checks if simulation has occoured
                {
                    printf("\nNo simulations have occurred.\n\n"); // prompts user that no info has occured 
                }else
                {
                    
                    Robot_file = fopen("Results.txt", "w"); //opens new file to save results 
                    for (i=0; i<Check1; i++){ // for loop to save all results in results struct that have occured
                    // Writes the result info into results text for each result
		            fprintf(Robot_file, "%d %d %s %d %.2f %.2f %.2f %.2f %.2f %d %d\n", Results1[i].test_id, Results1[i].Robot_Number, Results1[i].Robot_Name, Results1[i].Year_Manufactured, Results1[i].Top_Speed, Results1[i].Mass, Results1[i].Best_score, Results1[i].finish_line_distance, Results1[i].finish_line_time, Results1[i].strength, Results1[i].combat_1);
                    }
                 fclose(Robot_file); //closes file
                }
			break; // break to return to menu
		case 8: // Exit
			break;
		default:
                printf("Invalid input, please a number between 1~8\n\n");
			break; // break to return to menu
		}
	}
		while(choice !=8); // loop break for the main function
	return 0;
}

