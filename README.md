- An overview of my design decisions

  I approached the problem thinking about the overall structure of data and
  how it could be optimally organized. I eventually settled on creating an
  "Account" class that contains all the relevant information needed for one
  instance of an account. This class contains the owner of the account, the
  current balance of the account, whether the credit card number is valid, and
  the limit of the balance. By structuring my code this way, I could easily
  create Account objects based on the input and perform the credits/charges
  using methods of the Account class. From there all that was left was to read
  in the input, create the corresponding Account instances, call the correct
  functions, and then print the summary.

- Why I picked the programming language I used

  I chose C++ as the language for this program since we use C++ at school and
  as a result, I am currently most comfortable using it. C++ also has good
  object oriented programming capabilities and allows me to easily implement
  the code structure I thought of.

- How to run my code and tests

  In order to run my code on the command line, you can just run the "creditProcessor"
  executable followed by the input file like so:

      "./creditProcessor test_0.txt" or "./creditProcessor < test_0.txt"

  If the executable is unable to run, you may need to compile the code again. To do so,
  you can type:

      "g++ creditProcessor.cpp Account.cpp -std=c++11 -o creditProcessor"

  and then run the executable once again by typing the command listed above.

  To execute the tests, you can choose a test input file (test_*.txt), the
  correct output file (test_*_correct.txt), and then run the "creditTest" executable
  to see how the code performed against the expected output for that test file.
  This executable also contains unit tests for all functionality expected from the
  code. An example of the test executable being run:

      "./creditTest test_0.txt test_0_correct.txt"

  If the test executable is unable to run, you may need to compile this code again. To
  do so, you can type:

      "g++ creditProcessorTests.cpp Account.cpp -std=c++11 -o creditTest"

  and then run the test executable again by typing the command listed above.
