/*

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
    cout << kelvin_ << " K is: " << endl;
    cout << GetTempAsFahrenheit() << " F" << endl;
    cout << GetTempAsCelsius() << " C" << endl;
}

int main() {
    
    TemperatureConverter temp_conversion;
    
    char temperature_type;     // Used with the IF/ELSE IF statements to determine what our original input temperature is.
    double temperature_input;
    
    cout << "Is the original temperature in Celsius (C), Fahrenheit (F), or Kelvin (K)? (C, F, or K) ";
    cin >> temperature_type;
    
    if (temperature_type == 'C' || temperature_type == 'c')               // Checks if user wants Celsius input
    {
        cout << "What is the temperature (in Celsius)? "; 
        cin >> temperature_input;
        temp_conversion.SetTempFromCelsius(temperature_input);     // Convert to Kelvin & store the input.
    }
    else if (temperature_type == 'F' || temperature_type == 'f')          // Checks if user wants Fahrenheit input
    {
        cout << "What is the temperature (in Fahrenheit)? "; 
        cin >> temperature_input;
        temp_conversion.SetTempFromFahrenheit(temperature_input);  // Convert to Kelvin & store the input.
    }
    else                                                    // Default (Kelvin) input
    {
        cout << "What is the temperature (in Kelvin)? ";
        cin >> temperature_input;
        temp_conversion.SetTempFromKelvin(temperature_input);      // Store the input.
    }
    
    cout << endl;
    temp_conversion.PrintTemperatures();                    // Print the results.
}