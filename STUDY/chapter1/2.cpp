/* 2. C++11 에서 auto 예약어는 어떤 의미인지 쓰고 코드로 예를 보이세요. */

/* auto : 초기값의 형식에 맞춰 선언하는 인스턴스의 형식이 '자동'으로 결정 */

#include <iostream>

using namespace std;

int main()
{
    int a = 10;
    auto b(a);

    cout << "b : " << b << endl;

    return 0;
}
