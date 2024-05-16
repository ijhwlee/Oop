// hashInfo.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <unordered_set>
#include <random>

void getInfo(const std::unordered_set<int>& hash) {
  std::cout << "  hash.bucket_count(): " << hash.bucket_count() << std::endl;
  std::cout << "  hash.load_factor(): " << hash.load_factor() << std::endl;
}

void fillHash(std::unordered_set<int>& h, int n) {
  std::random_device seed;
  std::mt19937 engine(seed());
  //std::mt19937 engine(20240415); // 동일한 난수를 발생 시키고 싶을 때
  std::uniform_int_distribution<> uniformDist(0, 1000);
  for (int i = 1; i <= n; ++i) {
    h.insert(uniformDist(engine));
  }
}

int main()
{
  std::unordered_set<int> hash;
  std::cout << "hash.max_load_factor(): " << hash.max_load_factor() << std::endl;
  std::cout << "Initial Hash" << std::endl;
  getInfo(hash);
  hash.insert(500);
  std::cout << "hash.bucket(500): " << hash.bucket(500) << std::endl;
  std::cout << "One element added Hash" << std::endl;
  getInfo(hash);
  std::cout << "Hundred elements added Hash" << std::endl;
  fillHash(hash, 100);
  getInfo(hash);
  std::cout << "Rehashed with size 500 Hash" << std::endl;
  hash.rehash(1000);
  getInfo(hash);
  std::cout << "hash.bucket(500): " << hash.bucket(500) << std::endl;
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
