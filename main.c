#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>

// We get introduced to the game.
// Start game
// Choose your first hand --> // Agent chooses theirs
// Compare hands --> winner gets point
// When max points is achieved --> winning player wins
// Terminate

// Player hand is picked. Activate choiceMade 1 --> computer make choice
// if choice = 1 & computer made choice --> run comparator() which returns the
// winner (status [0(tie), 1(player), 2(computer)]) winner --> winner gets
// points++ Reloop.

enum Game { ROCK, SCISSORS, PAPER, SPOCK, LIZARD };

const char *gameNames[] = {"ROCK", "SCISSORS", "PAPER", "SPOCK", "LIZARD"};

enum GameMode { CONTINUE, WON, LOST };

enum Game playerChoice(char input[]);

int computerChoice(void);

int comparator(enum Game c, enum Game p);

int main(void) {

  srand(time(NULL));
  enum Game hand;
  enum GameMode gameMode;

  int computerPoints = 0;
  int playerPoints = 0;
  bool playerPlayed = false;
  bool computerPlayed = false;

  printf("Welcome to RPSSL! Begin game? (Y/N): ");

  char choice;

  while (1) {
    scanf("%c", &choice); // grab exactly 1 char
    while (getchar() != '\n')
      ; // discard everything else until newline

    if (choice == 'y' || choice == 'Y') {
      break;
    } else if (choice == 'n' || choice == 'N') {
      printf("You chose not to play. Bye!");
      gameMode = LOST;
      return 0;
    } else {
      printf("Please try again. Play? (Y/N): ");
    }
  }

  gameMode = CONTINUE;
  printf("Great! Let's play.\nMake your choice!: ");

  while (CONTINUE == gameMode) {
    enum Game p;
    char userHand[20];
    int tries = 0;

    while (1) {
      scanf("%s", userHand);
      userHand[strcspn(userHand, "\n")] = '\0';
      p = playerChoice(userHand);

      if (p == -1) {
        if (tries == 5) {
          printf("PLEASE! Pick the right HAND!\n");
        } else if (tries == 10) {
          printf("FINE! You clearly do not want to play. BYE!");
          return 0;
          break;
        }
        printf("Please choose a valid hand: ");
        tries++;
        continue;
      } else {
        printf("Player chose: %s\n\n", gameNames[p]);
        playerPlayed = true;
        tries = 0;
        break;
      }
    }

    enum Game c = computerChoice();
    computerPlayed = true;

    if (computerPlayed && playerPlayed) {
      int status = comparator(p, c);
      if (status == 1) {
        Sleep(2000);
        playerPoints++;
        printf("Player wins this round! %s beats %s\nPlayer points: %d. "
               "Computer points: %d\n",
               gameNames[p], gameNames[c], playerPoints, computerPoints);
        playerPlayed = 0;
        computerPlayed = 0;
      } else if (status == 2) {
        computerPoints++;
        Sleep(2000);
        printf("Computer wins this round! %s beats %s\n Player points: %d, "
               "computer points: %d\n",
               gameNames[c], gameNames[p], playerPoints, computerPoints);
        playerPlayed = 0;
        computerPlayed = 0;
      }
    }

    if (playerPoints == 5) {
      gameMode = WON;
      printf("Player wins! Good job! Exiting program.");
    } else if (computerPoints == 5) {
      gameMode = LOST;
      printf("Naw..! Computer wins! Better luck next time. \n\nExiting "
             "program....");
    } else {
      printf("Make your new choice: ");
    }
  }

  if (LOST == gameMode) {
    return 0;
  }

  if (WON == gameMode) {
    printf("Player won! Computer lost! Exiting program.");
    return 0;
  }
}

int computerChoice(void) {
  // Computer makes hand choice at random.

  printf("It is computer's turn to make a choice.\n\n");
  Sleep(1000);

  printf("Thinking.....\n\n");
  Sleep(1000);

  printf("Finalizing input.....\n\n");
  Sleep(2000);

  enum Game choice = rand() % 5;

  printf("Computer chose %s\n\n", gameNames[choice]);
  return choice;
}

// Compares player input to the enum values:
enum Game playerChoice(char input[]) {
  if (strcmp(input, "ROCK") == 0 || strcmp(input, "rock") == 0)
    return ROCK;
  else if (strcmp(input, "SCISSORS") == 0 || strcmp(input, "scissors") == 0)
    return SCISSORS;
  else if (strcmp(input, "PAPER") == 0 || strcmp(input, "paper") == 0)
    return PAPER;
  else if (strcmp(input, "SPOCK") == 0 || strcmp(input, "spock") == 0)
    return SPOCK;
  else if (strcmp(input, "LIZARD") == 0 || strcmp(input, "lizard") == 0)
    return LIZARD;
  else
    return -1; // invalid input
}

int comparator(enum Game p, enum Game c) {

  const enum Game beats[5][2] = {{SCISSORS, LIZARD}, // ROCK
                                 {LIZARD, PAPER},    // SCISSORS
                                 {ROCK, SPOCK},      // PAPER
                                 {SCISSORS, ROCK},   // SPOCK
                                 {SPOCK, PAPER}};    // LIZARD

  if (p == c) {
    printf("It's a tie! Both picked %s\n", gameNames[p]);
    return 0; // tie
  }
  for (int i = 0; i < 1; i++) {
    if (beats[p][i] == c) {
      return 1; // Player wins
    } else if (beats[p][i] != c) {
      return 2; // Computer wins
    }
  }
  // Default case, should not be reached
  return 0;
}