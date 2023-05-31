#pragma once

#include <string>
#include "result.cpp"
// Ŀ������ Ȯ�� : �Ʒ� ��ɾ ������ PowerShell�� �Է� (����-�͹̳�)
// ������Ʈ�� coverage���� �ȿ� ��� ���ϻ�����
// �ҽ��ڵ尡 c����̺꿡 ������. x64�� �����Ұ�
// OpenCppCoverage.exe --sources C:*.c --export_type=html:coverage -- .\x64\Debug\UnitTest.exe

class ALU
{
    const int RESULT_DEFAULT = 65535;
    const int STATUS_NO_RESULT = -1;
    const int STATUS_SUCCESS = 0;
    const int STATUS_FAIL_OP1 = 1;
    const int STATUS_FAIL_OP2 = 2;
    const int STATUS_FAIL_OPCODE = 3;
    const int OPERAND_INVALID = -1;

    int operand1 = OPERAND_INVALID;
    int operand2 = OPERAND_INVALID;
    std::string OPCODE = "";

public:

    void enableSignal(Result* r) {
        if(isInValidOpCode(r)) return;
        if (isInValidOperand(r)) return;

        int result = getResult();
        setResult(r, result, STATUS_SUCCESS);
    }

    void setOperand1(int operand1) {
        this->operand1 = operand1;
    }

    void setOperand2(int operand2) {
        this->operand2 = operand2;
    }

    void setOPCODE(std::string OPCODE) {
        this->OPCODE = OPCODE;
    }

private :
    bool isInValidOpCode(Result* r)
    {
	    if(OPCODE != "ADD" && OPCODE != "MUL" && OPCODE != "SUB")
	    {
            setResult(r, RESULT_DEFAULT, STATUS_FAIL_OPCODE);
            return true;
	    }
        return false;
    }
    bool isInValidOperand(Result* r)
    {
        bool result = false;
        if (operand1 == OPERAND_INVALID) {
            setResult(r, RESULT_DEFAULT, STATUS_FAIL_OP1);
            result = true;
        }
        else if (operand2 == OPERAND_INVALID) {
            setResult(r, RESULT_DEFAULT, STATUS_FAIL_OP2);
            result = true;
        }
        return result;
    }

    int getResult()
    {
        int result = RESULT_DEFAULT;
        if (OPCODE == "ADD") result = operand1 + operand2;
        else if (OPCODE == "MUL") result = operand1 * operand2;
        else if (OPCODE == "SUB") result = operand1 - operand2;
        return result;
    }

    void setResult(Result* r, int result, int status)
    {
        r->setResult(result);
        r->setStatus(status);
    }
};