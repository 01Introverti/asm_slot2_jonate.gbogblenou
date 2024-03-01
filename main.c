/*
** EPITECH PROJECT, 2024
** main.c
** File description:
** main
*/

#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>
#include <gnu/lib-names.h>

int main(void)
{
    void *handle;
    void *(*my_strcmp)(void *s, void *c, size_t n);
    char *error;
    handle = dlopen("./libasm.so", RTLD_LAZY);
    if (!handle) {
        printf("nop");
        exit(EXIT_FAILURE);
    }
    dlerror();
    my_strcmp = (void*(*)(void*, void*, size_t))dlsym(handle, "my_memcpy");
    error = dlerror();
    if (error != NULL) return 84;
    char str[] = "papa";
    char ok[] =  "a";
    printf("%s", my_strcmp(str, ok, 4));
    dlclose(handle);
}
