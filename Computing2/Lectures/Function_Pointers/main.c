#include <stdio.h>
#include <stdlib.h>

void say_hello(void);
void say_hola(void);
void say_hallo(void);
void say_bonjour(void);
void say_shalom(void);
void say_aloha(void);
void say_czesc(void);
void say_marhaba(void);

void do_work(void (*fpGreeting)(void)); // read as fpGreeting is a function that points to a function that takes nothing and returns void

int main(int argc, char *argv[])
{
    int number_of_functions;
    void (*fpGreetings[])(void) = {say_hello, say_aloha, say_hallo, say_bonjour, say_shalom, say_czesc, say_marhaba, say_hola};

    number_of_functions = sizeof(fpGreetings) / sizeof(*fpGreetings);
    for(int i = 0; i < number_of_functions; i++)
    {
        fpGreetings[i]();
    }

    return 0;
}

void do_work(void (*fpGreeting)(void))
{
    fpGreeting();
    printf("Prepairing to do work\n");
}

void say_hello(void)
{
    printf("hello\n");
}
void say_hola(void)
{
    printf("hola\n");
}
void say_hallo(void)
{
    printf("hallo\n");
}
void say_bonjour(void)
{
    printf("bonjour\n");
}
void say_shalom(void)
{
    printf("shalom\n");
}
void say_aloha(void)
{
    printf("aloha\n");
}
void say_czesc(void)
{
    printf("czesc\n");
}
void say_marhaba(void)
{
    printf("marhaba\n");
}