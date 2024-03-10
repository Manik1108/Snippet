#include <iostream>
#include <sstream> // For std::stringstream
using namespace std;

class sample {
public:
    int Compute(int (sample::*func)(int), int n) {
        return (this->*func)(n);
    }

    int findFactorial(int n) {
        int fact=1;
        for(int i=1; i<=n; i++) {
            fact = fact * i;
        }
        return fact;
    }

    int findSquare(int n) {
        return n * n;
    }

    int findCube(int n) {
        return n * n * n;
    }
};

int main(int argc, char *argv[]) {
    if (argc != 2) {
        cout << "Usage: " << argv[0] << " <number>" << endl;
        return 1;
    }

    int N;
    stringstream ss(argv[1]);
    if (!(ss >> N)) {
        cout << "Invalid number: " << argv[1] << endl;
        return 1;
    }

    sample obj;
    cout << "Factorial of " << N << ": " << obj.Compute(&sample::findFactorial, N) << endl;
    cout << "Square of " << N << ": " << obj.Compute(&sample::findSquare, N) << endl;
    cout << "Cube of " << N << ": " << obj.Compute(&sample::findCube, N) << endl;

    return 0;
}
