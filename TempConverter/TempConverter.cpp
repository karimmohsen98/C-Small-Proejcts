// TempConverter.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

double CelToFah(double tempC)
{
    return (tempC * 9.0 / 5.0) + 32.0;
}

double FahrToC(double tempF)
{
    return (tempF - 32.0) * 5.0 / 9.0;
}
double CelToKel(double celsius)
{
    return celsius + 273.15;
}

double KelToCel(double kelvin)
{
    return kelvin - 273.15;
}

int main()
{
    char choice;
    double temp, convertedTemp;

    cout << "\n Temp Converter \n" << endl;
    cout << "1.CtoF" << endl;
    cout << "2.FtoC" << endl;
    cout << "3.CtoK" << endl;
    cout << "4.KtoC \n" << endl;
    cout << "Select a choice" << endl;
    cin >> choice;

    cout << "Type the temperature" << endl;
    cin >> temp;

    switch (choice)
    {
    case '1':
        convertedTemp = CelToFah(temp);
        break;

    case '2':
        convertedTemp = FahrToC(temp);
        break;

    case '3':
        convertedTemp = CelToKel(temp);
        break;

    case '4':
        convertedTemp = KelToCel(temp);
        break;
    default:
        cout << "Invalid Choice." << endl;
        return 1;
     }
    cout << "Converted Temp is :" << convertedTemp << endl;
    return 0;

    
}


