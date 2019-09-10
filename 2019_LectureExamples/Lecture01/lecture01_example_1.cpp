/*
 * Related material about this topic
 * http://www.cplusplus.com/doc/tutorial/pointers/
 */
#include <iostream>

//The function takes one argument and copies its value
void add_c(int n)
{
    n = n + 2;
}//n will be removed from the memory

//The function takes one argument and copies its value
//but in this case the value is a memory address
void add_cp(int *n)
{
    *n = *n + *n;
}

//The function takes one argument as reference
//Copies its memory address
void add_cpp(int &n)
{
    n = n + n;
}


int main ()
{
    int a1, a2, a3 = 1;
    
    add_c(a1);
    std::cout << a1 << std::endl;
    // 1
    
    add_cp(&a2);
    std::cout << a2 << std::endl;
    // 3
    
    add_cpp(a3);
    std::cout << a3 << std::endl;
    // 3
    
    return 0;
}
