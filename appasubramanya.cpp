// gireesha

#include <iostream>

using namespace std;

bool overlap(double line1[], double line2[])
{
    //line 1
    double firstx1, firstx2, firsty1, firsty2;
    firstx1 = line1[0];
    firsty1 = line1[1];
    firstx2 = line1[2];
    firsty2 = line1[3];

    cout << firstx1 << firsty1 << firstx2 << firsty2 << endl;

    // y = mx + b
    double slope = (firsty2 - firsty1) / (firstx2 - firstx1);
    double b = firsty1 - slope * firstx1;
    cout << "y = " << slope << "x + " << b << endl;
    //line 2
    double secondx1, secondx2, secondy1, secondy2;
    secondx1 = line2[0];
    secondy1 = line2[1];
    secondx2 = line2[2];
    secondy2 = line2[3];

    cout << secondx1 << secondy1 << secondx2 << secondy2 << endl;
    // y = mx + b
    double slope2 = (secondy2 - secondy1) / (secondx2 - secondx1);
    double b2 = secondy1 - slope2 * secondx1;
    cout << "y = " << slope2 << "x + " << b2 << endl;

    double intersectX = (b2 - b) / (slope - slope2);
    double intersectY = (slope * intersectX) + b;
    cout << intersectX << " , " << intersectY << endl;

    bool result = false;

    if (intersectX > firstx1 && intersectX < firstx2)
    {
        if (slope < 0)
        {
            if (intersectY < firsty1 && intersectY > firsty2)
            {
                result = true;
            }
            else
            {
                return false;
            }
        }
        else
        {
            if (intersectY > firsty1 && intersectY < firsty2)
            {
                result = true;
            }
            else
            {
                return false;
            }
        }
    }
    if (result == true)
    {
        if (intersectX > secondx1 && intersectX < secondx2)
        {
            if (slope2 < 0)
            {

                if (intersectY < secondy1 && intersectY > secondy2)
                {
                    return true;
                }
                else
                {
                    return false;
                }
            }
            else
            {
                if (intersectY > secondy1 && intersectY < secondy2)
                {
                    return true;
                }
                else
                {
                    return false;
                }
            }
        }
    }
    return false;
}
int main()
{
    double line1[4];
    double line2[4];
    cout << "Insert x1, y1, x2, y2 for line 1:";
    cin >> line1[0];
    cin >> line1[1];
    cin >> line1[2];
    cin >> line1[3];
    cout << "Insert x1, y1, x2, y2 for line 2:";

    cin >> line2[0];
    cin >> line2[1];
    cin >> line2[2];
    cin >> line2[3];

    cout << overlap(line1, line2) << endl;

    return 0;
}
