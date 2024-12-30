//#include <iostream>
//#include <fstream>
//#include <string>
//#include <vector>
//#include <iomanip>
//
//using namespace std;
//const string ClientsFileName = "Clients.txt";
//
//void ShowMainMenue();
//void ShowTransactionsClientScreen();
//void GoBackToTransactionMenue();
//
//struct sTransactionsClient
//{
//    short Deposit = 0,
//        Withraw = 0,
//        TotalBalances = 0;
//
//};
//struct sClient
//{
//    string AccountNumber;
//    string PinCode;
//    string Name;
//    string Phone;
//    double AccountBalance = 0;
//    double TotalBalance = 0;
//    bool MarkForDelete = false;
//    sTransactionsClient TransactionsClient;
//};
//
//
//
//vector<string> SplitString(string S1, string Delim)
//{
//    vector<string> vString;
//    short pos = 0;
//    string sWord; // define a string variable  
//
//    // use find() function to get the position of the delimiters  
//    while ((pos = S1.find(Delim)) != std::string::npos)
//    {
//        sWord = S1.substr(0, pos); // store the word   
//        if (sWord != "")
//        {
//            vString.push_back(sWord);
//        }
//
//        S1.erase(0, pos + Delim.length());  /* erase() until positon and move to next word. */
//    }
//
//    if (S1 != "")
//    {
//        vString.push_back(S1); // it adds last word of the string.
//    }
//
//    return vString;
//
//}
//
//sClient ConvertLinetoRecord(string Line, string Seperator = "#//#")
//{
//    sClient Client;
//    vector<string> vClientData;
//    vClientData = SplitString(Line, Seperator);
//
//    Client.AccountNumber = vClientData[0];
//    Client.PinCode = vClientData[1];
//    Client.Name = vClientData[2];
//    Client.Phone = vClientData[3];
//    Client.AccountBalance = stod(vClientData[4]);//cast string to double
//    return Client;
//}
//
//string ConvertRecordToLine(sClient Client, string Seperator = "#//#")
//{
//
//    string stClientRecord = "";
//    stClientRecord += Client.AccountNumber + Seperator;
//    stClientRecord += Client.PinCode + Seperator;
//    stClientRecord += Client.Name + Seperator;
//    stClientRecord += Client.Phone + Seperator;
//    stClientRecord += to_string(Client.AccountBalance);
//    return stClientRecord;
//}
//
//bool ClientExistsByAccountNumber(string AccountNumber, string FileName)
//{
//
//    vector <sClient> vClients;
//    fstream MyFile;
//    MyFile.open(FileName, ios::in);//read Mode
//
//    if (MyFile.is_open())
//    {
//        string Line;
//        sClient Client;
//
//        while (getline(MyFile, Line))
//        {
//            Client = ConvertLinetoRecord(Line);
//            if (Client.AccountNumber == AccountNumber)
//            {
//                MyFile.close();
//                return true;
//            }
//            vClients.push_back(Client);
//        }
//
//        MyFile.close();
//
//    }
//    return false;
//}
//
//sClient ReadNewClient()
//{
//    sClient Client;
//    cout << "Enter Account Number? ";
//
//    // Usage of std::ws will extract all the whitespace character
//    getline(cin >> ws, Client.AccountNumber);
//
//    while (ClientExistsByAccountNumber(Client.AccountNumber, ClientsFileName))
//    {
//        cout << "\nClient with [" << Client.AccountNumber << "] already exists, Enter another Account Number? ";
//        getline(cin >> ws, Client.AccountNumber);
//    }
//
//    cout << "Enter PinCode? ";
//    getline(cin, Client.PinCode);
//
//    cout << "Enter Name? ";
//    getline(cin, Client.Name);
//
//    cout << "Enter Phone? ";
//    getline(cin, Client.Phone);
//
//    cout << "Enter AccountBalance? ";
//    cin >> Client.AccountBalance;
//
//    return Client;
//}
//
//vector <sClient> LoadCleintsDataFromFile(string FileName)
//{
//    vector <sClient> vClients;
//    fstream MyFile;
//    MyFile.open(FileName, ios::in);//read Mode
//
//    if (MyFile.is_open())
//    {
//        string Line;
//        sClient Client;
//
//        while (getline(MyFile, Line))
//        {
//            Client = ConvertLinetoRecord(Line);
//            vClients.push_back(Client);
//        }
//        MyFile.close();
//    }
//    return vClients;
//}
//
//void PrintClientRecordLine(sClient Client)
//{
//    cout << "| " << setw(15) << left << Client.AccountNumber;
//    cout << "| " << setw(10) << left << Client.PinCode;
//    cout << "| " << setw(40) << left << Client.Name;
//    cout << "| " << setw(12) << left << Client.Phone;
//    cout << "| " << setw(12) << left << Client.AccountBalance;
//}
//
//void ShowAllClientsScreen()
//{
//    vector <sClient> vClients = LoadCleintsDataFromFile(ClientsFileName);
//
//    cout << "\n\t\t\t\t\tClient List (" << vClients.size() << ") Client(s).";
//    cout << "\n_______________________________________________________";
//    cout << "_________________________________________\n" << endl;
//
//    cout << "| " << left << setw(15) << "Accout Number";
//    cout << "| " << left << setw(10) << "Pin Code";
//    cout << "| " << left << setw(40) << "Client Name";
//    cout << "| " << left << setw(12) << "Phone";
//    cout << "| " << left << setw(12) << "Balance";
//    cout << "\n_______________________________________________________";
//    cout << "_________________________________________\n" << endl;
//
//    if (vClients.size() == 0)
//        cout << "\t\t\t\tNo Clients Available In the System!";
//    else
//
//        for (sClient Client : vClients)
//        {
//
//            PrintClientRecordLine(Client);
//            cout << endl;
//        }
//
//    cout << "\n_______________________________________________________";
//    cout << "_________________________________________\n" << endl;
//}
//
//void PrintClientCard(sClient Client)
//{
//    cout << "\nThe following are the client details:\n";
//    cout << "-----------------------------------";
//    cout << "\nAccout Number: " << Client.AccountNumber;
//    cout << "\nPin Code     : " << Client.PinCode;
//    cout << "\nName         : " << Client.Name;
//    cout << "\nPhone        : " << Client.Phone;
//    cout << "\nAccount Balance: " << Client.AccountBalance;
//    cout << "\n-----------------------------------\n";
//}
//
//bool FindClientByAccountNumber(string AccountNumber, vector <sClient> vClients, sClient& Client)
//{
//    for (sClient C : vClients)
//    {
//
//        if (C.AccountNumber == AccountNumber)
//        {
//            Client = C;
//            return true;
//        }
//
//    }
//    return false;
//}
//
//sClient ChangeClientRecord(string AccountNumber)
//{
//    sClient Client;
//
//    Client.AccountNumber = AccountNumber;
//
//    cout << "\n\nEnter PinCode? ";
//    getline(cin >> ws, Client.PinCode);
//
//    cout << "Enter Name? ";
//    getline(cin, Client.Name);
//
//    cout << "Enter Phone? ";
//    getline(cin, Client.Phone);
//
//    cout << "Enter AccountBalance? ";
//    cin >> Client.AccountBalance;
//    return Client;
//}
//
//bool MarkClientForDeleteByAccountNumber(string AccountNumber, vector <sClient>& vClients)
//{
//
//    for (sClient& C : vClients)
//    {
//
//        if (C.AccountNumber == AccountNumber)
//        {
//            C.MarkForDelete = true;
//            return true;
//        }
//
//    }
//
//    return false;
//}
//
//vector <sClient> SaveCleintsDataToFile(string FileName, vector <sClient> vClients)
//{
//    fstream MyFile;
//    MyFile.open(FileName, ios::out);//overwrite
//
//    string DataLine;
//
//    if (MyFile.is_open())
//    {
//        for (sClient C : vClients)
//        {
//
//            if (C.MarkForDelete == false)
//            {
//                //we only write records that are not marked for delete.  
//                DataLine = ConvertRecordToLine(C);
//                MyFile << DataLine << endl;
//            }
//
//        }
//
//        MyFile.close();
//    }
//
//    return vClients;
//}
//
//void AddDataLineToFile(string FileName, string  stDataLine)
//{
//    fstream MyFile;
//    MyFile.open(FileName, ios::out | ios::app);
//
//    if (MyFile.is_open())
//    {
//
//        MyFile << stDataLine << endl;
//
//        MyFile.close();
//    }
//}
//
//void AddNewClient()
//{
//    sClient Client;
//    Client = ReadNewClient();
//    AddDataLineToFile(ClientsFileName, ConvertRecordToLine(Client));
//}
//
//void AddNewClients()
//{
//    char AddMore = 'Y';
//    do
//    {
//        //system("cls");
//        cout << "Adding New Client:\n\n";
//
//        AddNewClient();
//        cout << "\nClient Added Successfully, do you want to add more clients? Y/N? ";
//        cin >> AddMore;
//
//    } while (toupper(AddMore) == 'Y');
//
//}
//
//bool DeleteClientByAccountNumber(string AccountNumber, vector <sClient>& vClients)
//{
//    sClient Client;
//    char Answer = 'n';
//
//
//    if (FindClientByAccountNumber(AccountNumber, vClients, Client))
//    {
//
//        PrintClientCard(Client);
//
//        cout << "\n\nAre you sure you want delete this client? y/n ? ";
//        cin >> Answer;
//        if (Answer == 'y' || Answer == 'Y')
//        {
//            MarkClientForDeleteByAccountNumber(AccountNumber, vClients);
//            SaveCleintsDataToFile(ClientsFileName, vClients);
//
//            //Refresh Clients 
//            vClients = LoadCleintsDataFromFile(ClientsFileName);
//
//            cout << "\n\nClient Deleted Successfully.";
//            return true;
//
//
//        }
//
//    }
//
//    else
//    {
//        cout << "\nClient with Account Number (" << AccountNumber << ") is Not Found!";
//        return false;
//    }
//
//
//
//}
//
//bool UpdateClientByAccountNumber(string AccountNumber, vector <sClient>& vClients)
//{
//
//    sClient Client;
//    char Answer = 'n';
//
//    if (FindClientByAccountNumber(AccountNumber, vClients, Client))
//    {
//
//        PrintClientCard(Client);
//        cout << "\n\nAre you sure you want update this client? y/n ? ";
//        cin >> Answer;
//        if (Answer == 'y' || Answer == 'Y')
//        {
//            for (sClient& C : vClients)
//            {
//                if (C.AccountNumber == AccountNumber)
//                {
//                    C = ChangeClientRecord(AccountNumber);
//                    break;
//                }
//            }
//
//            SaveCleintsDataToFile(ClientsFileName, vClients);
//
//            cout << "\n\nClient Updated Successfully.";
//            return true;
//        }
//
//    }
//    else
//    {
//        cout << "\nClient with Account Number (" << AccountNumber << ") is Not Found!";
//        return false;
//    }
//}
//
//string ReadClientAccountNumber()
//{
//    string AccountNumber = "";
//
//    cout << "\nPlease enter AccountNumber? ";
//    cin >> AccountNumber;
//    return AccountNumber;
//
//}
//
//void ShowDeleteClientScreen()
//{
//    cout << "\n-----------------------------------\n";
//    cout << "\tDelete Client Screen";
//    cout << "\n-----------------------------------\n";
//
//    vector <sClient> vClients = LoadCleintsDataFromFile(ClientsFileName); // فائدة تكرار تحميل ما بالفايل في الفكتور لمتابعة التحديث الذي قد يقع على الفايل
//    string AccountNumber = ReadClientAccountNumber();
//    DeleteClientByAccountNumber(AccountNumber, vClients);
//}
//
//void ShowUpdateClientScreen()
//{
//    cout << "\n-----------------------------------\n";
//    cout << "\tUpdate Client Info Screen";
//    cout << "\n-----------------------------------\n";
//
//    vector <sClient> vClients = LoadCleintsDataFromFile(ClientsFileName);
//    string AccountNumber = ReadClientAccountNumber();
//    UpdateClientByAccountNumber(AccountNumber, vClients);
//
//}
//
//void ShowAddNewClientsScreen()
//{
//    cout << "\n-----------------------------------\n";
//    cout << "\tAdd New Clients Screen";
//    cout << "\n-----------------------------------\n";
//
//    AddNewClients();
//}
//
//void ShowFindClientScreen()
//{
//    cout << "\n-----------------------------------\n";
//    cout << "\tFind Client Screen";
//    cout << "\n-----------------------------------\n";
//
//    vector <sClient> vClients = LoadCleintsDataFromFile(ClientsFileName);
//    sClient Client;
//    string AccountNumber = ReadClientAccountNumber();
//    if (FindClientByAccountNumber(AccountNumber, vClients, Client))
//        PrintClientCard(Client);
//    else
//        cout << "\nClient with Account Number[" << AccountNumber << "] is not found!";
//}
//
//// Start Deposit Amount
//void DepositAmount(vector <sClient>& vClients, string AccountNumber)
//{
//    sClient Client;
//    char Transact = 'n';
//    cout << "Please enter deposit amount?";
//    cin >> Client.TransactionsClient.Deposit;
//
//    cout << "Are you sure you want perform this transaction? y/n?";
//    cin >> Transact;
//
//    if (Transact == 'Y' || Transact == 'y')
//    {
//        for (sClient& C : vClients)
//        {
//            if (C.AccountNumber == AccountNumber)
//            {
//                C.AccountBalance = C.AccountBalance + Client.TransactionsClient.Deposit;
//                break;
//
//            }
//        }
//    }
//
//
//}
//
//void DepositByAccountNumber(string AccountNumber, vector <sClient>& vClients)
//{
//    sClient Client;
//
//    if (FindClientByAccountNumber(AccountNumber, vClients, Client))
//    {
//        PrintClientCard(Client);
//
//        DepositAmount(vClients, AccountNumber);
//
//        SaveCleintsDataToFile(ClientsFileName, vClients);
//
//        cout << "\n\nDone Successfully. New balance is: " << Client.AccountBalance;
//
//
//    }
//    else
//    {
//        /*cout << "\nClient with Account Number (" << AccountNumber << ") is Not Found!";*/
//
//        do
//        {
//            cout << "Client with[" << AccountNumber << "] does not exist.\n";
//
//            cout << "\nPlease enter AccountNumber? ";
//            cin >> AccountNumber;
//        } while (FindClientByAccountNumber(AccountNumber, vClients, Client) == false);
//        DepositByAccountNumber(AccountNumber, vClients);
//
//
//
//    }
//
//
//}
//
//void ShowDepositSreen()
//{
//    system("cls");
//    cout << "\n-----------------------------------\n";
//    cout << "\tDeposit Screen";
//    cout << "\n-----------------------------------\n";
//    vector <sClient> vClients = LoadCleintsDataFromFile(ClientsFileName);
//    string AccountNumber = ReadClientAccountNumber();
//    DepositByAccountNumber(AccountNumber, vClients);
//    GoBackToTransactionMenue();
//
//}
//
//// end Deposit Amount
//
//// Start Withraw
//
//void WithrawAmount(vector <sClient>& vClients, string AccountNumber)
//{
//    sClient Client;
//    char Transact = 'n';
//    cout << "Please enter Withraw amount?";
//    cin >> Client.TransactionsClient.Withraw;
//
//    cout << "Are you sure you want perform this transaction? y/n?";
//    cin >> Transact;
//
//    if (Transact == 'Y' || Transact == 'y')
//    {
//        for (sClient& C : vClients)
//        {
//            if (C.AccountNumber == AccountNumber)
//            {
//
//                if (Client.TransactionsClient.Withraw > C.AccountBalance)
//                {
//                    do
//                    {
//                        cout << "Amount Exceeds the balance? you can withraw up to: " << C.AccountBalance << endl;
//                        cout << "Please enter another amount?";
//                        cin >> Client.TransactionsClient.Withraw;
//
//                    } while (Client.TransactionsClient.Withraw < C.AccountBalance);
//
//                }
//                C.AccountBalance = C.AccountBalance - Client.TransactionsClient.Withraw;
//                break;
//
//            }
//        }
//    }
//
//
//}
//
//
//void WithrawByAccountNumber(string AccountNumber, vector <sClient>& vClients)
//{
//    sClient Client;
//
//    if (FindClientByAccountNumber(AccountNumber, vClients, Client))
//    {
//        PrintClientCard(Client);
//
//        WithrawAmount(vClients, AccountNumber);
//
//        SaveCleintsDataToFile(ClientsFileName, vClients);
//
//    }
//    else
//    {
//        /*cout << "\nClient with Account Number (" << AccountNumber << ") is Not Found!";*/
//
//        do
//        {
//            cout << "Client with[" << AccountNumber << "] does not exist.\n";
//
//            cout << "\nPlease enter AccountNumber? ";
//            cin >> AccountNumber;
//        } while (FindClientByAccountNumber(AccountNumber, vClients, Client) == false);
//        WithrawByAccountNumber(AccountNumber, vClients);
//
//
//    }
//
//
//}
//
//void ShowWithrawSreen()
//{
//    system("cls");
//    cout << "\n-----------------------------------\n";
//    cout << "\Withraw Screen";
//    cout << "\n-----------------------------------\n";
//    vector <sClient> vClients = LoadCleintsDataFromFile(ClientsFileName);
//    string AccountNumber = ReadClientAccountNumber();
//    WithrawByAccountNumber(AccountNumber, vClients);
//    GoBackToTransactionMenue();
//
//}
//
//// end Withraw
//
//// Start Balances List
//void PrintClientRecordLineForBalances(sClient Client)
//{
//    cout << "| " << setw(15) << left << Client.AccountNumber;
//    cout << "| " << setw(40) << left << Client.Name;
//    cout << "| " << setw(12) << left << Client.AccountBalance;
//}
//
//void PrintTotalBalances(vector <sClient>& vClients, sClient& Client)
//{
//    double Total = 0.0;
//    for (sClient& Client : vClients)
//    {
//        Client.TotalBalance = Client.TotalBalance + Client.AccountBalance;
//        Total = Total + Client.AccountBalance;
//
//    }
//
//
//    cout << "Total Balances = " << Total << endl;
//    cout << "Total Balances = " << Client.TotalBalance;
//
//}
//
//
//void ShowTotalBalancesScreen()
//{
//    sClient Client;
//
//    vector <sClient> vClients = LoadCleintsDataFromFile(ClientsFileName);
//
//    cout << "\n\t\t\tBalances List (" << vClients.size() << ") Client(s).";
//
//    cout << "\n\n_____________________________________________________________________\n\n";
//    cout << "| " << left << setw(15) << "Accout Number";
//    cout << "| " << left << setw(40) << "Client Name";
//    cout << "| " << left << setw(12) << "Balance";
//    cout << "\n\n______________________________________________________________________\n\n";
//
//    if (vClients.size() == 0)
//        cout << "\t\t\t\tNo Clients Available In the System!";
//    else
//
//        for (sClient& Client : vClients)
//        {
//            PrintClientRecordLineForBalances(Client);
//            cout << "\n";
//
//        }
//
//    cout << "\n\n______________________________________________________________________\n\n";
//
//
//    cout << "\t\t\t";
//    PrintTotalBalances(vClients, Client);
//
//    GoBackToTransactionMenue();
//}
//
//
//// end Balances List
//short ReadTransactionsMenueOption()
//{
//    cout << "Choose what do you want to do? [1 to 4]? ";
//    short Choice = 0;
//    cin >> Choice;
//
//    return Choice;
//}
//
//enum enTransactionsMenueOption
//{
//    enDeposit = 1, enWithraw = 2,
//    enTotalBalances = 3, enMainMenue = 4
//};
//
//void GoBackToTransactionMenue()
//{
//    cout << "\n\nPress any key to go back to Transaction Menue...";
//    system("pause>0");
//    system("cls");
//    ShowTransactionsClientScreen();
//
//}
//
//void PerformTransactionsMenueOption(enTransactionsMenueOption TransactionsMenueOption)
//{
//
//    switch (TransactionsMenueOption)
//    {
//    case enDeposit:
//
//        system("cls");
//        ShowDepositSreen();
//        GoBackToTransactionMenue();
//        break;
//
//    case enWithraw:
//
//        system("cls");
//        ShowWithrawSreen();
//        GoBackToTransactionMenue();
//        break;
//
//    case enTotalBalances:
//
//        system("cls");
//        ShowTotalBalancesScreen();
//        GoBackToTransactionMenue();
//        break;
//
//    case enMainMenue:
//
//        ShowMainMenue();
//        break;
//
//    }
//
//}
//
//void ShowTransactionsClientScreen()
//{
//
//    cout << "\n============================";
//    cout << "============================\n";
//    cout << "\t\tTransaction Menue Screen";
//    cout << "\n============================";
//    cout << "============================\n";
//    cout << "\t[1] Deposit.\n";
//    cout << "\t[2] Withraw.\n";
//    cout << "\t[3] Total Balances.\n";
//    cout << "\t[4] Main Menue.";
//    cout << "\n============================";
//    cout << "============================\n";
//    PerformTransactionsMenueOption((enTransactionsMenueOption)ReadTransactionsMenueOption());
//
//}
//
//void ShowEndScreen()
//{
//    cout << "\n-----------------------------------\n";
//    cout << "\tProgram Ends :-)";
//    cout << "\n-----------------------------------\n";
//}
//
//enum enMainMenueOptions
//{
//    eListClients = 1, eAddNewClient = 2,
//    eDeleteClient = 3, eUpdateClient = 4,
//    eFindClient = 5, eTransactions = 6, eExit = 7
//};
//
//void GoBackToMainMenue()
//{
//    cout << "\n\nPress any key to go back to Main Menue...";
//    system("pause>0");
//    ShowMainMenue();
//
//}
//
//short ReadMainMenueOption()
//{
//    cout << "Choose what do you want to do? [1 to 7]? ";
//    short Choice = 0;
//    cin >> Choice;
//
//    return Choice;
//}
//
//void PerfromMainMenueOption(enMainMenueOptions MainMenueOption)
//{
//    switch (MainMenueOption)
//    {
//    case enMainMenueOptions::eListClients:
//    {
//        system("cls");
//        ShowAllClientsScreen();
//        GoBackToMainMenue();
//        break;
//    }
//    case enMainMenueOptions::eAddNewClient:
//        system("cls");
//        ShowAddNewClientsScreen();
//        GoBackToMainMenue();
//        break;
//
//    case enMainMenueOptions::eDeleteClient:
//        system("cls");
//        ShowDeleteClientScreen();
//        GoBackToMainMenue();
//        break;
//
//    case enMainMenueOptions::eUpdateClient:
//        system("cls");
//        ShowUpdateClientScreen();
//        GoBackToMainMenue();
//        break;
//
//    case enMainMenueOptions::eFindClient:
//        system("cls");
//        ShowFindClientScreen();
//        GoBackToMainMenue();
//        break;
//
//    case enMainMenueOptions::eTransactions:
//        system("cls");
//        ShowTransactionsClientScreen();
//        break;
//
//    case enMainMenueOptions::eExit:
//        system("cls");
//        ShowEndScreen();
//        break;
//    }
//}
//
//void ShowMainMenue()
//{
//    system("cls");
//    cout << "===========================================\n";
//    cout << "\t\tMain Menue Screen\n";
//    cout << "===========================================\n";
//    cout << "\t[1] Show Client List.\n";
//    cout << "\t[2] Add New Client.\n";
//    cout << "\t[3] Delete Client.\n";
//    cout << "\t[4] Update Client Info.\n";
//    cout << "\t[5] Find Client.\n";
//    cout << "\t[6] Transactions.\n";
//    cout << "\t[7] Exit.\n";
//    cout << "===========================================\n";
//    PerfromMainMenueOption((enMainMenueOptions)ReadMainMenueOption()); // He does casting from short to enum;
//}
//
//int main()
//
//{
//    ShowMainMenue();
//    system("pause>0");
//    return 0;
//}

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;
const string ClientsFileName = "Clients.txt";

