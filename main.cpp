#include <iostream>

using namespace std;

char* mystrtok(char *str, char space) {
    char* token;

    static int buff = 0;
    int i = buff;

    
    do{
        token[i - buff] = str[i];
        i++;
    }
    while (str[i] != space);

    cout << buff << '\n';
    buff += i;
    
    return token;
}

char* mystrcpy(char* dest, const char* donor){
    int i = 0;

    while(donor[i] != '\0'){
        dest[i] = donor[i];
        i++;
    }

    dest[i] = '\0';

    return dest;
}

char* mystrcat(char* dest, const char* donor){
    int i = 0;
    int i2 = 0;

    while(dest[i] != '\0'){;
        i++;
    }
    
    while(donor[i2] != '\0'){
        dest[i + i2] = donor[i2];
        i2++;
    }

    dest[i + i2] = '\0';

    return dest;
}

int mystrlen(char *str) {
    int i = 0;

    while(str[i] != '\0') i++;

    return i;
}
int mystrcmp(char *str1, char *str2) {

    if(str1 == str2) return 0;

    int i = 0;

    while(str1[i] == '\0' or str2[i] == '\0'){

        if(int(str1[i]) < int(str2[i])) return -1;
        if(int(str1[i]) > int(str2[i])) return 1;

        i++;
    }
}

int mystrncmp(char* str1, char* str2, size_t n){
    int i = 0;
    
    while(i < n){
        if(str1[i] == '\0' and str2[i] != '\0') return -1;
        if(str1[i] != '\0' and str2[i] == '\0') return 1;
        i++;
    }
    return 0;
}

char* mystrncpy(char* dest, const char* donor, size_t n){
    size_t i = 0;

    while(donor[i] != '\0' and i < n){
        dest[i] = donor[i];
        i++;
    }

    dest[i] = '\0';

    return dest;
}

char* mystrncat(char* dest, const char* donor, size_t n){
    int i = 0;
    int i2 = 0;

    while(dest[i] != '\0'){;
        i++;
    }
    
    while(donor[i2] != '\0' and i2 < n){
        dest[i + i2] = donor[i2];
        i2++;
    }

    dest[i + i2] = '\0';

    return dest;
}

char* mystrstr(char* target, char* donor){
    int i = 0;
    int i2 = 0;

    char* token;

    while(donor[i] != target[i2]){
        if(donor[i] == '\0') return NULL;
        i++;
    }

    while(donor[i + i2] == target[i2]){
        if(donor[i + i2] == '\0' and token == NULL) return NULL;
        token[i2] = donor[i + i2];
        i2++;
    }
    token[i2 + 1] = '\0';

    return token;
}

int main() {
    char str[] = "Hello world!";
    char test[256];

    cout << "start\nAll parameters in functions is (test, str, 5)\n\n";
    cout << mystrtok(str, ' ') << " :: strtok 1\n";
    cout << mystrtok(str, ' ') << " :: strtok 2\n";
    cout << mystrcpy(test, str) << " :: strcpy\n";
    cout << mystrncpy(test, str, 5) << " :: strncpy\n";
    cout << mystrcat(test, str) << " :: strcat\n";
    cout << mystrncat(test, str, 5) << " :: strncat\n";
    cout << mystrlen(test) << " :: strlen(test)\n";
    cout << mystrlen(str) << " :: strlen(str)\n";
    //cout << mystrcmp(test, str) << " :: strcmp\n";
    cout << mystrncmp(test, str, 5) << " :: strncmp\n";
    cout << mystrstr("Hell", test) << " :: strstr\n";

    return 0;
}
