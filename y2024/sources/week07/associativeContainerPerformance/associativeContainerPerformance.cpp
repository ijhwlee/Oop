// associativeContainerPerformance.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <map>
#include <unordered_map>
#include <random>
#include <chrono>

static const long long mapSize = 10000000;
static const long long accSize = 1000000;

int main()
{
  std::map<int, int> myMap;
  std::unordered_map<int, int> myHash;
  auto start1 = std::chrono::system_clock::now();
  for (long long i = 0; i < mapSize; ++i) {
    myMap[i] = i;
    myHash[i] = i;
  }
  std::chrono::duration<double> dur1 = std::chrono::system_clock::now() - start1;
  std::cout << "time for 2 10 millions index set  " << dur1.count() << " seconds" << std::endl;
  std::vector<int> randValues;
  randValues.reserve(accSize);
  std::random_device seed;
  std::mt19937 engine(seed());
  std::uniform_int_distribution<> uniformDist(0, mapSize);
  for (long long i = 0; i < accSize; ++i) randValues.push_back(uniformDist(engine));
  auto start = std::chrono::system_clock::now();
  for (long long i = 0; i < accSize; ++i) {
    myMap[randValues[i]];
  }
  std::chrono::duration<double> dur = std::chrono::system_clock::now() - start;
  std::cout << "time for std::map: " << dur.count() << " seconds" << std::endl;

  auto start2 = std::chrono::system_clock::now();
  for (long long i = 0; i < accSize; ++i) {
    myHash[randValues[i]];
  }
  std::chrono::duration<double> dur2 = std::chrono::system_clock::now() - start2;
  std::cout << "time for std::unordered_map: " << dur2.count() << " seconds" << std::endl;
  return 0;
}

// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.
