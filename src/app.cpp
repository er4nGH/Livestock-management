#include "app.hpp"
#include <exception>
#include <cstdlib>
#include <iostream>

using namespace std;

App::App()
{
    splashScreen();
}

void App::splashScreen()
{
    cout << "-----------------------\n"
            "|          |          |\n"
            "| -------- | -------- |\n"
            "|          |          |\n"
            "| -------- | -------- |\n"
            "|          |          |\n"
            "| -------- | -------- |\n"
            "-----------------------\n"
             "         \n" << endl;

    cout << "Welcome to the livestock management system\n" << endl << "The first phase of the advanced programming project"<<endl;

}

int App::exec()
{
    try
    {
        getInformation();
        
        print();
    }
    catch(const char * message)
    {
        cout << "! " << message << endl;
    }
}

void App::getInformation()
{
    unsigned int temp;

    try
    {
        cout << ">> Specify the number of cows : ";
        cin >> cows;

        cout << ">> Specify the number of sheep : ";
        cin >> sheep;

        cout << ">> Specify the number of chickens : ";
        cin >> chickens;

        checkInputs();
    }
    catch(const char * message)
    {
        cerr << message << endl;
        abort();
    }

    cout << endl;
}

void App::print()
{
    cout << "Livestock inventory includes:" << endl;
    cout << "Cows :" << cows << endl;
    cout << "Sheep :" << sheep << endl;
    cout << "Chickens :" << chickens << endl;
    
}

//////////////////////////////////////////////////////////////////oky
void App::checkInputs() const
{
    if(cows < 0 || sheep < 0 || chickens < 0 )
    {
        throw "Input is incorrect";
    }
}

