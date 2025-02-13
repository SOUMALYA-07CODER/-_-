#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

struct User {
    string username;
    string password;
    int score;
};

struct Question {
    string questionText;
    vector<string> options;
    int correctAnswer;
};

map<string, User> users;
vector<Question> questions; 

void registerUser() {
    User newUser;
    cout << "Enter a username: ";
    cin >> newUser.username;
    cout << "Enter a password: ";
    cin >> newUser.password;
    newUser.score = 0;
    users[newUser.username] = newUser;
    cout << "Registration successful!\n";
}

void initializeQuestions() {
    questions = {
        {"What is the capital of France?", {"Paris", "London", "Berlin", "Madrid"}, 0},
        {"Which planet is known as the Red Planet?", {"Earth", "Mars", "Jupiter", "Saturn"}, 1},
        {"What is the largest ocean on Earth?", {"Atlantic", "Indian", "Arctic", "Pacific"}, 3},
        {"Who wrote 'Romeo and Juliet'?", {"William Shakespeare", "Charles Dickens", "Mark Twain", "Jane Austen"}, 0},
        {"What is the chemical symbol for water?", {"H2O", "CO2", "NaCl", "O2"}, 0}
    };
}

void takeQuiz(User &user) {
    int score = 0;
    cout << "\n--- Welcome to the Quiz, " << user.username << "! ---\n";
    for (size_t i = 0; i < questions.size(); ++i) {
        const auto &q = questions[i];
        cout << "\nQuestion " << i + 1 << ": " << q.questionText << "\n";
        for (size_t j = 0; j < q.options.size(); ++j) {
            cout << j + 1 << ". " << q.options[j] << "\n";
        }
        int answer;
        cout << "Your answer (1-" << q.options.size() << "): ";
        cin >> answer;
        if (answer - 1 == q.correctAnswer) {
            cout << "Correct!\n";
            score++;
        } else {
            cout << "Wrong! The correct answer was " << q.correctAnswer + 1 << ". " << q.options[q.correctAnswer] << "\n";
        }
    }
    user.score += score;
    cout << "\nQuiz ended! Your score is " << score << "/" << questions.size() << "\n";
    cout << "Your total score so far: " << user.score << "\n";
}

int main() {
    initializeQuestions();
    while (true) {
        cout << "\n--- ONLINE QUIZ GAME ---\n";
        cout << "1. Register\n";
        cout << "2. Take Quiz\n";
        cout << "3. Exit\n";
        cout << "Choose an option: ";
        int choice;
        cin >> choice;

        if (choice == 1) {
            registerUser();
        } else if (choice == 2) {
            string username;
            cout << "Enter your username: ";
            cin >> username;
            if (users.find(username) != users.end()) {
                takeQuiz(users[username]); 
            } else {
                cout << "User not found! Please register first.\n";
            }
        } else if (choice == 3) {
            cout << "Exiting the game. Goodbye!\n";
            break;
        } else {
            cout << "Invalid option! Please try again.\n";
        }
    }

    return 0;
}