enum enQuickWithdrawMenueOptions { Twenty = 1, Fifty = 2, OneHundred = 3, TwoHundred = 4, FourHundred = 5, SixHundred = 6, EightHundred = 7, OneThousand = 8, Exit = 9 };
enum enATMMainMenueOptions { eQuickWithdraw = 1, eNormalWithdraw = 2, eDeposit = 3, eCheckBalance = 4, eLogout = 5 };




string ReadClientAccountNumber();
void ShowLoginMenue();
void ShowATMMainMenue();
void GoBackToMainMenue();

struct sClient
{
    string AccountNumber;
    string PinCode;
    string Name;
    string Phone;
    double AccountBalance;
    bool MarkForDelete = false;


};


sClient ClientCurrent;



vector<string> SplitString(string S1, string Delim)
{

    vector<string> vString;

    short pos = 0;
    string sWord; // define a string variable  

    // use find() function to get the position of the delimiters  
    while ((pos = S1.find(Delim)) != std::string::npos)
    {
        sWord = S1.substr(0, pos); // store the word   
        if (sWord != "")
        {
            vString.push_back(sWord);
        }

        S1.erase(0, pos + Delim.length());  /* erase() until position and move to next word. */
    }

    if (S1 != "")
    {
        vString.push_back(S1); // it adds last word of the string.
    }

    return vString;

}

