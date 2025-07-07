# ColorLearner-CPP
 An interactive C++ color learning and assessment tool.

# 🎨 Color Learning and Assessment Tool (C++)

This project is an interactive C++ console application that helps users **learn and identify colors** through a fun, quiz-based approach. Users view colored blocks, type the name of the color, and receive instant feedback. The system logs results, tracks performance, and adapts difficulty accordingly.

---

## 🚀 Features

- Teaches 10 different colors using terminal-based colored blocks
- Quiz system to test user's color recognition skills
- Case-insensitive input handling
- Tracks correct/incorrect answers across sessions
- Automatically increases difficulty level for wrongly answered colors
- Saves quiz history in a text file
- Displays average performance over all attempts

---

## 🧠 Data Structures Used (and Their Role)

| Data Structure       | Usage in the Project                                                                 |
|----------------------|----------------------------------------------------------------------------------------|
| `struct`             | Defines a `Color` object holding name, display code, and difficulty score.            |
| `vector<Color>`      | Stores the list of 10 predefined colors for teaching and quizzing.                    |
| `unordered_map`      | Tracks the number of correct and incorrect responses for each color across turns.     |
| `string`             | Used for input, output, and storing color names and terminal codes.                   |

These data structures make the code:
- 💡 Simple and modular
- 📈 Scalable for more colors or complexity
- 🔄 Efficient for dynamic response tracking

---

## 🖥️ How to Run the Project

1. Save the code in a file named `ColorLearning.cpp`.
2. Open terminal or command prompt.
3. Compile using:

g++ ColorLearning.cpp -o colorlearn

4. Run it:

./colorlearn

---

## 📸 Sample Output

```text
Here are the colors you will learn:
- Red (or red)
- Blue (or blue)
- Green (or green)
- Yellow (or yellow)
- Orange (or orange)
- Purple (or purple)
- Black (or black)
- White (or white)
- Pink (or pink)
- Brown (or brown)

Let's start identifying colors!

Turn 1
██████████
██████████
██████████

What color is this? pink  
Incorrect! The correct color is Purple.

Turn 2
██████████
██████████
██████████

What color is this?
📊 Performance Evaluation
After each session, results are logged in a file: ColorLearningLog.txt

Each turn logs:
Color name
Response (Correct/Incorrect)
Difficulty level
At the end, you’ll see:
Count of correct & incorrect responses for each color
Dynamic difficulty level
Cumulative average performance across all sessions

Example summary:

Red: Correct = 2, Incorrect = 1, Difficulty = 1  
Blue: Correct = 3, Incorrect = 0, Difficulty = 0  
...
Average performance (all sessions): 83.3%

```

##📁 File Storage

All quiz logs are saved to ColorLearningLog.txt

Appends new session data without erasing old logs

Useful for tracking progress over time

##🛠️ Technologies Used

Language: C++

Concepts: File handling, Data Structures, ANSI Terminal Coloring, Looping, Conditional Logic

##📜 License

This project is free to use and modify for educational purposes.
