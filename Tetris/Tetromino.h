// class //Tetromino{
//     public:
//         Tetromino();
//     void rotation(int R);

//     private:

// };
#include <array>
#include <vector>
#include <iostream>

class Tetromino {
public:
    // Enum for Tetromino types
    enum Type {
        I, J, L, O, S, T, Z
    };

    // Constructor to initialize Tetromino shapes
    Tetromino(Type type);

    // Rotate the Tetromino
    void rotate();

    // Print the current state of the Tetromino
    void print() const;

private:
    // Current rotation of the Tetromino
    int rotation;
    // Shape matrix for the current rotation
    std::vector<std::vector<char>> shape;

    // Tetromino shapes (4x4 for simplicity, use 2D vectors)
    std::vector<std::vector<std::vector<char>>> tetrominos;

    // Initialize Tetromino shapes
    void initializeShapes();
    // Rotate matrix 90 degrees clockwise
    void rotateMatrix();
};

Tetromino::Tetromino(Type type) : rotation(0) {
    initializeShapes();
    shape = tetrominos[type][rotation];
}

void Tetromino::initializeShapes() {
    tetrominos.resize(7);

    // I Tetromino
    tetrominos[I] = {
        {{'I', 'I', 'I', 'I'}},
        {{' ', 'I', ' ', ' '},
         {' ', 'I', ' ', ' '},
         {' ', 'I', ' ', ' '},
         {' ', 'I', ' ', ' '}}
    };

    // J Tetromino
    tetrominos[J] = {
        {{'J', ' ', ' '},
         {'J', 'J', 'J'}},
        {{'J', 'J'},
         {'J', ' '},
         {'J', ' '}},
        {{' ', 'J', ' '},
         {'J', 'J', 'J'}},
        {{' ', 'J', 'J'},
         {' ', 'J', ' '}}
    };

    // L Tetromino
    tetrominos[L] = {
        {{'L', ' ', ' '},
         {'L', 'L', 'L'}},
        {{'L', 'L'},
         {' ', 'L'},
         {' ', 'L'}},
        {{'L', 'L', 'L'},
         {' ', ' ', 'L'}},
        {{'L', ' '},
         {'L', ' '},
         {'L', 'L'}}
    };

    // O Tetromino
    tetrominos[O] = {
        {{'O', 'O'},
         {'O', 'O'}}
    };

    // S Tetromino
    tetrominos[S] = {
        {{' ', 'S', 'S'},
         {'S', 'S', ' '}},
        {{'S', ' '},
         {'S', 'S'},
         {' ', 'S'}}
    };

    // T Tetromino
    tetrominos[T] = {
        {{' ', 'T', ' '},
         {'T', 'T', 'T'}},
        {{'T', ' '},
         {'T', 'T'},
         {'T', ' '}},
        {{'T', 'T', 'T'},
         {' ', 'T', ' '}},
        {{' ', 'T'},
         {'T', 'T'},
         {' ', 'T'}}
    };

    // Z Tetromino
    tetrominos[Z] = {
        {{'Z', 'Z', ' '},
         {' ', 'Z', 'Z'}},
        {{' ', 'Z'},
         {'Z', 'Z'},
         {'Z', ' '}}
    };
}

void Tetromino::rotate() {
    rotation = (rotation + 1) % tetrominos[0].size(); // Update based on type
    shape = tetrominos[0][rotation];
}

void Tetromino::rotateMatrix() {
    int n = shape.size();
    std::vector<std::vector<char>> newShape(n, std::vector<char>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            newShape[j][n - 1 - i] = shape[i][j];
        }
    }
    shape = newShape;
}

void Tetromino::print() const {
    for (const auto& row : shape) {
        for (char c : row) {
            std::cout << (c == ' ' ? '.' : c) << ' ';
        }
        std::cout << '\n';
    }
    std::cout << '\n';
}
