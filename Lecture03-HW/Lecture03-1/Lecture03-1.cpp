#include <iostream>

using namespace std;

enum ForeColour
{
    Default = 0,
    Black = 30,
    Red = 31,
    Green = 32,
    Yellow = 33,
    Blue = 34,
    Magenta = 35,
    Cyan = 36,
    White = 37,
};

int main()
{
    int num = 0;
    int rest = 1;
    bool okay = true;
    int condition = 32;
    cout << "\x1b[000m" << "화면에 그림을 그리는 프로그램입니다." << endl;
    cout << "학번 : 202127073" << endl;
    cout << "이름 : 김병규" << endl;
    cout << "\x1b[037m" << "흰색 블록을 그리는 키코드 : 1 (1)" << endl;
    cout << "\x1b[031m" << "빨강색 블록을 그리는 키코드 : 2 (10)" << endl;
    cout << "\x1b[032m" << "녹색 블록을 그리는 키코드 : 4 (100)" << endl;
    cout << "\x1b[033m" << "노란색 블록을 그리는 키코드 : 8 (1000)" << endl;
    cout << "\x1b[036m" << "청록색 블록을 그리는 : 16 (10000)" << endl;
    cout << "\x1b[035m" << "마젠타색 블록을 그리는 키코드 : 32 (100000)" << endl;
    cout << "\x1b[037m" << "프로그램 종료 : 64(1000000)" << endl << endl;
    cout << "화면에 그릴 물체코드를 입력하세요 :" << endl;
    cin >> num;

    while (num != 64)
    {
        while (okay)
        {
            if (condition == 32)
            {
                rest = num / 32;
                if (num % 32 == 0 || rest >= 1)
                {
                    rest = 0;
                    
                    cout << "\x1b[035m" << "##########" << endl;
                    cout << "\x1b[035m" << "##########" << endl;
                    cout << "\x1b[035m" << "##########" << endl;
                    cout << "\x1b[035m" << "##########" << endl;
                    cout << "\x1b[035m" << "##########" << endl << endl;
                    num -= 32;
                    if (num % 32 == 0)
                    {
                        condition = 0;
                        okay = false;
                        break;
                    }
                }
                condition = 16;
            }

            else if (condition == 16)
            {
                rest = num / 16;
                if (num % 16 == 0 || rest >= 1)
                {
                    rest = 0;
                    
                    cout << "\x1b[036m" << "##########" << endl;
                    cout << "\x1b[036m" << "##########" << endl;
                    cout << "\x1b[036m" << "##########" << endl;
                    cout << "\x1b[036m" << "##########" << endl;
                    cout << "\x1b[036m" << "##########" << endl << endl;
                    num -= 16;
                    if (num % 16 == 0)
                    {
                        condition = 0;
                        okay = false;
                        break;
                    }
                }
                condition = 8;
            }

            else if (condition == 8)
            {
                rest = num / 8;
                if (num % 8 == 0 || rest >= 1)
                {
                    rest = 0;
                    
                    cout << "\x1b[033m" << "##########" << endl;
                    cout << "\x1b[033m" << "##########" << endl;
                    cout << "\x1b[033m" << "##########" << endl;
                    cout << "\x1b[033m" << "##########" << endl;
                    cout << "\x1b[033m" << "##########" << endl << endl;
                    num -= 8;
                    if (num % 8 == 0)
                    {
                        condition = 0;
                        okay = false;
                        break;
                    }
                }
                condition = 4;
            }

            else if (condition == 4)
            {
                rest = num / 4;
                if (num % 4 == 0 || rest >= 1)
                {
                    rest = 0;
                    
                    cout << "\x1b[032m" << "##########" << endl;
                    cout << "\x1b[032m" << "##########" << endl;
                    cout << "\x1b[032m" << "##########" << endl;
                    cout << "\x1b[032m" << "##########" << endl;
                    cout << "\x1b[032m" << "##########" << endl << endl;
                    num -= 4;
                    if (num % 4 == 0)
                    {
                        condition = 0;
                        okay = false;
                        break;
                    }
                }
                condition = 2;
            }

            else if (condition == 2)
            {
                rest = num / 2;
                if (num % 2 == 0 || rest >= 1)
                {
                    rest = 0;
                    
                    cout << "\x1b[031m" << "##########" << endl;
                    cout << "\x1b[031m" << "##########" << endl;
                    cout << "\x1b[031m" << "##########" << endl;
                    cout << "\x1b[031m" << "##########" << endl;
                    cout << "\x1b[031m" << "##########" << endl << endl;
                    num -= 2;
                    if (num % 2 == 0)
                    {
                        condition = 0;
                        okay = false;
                        break;
                    }
                }
                condition = 1;
            }

            else if (condition == 1)
            {
                rest = num / 1;
                if (num % 1 == 0 || rest >= 1)
                {
                    rest = 0;
                    
                    cout << "\x1b[037m" << "##########" << endl;
                    cout << "\x1b[037m" << "##########" << endl;
                    cout << "\x1b[037m" << "##########" << endl;
                    cout << "\x1b[037m" << "##########" << endl;
                    cout << "\x1b[037m" << "##########" << endl << endl;
                    num -= 1;
                    if (num % 1 == 0)
                    {
                        condition = 0;
                        okay = false;
                        break;
                    }
                }
                condition = 0;
            }
        }

        cout << "\x1b[037m" << "물체 코드를 입력하세요 : ";
        cin >> num;
        condition = 32;
        okay = true;
    }

}
