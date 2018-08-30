#include <iostream>
#include <string>
using namespace std;

class Student{
    private:
        string name, admNo, gender, course;
        int semFee = 25481, paidFee, remFee;
    public:
        // Default constructor. This Will print values not set.
        Student(){
            name = "Not Set";
            admNo = "Not Yet Registered";
            gender = "Male/Female";
            course = "Not yet Registered";
            semFee = 25481;
            paidFee = 0;
            remFee;
        }
        //parameterized constructor. passing values to the constructor.
        Student(string temp_name, string temp_admNo,
                string temp_gender, string temp_course,
                int temp_semFee, int temp_paidFee, int temp_remFee){
            name = temp_name;
            admNo = temp_admNo;
            gender = temp_gender;
            course = temp_course;
            semFee = temp_semFee;
            paidFee = temp_paidFee;
            remFee = temp_remFee;
        }

        void print(){

            remFee = getpayfee() - semFee;
            cout << "\n\n\nThe Following are your details: \n";

            cout << "\n************************************************************************** \n";
            cout <<"* \t"<< " \t\t\t\t\t\t\t\t * \n* \t\t\t\t\t\t\t\t\t * \n";
            cout <<"* \t"<< "Name: \t \t \t\t"<< name<< "\t\t\t *"<< endl;
            cout <<"* \t"<< "Admission Number: \t\t"<< admNo<< "\t\t *"<< endl;
            cout <<"* \t"<< "Gender: \t \t \t"<< gender<< "\t\t\t\t *"<< endl;
            cout <<"* \t"<< "Course: \t \t \t"<< course<< "\t\t *"<< endl;
            cout <<"* \t"<< " \t\t\t\t\t\t\t\t * \t\t\n* \t\t\t\t\t\t\t\t\t * \n";
            cout <<"* \t"<< "The Current Semester Fee  = \t"<< semFee<< "\t\t\t\t *"<< endl;
            cout <<"* \t"<< " \t\t\t\t\t\t\t\t * \n* \t\t\t\t\t\t\t\t\t * \n";
            cout <<"* \t"<< "Fee Paid = \t \t \t"<< getpayfee()<< "\t\t\t\t *"<< endl;
            cout <<"* \t"<< "Remaining fee: \t\t \t"<< getRemFee()<< "\t\t\t\t *"<< endl;
            cout <<"* \t"<< " \t\t\t\t\t\t\t\t * \n* \t\t\t\t\t\t\t\t\t * \n";
            cout << "************************************************************************** \n";
        }

        void setpayfee(int temp_paidfee){
            paidFee = temp_paidfee;
        }

        int getpayfee(){
            return paidFee;
        }

        int getRemFee(){
            return remFee;
        }
};

int main()
{
    char stuName [65] [35] = {
        "Victor Omondi",
        "Sylster Otieno",
        "James Prudence",
        "Wycliff Ndiba",
        "Kelvin Kiprono",
        "Nancy Wambui",
        "Linet Ongalo",
        "Lynn Mwangi"
    };

    char stuAdm [65] [17] = {
        "CIT-222-045/2017",
        "CIT-222-022/2017",
        "CIT-222-056/2017",
        "CIT-222-001/2017",
        "CIT-222-002/2017",
        "CIT-222-003/2017",
        "CIT-222-004/2017"
    };

    char stuGender [65] [8] = {
        "Male",
        "Male",
        "Male",
        "Male",
        "Male",
        "Female",
        "Female",
        "Female"
    };

    char stuCourse [65] [35] = {
        "Computer Technology",
        "Computer Technology",
        "Computer Technology",
        "Computer Technology",
        "Computer Technology",
        "Computer Technology",
        "Computer Technology",
        "Computer Technology"
    };

    int stucurrFee [65] = {
        25481,
        25481,
        25481,
        25481,
        25481,
        25481,
        25481,
        25481
    };

    int stufeePaid [65]= {
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0
    };
    int stuRemFee [65] = {
        25481,
        25481,
        25481,
        25481,
        25481,
        25481,
        25481,
        25481
    };

    Student bo(stuName[0], stuAdm[0], stuGender[0], stuCourse[0], stucurrFee[0], stufeePaid[0], stuRemFee[0]);

    int option;
    int option2;
    int payFeeNow = 0;
    int overpay = 0;
    cout << " ________________________________________________________________ \n\n";
    cout << "| \t\t\t\t\t\t\t\t|";
    cout << "\n|\t\t\t Choose an Option \t\t\t|\n";
    cout << " ________________________________________________________________ \n\n";
    cout << "1. Pay Fees \t\t\t" << "2. Check Fee Balance \n";
    cout << "3. Print Student info \t\t" << "4. Refresh \n";


    cout<<"\t\tEnter Option Here: ";cin >> option;
    if(option == 1){
        cout << "Enter The Fee You Want To pay Here :";
        cin >> payFeeNow;

        if(payFeeNow < 0){
            cout << "Error!! \a You Cant Pay Less That 0. In fact, it doesn't even exist!!! \n";
        }else if(payFeeNow > 25481){
            overpay = payFeeNow - 25481;
            cout << "Fee OverPaid by : "<< overpay;
        }
        cout<<endl;
        bo.setpayfee(payFeeNow);
        cout <<"Success You Have Paid: "<< bo.getpayfee();
        bo.print();

        cout << "Do you want to Check your balance: \n";

        cout << "1. Yes \t 2. No\n";
        cin >> option2;
        if(option2 == 1){
            cout << "\nThe Remaining Fee = " << bo.getRemFee()<<endl;
        }
        }else if(option == 3){
            bo.print();

            cout << "Do you want to add Fee? \n";

            cout << "1. Yes \t 2. No\n";

            int option3;
            cin >> option3;
            if(option3 == 1){
                cout << "Enter The Fee You Want To pay Here :";
                cin >> payFeeNow;
                if(payFeeNow < 0){
                    cout << "Error!! \a You Cant Pay Less That 0. In fact, it doesn't even exist!!! \n";
                }else if(payFeeNow > 25481){
                    overpay = payFeeNow - 25481;
                    cout << "Fee OverPaid by : "<< overpay;
                }
                cout<<endl;
                bo.setpayfee(payFeeNow);
                cout <<"Success You Have Paid: "<< bo.getpayfee();
                bo.print();

                cout << "Do you want to Check your balance: \n";

                cout << "1. Yes \t 2. No\n";
                int option4;
                cin >> option4;
                if(option4 == 1){
                    cout << "\nThe Remaining Fee = " << bo.getRemFee()<<endl;
                }

        }else if(option == 4){
            cout << "\n\aThis Key Is Non-Functional At The Moment \n";
        }else{
            cout<< "\nError!! \a \nKey Not Defined \n";
        }
    }
    return 0;
}
