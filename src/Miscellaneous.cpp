#include "Miscellaneous.h"


int created = 0;
int destroyed = 0;
int volume = 50;
int typing_speed = 50;

void display_text(const std::string text)
{   
    for (const char letter : text) 
    {   
        std::cout << letter;
        std::this_thread::sleep_for(std::chrono::milliseconds(typing_speed));
    }
}

const std::string string_to_lower(const std::string string)
{   
    std::string to_lower;
    for (const char letter : string)
        to_lower += tolower(letter);

    return to_lower;
}

int choose(const std::vector <std::string>& choices)
{
    int choice = -1;
    std::string input;

    do 
    {   
        display_text("> ");
        std::getline(std::cin, input);
        input = string_to_lower(input);
        for (int i = 0; i < choices.size(); i++)
            if (input == choices[i])
            {
                choice = i;
                break;
            }
        
        if(choice == -1)
            invalid_choice();
      
    } while (choice == -1);

    return choice;
}

void press_any_key()
{
    getch();
}

void invalid_choice()
{
    display_text("You must choose one of the options above.\n");
}

void clear_screen()
{
    COORD topLeft  = { 0, 0 };
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO screen;
    DWORD written;

    GetConsoleScreenBufferInfo(console, &screen);
    FillConsoleOutputCharacterA(
        console, ' ', screen.dwSize.X * screen.dwSize.Y, topLeft, &written
    );
    FillConsoleOutputAttribute(
        console, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE,
        screen.dwSize.X * screen.dwSize.Y, topLeft, &written
    );
    SetConsoleCursorPosition(console, topLeft);
}
