// containerSize.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <map>
#include <unordered_map>
#include <set>
#include <vector>

int main()
{
	std::vector<int> intVec{ 1,2,3,4,5,6,7,8,9 };
	std::unordered_map<std::string, int> str2Int = { {"grimm", 12345},
		{"인제대학교", 46574}, {"zebra", 7684},
		{"AI소프트웨어", 4536}, {"김해", 573882} };
	std::map<std::string, int> str2Int2{ str2Int.begin(), str2Int.end()};
	std::set<double> doubleSet{ 3.14, 2.5 };

  std::cout << "str2Int = ";
  for (auto m : str2Int)
    std::cout << m.first << ", " << m.second << " ";
  std::cout << std::endl;
  std::cout << "str2Int2 = ";
  for (auto m : str2Int2)
    std::cout << m.first << ", " << m.second << " ";
  std::cout << std::endl;

  std::cout << std::boolalpha;
  std::cout << "intVec.empty() = " << intVec.empty() << std::endl;
  std::cout << "str2Int.empty() = " << str2Int.empty() << std::endl;
  std::cout << "str2Int2.empty() = " << str2Int2.empty() << std::endl;
  std::cout << "doubleSet.empty() = " << doubleSet.empty() << std::endl;

  std::cout << "intVec.size() = " << intVec.size() << std::endl;
  std::cout << "str2Int.size() = " << str2Int.size() << std::endl;
  std::cout << "str2Int2.size() = " << str2Int2.size() << std::endl;
  std::cout << "doubleSet.size() = " << doubleSet.size() << std::endl;

  std::cout << "intVec.max_size() = " << intVec.max_size() << std::endl;
  std::cout << "str2Int.max_size() = " << str2Int.max_size() << std::endl;
  std::cout << "str2Int2.max_size() = " << str2Int2.max_size() << std::endl;
  std::cout << "doubleSet.max_size() = " << doubleSet.max_size() << std::endl;

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
