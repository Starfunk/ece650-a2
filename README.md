# ECE650 : Assignment 2

Replace FIRST_NAME, LAST_NAME, WATIAM, and STUDENT_ID, EMAIL in
`user.yml` by your first and last name, WatIAM id, student number, and
email, respectively. Whenever possible, please use ASCII characters.

Do not change the format `user.yml`. We will parse it
automatically. Only enter the information requested.

The main file for your solution to the assignment should be
`a2-ece650.cpp`. You can use `gtest_example.cpp` for your unit tests.

You might need to modify `CMakeLists.txt` if you are adding additional
source files for your code and/or tests.

Commit your changes and submit on GitHub.

# Clang-format
To format code in the Google style, run:

`clang-format -style=file -i -fallback-style=none ece650-a2.cpp	node.cpp amatrix.cpp headers/amatrix.h headers/node.h`