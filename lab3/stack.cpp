#include <iostream>
#include <random>

const int N = 10;


int Stack__push(int stack[], int& top, int number){
    if(top >= N - 1){
        return -1; // stos jest pełny
    }
    top++;
    stack[top] = number;
    return 0; // sukces
}

int Stack__pop(int stack[], int& top){
    if(top < 0){
        return -2; //stos jest pusty
    }
    int num = stack[top];
    top--;
    return num; // zwraca zdjętą liczbę
}

void Stack__print(int stack[], int top){
    for(int i = top; i >= 0; i--){
        std::cout << stack[i] << " ";
    }
    std::cout << std::endl;
}

int main(){

    int stack[N];
    int top = -1; // -1 oznacza pusty stos

    std::mt19937 gen{std::random_device{}()}; //generator liczb losowych
    std::uniform_int_distribution<> losuj(0, 100);

    for(int i = 0; i < N; i++){
        Stack__push(stack, top, losuj(gen));
        Stack__print(stack, top);
    }
    Stack__print(stack, top);

    for(int i = 0; i < N; i++){
        int num = Stack__pop(stack, top);
        std::cout << "Popped: " << num << std::endl;
    }
    Stack__print(stack, top);

    return 0;
}