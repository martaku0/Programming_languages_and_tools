#include <iostream>
#include <cmath>
#include <random>

int main(){
    long long N = 1000000;// ilosc prób
    long long hits = 0;// ilosc trafień

    std::mt19937 gen{std::random_device{}()}; //generator liczb losowych
    std::uniform_real_distribution<double> losuj{-0.5, 0.5}; //rozkład jednorodny na przedziale [-0.5, 0.5]

    double x,y;

    for (long long i = 0; i < N; ++i) {
        double x = losuj(gen);
        double y = losuj(gen);

        bool inside = false;

        // Sprawdzamy czy punkt się znajduje w:
        if (x < 0 && y > 0) { // Lewym górnym
            if (y <= std::sqrt(0.25 - x * x)) inside = true;
        } 
        else if (x >= 0 && y > 0) { // Prawym górnym
            if (y <= -std::sqrt(-x * x + x) + 0.5) inside = true;
        } 
        else if (x < 0 && y <= 0) { // Lewym dolnym
            if (y >= -std::sqrt((1.0 - (x * x) / 0.25) * 0.09)) inside = true;
        } 
        else if (x >= 0 && y <= 0) { // Prawym dolnym
            if (y >= 1.2 * x * x - 0.3) inside = true;
        }

        // Jeśli znajduje się w środku figury zliczamy go:
        if (inside) {
            hits++;
        }
    }

    double prostokat = 1.0; // Pole calego prostokąta
    double figura = (double)hits / N * prostokat; // Pole szukanej figury

    std::cout << "Liczba prob: " << N << std::endl;
    std::cout << "Liczba trafień: " << hits << std::endl;
    std::cout << "Pole figury: " << figura << std::endl;

    return 0;
}