sClient ConvertLinetoRecord(string Line, string Seperator = "#//#")
{

    sClient Client;
    vector<string> vClientData;

    vClientData = SplitString(Line, Seperator);

    Client.AccountNumber = vClientData[0];
    Client.PinCode = vClientData[1];
    Client.Name = vClientData[2];
    Client.Phone = vClientData[3];
    Client.AccountBalance = stod(vClientData[4]);//cast string to double


    return Client;

}

string ConvertRecordToLine(sClient Client, string Seperator = "#//#")
{

    string stClientRecord = "";

    stClientRecord += Client.AccountNumber + Seperator;
    stClientRecord += Client.PinCode + Seperator;
    stClientRecord += Client.Name + Seperator;
    stClientRecord += Client.Phone + Seperator;
    stClientRecord += to_string(Client.AccountBalance);

    return stClientRecord;

}

bool ClientExistsByAccountNumber(string AccountNumber, string FileName)
{

    vector <sClient> vClients;

    fstream MyFile;
    MyFile.open(FileName, ios::in);//read Mode

    if (MyFile.is_open())
    {

        string Line;
        sClient Client;

        while (getline(MyFile, Line))
        {

            Client = ConvertLinetoRecord(Line);
            if (Client.AccountNumber == AccountNumber)
            {
                MyFile.close();
                return true;
            }


            vClients.push_back(Client);
        }

        MyFile.close();

    }

    return false;


}

