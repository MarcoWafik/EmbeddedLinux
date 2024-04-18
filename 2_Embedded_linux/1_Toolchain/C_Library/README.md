# C Library Tutorial

## Introduction

A library in programming is a collection of precompiled functions and procedures that a program can use. Libraries help in reusing code, reducing code redundancy, and making code more modular.

In C programming, there are mainly two types of libraries:

1. **Static Libraries**: These are libraries where the functions are linked to the executable at compile time. The functions' code is copied into the executable.
2. **Dynamic Libraries**: These are libraries where the functions are linked to the executable at runtime. The functions' code resides in a separate file, and the executable references this file during runtime.

In this section , I will demonstrate how to create both static and dynamic libraries in C.

---

## Creating Static Library

### Steps to Create a Static Library

1. **Write Library Code**: Write the functions you want to include in your library. Save them in separate `.c` files , you can easily find simple examples in my repo.

    ```c
    // add.c
    int add(int a, int b) {
        return a + b;
    }
    ```

2. **Compile Library Code**: Compile the library code using `gcc` and create an object file (`.o`).

    ```bash
    gcc -c {file_name.c} -o {file_name.o}
    ```

3. **Create Static Library**: Use the `ar` (archive) command to create a static library (`lib<name>.a`).

    ```bash
    ar rcs {lib<name>.a} {files.o}
    ```

### Using Static Library

To use the static library in your program:

1. Write a program that uses the functions from the static library.

    ```c
    // main.c

    //you can pass the absolute path to your library header
        //#include<Absolute/path/to/your/Library/header>

    //you can include the file and pass the path during linking 
    #include<lib_name.h> 
    #include <stdio.h>

    int main() {
        int result = add(5, 3);
        printf("Result: %d\n", result);
        return 0;
    }
    ```

2. Compile your program with the static library.

    ```bash
    gcc main.c -L. -l{name} -o mainStatic.elf
    ```
    or
    ```bash
    gcc main.c -I {Relative/path/to/your/Library/Header} -L. -l{name} -o mainStatic.elf
    ```

---

## Creating Dynamic Library

### Steps to Create a Dynamic Library

1. **Write Library Code**: Write the functions you want to include in your library. Save them in separate `.c` files., you can easily find simple examples in my repo.

    ```c
    // subtract.c
    int subtract(int a, int b) {
        return a - b;
    }
    ```

2. **Compile Library Code**: Compile the library code using `gcc` with the `-shared` option to create a shared object file (`.so`).

    ```bash
    gcc -c -fPIC {file_name.c} -o {file_name.o}
    gcc -shared -o {lib<name>.so} {files.o}
    ```

### Using Dynamic Library

To use the dynamic library in your program:

1. Write a program that uses the functions from the dynamic library.

    ```c
    // main_dynamic.c
    //you can pass the absolute path to your library header
        //#include<Absolute/path/to/your/Library/header>

    //you can include the file and pass the path during linking 
    #include<lib_name.h> 
    #include <stdio.h>

    int main() {

        int result = subtract(8, 3);
        printf("Result: %d\n", result);
        
        return 0;
    }
    ```

2. Compile your program with the dynamic library.

    ```bash
    gcc main_dynamic.c -l{name} -o mainDynamic.elf
    ```
    or
    ```bash
    gcc main_dynamic.c -I {Relative/path/to/your/Library/Header} -L. -ladd -o mainDynamic.elf
    ```

---
# Inspecting Function Resolution

## You can inspect whether a function is resolved statically or remains undefined, to be resolved dynamically, using these commands. 
To inspect the  function using `readelf` and `objdump`:

1. **Using readelf**:

    ```bash
    readelf -h {Output/elf/file}
    ```

2. **Using objdump**:

    ```bash
    objdump -t {Output/elf/file}
    ```



---
## Conclusion

Libraries are powerful tools in C programming that allow for code reuse and modularity. Whether you choose to use static or dynamic libraries depends on your project's requirements.

