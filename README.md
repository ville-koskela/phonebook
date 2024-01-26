# Phonebook

I started this project as an attempt to learn the C language. A phonebook was a nice application to start with since it allows the use of different data structures like binary trees and linked lists. It includes file I/O and is a large enough application to be spread across multiple source files, which helps in learning how to effectively use header files. In addition, it requires memory management and can easily be expanded in the future to include features like an API, search functionality, etc.

## clang-format

You can formmat all source files using clang-format. This requires  
clang-format to be installed in your system. You can install  
clang-format with following command:

```shell
sudo apt install clang-format
```

To format files, go to project root and run command:

```shell
find src -name *.[ch] -exec clang-format -i {} \;
```

To run formatter without actually making changes to files,  
go to project root and run:

```shell
find src -name *.[ch] -exec clang-format {} \;
```

## Testing

This application uses CUnit for unit testing. To install CUnit, run  
the following commands:

```shell
sudo apt install libcunit1 libcunit1-doc libcunit1-dev
```

After that you can build and run tests with commands:

```shell
make tests
./test
```

When writing tests, you can find available assertations from  
CUnit [website](https://cunit.sourceforge.net/doc/writing_tests.html).

## Build and run app

To build the app, you must have gcc installed in to your system.  
Building is pretty straight forward and can simply be done by  
going to project root and running command: 

```shell
make build
./book
```

In case you wish to include debug-code to the build, you will  
need to edit `Makefile` and include `-DDEBUG` to compile-flags. 

After that just build the application normally and run it like 
normal. It will print out additional debug information. 