sClient ReadNewClient()
{
    sClient Client;

    cout << "Enter Account Number? ";

    // Usage of std::ws will extract allthe whitespace character
    getline(cin >> ws, Client.AccountNumber);

    while (ClientExistsByAccountNumber(Client.AccountNumber, ClientsFileName))
    {
        cout << "\nClient with [" << Client.AccountNumber << "] already exists, Enter another Account Number? ";
        getline(cin >> ws, Client.AccountNumber);
    }


    cout << "Enter PinCode? ";
    getline(cin, Client.PinCode);

    cout << "Enter Name? ";
    getline(cin, Client.Name);

    cout << "Enter Phone? ";
    getline(cin, Client.Phone);

    cout << "Enter AccountBalance? ";
    cin >> Client.AccountBalance;

    return Client;

}

vector <sClient> LoadClientsDataFromFile(string FileName)
{

    vector <sClient> vClients;

    fstream MyFile;
    MyFile.open(FileName, ios::in);//read Mode

    if (MyFile.is_open())
    {

        string Line;
        sClient Client;

        while (getline(MyFile, Line))
        {

            Client = ConvertLinetoRecord(Line);

            vClients.push_back(Client);
        }

        MyFile.close();

    }

    return vClients;

}

void PrintClientRecordLine(sClient Client)
{

    cout << "| " << setw(15) << left << Client.AccountNumber;
    cout << "| " << setw(10) << left << Client.PinCode;
    cout << "| " << setw(40) << left << Client.Name;
    cout << "| " << setw(12) << left << Client.Phone;
    cout << "| " << setw(12) << left << Client.AccountBalance;

}

