#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

const double g = 9.8;
const double vLevel1 = 20.0; // Initial velocity for Level 1
const double vLevel2 = 25.0; // Initial velocity for Level 2
const double vLevel3 = 30.0; // Initial velocity for Level 3
const double dLevel1 = 30.0; // Distance for Level 1
const double dLevel2 = 50.0; // Distance for Level 2
const double dLevel3 = 70.0; // Distance for Level 3
const double tolerance = 0.5;

double degreesToRadians(double degrees) {
    return degrees * M_PI / 180.0;
}

double calculateRange(double angleDegrees, double velocity) {
    double angleRadians = degreesToRadians(angleDegrees);
    return (velocity * velocity * sin(2 * angleRadians)) / g;
}

void playLevel(int level) {
    double v = (level == 1) ? vLevel1 : (level == 2) ? vLevel2 : vLevel3;
    double d = (level == 1) ? dLevel1 : (level == 2) ? dLevel2 : dLevel3;

    cout << "\nWelcome to Level " << level << "!" << endl;
    cout << "Your task is to hit a target located at " << d << " meters away." << endl;
    cout << "The initial velocity is " << v << " m/s." << endl;
    cout << "\nEnter the correct launch angle in degrees to win the level!\n";

    double userAngle;
    bool won = false;

    while (!won) {
        cout << "\nEnter your angle (in degrees): ";
        cin >> userAngle;

        double range = calculateRange(userAngle, v);

        cout << fixed << setprecision(2);
        cout << "Your projectile landed at " << range << " meters." << endl;

        if (abs(range - d) <= tolerance) {
            cout << "\nCongratulations! You hit the target!" << endl;
            won = true;
            if (level < 3) {
                cout << "Proceeding to Level " << (level + 1) << "!" << endl;
            } else {
                cout << "You've completed all levels! Well done!" << endl;
            }
        } else if (range < d) {
            cout << "Your projectile fell short of the target. Try a larger angle." << endl;
        } else {
            cout << "Your projectile overshot the target. Try a smaller angle." << endl;
        }
    }
}

int main() {
    playLevel(1); // Start with Level 1
    playLevel(2); // Proceed to Level 2
    playLevel(3); // Proceed to Level 3
    return 0;
}
