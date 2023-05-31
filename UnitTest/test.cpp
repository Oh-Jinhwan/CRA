#include "pch.h"
#include "../CRA/cal.cpp"
#include "../CRA/sumChecker.cpp"
#include "../CRA/ALU.cpp";
#include "../CRA/result.cpp";
using namespace std;

// cpp���� include�� ��
// Ctrl + Space : �ڵ��ϼ�(�ڵ����� include ��� ��õ)
// main �Լ��� ���� cpp�� ������

// 1) �׽�Ʈ -> �׽�Ʈ Ž���� (����)
// : UnitTest ������Ʈ ��Ŭ���ؼ� ����������Ʈ�� �����ϸ� run�ϸ� �ܼ�â ��
// 2) Google Test �ܼ� (��û����, CLIȯ��)
// 3) ������ TestŽ���� : �׽�Ʈ �����ʿ� ���׶�� Ŭ�� -> run
// : ����Ű �����Ϸ��� ����->�ɼ�->ȯ��->Ű����->unittestrunsolution �˻� �� �Ҵ�
//   �ϴ� ���⼭�� shift + f10���� �Ҵ���
TEST(TestCaseName, TestName) {
  EXPECT_EQ(1, 1);
  EXPECT_TRUE(true);
}

TEST(TestCaseName, TestName2)
{
	// �غ�(����) Arrange

	// ���� Act

	// �׽�Ʈ Assert
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