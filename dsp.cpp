#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <unordered_map>
#include <random> // ✅ Required for std::shuffle

using namespace std;

struct Color {
    string name;
    string code;
    int difficultyScore;
};

class ColorLearning {
private:
    vector<Color> colors;
    ofstream logFile;
    int turnCount;
    unordered_map<string, pair<int, int>> responses;

public:
    ColorLearning() {
        colors = {
            {"Red", "\033[41m", 0}, {"Blue", "\033[44m", 0}, {"Green", "\033[42m", 0},
            {"Yellow", "\033[43m", 0}, {"Orange", "\033[48;5;202m", 0},
            {"Purple", "\033[45m", 0}, {"Black", "\033[40m", 0}, {"White", "\033[47m", 0},
            {"Pink", "\033[48;5;206m", 0}, {"Brown", "\033[48;5;94m", 0}
        };

        turnCount = 1;
        logFile.open("ColorLearningLog.txt", ios::app);
        if (!logFile) {
            cerr << "Error: Could not open log file.\n";
            exit(1);
        }
    }

    ~ColorLearning() {
        logFile.close();
    }

    void teachColors() {
        cout << "Here are the colors you will learn:\n";
        for (auto& color : colors) {
            cout << color.code << "  " << "\033[0m - " << color.name << " (or " << toLower(color.name) << ")\n";
        }
    }

    void assessUnderstanding() {
        cout << "\nLet's start identifying colors!\n";
        random_device rd;
        mt19937 g(rd());
        shuffle(colors.begin(), colors.end(), g);

        for (auto& color : colors) {
            cout << "\nTurn " << turnCount << "\n";
            displayColorBlock(color.code);
            string userAnswer;
            cout << "What color is this? ";
            cin >> userAnswer;

            bool isCorrect = isAnswerCorrect(userAnswer, color.name);
            logResponse(color.name, isCorrect, color.difficultyScore);

            if (!isCorrect) {
                color.difficultyScore++;
                cout << "Incorrect! The correct color is " << color.name << ".\n";
            } else {
                cout << "Correct!\n";
            }

            turnCount++;
        }
    }

    void showResults() {
        int sessionCorrect = 0, sessionAttempts = 0;
        int fileCorrect = 0, fileAttempts = 0;

        cout << "\nYour performance summary:\n";
        logFile << "\nPerformance Summary:\n";

        for (auto& color : colors) {
            int correct = responses[color.name].first;
            int incorrect = responses[color.name].second;

            sessionCorrect += correct;
            sessionAttempts += (correct + incorrect);

            cout << color.name << ": Correct = " << correct << ", Incorrect = " << incorrect
                 << ", Difficulty = " << color.difficultyScore << "\n";

            logFile << color.name << ": Correct = " << correct << ", Incorrect = " << incorrect
                    << ", Difficulty = " << color.difficultyScore << "\n";
        }

        ifstream inputFile("ColorLearningLog.txt");
        string line;
        while (getline(inputFile, line)) {
            size_t correctPos = line.find("Correct = ");
            size_t incorrectPos = line.find(", Incorrect = ");

            if (correctPos != string::npos && incorrectPos != string::npos) {
                int correct = stoi(line.substr(correctPos + 10, incorrectPos - (correctPos + 10)));
                int incorrect = stoi(line.substr(incorrectPos + 13, line.find(", Difficulty") - (incorrectPos + 13)));

                fileCorrect += correct;
                fileAttempts += (correct + incorrect);
            }
        }
        inputFile.close();

        int totalCorrect = sessionCorrect + fileCorrect;
        int totalAttempts = sessionAttempts + fileAttempts;

        double avgPerformance = totalAttempts > 0 ? (static_cast<double>(totalCorrect) / totalAttempts) * 100: 0;

        cout << "\nYour average performance (all sessions): " << avgPerformance << "%\n";
        logFile << "\nAverage Performance (all sessions): " << avgPerformance << "%\n\n";
        cout << "Results saved to 'ColorLearningLog.txt'.\n";
    }

private:
    void displayColorBlock(const string& colorCode) {
        const int blockSize = 5;  
        for (int i = 0; i < blockSize; ++i) {
            for (int j = 0; j < blockSize; ++j) {
                cout << colorCode << "  " << "\033[0m";
            }
            cout << endl;
        }
    }

    bool isAnswerCorrect(const string& userAnswer, const string& correctAnswer) {
        return toLower(userAnswer) == toLower(correctAnswer);
    }

    string toLower(const string& str) {
        string lowerStr = str;
        transform(lowerStr.begin(), lowerStr.end(), lowerStr.begin(), ::tolower);
        return lowerStr;
    }

    void logResponse(const string& colorName, bool isCorrect, int difficulty) {
        string result = isCorrect ? "Correct" : "Incorrect";
        logFile << "Turn " << turnCount << ": Color = " << colorName
                << ", Response = " << result << ", Difficulty = " << difficulty << "\n\n";

        if (isCorrect) {
            responses[colorName].first++;
        } else {
            responses[colorName].second++;
        }
    }
};

int main() {
    ColorLearning assistant;

    assistant.teachColors();
    assistant.assessUnderstanding();
    assistant.showResults();

    return 0;
}
