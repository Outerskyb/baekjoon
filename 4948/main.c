#include<stdio.h>

int primeNum[246913] = { 1, 1,0, };

void is_prime(void) {
    for (int i = 2; i < 246913; i++) {
        if (primeNum[i] == 0) {
            for (int j = i * 2; j < 246913; j += i) primeNum[j] = 1;
        }
    }
}

int main(void) {
    is_prime();
    while(1){
        int input,count=0;
        scanf("%d", &input);
        if (!input) break;
        for (int i = input+1; i < 2 * input + 1; i++) {
            if (primeNum[i]==0) count++;
        }
        printf("%d\n", count);
    } 
}