// pase here 
#include<stdio.h>
#include<stdbool.h>
#include <stdlib.h>
#include <time.h>

void craps(void);
void pigs(void);
void twoDicePigs(void);
void abyss(void);

void main (void){
    int answer;
    int exit = 0;

    while (exit <1){
        printf("Which game would you like to play?\n");
        printf("Enter 1 for Craps\nEnter 2 for The Abyss\nEnter 3 for Pig\nEnter 0 to Quit\n");
        printf("Your choice? ");
        int exit2 = 0;
        while(exit2<1){
        scanf("%d",&answer);

        if(answer==1){
            craps();
            exit2++;
        }
        else if(answer==2){
            abyss();
            exit2++;
        }
        else if(answer==3){
            pigs();
            exit2++;
        }
        else if(answer==0){
            exit2++;
            exit++;
        }
        else if(answer=='\n' || answer=='\t' || answer==' '){
            continue; 
        }
        else{
            printf("Please enter a valid option: ");
        }
     }
   }
}

//Craps
enum Status {COUNTINUE,WON,LOST};
int raandom(void) {
    int die1= 1+(rand()%6);
    int die2= 1+(rand()%6);
    printf("Point is %d + %d = %d\n",die1,die2,die1+die2);

    return die1+die2;
}
void craps(void){

    srand(time(NULL));
    int Mypoint; 
    enum Status gameStatus;
    int sum = raandom();

    switch(sum){

        case 7:
        case 11:
        gameStatus = WON;
        break;

        case 2:
        case 3: 
        case 12: 
        gameStatus = LOST;
        break;

        default:
        gameStatus =COUNTINUE;
        Mypoint=sum;
        printf("Point is %d\n", Mypoint);
        break;

    }
    while(gameStatus==COUNTINUE){
        sum = raandom(); 

        if(sum==Mypoint){
            gameStatus =WON;
        }
        else if(sum==7){
            gameStatus =LOST;
        }
        else{
            gameStatus =COUNTINUE;
        }
    }
    if(gameStatus==WON){
        puts("You won");
    }
    else{
        puts("You lost");
    }
    
}

//Abyss
int ABYSS_HUMAN_PART(void){
    
    int point=0;
    char answer;
    int exit=0;
    printf("Please enter R to roll: ");

    while(exit<1){
        scanf("%c",&answer);

        if(answer=='R' || answer=='r'){
            point=1+rand()%6;
            exit++;
        }
        else if(answer=='\n' || answer=='\t' || answer==' '){
            continue;
        }
        else{
            printf("Only r or R: ");
        } 
    }
    printf("you rolled %d\n",point);
    return point;
}

int ABYSS_COMPUTER_PART(void){
    int point=1+rand()%6;
    return point;
}

