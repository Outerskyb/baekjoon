#include <iostream>

using namespace std;

int main()
{
    int A, B, V;
    scanf("%d %d %d", &A, &B, &V);
    if ((V - A) % (A - B) == 0) printf("%d", (V - A) / (A - B) + 1);
    else if (V-(V ) / (A - B)*(A-B)<A ) printf("%d", V /(A- B));
    else  printf("%d", V / (A-B) + 1);
}