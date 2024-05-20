// random.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <random>
#include <map>
#include <fstream>
#include <iostream>

void writeToFile(const std::string file_name, std::map<int, int>& frequency);

int main()
{
  std::random_device seed;
  std::mt19937 engine(seed());
  std::uniform_int_distribution<> uniformDist(0, 20);
  std::normal_distribution<> normDist(50, 8);
  int N = 10;
  std::cout << "Uniform distribution : ";
  for (auto i = 0; i < N; ++i) {
    std::cout << uniformDist(engine) << " ";
  }
  std::cout << std::endl;
  std::cout << "Normal distribution : ";
  for (auto i = 0; i < N; ++i) {
    std::cout << normDist(engine) << " ";
  }
  std::cout << std::endl;

  int NUM = 1000000;
  std::map<int, int> uniformFrequency;
  std::map<int, int> normFrequency;
  for (int i = 0; i <= NUM; ++i) {
    ++uniformFrequency[uniformDist(engine)];
    ++normFrequency[std::round(normDist(engine))];
  }
  writeToFile("uniform_int_distribution.txt", uniformFrequency);
  writeToFile("normal_distribution.txt", normFrequency);
  return 0;
}

void writeToFile(const std::string file_name, std::map<int, int>& frequency) {
  std::ofstream out(file_name);
  for (auto n = 0; n < frequency.size(); ++n) out << n << " : " << frequency[n] << std::endl;
  out.close();
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