void abyss(void){
    srand(time(NULL));
    printf("Welcome to Abyss!\n");
    int humanpoint=0; 
    int computerpoint=0; 
    int exit=0;
    while(exit<1){
        printf("\t\t\t\t\t\tyour total: %d\t\t\t computers total: %d\n",humanpoint, computerpoint);
        int human_roll=ABYSS_HUMAN_PART();
        int humanpoint_after_roll=humanpoint+human_roll;
        int computer_roll=ABYSS_COMPUTER_PART();
        int computerpoint_after_roll=computerpoint+computer_roll; 

        if(humanpoint_after_roll==26){
            printf("you got 26, you win!\n");
            exit++;
        }
        else if(computerpoint_after_roll==26){
            printf("computer got 26, computer wins!\n");
            exit++;
        }
        else if(humanpoint_after_roll>26 && computerpoint_after_roll>26){
            humanpoint;
            computerpoint;
        }
        else if(humanpoint_after_roll>26){
            humanpoint;
            computerpoint=computerpoint_after_roll;
        }
        else if(computerpoint_after_roll>26){
            computerpoint;
            humanpoint=humanpoint_after_roll;
        }
        else if (humanpoint_after_roll==13){
            printf("you got 13, you lost :(\n");
            exit++;
        }
        else if(computerpoint_after_roll==13){
            printf("computer got 13, you win!\n");
            exit++;
        }
        else if(humanpoint_after_roll<=12 && humanpoint_after_roll==computerpoint){
            printf("you got the same point as computer, your point goes to 0!\n");
            humanpoint=0;
            computerpoint=computerpoint_after_roll;
        }
        else if(computerpoint_after_roll<=12 && computerpoint_after_roll==humanpoint_after_roll){
            printf("computer got the same point as you, computers point goes to 0!\n");
            computerpoint=0;
            humanpoint=humanpoint_after_roll;
        }
        else if(humanpoint_after_roll<=24 && humanpoint_after_roll>12 && humanpoint_after_roll==computerpoint){
            printf("you got the same point as computer, your point goes to 12!\n");
            humanpoint=12;
            computerpoint=computerpoint_after_roll;
        }
        else if(computerpoint_after_roll<=24 && computerpoint_after_roll>12 && computerpoint_after_roll==humanpoint_after_roll){
            printf("computer got the same point as you, computers point goes to 12!\n");
            computerpoint=12;
            humanpoint=humanpoint_after_roll;
        }
        else if(humanpoint_after_roll==25 && humanpoint_after_roll==computerpoint){
            printf("you got 25 and computer already sits on 25, you point goes to 14!\n");
            humanpoint=14;
            computerpoint=computerpoint_after_roll;
        }
        else if(computerpoint_after_roll==25 && computerpoint_after_roll==humanpoint_after_roll){
            printf("computer got 25 and you already sit on 25, computers point goes to 14!\n");
            computerpoint=14;
            humanpoint=humanpoint_after_roll;
        }
        else{
            humanpoint=humanpoint_after_roll;
            computerpoint=computerpoint_after_roll;
        }
    }       
}

//Pigs
int PIGS_COMPUTER_PART (void){

    int point= 0; 
    int exit=0;

    while(exit<1){
        int roll1 = 1+rand()%6;
        if (roll1==1){
            point=0;
            printf("computer got %d points round\n",point);
            exit++;
            return point;
        }
        else{
            point= point + roll1;
            int roll2 = 1+rand()%6;    
            if(roll2==1){
                point=0;
                printf("computer got %d points this round\n",point);
                exit++;
                return point;
            }
            else{
                point= point + roll2;
                int exit2=0;
                while(exit2<1){
                int decision = 1+rand()%2;
                if(decision== 1){
                    printf("computer got %d points this round\n",point);
                    exit2++;
                    exit++;
                    return point;
                }
                else{
                    int roll= 1+rand()%6;
                    if(roll==1){
                        point=0;
                        printf("computer got %d points this round\n",point);
                        exit++;
                        exit++;
                        return point;
                    }
                    else{
                        point= point + roll;  
                    }    
                }
            }
        }
    }
 }
}

int PIGS_HUMAN_PART(void){
    int point=0;
    int exit=0;
    int answer;

    printf("for rol enter R and for hold enter H: ");

    while(exit<1){
        answer= getchar();

        if(answer=='H' || answer=='h'){
            exit++;
        }
        else if(answer=='R' || answer=='r'){
            int roll= 1+rand()%6;
            if(roll==1){
                printf("sorry you rolled 1\n");
                point=0;
                printf("you got %d points this round\n",point);
                exit++;
            }
            else{
                printf("you rolled %d\n",roll);
                point= point + roll;
                printf("so far you got %d points this round\n",point);
            }
        }
        else if(answer=='\n' || answer=='\t' || answer==' '){
            continue;
        }
        else{
            printf("Only R or H: ");
        }
    }
    return point;
}


void pigs(void){
    printf("Welcome to Pigs!\n");
    srand(time(NULL)); 
    int humanpoint= 0;
    int computerpoint=0;


    while (humanpoint <100 && computerpoint <100){
        printf("\t\t\t\t\t\tyour total: %d\t\t\t computers total: %d\n",humanpoint, computerpoint);
        humanpoint=humanpoint + PIGS_HUMAN_PART();
        computerpoint= computerpoint + PIGS_COMPUTER_PART();
    }

    if(computerpoint < humanpoint){
        printf("you win!\n");
        }
    else if(computerpoint > humanpoint){
        printf("computer wins!\n");
    }
    else{
        printf("equal!\n");
    }
    printf("%d\n",humanpoint);
    printf("%d\n", computerpoint);  
}