void PrintClientRecordBalanceLine(sClient Client)
{

    cout << "| " << setw(15) << left << Client.AccountNumber;
    cout << "| " << setw(40) << left << Client.Name;
    cout << "| " << setw(12) << left << Client.AccountBalance;
}


void ShowAllClientsScreen()
{


    vector <sClient> vClients = LoadClientsDataFromFile(ClientsFileName);

    cout << "\n\t\t\t\t\tClient List (" << vClients.size() << ") Client(s).";
    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n" << endl;

    cout << "| " << left << setw(15) << "Accout Number";
    cout << "| " << left << setw(10) << "Pin Code";
    cout << "| " << left << setw(40) << "Client Name";
    cout << "| " << left << setw(12) << "Phone";
    cout << "| " << left << setw(12) << "Balance";
    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n" << endl;

    if (vClients.size() == 0)
        cout << "\t\t\t\tNo Clients Available In the System!";
    else

        for (sClient Client : vClients)
        {

            PrintClientRecordLine(Client);
            cout << endl;
        }

    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n" << endl;

}

void CountBalance()
{
    vector <sClient> vClients = LoadClientsDataFromFile(ClientsFileName);

    double YourBalance = 0;

    if (vClients.size() == 0)
        cout << "\t\t\t\tNo Clients Available In the System!";
    else

        for (sClient& Client : vClients)
        {
            if (Client.AccountNumber == ClientCurrent.AccountNumber)
            {
                YourBalance = ClientCurrent.AccountBalance;

            }
        }

    cout << YourBalance;
}


