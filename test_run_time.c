#include "caesar_cipher.h"
#include <dlfcn.h>

int main()
{
    void *handle;
    void(*encoder)(const char*,int);
    void(*decoder)(const char*);
    char *error;
    handle = dlopen("./libcaesar.so", RTLD_LAZY);
    if(!handle)
    {
        fprintf(stderr, "%s\n", dlerror());
        exit(1);
    }
    encoder = dlsym(handle, "encoder");
    decoder = dlsym(handle, "decoder");
    if((error=dlerror())!=NULL)
    {
        fprintf(stderr, "%s\n", error);
        exit(1);
    }
    encoder("This is for run time test",15);
    decoder("Dtz hfs stz xtmj jfhjw Hnsjwj Hnslw");
    if(dlclose(handle)<0)
    {
        fprintf(stderr, "%s\n", dlerror());
        exit(1);
    }
    return 0;
}