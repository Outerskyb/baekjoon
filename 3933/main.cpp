#include <iostream>
#include <cmath>

int sum_of_divisior(int n) {
    int sum = 0;
    for (int i = 1; i < int(sqrt(n)); i++) {
        if (n%i == 0) {
            sum += i;
            sum += n / i;
        }
    }
    if (sqrt(n)*sqrt(n) == n) sum += sqrt(n);
    return sum;
}
int sum_of_odd_divisior(int n) {
    int sum = 0;
    for (int i = 1; i < int(sqrt(n)); i++) {
        if (n%i == 0) {
            sum += i;
            sum += n / i;
        }
    }
    if (sqrt(n)*sqrt(n) == n) sum += sqrt(n);
    return sum;
}
int main()
{
    int ip;
    while(1) {
        scanf("%d", &ip);
        if (!ip) break;
        int cur = ip;
        for (int i = sqrt(ip); i > 0; i--) {
            cur -= i;
            for(int j = 0 ; j < )
        }

    } 

}