void PrintClientCard(sClient Client)
{
    cout << "\nThe following are the client details:\n";
    cout << "-----------------------------------";
    cout << "\nAccount Number: " << Client.AccountNumber;
    cout << "\nPin Code     : " << Client.PinCode;
    cout << "\nName         : " << Client.Name;
    cout << "\nPhone        : " << Client.Phone;
    cout << "\nAccount Balance: " << Client.AccountBalance;
    cout << "\n-----------------------------------\n";

}

bool FindClientByAccountNumber(sClient& Client)
{
    vector <sClient> vClients = LoadClientsDataFromFile(ClientsFileName);

    for (sClient C : vClients)
    {

        if (C.AccountNumber == ClientCurrent.AccountNumber)
        {
            Client = C;
            return true;
        }

    }
    return false;

}

bool FindClientByAccountNumberAndPinCode(string AccountNumber, string PinCode, sClient& Client)
{
    vector <sClient> vClients = LoadClientsDataFromFile(ClientsFileName);

    for (sClient C : vClients)
    {

        if (C.AccountNumber == AccountNumber && C.PinCode == PinCode)
        {
            Client = C;
            return true;
        }

    }
    return false;

}

sClient ChangeClientRecord(string AccountNumber)
{
    sClient Client;

    Client.AccountNumber = AccountNumber;

    cout << "\n\nEnter PinCode? ";
    getline(cin >> ws, Client.PinCode);

    cout << "Enter Name? ";
    getline(cin, Client.Name);

    cout << "Enter Phone? ";
    getline(cin, Client.Phone);

    cout << "Enter AccountBalance? ";
    cin >> Client.AccountBalance;

    return Client;

}


bool MarkClientForDeleteByAccountNumber(string AccountNumber, vector <sClient>& vClients)
{

    for (sClient& C : vClients)
    {

        if (C.AccountNumber == AccountNumber)
        {
            C.MarkForDelete = true;
            return true;
        }

    }

    return false;

}


vector <sClient> SaveCleintsDataToFile(string FileName, vector <sClient> vClients)
{

    fstream MyFile;
    MyFile.open(FileName, ios::out);//overwrite

    string DataLine;

    if (MyFile.is_open())
    {

        for (sClient C : vClients)
        {

            if (C.MarkForDelete == false)
            {
                //we only write records that are not marked for delete.  
                DataLine = ConvertRecordToLine(C);
                MyFile << DataLine << endl;

            }

        }

        MyFile.close();

    }

    return vClients;

}


void AddDataLineToFile(string FileName, string  stDataLine)
{
    fstream MyFile;
    MyFile.open(FileName, ios::out | ios::app);

    if (MyFile.is_open())
    {

        MyFile << stDataLine << endl;

        MyFile.close();
    }

}



