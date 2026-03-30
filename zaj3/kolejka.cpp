#include <iostream>
#include <random>

const int N = 10;

int Queue__push(int queue[], int& head, int& tail, int& count, int number){
    if(count >= N){
        return -1; // kolejka jest pełna
    }
    queue[tail] = number;
    tail = (tail + 1) % N;
    count++;
    return 0; // sukces
}

int Queue__pop(int queue[], int& head, int& tail, int& count){
    if(count <= 0){
        return -2; // kolejka jest pusta
    }
    int num = queue[head];
    head = (head + 1) % N;
    count--;
    return num; // zwraca zdjętą liczbę
}

void Queue__print(int queue[], int head, int count){
    for(int i = 0; i < count; i++){
        std::cout << queue[(head + i) % N] << " "; // wypisanie od przodu do tyłu kolejki
    }
    std::cout << std::endl;
}

int main(){

    int queue[N];
    int head = 0;
    int tail = 0;
    int count = 0;

    std::mt19937 gen{std::random_device{}()}; //generator liczb losowych
    std::uniform_int_distribution<> losuj(0, 100);

    for(int i = 0; i < N; i++){
        Queue__push(queue, head, tail, count, losuj(gen));
        Queue__print(queue, head, count);
    }
    Queue__print(queue, head, count);

    for(int i = 0; i < N; i++){
        int num = Queue__pop(queue, head, tail, count);
        std::cout << "Popped: " << num << std::endl;
    }
    Queue__print(queue, head, count);

    return 0;
}