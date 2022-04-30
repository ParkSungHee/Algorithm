cmake_minimum_required(VERSION 3.20)
project(Algorithm)

set(CMAKE_CXX_STANDARD 14)

include_directories(프로그래머스/프로그래머스)

add_executable(Algorithm
#        baekjoon/project/1012_유기농배추.cpp
#        baekjoon/project/1018_체스판다시칠하기.cpp
#        baekjoon/project/10972_다음 순열.cpp
#        baekjoon/project/10973_이전 순열.cpp
#        baekjoon/project/10974_모든 순열.cpp
#        baekjoon/project/1260_dfs와 bfs.cpp
#        baekjoon/project/14499_주사위 굴리기.cpp
#        baekjoon/project/14502_연구소.cpp
#        baekjoon/project/14503_로봇 청소기.cpp
#        baekjoon/project/14888_연산자 끼워넣기 실패(순열,동적할당) .cpp
#        baekjoon/project/14888_연산자 끼워넣기.cpp
#        baekjoon/project/14889_스타트와 링크.cpp
#        baekjoon/project/14890_경사로.cpp
#        baekjoon/project/14891_톱니바퀴.cpp
#        baekjoon/project/15649_n과 m(백트래킹).cpp
#        baekjoon/project/15650_n과 m.cpp
#        baekjoon/project/15655_n과 m.cpp
#        baekjoon/project/15683_감시.cpp
#        baekjoon/project/15686_치킨배달.cpp
#        baekjoon/project/1697_숨바꼭질.cpp
#        baekjoon/project/1926_그림.cpp
#        baekjoon/project/2178_미로탐색.cpp
#        baekjoon/project/2468_안전 영역.cpp
#        baekjoon/project/2583_영역 구하기.cpp
#        baekjoon/project/2667_단지번호붙이기.cpp
#        baekjoon/project/7562_나이트의 이동.cpp
#        baekjoon/project/7569_토마토.cpp
#        baekjoon/project/7576_토마토.cpp
#        baekjoon/project/9663_N-Queen.cpp
#        baekjoon/project/소스.cpp
#        프로그래머스/프로그래머스/2016년.cpp
#        프로그래머스/프로그래머스/3진법 뒤집기.cpp
#        프로그래머스/프로그래머스/K번째수.cpp
#        프로그래머스/프로그래머스/x만큼 간격이 있는 n개의 숫자.cpp
#        프로그래머스/프로그래머스/가운데 글자 가져오기.cpp
#        프로그래머스/프로그래머스/같은 숫자는 싫어.cpp
#        프로그래머스/프로그래머스/나누어 떨어지는 숫자 배열.cpp
#        프로그래머스/프로그래머스/다트 게임.cpp
#        프로그래머스/프로그래머스/두 개 뽑아서 더하기.cpp
#        프로그래머스/프로그래머스/두 정수 사이의 합.cpp
#        프로그래머스/프로그래머스/로또의 최고 순위와 최저 순위.cpp
#        프로그래머스/프로그래머스/모의고사.cpp
#        프로그래머스/프로그래머스/문자열 내 p와 y의 개수.cpp
#        프로그래머스/프로그래머스/문자열 내 마음대로 정렬하기.cpp
#        프로그래머스/프로그래머스/문자열 내림차순으로 배치하기.cpp
#        프로그래머스/프로그래머스/문자열 다루기 기본cpp.cpp
#        프로그래머스/프로그래머스/문자열을 정수로 바꾸기.cpp
#        프로그래머스/프로그래머스/비밀지도.cpp
#        프로그래머스/프로그래머스/서울에서 김서방 찾기.cpp
#        프로그래머스/프로그래머스/소수 만들기.cpp
#        프로그래머스/프로그래머스/소수 찾기.cpp
#        프로그래머스/프로그래머스/수박수박수박수박수박.cpp
#        프로그래머스/프로그래머스/시저 암호.cpp
#        프로그래머스/프로그래머스/신규 아이디 추천.cpp
#        프로그래머스/프로그래머스/실패율.cpp
#        프로그래머스/프로그래머스/약수의 개수와 덧셈.cpp
#        프로그래머스/프로그래머스/약수의 합.cpp
#        프로그래머스/프로그래머스/예산.cpp
#        프로그래머스/프로그래머스/완주하지 못한 선수n^2.cpp
#        프로그래머스/프로그래머스/완주하지 못한 선수nlogn.cpp
#        프로그래머스/프로그래머스/음양 더하기.cpp
#        프로그래머스/프로그래머스/이상한 문자 만들기.cpp
#        프로그래머스/프로그래머스/자가진단-6번 함수구현.cpp
#        프로그래머스/프로그래머스/자릿수 더하기.cpp
#        프로그래머스/프로그래머스/자연수 뒤집어 배열로 만들기.cpp
#        프로그래머스/프로그래머스/정수 내림차순으로 배치하기.cpp
#        프로그래머스/프로그래머스/정수 제곱근 판별.cpp
#        프로그래머스/프로그래머스/제일 작은 수 제거하기.cpp
#        프로그래머스/프로그래머스/직사각형 별찍기.cpp
#        프로그래머스/프로그래머스/짝수와 홀수.cpp
#        프로그래머스/프로그래머스/체육복.cpp
#        프로그래머스/프로그래머스/최대공약수와 최소공배수.cpp
#        프로그래머스/프로그래머스/콜라츠 추측.cpp
#        프로그래머스/프로그래머스/크레인 인형뽑기 게임.cpp
#        프로그래머스/프로그래머스/키패드 누르기.cpp
#        프로그래머스/프로그래머스/평균 구하기.cpp
#        프로그래머스/프로그래머스/폰켓몬.cpp
#        프로그래머스/프로그래머스/하샤드 수.cpp
#        프로그래머스/프로그래머스/핸드폰 번호 가리기.cpp
#        프로그래머스/프로그래머스/행렬의 덧셈.cpp
#        프로그래머스/프로그래머스/조이스틱.cpp
#        프로그래머스/프로그래머스/가장큰수.cpp
#        프로그래머스/프로그래머스/큰수만들기.cpp
        프로그래머스/프로그래머스/test.cpp
        )