bool DepositBalanceToClientByAccountNumber(sClient& Client, double Amount)
{
    vector <sClient> vClients = LoadClientsDataFromFile(ClientsFileName);

    char Answer = 'n';

    cout << "\n\nAre you sure you want perform this transaction? y/n ? ";
    cin >> Answer;

    if (Answer == 'y' || Answer == 'Y')
    {

        for (sClient& C : vClients)
        {
            if (C.AccountNumber == ClientCurrent.AccountNumber)
            {
                Client = C;
                C.AccountBalance += Amount;
                SaveCleintsDataToFile(ClientsFileName, vClients);
                cout << "\n\nDone Successfully. New balance is: " << C.AccountBalance;
                return true;
            }

        }

    }

    return false;
}

string ReadClientAccountNumber()
{
    string AccountNumber = "";

    cout << "\nPlease enter AccountNumber? ";
    getline(cin >> ws, AccountNumber);
    return AccountNumber;

}

string ReadPinCode()
{
    string PinCode;

    cout << "\nPlease enter PinCode? ";
    getline(cin, PinCode);

    return PinCode;

}



void ShowEndScreen()
{
    ShowLoginMenue();
}

//void ShowDepositScreen()
//{
//    cout << "\n-----------------------------------\n";
//    cout << "\tDeposit Screen";
//    cout << "\n-----------------------------------\n";
//
//
//    sClient Client;
//
//    vector <sClient> vClients = LoadClientsDataFromFile(ClientsFileName);
//    string AccountNumber = ReadClientAccountNumber();
//
//    
//    while (!FindClientByAccountNumber( Client))
//    {
//        cout << "\nClient with [" << AccountNumber << "] does not exist.\n";
//        AccountNumber = ReadClientAccountNumber();
//    }
//
//
//    PrintClientCard(Client);
//
//    double Amount = 0;
//    cout << "\nPlease enter deposit amount? ";
//    cin >> Amount;
//
//    DepositBalanceToClientByAccountNumber(ClientCurrent, Amount);
//
//}

void ShowWithDrawScreen()
{
    string AccountNumber = "";
    cout << "\n-----------------------------------\n";
    cout << "\tWithdraw Screen";
    cout << "\n-----------------------------------\n";

    sClient Client;

    vector <sClient> vClients = LoadClientsDataFromFile(ClientsFileName);


    while (!FindClientByAccountNumber(Client)) //  (do while)، و أنا أستعمل ، (while)، هو استعمل 
    {
        cout << "\nClient with [" << Client.AccountNumber << "] does not exist.\n";
        AccountNumber = ReadClientAccountNumber();
    }

    PrintClientCard(Client);

    double Amount = 0;
    cout << "\nPlease enter withdraw amount? ";
    cin >> Amount;

    //Validate that the amount does not exceeds the balance
    while (Amount > Client.AccountBalance)// ، (Client) كان علي أن أجعل اللوب هذه خارج  الفانكشيون التي تقوم بالخصم من المال العام ، لأنني بداخل الفيكتور ولدي جميع 
    {
        cout << "\nAmount Exceeds the balance, you can withdraw up to : " << Client.AccountBalance << endl;
        cout << "Please enter another amount? ";
        cin >> Amount;
    }

    DepositBalanceToClientByAccountNumber(ClientCurrent, Amount * -1);

}

bool ShowBalance()
{

    vector <sClient> vClients = LoadClientsDataFromFile(ClientsFileName);

    cout << "\n======================================\n";
    cout << "\t\t" << "Check Balance Screen ";
    cout << "\n======================================\n";

    double YourBalance = 0.0;

    if (vClients.size() == 0)
        cout << "\t\t\t\tNo Clients Available In the System!";
    else

        for (sClient Client : vClients)
        {
            if (Client.AccountNumber == ClientCurrent.AccountNumber)
            {
                YourBalance = Client.AccountBalance;
                cout << "  Your  Balances is " << YourBalance;
                return true;
            }
        }
    return false;



}


void ShowBalanceScreen()
{

    ShowBalance();

}

//void ShowTransactionsMenue()
//{
//  
//
//    system("cls");
//    cout << "===========================================\n";
//    cout << "\t\tTransactions Menue Screen\n";
//    cout << "===========================================\n";
//    cout << "\t[1] Deposit.\n";
//    cout << "\t[2] Withdraw.\n";
//    cout << "\t[3] Total Balances.\n";
//    cout << "\t[4] Main Menue.\n";
//    cout << "===========================================\n";
//    PerfromTranactionsMenueOption((enTransactionsMenueOptions)ReadTransactionsMenueOption());
//
//}

void GoBackToMainMenue()
{
    cout << "\n\nPress any key to go back to Main Menue...";
    system("pause>0");
    ShowLoginMenue();

}

void GoBackToATMMainMenue()
{
    cout << "\n\nPress any key to go back to ATM Main Menue...";
    system("pause>0");
    ShowATMMainMenue();
}

short ReadQuickWithrawMenueOption()
{
    cout << "Choose what Withdraw from [1 to 8]? ";
    short Choice = 0;
    cin >> Choice;

    return Choice;
}

short ReadMainMenueOption()
{
    cout << "Choose what do you want to do? [1 to 5]? ";
    short Choice = 0;
    cin >> Choice;

    return Choice;
}

void QuickWithdraw(double Amount)
{
    sClient Client;

    vector <sClient> vClients = LoadClientsDataFromFile(ClientsFileName);

    //Validate that the amount does not exceeds the balance
    while (Amount > ClientCurrent.AccountBalance)// ، (Client) كان علي أن أجعل اللوب هذه خارج  الفانكشيون التي تقوم بالخصم من المال العام ، لأنني بداخل الفيكتور ولدي جميع 
    {
        cout << "\nAmount Exceeds the balance, you can withdraw up to : " << ClientCurrent.AccountBalance << endl;
        system("pause>0");
        ReadQuickWithrawMenueOption();
    }

    DepositBalanceToClientByAccountNumber(ClientCurrent, Amount * -1);



}


