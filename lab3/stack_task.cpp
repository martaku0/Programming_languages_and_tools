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

void move_max_to_bottom(int stack[], int& top){
    if(top < 0) return; // pusty stos

    int temp_stack[N];
    int temp_top = -1;

    int max_val = -99999999; // bardzo mała liczba, aby znaleźć maksimum
    int max_count = 0;

    // szukamy maksimum i jego ilość
    while(top >= 0){
        int num = Stack__pop(stack, top);
        if(num > max_val){
            max_val = num;
            max_count = 1;
        }
        else if(num == max_val){
            max_count++;
        }
        Stack__push(temp_stack, temp_top, num);
    }

    // maksimum na dole stosu
    for(int i = 0; i < max_count; i++){
        Stack__push(stack, top, max_val);
    }

    // pozostałe elementy
    while(temp_top >= 0){
        int num = Stack__pop(temp_stack, temp_top);
        if(num != max_val){
            Stack__push(stack, top, num);
        }
    }
}

int main(){

    int stack[N];
    int top = -1; // -1 oznacza pusty stos

    std::mt19937 gen{std::random_device{}()}; //generator liczb losowych
    std::uniform_int_distribution<> losuj(0, 100);

    for(int i = 0; i < N; i++){
        Stack__push(stack, top, losuj(gen));
    }
    Stack__print(stack, top);

    move_max_to_bottom(stack, top);
    
    Stack__print(stack, top);

    return 0;
}