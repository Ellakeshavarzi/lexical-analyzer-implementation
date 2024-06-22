# Lexical Analyzer

## Description

This project is a lexical analyzer implemented in C++. A lexical analyzer (or lexer) is a critical component of a compiler that processes an input source code and converts it into a sequence of tokens. Each token represents a string with an assigned and thus identified meaning. This lexical analyzer is designed to read source code, identify tokens, and handle errors gracefully.

## Features

- **Token Identification**: Recognizes various tokens from the source code including keywords, identifiers, operators, and literals.
- **Error Handling**: Detects and reports lexical errors in the input source code.
- **State Management**: Efficiently manages states to process the input using a state machine approach.

## Installation

To compile and run the lexical analyzer, you need to have a C++ compiler installed on your machine. Follow the steps below to set up and run the project:

1. **Clone the Repository**:
    ```sh
    git clone https://github.com/your-username/lexical-analyzer.git
    cd lexical-analyzer
    ```

2. **Compile the Code**:
    ```sh
    g++ -o LexicalAnalyzer LexicalAnalyzer.cpp
    ```

3. **Run the Executable**:
    ```sh
    ./LexicalAnalyzer
    ```

## Usage

To use the lexical analyzer, you need to provide an input source code file. The lexer will read this file and output the identified tokens and any lexical errors encountered.

### Example

1. **Input Source Code File (`input.txt`)**:
    ```c
    int main() {
        int number = 42;
        printf("Hello, World!");
        return 0;
    }
    ```

2. **Running the Lexer**:
    ```sh
    ./LexicalAnalyzer input.txt
    ```

3. **Output**:
    ```
    int:Keyword
    main:Identifier
    ( : Punctuators
    ) : Punctuators
    { : Punctuators
    int:Keyword
    number:Identifier
    = : Operator
    42 : Integer
    ; : Punctuators
    printf:Identifier
    ( : Punctuators
    "Hello, World!" : String
    ) : Punctuators
    ; : Punctuators
    return:Keyword
    0 : Integer
    ; : Punctuators
    } : Punctuators

    ```

## Contributing

Contributions are welcome! If you have any improvements or new features to add, feel free to submit a pull request. Please ensure that your contributions adhere to the project's coding standards and include relevant tests.

1. Fork the repository
2. Create a new branch (`git checkout -b feature-branch`)
3. Commit your changes (`git commit -am 'Add new feature'`)
4. Push to the branch (`git push origin feature-branch`)
5. Create a new Pull Request