void PerformQuickWithdraw(enQuickWithdrawMenueOptions QuickWithdrawMenueOptions)
{
    switch (QuickWithdrawMenueOptions)
    {
    case Twenty:
        QuickWithdraw(20);
        break;
    case Fifty:
        QuickWithdraw(50);
        break;
    case OneHundred:
        QuickWithdraw(100);
        break;
    case TwoHundred:
        QuickWithdraw(200);
        break;
    case FourHundred:
        QuickWithdraw(400);
        break;
    case SixHundred:
        QuickWithdraw(600);
        break;
    case EightHundred:
        QuickWithdraw(800);
        break;
    case OneThousand:
        QuickWithdraw(1000);
        break;
    case Exit:
        ShowATMMainMenue();
        break;
    default:
        break;
    }

}


void ShowQuickWithDrawScreen()
{
    cout << "\n=======================================\n";
    cout << "\t\t Quick Withdraw Screen";
    cout << "\n=======================================\n";
    cout << "\t[1] 20";
    cout << "\t\t[2] 50" << endl;
    cout << "\t[3] 100";
    cout << "\t\t[4] 200" << endl;
    cout << "\t[5] 400";
    cout << "\t\t[6] 600" << endl;
    cout << "\t[7] 800";
    cout << "\t\t[8] 1000" << endl;
    cout << "\t[9] Exit" << endl;
    cout << "\n=======================================\n";
    cout << "Your Balance is: ";
    CountBalance();
    cout << "\n";
    PerformQuickWithdraw((enQuickWithdrawMenueOptions)ReadQuickWithrawMenueOption());


}

void NormalWithdraw()
{
    int Amount = 0.0;
    sClient Client;

    vector <sClient> vClients = LoadClientsDataFromFile(ClientsFileName);

    do
    {
        do
        {
            cout << "\nEnter an amount multiple of 5 's ?";
            cin >> Amount;

        } while (Amount % 5 != 0);

        while (Amount > ClientCurrent.AccountBalance)
        {
            cout << " The amount exceeds your balance , make another choice." << endl;
            cout << "Press any key to continue";
            system("pause>0 ");

        }
    } while (Amount > ClientCurrent.AccountBalance);


    DepositBalanceToClientByAccountNumber(Client, Amount * -1);

}

void ShowNormalWithdarwScreen()
{
    cout << "\n===========================================\n";
    cout << "\t\t Normal Withdraw Screen";
    cout << "\n===========================================\n";
    NormalWithdraw();
}

void DepositOperation()
{
    vector <sClient> vClients = LoadClientsDataFromFile(ClientsFileName);
    sClient Client;
    double Amount;

    do
    {
        cout << "Enter a positive Deposit Amount?";
        cin >> Amount;

    } while (Amount < 0);

    DepositBalanceToClientByAccountNumber(Client, Amount);

}

void ShowDepositScreen()
{
    cout << "\n===========================================\n";
    cout << "\t\t Deposit Screen";
    cout << "\n===========================================\n";
    DepositOperation();
}

void  PerformATMMainMenueOption(enATMMainMenueOptions ATMMainMenueOptions)
{

    switch (ATMMainMenueOptions)
    {
    case eQuickWithdraw:
        system("cls");
        ShowQuickWithDrawScreen();
        GoBackToATMMainMenue();

        break;

    case eNormalWithdraw:
        system("cls");
        ShowNormalWithdarwScreen();
        GoBackToATMMainMenue();

        break;

    case eDeposit:
        system("cls");
        ShowDepositScreen();
        GoBackToATMMainMenue();

        break;

    case eCheckBalance:
        system("cls");
        ShowBalance();
        GoBackToATMMainMenue();

        break;

    case eLogout:
        system("cls");
        ShowLoginMenue();
        break;


    default:
        break;
    }

}


void ShowATMMainMenue()
{

    system("cls");
    cout << "===========================================\n";
    cout << "\t\ATM Main Menue Screen\n";
    cout << "===========================================\n";
    cout << "\t[1] Quick Withdraw.\n";
    cout << "\t[2] Normal Withdraw.\n";
    cout << "\t[3] Deposit .\n";
    cout << "\t[4] Check Balance.\n";
    cout << "\t[5] Logout.\n";
    cout << "===========================================\n";
    PerformATMMainMenueOption((enATMMainMenueOptions)ReadMainMenueOption());
}

bool  LoadUserInfo(string AccountNumber, string PinCode)
{
    sClient Client;

    if (FindClientByAccountNumberAndPinCode(AccountNumber, PinCode, ClientCurrent))
        return true;
    else
        return false;

}

void PerformLoginOptions()
{

    bool LoginFailed = false;
    string AccountNumber = "";
    string PinCode = "";


    do
    {
        if (LoginFailed)
        {
            cout << "\nInvalid AccountNumber or PinCode , Please entre other Client Info." << endl;
        }

        AccountNumber = ReadClientAccountNumber();

        PinCode = ReadPinCode();

        LoginFailed = !LoadUserInfo(AccountNumber, PinCode);

    } while (LoginFailed);



}

void ShowLoginMenue()
{
    cout << "\n-----------------------------------\n\n";
    cout << "\tLogin Screen\n";
    cout << "\n-----------------------------------\n";

    PerformLoginOptions();
    ShowATMMainMenue();
    system("cls");

}

int main()

{



    ShowLoginMenue();


    system("pause>0");
    return 0;
}