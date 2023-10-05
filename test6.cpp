#include <iostream>
int main()
{
    char mychar[9];
    scanf("%s", mychar);
    printf("what is your favorite char:%s\nplease enter a char", mychar);
    getchar();
    std::cin.get();
}