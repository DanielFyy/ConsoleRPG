#ifndef MISCELLANEOUS_H
#define MISCELLANEOUS_H

#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <random>
#include <memory>
#include <chrono>
#include <thread>
#include <windows.h>
#include <conio.h>
#include <SFML/Audio.hpp>

extern int created;
extern int destroyed;

extern int volume;
extern int typing_speed;

void display_text(const std::string text); //displays texdt letter by letter according to typing_speed

const std::string string_to_lower(const std::string string); //returns an all lower case string of the parameter string

int choose(const std::vector <std::string>& choices); //returns a value depending on the player input in accordance to the vector parameter (used for switch statement during scenes)

void press_any_key(); //displays a press any key message and waits for player input

void invalid_choice(); //displays invalid choice message

void clear_screen(); //clears the console



#endif