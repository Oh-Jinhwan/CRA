#include <iostream>
#include <vector>
using namespace std;

class Paper {
public:
    int dateCode;
    string name;

    Paper(int dateCode, string name) {
        this->dateCode = dateCode;
        this->name = name;
    }
};

class Sign {
public:
    void makeSign(vector<Paper>& signVector) {

        //1. 서명 정렬하기
        sortSigns(signVector);

        //2. valid 검사
        if (isVaild(signVector) == false) {
            throw "Invalid dateCode";
        }
        else {
            //3. 서명하기
            doSign(signVector);
        }
    }
private:
    void sortSigns(vector<Paper>& signVector)
    {
        for (unsigned y = 0; y < signVector.size(); y++) {
            for (unsigned x = y + 1; x < signVector.size(); x++) {
                if (signVector[y].dateCode > signVector[x].dateCode) {
                    Paper temp(signVector[y].dateCode, signVector[y].name);
                    signVector[y].dateCode = signVector[x].dateCode;
                    signVector[y].name = signVector[x].name;
                    signVector[x].dateCode = temp.dateCode;
                    signVector[x].name = temp.name;
                }
            }
        }
    }

    // 되도록 긍정체크로 하자.
    bool isVaild(const vector<Paper> signVector)
    {
        bool bResult = true;
        for (Paper sign : signVector)
        {
            if (sign.dateCode > 0 && sign.dateCode < 10)
            {
                continue;
            }
            bResult = false;
            break;
        }

        return bResult;
    }

    void doSign(vector<Paper>& signVector)
    {
        for (Paper tar : signVector)
        {
            cout << tar.dateCode << " : " << tar.name << endl;
        }
    }
};

int main5() {
    Sign sign;
    vector<Paper> arr;
    arr.push_back(Paper(5, "KFC"));
    arr.push_back(Paper(1, "JASON"));
    arr.push_back(Paper(2, "LUCKY"));

    try {
        sign.makeSign(arr);
    }
    catch (const char* msg) {
        cerr << msg << endl;
    }

    return 0;
}