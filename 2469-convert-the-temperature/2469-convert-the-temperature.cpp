class Solution {
public:
    vector<double> convertTemperature(double celsius) {
        vector<double> solution;
        // find kelvin
        double Kelvin = celsius + 273.15;
        solution.push_back(Kelvin);
        //find fashrenheit
        double Fahrenheit = celsius * 1.80 + 32.00;
        solution.push_back(Fahrenheit);
        return solution;
    }
};