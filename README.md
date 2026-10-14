# Competition Score Calculator (C)

A lightweight CLI tool written in C that models competitor data, calculates fair Olympic scores, and ranks participants using Bubble Sort.

I built this project to get hands-on experience with **`struct` data structures**, **array manipulations**, and **sorting algorithms** in C.

---

## How It Works

1. **Competitor Data (`struct`)**: Stores participant details like name, surname, age, and an array of 10 judge scores.
2. **Olympic Scoring Logic**: Automatically finds and discards the **highest** and **lowest** scores to eliminate bias, then calculates the average of the remaining 8 scores.
3. **Leaderboard Ranking**: Sorts competitors in descending order using Bubble Sort based on their final average score.
4. **Input Validation**: Keeps score inputs strictly between 0 and 6, and guards string buffers against overflow.

---

## 🛠️ Build & Run

Compile using any standard C compiler (like `gcc`):

```bash
# Compile
gcc -o score_calculator competition-score-calculator.c

# Run
./score_calculator