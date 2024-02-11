// Contraint - use all types of constructor
// use inheritance
#include <bits\stdc++.h>
using namespace std;

class detail
{
private:
    string name, address, PanNo, accType;
    long long adharNo;
    int age, balance;

public:
    detail();
};

detail::detail()
{
}
class savings_account : public detail
{
private:
public:
    savings_account();
    void comInterest(float, float);
    void deposit(float, int);
    void withdraw(float, int);
    void dispBal(float);
};

savings_account::savings_account()
{
}
class current_account
{
private:
public:
    current_account();
    void sInterest(float, float);
    void cDeposit(float, int);
    void cWithdraw(float, int);
    void cWithCheq(float, int);
    void cDispBal(float);
    int fine(float);
};

current_account::current_account()
{
}
/********************************* count no of days *******************************/
struct Date
{
    int d, m, y;
};

const int monthDays[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int countLeapYears(Date d)
{
    int years = d.y;
    if (d.m <= 2)
        years--;
    return years / 4 - years / 100 + years / 400;
}

int getDifference(Date dt1, Date dt2)
{
    long int n1 = dt1.y * 365 + dt1.d;

    for (int i = 0; i < dt1.m - 1; i++)
        n1 += monthDays[i];

    n1 += countLeapYears(dt1);

    long int n2 = dt2.y * 365 + dt2.d;
    for (int i = 0; i < dt2.m - 1; i++)
        n2 += monthDays[i];
    n2 += countLeapYears(dt2);
    return (n2 - n1);
}
/******************************************************/
void savings_account::comInterest(float p, float rate)
{
    time_t tmNow;
    tmNow = time(NULL);
    struct tm t = *localtime(&tmNow);

    Date dt1 = {1, 11, 2022};
    Date dt2 = {t.tm_mday, (t.tm_mon + 1), (t.tm_year + 1900)};

    cout << "Difference between two dates is " << getDifference(dt1, dt2);
    float A, years;
    A = (float)p * (pow((1 + rate), years));
}

void savLogin(long accNo)
{
    savings_account obSav;
    int Choice;
    cout << "1- Deposit money." << endl;
    cout << "2- Withdraw money " << endl;
    cout << "3- Calculate interest " << endl;
    cout << "4- Display balance." << endl;
    cout << "0- Exit" << endl;
    int amount;
    float rate;
    do
    {
        cout << "Enter your choice." << endl;
        cin >> Choice;
        switch (Choice)
        {
        case 1:
            cout << "Enter the amount you want to deposit.\n";
            cin >> amount;
            obSav.deposit(accNo, amount);
            break;
        case 2:
            cout << "Enter the amount you want to withdraw." << endl;
            cin >> amount;
            obSav.withdraw(accNo, amount);
            break;
        case 3:
            cout << "Enter interest annually." << endl;
            cin >> rate;
            obSav.comInterest(accNo, rate);
            break;
        case 4:
            obSav.dispBal(accNo);
        case 0:
            exit;
        default:
            cout << "Not a valid input !\n";
            break;
        }
    } while (Choice != 0);
}

void currLogin(long accNo)
{
    current_account obCurr;
    int Choice;
    cout << "1- Deposit money." << endl;
    cout << "2- Withdraw money " << endl;
    cout << "3- Withdraw money by cheque." << endl;
    cout << "4- Calculate interest " << endl;
    cout << "5- Display balance." << endl;
    cout << "0- Exit" << endl;
    int amount;
    float rate;
    do
    {
        cout << "Enter your choice." << endl;
        cin >> Choice;
        switch (Choice)
        {
        case 1:
            cout << "Enter the amount you want to deposit.\n";
            cin >> amount;
            obCurr.cDeposit(accNo, amount);
            break;
        case 2:
            cout << "Enter the amount you want to withdraw." << endl;
            cin >> amount;
            obCurr.cWithdraw(accNo, amount);
            break;
        case 3:
            cout << "Enter the amount you want to withdraw through cheque." << endl;
            cin >> amount;
            obCurr.cWithCheq(accNo, amount);
            break;
        case 4:
            cout << "Enter interest annually." << endl;
            cin >> rate;
            obCurr.sInterest(accNo, rate);
        case 5:
            obCurr.cDispBal(accNo);
        case 0:
            exit;
        default:
            cout << "Not a valid input !\n";
            break;
        }
    } while (Choice != 0);
}

void login(long accNo)
{
    string type;
    long chkAccNo;
    int passwd, chkPasswd;
    cout << "Enter password." << endl;
    cin >> passwd;
    cout << "Enter account type." << endl;
    cin >> type;
    ifstream fin;
    fin.open("Accounts.txt");

    while (!fin.eof())
    {
        fin >> chkAccNo >> ws;
        fin >> chkPasswd >> ws;
        if (chkAccNo == accNo && chkPasswd == passwd)
        {
            if (type == "savings")
            {
                savLogin(accNo);
            }
            else if (type == "current")
            {
                currLogin(accNo);
            }
        }
        else if (chkAccNo == accNo && chkPasswd != passwd)
        {
            cout << "Incorrect password." << endl;
        }
        else
            cout << "Enter valid account number !" << endl;
    }
}
/********************************** main *************************************/
int main()
{
    int Choice;
    cout << "1- Log in." << endl;
    cout << "2- Open account." << endl;
    cout << "0- Exit" << endl;
    do
    {
        long accNo;
        cout << "Enter your choice." << endl;
        cin >> Choice;
        switch (Choice)
        {
        case 1:
            cout << "Enter your account number.\n";
            cin >> accNo;
            login(accNo);
            break;
        case 2:
            // signUp();
            break;
        case 0:
            exit;
        default:
            cout << "Not a valid input !\n";
            break;
        }
    } while (Choice != 0);
    return 0;
}