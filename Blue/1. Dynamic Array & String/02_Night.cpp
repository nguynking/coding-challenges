#include <iostream>
using namespace std;

int main() {
    string item;
    cin >> item;
    int pointer = 'a';
    int rotations = 0;
    for (int i = 0; i < item.length(); i++) {
        int direction = abs(item[i] - pointer),
            opposite_direction = 26 - abs(item[i] - pointer);

        if (direction > opposite_direction) {
            rotations += opposite_direction;
        }
        else {
            rotations += direction;
        }
        
        pointer = item[i];
    }
    cout << rotations;
    return 0;
}