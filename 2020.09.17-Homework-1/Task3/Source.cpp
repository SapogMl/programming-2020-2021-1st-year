#include <iostream>
using namespace std;

int allTickets(int sum, int Q)
{
    /*
    Вывод всех возможных номеров до обнуления счетчика. n1, n2, n4, n5 — первая, вторая, четвертая и пятая цифры текущего номера билета соответственно.
    */

    int n1 = 1;
    int n2 = 0;
    int n4 = 0;
    int n5 = 0;

    while (Q > 0)
    {
        if (((sum - n1 - n2) < 0) or ((sum - n1 - n2) > 9) or ((sum - n4 - n5) < 0) or ((sum - n4 - n5) > 9))
        {
            n1++;
            n2 = 0;
            n4 = 0;
            n5 = 0;
        }
        else
        {
            cout << n1 << n2 << sum - n1 - n2;
            cout << n4 << n5 << sum - n4 - n5 << endl;
            n5++;
            if ((sum - n4 - n5) < 0)
            {
                n4++;
                n5 = 0;
            }
            if ((sum - n4) < 0)
            {
                n2++;
                n4 = 0;
                n5 = 0;
            }
            Q--;
        }
    }

    return 0;
}

int main() 
{
    int figureSum = 0;
    int quantity = 0;
    int leftHalf = 0;
    int rightHalf = 0;

    cin >> figureSum;

    /*
    Счетчик числа таких билетов (итоговое количество лежит в quantity).
    */
    for (int n = 0; n < figureSum; n++)
    {
        leftHalf += figureSum - n;
    }

    for (int n = -1; n < figureSum; n++)
    {
        rightHalf += figureSum - n;
    }

    quantity = leftHalf * rightHalf;

    allTickets(figureSum, quantity);
}
