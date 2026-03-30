#include <iostream>
#include <random>
#include <string>
#include <iomanip>

void heapify(int arr[], int n, int i){ // funkcja przywracająca własność kopca
    int largest = i;
    int left = 2*i+1;
    int right = 2*i+2;

    if(left < n && arr[left] > arr[largest])
        largest = left;

    if(right < n && arr[right] > arr[largest])
        largest = right;

    if(largest != i){
        std::swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void print_step(int heap[], int heap_size, int sorted[], const std::string& msg, int N){
    for (int i = 0; i < N - heap_size; i++) std::cout << "   ";
    for (int i = 0; i < heap_size; i++) std::cout << std::setw(2) << heap[i] << " ";
    
    std::cout << "                        "; 
    
    for (int i = 0; i < heap_size; i++) std::cout << "   ";
    for (int i = heap_size; i < N; i++) std::cout << std::setw(2) << sorted[i] << " ";
    
    std::cout << " ← " << msg << std::endl;
}

int main(int argc, char* argv[]){
    bool track = false;
    if(argc > 1 && std::string(argv[1]) == "--track") {
        track = true;
    }

    const int N = 10;

    int heap[N];
    int sorted[N];

    std::mt19937 gen{std::random_device{}()}; //generator liczb losowych
    std::uniform_int_distribution<> losuj(-10, 9);

    for(int i = 0; i < N; i++){
        heap[i] = losuj(gen);
    }

    if (track) {
        std::cout << "                      heap                sorted\n";
        std::cout << "------------------------------------------------\n";
        print_step(heap, N, sorted, "Wylosowane dane", N);
    }

    for(int i = N / 2 -1; i >= 0; i--){
        heapify(heap, N, i);
    }

    if (track) {
        print_step(heap, N, sorted, "Utworzenie kopca", N);
    }

    int current_size = N;
    while(current_size > 0){
        sorted[current_size - 1] = heap[0]; // największy element trafia do posortowanej części
        heap[0] = heap[current_size - 1]; // ostatni element trafia na szczyt kopca
        current_size--;

        heapify(heap, current_size, 0); // przywracamy własność kopca

        if (track) {
            print_step(heap, current_size, sorted, "Przeniesienie największego elementu", N);
        }
    }

    std::cout << std::endl;
    return 0;
}