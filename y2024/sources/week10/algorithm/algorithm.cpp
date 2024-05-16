// algorithm.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <algorithm>
#include <deque>
#include <list>
#include <string>
#include <vector>

template <typename Cont, typename T>
void doTheSame(Cont cont, T t) {
  std::cout << "Original container: " << std::endl;
  for (auto c : cont) std::cout << c << " "; // cont의 내용을 출력
  std::cout << std::endl;
  std::cout << "Original container size: " << std::endl;
  std::cout << "cont.size(): " << cont.size() << std::endl; // cont의 크기를 출력

  std::cout << "Reversed container: " << std::endl;
  std::reverse(cont.begin(), cont.end()); // cont의 순서를 역순으로
  for (auto c : cont) std::cout << c << " ";
  std::cout << std::endl;

  std::cout << "Reversed again container: " << std::endl;
  std::reverse(cont.begin(), cont.end()); // cont의 순서를 다시 역순으로
  for (auto c : cont) std::cout << c << " ";
  std::cout << std::endl;

  std::cout << "Reversed container from element " << t << " : " << std::endl;
  auto It = std::find(cont.begin(), cont.end(), t); // cont에서 원소 t 찾기
  std::reverse(It, cont.end()); // 원소 t 부터 끝까지 역순으로 변경
  for (auto c : cont) std::cout << c << " "; // cont의 내용을 출력
  std::cout << std::endl << std::endl;
}

int main()
{
  std::vector<int> myVec{ 1,2,3,4,5,6,7,8,9,10 };
  doTheSame(myVec, 5);
  std::deque<std::string> myDeque({ "A","B","C","D","E","F","G","H","I" });
  doTheSame(myDeque, "E");
  std::list<char> myList({ 'a','b', 'c', 'd', 'e', 'f', 'g', 'h', 'i'});
  doTheSame(myList, 'e');
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
