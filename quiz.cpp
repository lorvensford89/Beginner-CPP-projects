// This is a quiz game where the user will have to answer questions
// more like 4 answers will be availible and he'll pick one. 
// There will be a score table at the end



#include <iostream>
#include <vector>
#include <string>
#include <random>
#include <cctype>

void quiz(){

    std::cout << "\n========================== QUIZ GAME ==========================\n\n";
    std::cout << "---------------------------------------------------------------\n";
    std::cout << "10 random questions out of 50.\nThe score will be display at the end\n\n";
    char user_guess;
    double score = 0;

    // The questions
    std::vector<std::string> questions = {

        "What planet is known as the Red Planet?",
        "How many days are there in a leap year?",
        "Which animal is known as “man’s best friend?”",
        "What is the largest ocean on Earth?",
        "What do bees produce?",
        "What color do you get by mixing red and blue?",
        "How many continents are there on Earth?",
        "What gas do humans need to breathe to survive?",
        "Which device is used to tell time ?",
        "Which season comes after summer ?",

        "What is the capital of France?",
        "How many hours are there in a day?",
        "Which animal says 'meow'?",
        "What do plants need for photosynthesis?",
        "Which planet is closest to the Sun?",
        "What shape has three sides?",
        "Which fruit is yellow and curved?",
        "What do cows drink?",
        "How many legs does a spider have?",
        "What color is the sky on a clear day?",

        "Which instrument has six strings?",
        "What do you use to write on paper?",
        "Which month comes after January?",
        "What is frozen water called?",
        "Which animal is the king of the jungle?",
        "How many wheels does a bicycle have?",
        "What do you call a baby cat?",
        "Which sense do you use to hear?",
        "What is the opposite of hot?",
        "What do you wear on your feet?",

        "Which planet do we live on?",
        "How many minutes are in an hour?",
        "Which animal can fly?",
        "What do you use to cut paper?",
        "What color are bananas when ripe?",
        "Which day comes after Friday?",
        "What do you call a place where books are kept?",
        "Which object gives us light?",
        "What do you use to eat soup?",
        "Which season is the coldest?",

        "What do you brush your teeth with?",
        "Which animal is known for its long neck?",
        "What do you use to open a door?",
        "What color is grass?",
        "What do you use to make a phone call?",
        "Which animal lives in water and has gills?",
        "What do you wear on your head?",
        "Which object tells temperature?",
        "What do you drink when you are thirsty?",
        "Which season comes before summer?"
    };

    // The answers
    std::vector<std::vector<std::string>> answers = {

        {"A. Venus", "B. Mars", "C. Jupiter", "D. Saturn"},
        {"A. 365", "B. 366", "C. 364", "D. 360"},
        {"A. Cat", "B. Horse", "C. Dog", "D. Dolphin"},
        {"A. Atlantic Ocean", "B. Indian Ocean", "C. Arctic Ocean", "D. Pacific Ocean"},
        {"A. Milk", "B. Honey", "C. Wax", "D. Sugar"},
        {"A. Green", "B. Orange", "C. Purple", "D. Brown"},
        {"A. 5", "B. 6", "C. 7", "D. 8"},
        {"A. Carbon dioxide", "B. Oxygen", "C. Nitrogen", "D. Hydrogen"},
        {"A. Thermometer", "B. Compass", "C. Clock", "D. Scale"},
        {"A. Winter", "B. Spring", "C. Autumn", "D. Monsoon"},

        {"A. Rome", "B. Madrid", "C. Paris", "D. Berlin"},
        {"A. 12", "B. 24", "C. 48", "D. 60"},
        {"A. Dog", "B. Cat", "C. Cow", "D. Bird"},
        {"A. Water", "B. Sunlight", "C. Air", "D. All of the above"},
        {"A. Mercury", "B. Venus", "C. Earth", "D. Mars"},
        {"A. Square", "B. Triangle", "C. Circle", "D. Rectangle"},
        {"A. Apple", "B. Banana", "C. Grape", "D. Cherry"},
        {"A. Milk", "B. Juice", "C. Water", "D. Soda"},
        {"A. 6", "B. 8", "C. 10", "D. 12"},
        {"A. Green", "B. Red", "C. Blue", "D. Yellow"},

        {"A. Piano", "B. Violin", "C. Guitar", "D. Drums"},
        {"A. Pen", "B. Spoon", "C. Plate", "D. Cup"},
        {"A. February", "B. March", "C. December", "D. April"},
        {"A. Ice", "B. Steam", "C. Snow", "D. Rain"},
        {"A. Tiger", "B. Lion", "C. Elephant", "D. Bear"},
        {"A. 1", "B. 2", "C. 3", "D. 4"},
        {"A. Puppy", "B. Kitten", "C. Cub", "D. Calf"},
        {"A. Sight", "B. Smell", "C. Hearing", "D. Taste"},
        {"A. Cold", "B. Warm", "C. Wet", "D. Soft"},
        {"A. Gloves", "B. Shoes", "C. Hat", "D. Jacket"},

        {"A. Mars", "B. Earth", "C. Venus", "D. Jupiter"},
        {"A. 30", "B. 45", "C. 60", "D. 90"},
        {"A. Dog", "B. Fish", "C. Bird", "D. Snake"},
        {"A. Knife", "B. Scissors", "C. Fork", "D. Spoon"},
        {"A. Green", "B. Yellow", "C. Red", "D. Blue"},
        {"A. Thursday", "B. Saturday", "C. Sunday", "D. Monday"},
        {"A. School", "B. Library", "C. Store", "D. Office"},
        {"A. Candle", "B. Chair", "C. Table", "D. Door"},
        {"A. Fork", "B. Knife", "C. Spoon", "D. Plate"},
        {"A. Winter", "B. Spring", "C. Summer", "D. Autumn"},

        {"A. Soap", "B. Toothpaste", "C. Water", "D. Towel"},
        {"A. Elephant", "B. Giraffe", "C. Horse", "D. Dog"},
        {"A. Key", "B. Phone", "C. Plate", "D. Book"},
        {"A. Blue", "B. Yellow", "C. Green", "D. Red"},
        {"A. Computer", "B. Television", "C. Phone", "D. Radio"},
        {"A. Dog", "B. Bird", "C. Fish", "D. Cat"},
        {"A. Shoes", "B. Hat", "C. Shirt", "D. Socks"},
        {"A. Clock", "B. Thermometer", "C. Scale", "D. Compass"},
        {"A. Milk", "B. Water", "C. Juice", "D. Soda"},
        {"A. Winter", "B. Spring", "C. Autumn", "D. Summer"}
    };

    std::vector<char> answer_keys = {
        'B','B','C','D','B','C','C','B','C','C',
        'C','B','B','D','A','B','B','C','B','C',
        'C','A','A','A','B','B','B','C','A','B',
        'B','C','C','B','B','B','B','A','C','A',
        'B','B','A','C','C','C','B','B','B','B'
    };



    // Generate random numbers
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> distr(1, 50);

    std::vector<int> random_numbers;

    for (size_t i = 0; i < 10; i++)
        random_numbers.push_back(distr(gen));

    // 10 unique random numbers
    for (size_t i = 0; i < random_numbers.size(); i++) {
        for (size_t j = 0; j < i;) {
            if (random_numbers[i] == random_numbers[j]) {
                random_numbers[i] = distr(gen);
                j = 0;
            }
            else {
                j++;
            }
        }
    }



    // Read the questions with their answers and finalize
    for (size_t i = 0; i < random_numbers.size(); i++) {
        int rd = random_numbers[i] - 1;
        std::cout << "**********************************************\n";
        std::cout << i + 1 << " - " << questions[rd] << "\n";
        std::cout << "**********************************************\n";

        for (size_t j = 0; j < answers[rd].size(); j++)
            std::cout << answers[rd][j] << "\n";

        std::cout << "Answer: ";
        std::cin >> user_guess;
        user_guess = std::toupper(user_guess);
        // user_guess = static_cast<char>(std::toupper(static_cast<unsigned char>(user_guess)));


        while (user_guess != 'A' && user_guess != 'B' && user_guess != 'C' && user_guess != 'D') {
            std::cout << "Invalid answer! Choose A, B, C or D.\n";
            std::cout << "Answer: ";
            std::cin >> user_guess;
            user_guess = std::toupper(user_guess);
        }

        if (user_guess == answer_keys[rd]) {
            std::cout << "CORRECT!\n\n";
            score++;
        }
        else {
            std::cout << "INCORRECT! The correct answer is : " << answer_keys[rd] << "\n\n";
        }

    }

    std::cout << "---------------------------------------------------------------\n";
    std::cout << "Correct answers: " << score << "\n";
    std::cout << "Score: " << (score / 10) * 100 << "%\n";
    std::cout << "---------------------------------------------------------------\n\n";
    std::cout << "===============================================================\n\n\n";

    std::cout << "\tThank you for playing!\n\n";
    std::cout << "\t\tCreator: LORVENSOFD\n";
}