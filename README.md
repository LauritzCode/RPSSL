# Rock–Paper–Scissors–Lizard–Spock (RPSSL)

A console-based implementation of **Rock–Paper–Scissors–Lizard–Spock** written in C.  
The game is extended from the classic Rock–Paper–Scissors to include **Lizard** and **Spock**, popularized by *The Big Bang Theory*.

---

##  How to play
1. Run the program.
2. When prompted:
   - Enter **Y** to start playing.
   - Enter **N** to exit the game.
3. On each round:
   - Type your choice:  
     `ROCK`, `PAPER`, `SCISSORS`, `LIZARD`, or `SPOCK`  
     (case-insensitive).
   - The computer will make a random choice.
   - The winner of the round is announced, and points are updated.
4. First to **5 points** wins the game!

---

## Rules
- **Rock** crushes Scissors and crushes Lizard.  
- **Paper** covers Rock and disproves Spock.  
- **Scissors** cuts Paper and decapitates Lizard.  
- **Lizard** eats Paper and poisons Spock.  
- **Spock** smashes Scissors and vaporizes Rock.  

---

## ⚙️ Requirements
- A C compiler 
- Windows (uses `Sleep()` from `<windows.h>` for delays).  

---

## Example run:

Welcome to RPSSL! Begin game? (Y/N): y
Make your choice!: ROCK
Player chose: ROCK

It is computer's turn to make a choice.
Thinking.....
Finalizing input.....
Computer chose SCISSORS.
Player wins this round! Rock beats SCISSORS.
Player points: 1. Computer points: 0.
Make your choice:

---

## Notes

Invalid inputs are rejected with a re-prompt.

After 10 invalid attempts in a row, the program exits.

Delays (Sleep()) simulate the computer "thinking" for a more engaging experience.
