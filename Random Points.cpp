/*
This program plots a random values between 0 and 1

Author:
Angelo
*/



#include "gnuplot-iostream.h"
#include <iostream>
#include <random>
#include <fstream>
#include <cstdlib> 



using namespace std;

void generate_plot_script() {
    ofstream Write("plot_scrip.gp");

    if (!Write) {
        cerr << "Error opening file for writing plot script." << endl;
        exit(1);
    }

    Write << "set terminal pngcairo enhanced" << endl;
    Write << "set output 'random_values.png'" << endl;
    Write << "randomData" << endl;
    Write << "set xlabel 'Index'" << endl;
    Write << "set ylabel 'Value'" << endl;
    Write << "set grid" << endl;
    Write << "plot 'randomData.txt' " << endl;

    Write.close();
}

int main() {
    // Seed with a real random value, if available
    random_device rd;
    mt19937 gen(rd());

    // Define the distribution range
    uniform_real_distribution<> dis(0.0, 1.0);

    // Open a file to save the generated values
    ofstream file("randomData.txt");

    cout << "\n\n\n\n";

    if (!file) {

        cerr << "Error opening file for writing." << endl;

        return 1;
    }

    // Generate and print 1000 random values
    for (int i = 0; i < 1000; ++i) {

        double value = dis(gen);

        cout << "\n\n";

        file << value << endl;
    }

    file.close();

    cout << "\n\n";

    cout << "1000 random values. Done" << endl;

    cout << "\n\n";

    // Generate the gnuplot script
    generate_plot_script();

    // Call gnuplot to generate the plot
    int result = system("gnuplot plot_script.gp");

    if (result != 0) {

        cerr << "Error running gnuplot." << endl;

        return 1;
    }

    cout << "\n\n";

    cout << "Plot has been generated and saved as 'random_values.png'." << endl;

    cout << "\n\n";

    return 0;
}


