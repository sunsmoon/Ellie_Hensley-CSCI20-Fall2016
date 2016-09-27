/*
Lab 9: Classes & Objects

This program converts to and from Celsius, Fahrenheit, and Kelvin, then prints out the different values.

by Ellie Hensley
9-25-16

*/

#include <iostream>
using namespace std;

class TemperatureConverter {
    public:
        TemperatureConverter();                                 // Sets Kelvin to Zero.
        TemperatureConverter(double kelvin);                    // Stores an input to the kelvin_ variable
        
        void SetTempFromCelsius(double celsius);                // Converts Celsius to Kelvin
        void SetTempFromFahrenheit(double fahrenheit);          // Converts Fahrenheit to Kelvin
        void SetTempFromKelvin(double kelvin);                  // Sets the private kelvin_ variaible to the input value.
        
        double GetTempFromKelvin() const;                       // Returns the stored Kelvin variable.
        double GetTempAsCelsius() const;                        // Converts Kelvin to Celsius
        double GetTempAsFahrenheit() const;                     // Converts Kelvin to Fahrenheit
        
        string PrintTemperatures();                             // Prints the Temperatures given by the other GetTempAs() functions.
        
        private:
        double kelvin_;
};

// TemperatureConverter();
// Sets Kelvin to zero.
TemperatureConverter::TemperatureConverter()
{
    kelvin_ = 0;
}

// TemperatureConverter();
// Sets Kelvin to zero.
TemperatureConverter::TemperatureConverter(double kelvin)
{
    kelvin_ = kelvin;
}

// SetTempFromCelsius():
// Converts a temperature from Celsius (input) to Kelvin
// and stores (outputs) it in a variable.
void TemperatureConverter::SetTempFromCelsius(double celsius)
{
    kelvin_ = celsius + 273.15;
}

// SetTempFromFahrenheit():
// Converts a temperature from Fahrenheit (input) to Kelvin
// and stores (outputs) it in a variable.
void TemperatureConverter::SetTempFromFahrenheit(double fahrenheit)
{
    kelvin_ = (5 * (fahrenheit - 32) / 9) + 273.15;
}

// SetTempFromKelvin():
// Stores the input Kelvin temperature in the private kelvin_ variable.
void TemperatureConverter::SetTempFromKelvin(double kelvin)
{
    kelvin_ = kelvin;
}

// GetTempFromKelvin():
// "Reads" the value stored in kelvin_
double TemperatureConverter::GetTempFromKelvin() const
{
    return kelvin_;
}

// GetTempAsCelsius():
// Converts a temperature from Kelvin to Celsius
// and returns it.
double TemperatureConverter::GetTempAsCelsius() const
{
    return kelvin_ - 273.15;
}

// GetTempAsFahrenheit():
// Converts a temperature from Kelvin to Fahrenheit
// and returns it.
double TemperatureConverter::GetTempAsFahrenheit() const
{
    return (((kelvin_ - 273.15) * 9) / 5 + 32);
}

// PrintTemperatures():
// Couts (prints) the conversions for the original temperatuture
// in Kelvin, Celsius, Fahrenheit.
string TemperatureConverter::PrintTemperatures()
{
    cout << kelvin_ << " K is the same as " << GetTempAsFahrenheit() << " F and " <<  GetTempAsCelsius() << " C." << endl << endl;
}