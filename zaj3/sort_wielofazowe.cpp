#include <iostream>
#include <random>
#include <algorithm>

const int N = 5; // kolejka
const int M = 20; // pamięć
bool track = false;

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

void multiphase_sort(int memory[]){
    if(track){
        std::cout << "\n\n-------------------------------\n";
    }

    int tape1[N], head1 = 0, tail1 = 0, count1 = 0;
    int tape2[N], head2 = 0, tail2 = 0, count2 = 0;

    int temp_memory[M];

    int chunk_size = 1;

    while(chunk_size < M){
        int write_index = 0;

        for(int i = 0; i<M; i += 2*chunk_size){
            int left = i;
            int left_end = std::min(i + chunk_size, M);

            int right = std::min(i + chunk_size, M);
            int right_end = std::min(i + 2*chunk_size, M);

            while(left < left_end || right < right_end || count1 > 0 || count2 > 0){
                
                // uzupełnienie taśmy nr 1
                while(count1 < N && left < left_end){
                    Queue__push(tape1, head1, tail1, count1, memory[left]);
                    left++;
                }

                // uzupełnienie taśmy nr 2
                while(count2 < N && right < right_end){
                    Queue__push(tape2, head2, tail2, count2, memory[right]);
                    right++;
                }

                // Scalanie (pop + memory_temp)
                if(count1 > 0 && count2 > 0){
                    if(tape1[head1] < tape2[head2]){
                        temp_memory[write_index++] = Queue__pop(tape1, head1, tail1, count1);
                    } else {
                        temp_memory[write_index++] = Queue__pop(tape2, head2, tail2, count2);
                    }
                } else if(count1 > 0){
                    temp_memory[write_index++] = Queue__pop(tape1, head1, tail1, count1);
                } else if(count2 > 0){
                    temp_memory[write_index++] = Queue__pop(tape2, head2, tail2, count2);
                }
            }
        }

        // tmp do main memory
        for(int i = 0; i < M; i++){
            memory[i] = temp_memory[i];
        }

        chunk_size *= 2; // podwajamy rozmiar porcji do sortowania

        if(track){
            std::cout << "Merge chunk_size = " << chunk_size / 2 << ":\n";
            for (int k = 0; k < M; k++){
                std::cout << memory[k] << " ";
            }
            std::cout << "\n\n";
        }
    }

    if(track){
        std::cout << "-------------------------------\n\n";
    }
}

int main(int argc, char* argv[]){
    if(argc > 1 && std::string(argv[1]) == "--track") {
        track = true;
    }

    int memory[M];

    std::mt19937 gen{std::random_device{}()}; //generator liczb losowych
    std::uniform_int_distribution<> losuj(0, 100);

    std::cout << "Before:\n";
    for(int i = 0; i < M; i++){
        memory[i] = losuj(gen);
        std::cout << memory[i] << " ";
    }
    std::cout << std::endl;

    multiphase_sort(memory);

    std::cout << "After:\n";
    for(int i = 0; i < M; i++){
        std::cout << memory[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}