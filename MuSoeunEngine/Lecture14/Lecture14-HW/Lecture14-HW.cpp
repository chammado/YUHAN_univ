#include <iostream>
#include <chrono>
#include <thread>

using namespace std;

void Eventhandler()
{
    cout << "끄아아아아아" << endl;
}

int main()
{
    void (*onCollisionEnter)() = Eventhandler;

    int count = 0;

    chrono::steady_clock::time_point prev_end = chrono::steady_clock::now();
    chrono::steady_clock::time_point end = chrono::steady_clock::now();

    int delay_time_ms = 0;

    while (count < 10)
    {
        // 슬립
        this_thread::sleep_for(chrono::milliseconds(1000 + delay_time_ms));
        // 시작시간과 끝시간
        prev_end = end;
        end = chrono::steady_clock::now();
        // 시간차 구하기
        chrono::steady_clock::duration diff = end - prev_end;
        delay_time_ms = 1000 - chrono::duration_cast<chrono::milliseconds>(diff).count();
        // delay_time_ms가 음수가 되는 것을 방지
        if (delay_time_ms < 0)
        {
            delay_time_ms = 0;
        }
        // 출력
        count++;
        cout << count << "   dur:" << delay_time_ms << "ms" << endl;
        onCollisionEnter();
    }

    return 0;
}