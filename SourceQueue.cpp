#include <iostream>
#include <string.h>
#include <windows.h>
using namespace std;

class Queue

{

    char* Wait;
    int MaxQueueLenght;
    int QueueLenght;

public:

    Queue(const char* buf);
    ~Queue();
    bool Empty();
    char Extract();

};

Queue::Queue(const char* buffer) 

{

    MaxQueueLenght = 6;

    Wait = new char[MaxQueueLenght];

    strcpy_s(Wait, 7, buffer);

    QueueLenght = 6;

}
bool Queue::Empty()

{

    return QueueLenght == 0;

}
char Queue::Extract()

{

    char temp = Wait[0];

    for (int i = 1; i < QueueLenght; i++)

    {

        Wait[i - 1] = Wait[i];

    }

    Wait[QueueLenght - 1] = temp;

    return temp;

}
Queue::~Queue()

{

    delete[]Wait;

}


int main()

{

    srand(time(0));

    HANDLE h;

    Queue B_1("012345");

    Queue B_2("102345");

    Queue B_3("012345");

    char B1, B2, B3;

    int randd = rand() % (15 - 30) + 15;

    while (true)

    {

        for (int i = 0; i < randd; i++)

        {
            char c;

            h = GetStdHandle(STD_OUTPUT_HANDLE);

            COORD a{ 0 , 0 };

            c = B_1.Extract();

            SetConsoleTextAttribute(h, 4);
            SetConsoleCursorPosition(h, a);
            cout << c;

            B1 = c;

            Sleep(50);

        }

        randd = rand() % (15 - 30) + 15;

        for (int i = 0; i < randd; i++)

        {

            char c;

            h = GetStdHandle(STD_OUTPUT_HANDLE);

            COORD a{ 5 , 0 };

            c = B_2.Extract();

            SetConsoleTextAttribute(h, 4);

            SetConsoleCursorPosition(h, a);

            cout << c;

            B2 = c;

            Sleep(50);

        }

        randd = rand() % (15 - 30) + 15;

        for (int i = 0; i < randd; i++)

        {

            char c;

            h = GetStdHandle(STD_OUTPUT_HANDLE);

            COORD a{ 10 , 0 };

            c = B_3.Extract();

            SetConsoleTextAttribute(h, 4);

            SetConsoleCursorPosition(h, a);

            cout << c;

            B3 = c;

            Sleep(50);

        }

        cout << endl;

        if (B1 == B2 == B3)

        {

            if (B1 = '0')

                cout << "You are win 1000$";

            else if (B1 == '1')

                cout << "You are win 500$";

            else if (B1 == '2')

                cout << "You are win 250$";

            else if (B1 == '3')

                cout << "You are win 150$";

            else if (B1 == '4')

                cout << "You are win 100$";

        }

        else if (B1 == '5' || B2 == '5' || B3 == '5')

        {

            int count = 0;

            if (B1 == '5')

                count++;

            if (B2 == '5')

                count++;

            if (B3 == '5')

                count++;

            if (count == 1)

                cout << "You are win 50$";

            else if (count == 2)

                cout << "You are win 100$";

            else if (count == 3)

                cout << "You are win 200$";

        }

        else

            cout << "Not today ;(";

        cout << endl;

        system("pause");

        system("cls");

    }

}