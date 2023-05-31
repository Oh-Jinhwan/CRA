#include "pch.h"
#include "../CRA/cal.cpp"
#include "../CRA/sumChecker.cpp"
#include "../CRA/ALU.cpp";
#include "../CRA/result.cpp";
using namespace std;

// cpp파일 include할 것
// Ctrl + Space : 자동완성(자동으로 include 경로 추천)
// main 함수는 따로 cpp로 빼야함

// 1) 테스트 -> 테스트 탐색기 (느림)
// : UnitTest 프로젝트 우클릭해서 시작프로젝트로 설정하면 run하면 콘솔창 뜸
// 2) Google Test 콘솔 (엄청빠름, CLI환경)
// 3) 리샤퍼 Test탐색기 : 테스트 오른쪽에 동그라미 클릭 -> run
// : 단축키 지정하려면 도구->옵션->환경->키보드->unittestrunsolution 검색 후 할당
//   일단 여기서는 shift + f10으로 할당함
TEST(TestCaseName, TestName) {
  EXPECT_EQ(1, 1);
  EXPECT_TRUE(true);
}

TEST(TestCaseName, TestName2)
{
	// 준비(생성) Arrange

	// 실행 Act

	// 테스트 Assert
}

TEST(RefactoringTest, SumCheckerTest)
{
	EXPECT_EQ("PASS", SumChecker().GetResult("25+61=86"));
}

TEST(RefactoringTest, SumCheckerTest2)
{
	EXPECT_EQ("ERROR", SumChecker().GetResult("5++5=10"));
}

TEST(RefactoringTest, SumCheckerTest3)
{
	EXPECT_EQ("FAIL", SumChecker().GetResult("10000+1=10002"));
}

TEST(ALU, ADDTest1) {
	ALU alu;
	alu.setOperand1(10);
	alu.setOperand2(20);
	alu.setOPCODE("ADD");

	Result ret;
	alu.enableSignal(&ret);

	EXPECT_EQ(30, ret.getResult());
	EXPECT_EQ(0, ret.getStatus());
}

TEST(ALU, ADDTest2) {
	ALU alu;
	alu.setOperand1(10);
	alu.setOPCODE("ADD");

	Result ret;
	alu.enableSignal(&ret);

	EXPECT_EQ(65535, ret.getResult());
	EXPECT_EQ(2, ret.getStatus());
}

TEST(ALU, ADDTest3) {
	ALU alu;
	alu.setOperand2(20);
	alu.setOPCODE("ADD");

	Result ret;
	alu.enableSignal(&ret);

	EXPECT_EQ(65535, ret.getResult());
	EXPECT_EQ(1, ret.getStatus());
}

TEST(ALU, MULTest1) {
	ALU alu;
	alu.setOperand1(10);
	alu.setOperand2(20);
	alu.setOPCODE("MUL");

	Result ret;
	alu.enableSignal(&ret);

	EXPECT_EQ(200, ret.getResult());
	EXPECT_EQ(0, ret.getStatus());
}

TEST(ALU, MULTest2) {
	ALU alu;
	alu.setOperand1(10);
	alu.setOPCODE("MUL");

	Result ret;
	alu.enableSignal(&ret);

	EXPECT_EQ(65535, ret.getResult());
	EXPECT_EQ(2, ret.getStatus());
}

TEST(ALU, MULTest3) {
	ALU alu;
	alu.setOperand2(20);
	alu.setOPCODE("MUL");

	Result ret;
	alu.enableSignal(&ret);

	EXPECT_EQ(65535, ret.getResult());
	EXPECT_EQ(1, ret.getStatus());
}

TEST(ALU, SUBTest1) {
	ALU alu;
	alu.setOperand1(20);
	alu.setOperand2(10);
	alu.setOPCODE("SUB");

	Result ret;
	alu.enableSignal(&ret);

	EXPECT_EQ(10, ret.getResult());
	EXPECT_EQ(0, ret.getStatus());
}

TEST(ALU, SUBTest2) {
	ALU alu;
	alu.setOperand1(20);
	alu.setOPCODE("SUB");

	Result ret;
	alu.enableSignal(&ret);

	EXPECT_EQ(65535, ret.getResult());
	EXPECT_EQ(2, ret.getStatus());
}

TEST(ALU, SUBTest3) {
	ALU alu;
	alu.setOperand2(10);
	alu.setOPCODE("SUB");

	Result ret;
	alu.enableSignal(&ret);

	EXPECT_EQ(65535, ret.getResult());
	EXPECT_EQ(1, ret.getStatus());
}

TEST(ALU, InvalidOpCode) {
	ALU alu;
	alu.setOperand1(10);
	alu.setOperand2(20);
	alu.setOPCODE("DIV");

	Result ret;
	alu.enableSignal(&ret);

	EXPECT_EQ(65535, ret.getResult());
	EXPECT_EQ(3, ret.getStatus());
}