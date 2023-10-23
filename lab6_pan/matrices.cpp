#include <iostream>
#include <fstream>

// Define the maximum size of the square matrix
const int maxMatrixSize = 100;

// Function to read two square matrices from a file and store them in 2D arrays
bool readMatricesFromFile(const std::string& filename, int matrixA[][maxMatrixSize], int matrixB[][maxMatrixSize], int& matrixSize) {
    std::ifstream inputFile(filename);

    if (!inputFile.is_open()) {
        std::cerr << "Error: Unable to open the file." << std::endl;
        return false;
    }

    // Read the size of the matrix from the first line
    if (!(inputFile >> matrixSize)) {
        std::cerr << "Error: Failed to read matrix size from the file." << std::endl;
        return false;
    }

    if (matrixSize <= 0 || matrixSize > maxMatrixSize) {
        std::cerr << "Error: Invalid matrix size." << std::endl;
        return false;
    }

    // Read matrix elements into the first 2D array (Matrix A)
    for (int i = 0; i < matrixSize; ++i) {
        for (int j = 0; j < matrixSize; ++j) {
            if (!(inputFile >> matrixA[i][j])) {
                std::cerr << "Error: Failed to read matrix elements." << std::endl;
                return false;
            }
        }
    }

    // Read matrix elements into the second 2D array (Matrix B)
    for (int i = 0; i < matrixSize; ++i) {
        for (int j = 0; j < matrixSize; ++j) {
            if (!(inputFile >> matrixB[i][j])) {
                std::cerr << "Error: Failed to read matrix elements." << std::endl;
                return false;
            }
        }
    }

    inputFile.close();
    return true;
}

// Function to add two square matrices and store the result in a third matrix
void addMatrices(int matrixA[][maxMatrixSize], int matrixB[][maxMatrixSize], int matrixResult[][maxMatrixSize], int matrixSize) {
    for (int i = 0; i < matrixSize; ++i) {
        for (int j = 0; j < matrixSize; ++j) {
            matrixResult[i][j] = matrixA[i][j] + matrixB[i][j];
        }
    }
}

// Function to multiply two square matrices and store the product in a third matrix
void multiplyMatrices(int matrixA[][maxMatrixSize], int matrixB[][maxMatrixSize], int matrixResult[][maxMatrixSize], int matrixSize) {
    for (int i = 0; i < matrixSize; ++i) {
        for (int j = 0; j < matrixSize; ++j) {
            matrixResult[i][j] = 0;
            for (int k = 0; k < matrixSize; ++k) {
                matrixResult[i][j] += matrixA[i][k] * matrixB[k][j];
            }
        }
    }
}

// Function to subtract two square matrices and store the result in a third matrix
void subtractMatrices(int matrixA[][maxMatrixSize], int matrixB[][maxMatrixSize], int matrixResult[][maxMatrixSize], int matrixSize) {
    for (int i = 0; i < matrixSize; ++i) {
        for (int j = 0; j < matrixSize; ++j) {
            matrixResult[i][j] = matrixA[i][j] - matrixB[i][j];
        }
    }
}

// Function to print a square matrix
void printMatrix(int matrix[][maxMatrixSize], int matrixSize) {
    for (int i = 0; i < matrixSize; ++i) {
        for (int j = 0; j < matrixSize; ++j) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << "\n";
    }
}

int main() {
    int matrixA[maxMatrixSize][maxMatrixSize];
    int matrixB[maxMatrixSize][maxMatrixSize];
    int matrixResult[maxMatrixSize][maxMatrixSize];
    int matrixSize;
	
	std::cout<<"Name: Audrey Pan\n";
	std::cout<<"Lab #6: Matrix Manipulation\n";
	std::cout << "\n";

    if (readMatricesFromFile("matrix_input.txt", matrixA, matrixB, matrixSize)) {
        // Print Matrix A
        std::cout << "Matrix A:\n";
        printMatrix(matrixA, matrixSize);
		std::cout << "\n";

        // Print Matrix B
        std::cout << "Matrix B:\n";
        printMatrix(matrixB, matrixSize);
		std::cout << "\n";

        // Add Matrix A and Matrix B
        addMatrices(matrixA, matrixB, matrixResult, matrixSize);

        // Print the result of Matrix A + Matrix B
        std::cout << "Matrix A + Matrix B:\n";
        printMatrix(matrixResult, matrixSize);
		std::cout << "\n";
		
        // Multiply Matrix A and Matrix B
        multiplyMatrices(matrixA, matrixB, matrixResult, matrixSize);

        // Print the result of Matrix A * Matrix B
        std::cout << "Matrix A * Matrix B:\n";
        printMatrix(matrixResult, matrixSize);
		std::cout << "\n";

        // Subtract Matrix A and Matrix B
        subtractMatrices(matrixA, matrixB, matrixResult, matrixSize);

        // Print the result of Matrix A - Matrix B
        std::cout << "Matrix A - Matrix B:\n";
        printMatrix(matrixResult, matrixSize);
		std::cout << "\n";


    }

    return 0;
}
