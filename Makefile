# 컴파일러 및 플래그 설정
CXX       = g++
CXXFLAGS  = -std=c++23 -Wall -O2

# 최종 생성할 실행 파일명
TARGET    = test

# 소스 파일들 (추가적인 정렬 알고리즘 소스 파일이 있으면 여기에 추가)
SOURCES   = test.cc merge_sort.cc heap_sort.cc bubble_sort.cc insertion_sort.cc selection_sort.cc quick_sort.cc library_sort.cc tim_sort.cc cocktailshaker_sort.cc comb_sort.cc tournament_sort.cc intro_sort.cc

# 오브젝트 파일들은 소스 파일 이름에 .o 확장자로 변환
OBJECTS   = $(SOURCES:.cc=.o)
OBJECTS   := $(OBJECTS:.cpp=.o)

# 기본 빌드 타겟
all: $(TARGET)

# 링크 단계: 오브젝트 파일들을 함께 링크하여 실행 파일 생성
$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJECTS)

# 패턴 규칙: 각각의 .cpp 또는 .cc 파일에서 .o 파일 생성
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

%.o: %.cc
	$(CXX) $(CXXFLAGS) -c $< -o $@

# 클린 타겟: 생성된 실행 파일과 오브젝트 파일 삭제
clean:
	rm -f $(TARGET) $(OBJECTS)

.PHONY: all clean
