#include <iostream>
#include <cmath>
#include <iomanip>
#include <windows.h>
#include <string>
using namespace std;

void SetColor(int value){
  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),  value);
}

void FalseInput() {
  SetColor(12);
  cout << "FALSE INPUT!" << endl;
  SetColor(7);
}

int strnum(string s) {
  cout << fixed;
  cout << setprecision(0);
  bool Negative_Number = 0;
  bool Decimal_Number = 0;
  int NumberPart;
  double count = 0;
  int asciiNumber[10] = { 48, 49, 50, 51, 52, 53, 54, 55, 56, 57 };
  for (int i = 0; i <= s.length()-1; i++) {
    if (!(s[i] >= '0' && s[i] <= '9')) {
      if ((s[i] == '-' && Negative_Number == 1) || (s[i] == '.' && Decimal_Number == 1)) {
        return 0;
      } else if (i > 0 && s[i] == '-') {
        return 0;
      } else if (i == s.length()-1 && s[i] == '.') {
        return 0;
      } else if (s[i] != '-' && s[i] != '.') {
        return 0;
      }
    }
    if (i == 0 && s[i] == '-') {
      Negative_Number = 1; 
    }
    if (s[i] == '.') {
      Decimal_Number = 1;
      NumberPart = i - 1;
    }
    if (s[i+1] == '\0' && Decimal_Number == 0) {
      NumberPart = i;
    }
  }
  for (int i = 0; i <= NumberPart; i++) {
    for (int j = 0; j <= 9; j++) {
      if (s[i] == asciiNumber[j]) {
        int countzero = 1;
        for (int k = (NumberPart - i); k >= 1; k--) {
          if (i == NumberPart) {
            countzero = 1;
          } else {
            countzero *= 10;
          }
        }
        count += (j * countzero);
      }
    }
  }
  if (Decimal_Number) {
    cout << fixed;
    cout << setprecision((s.length()-1) - (NumberPart+1));
    for (int i = NumberPart+1; i < s.length(); i++) {
      for (int j = 0; j <= 9; j++) {
        if (s[i] == asciiNumber[j]) {
          double countzero = 1;
          for (int k = i; k > NumberPart+1; k--) {
            countzero /= 10;
          }
          count += (j * countzero);
        }
      }
    }
  }
  if (Negative_Number) {
    count *= -1;
  }
  return count;
}

double gold, silver, copper;
bool quit = false;                      
void input(string kalimat) {
  bool success = false;
  while(!success) {
    string smoney;
    string sgold, ssilver, scopper;
    bool NotNumber = 0;
    cout << kalimat << " : ";
    getline(cin, smoney);
    if (smoney == "q" || smoney == "quit") {
      quit = true;
      return;
    }
    bool falseI = 0;
    int CountSpace = 0;
    for (int i = 0; i <= smoney.length()-1; i++) {
      if (!(smoney[i] >= '0' && smoney[i] <= '9')) {
        if (smoney[i] == ' ') {
          if (smoney[i+1] == ' ' || smoney[i+1] == '\0') {
            falseI = 1;
            break;
          } else if (smoney[i+1] != ' ') {
            CountSpace++;
            continue;
          }
        } else {
          falseI = 1;
          break;
        }
      }
    }
    if (falseI == 1) {
      FalseInput();
      continue;
    } else if (CountSpace != 2) {
      FalseInput();
      continue;
    }
    bool bgold = 0; bool bsilver = 0; bool bcopper = 0;
    int savei;
    for (int i = 0; i <= smoney.length()-1; i++) {
      if (bgold == 0 && smoney[i+1] == ' ') {
        for (int j = 0; j <= i; j++) {
          sgold = sgold + smoney[j];
        }
        if (sgold.length() > 8) {
          break;
        }
        savei = i+2;
        bgold = 1;
      } else if (bsilver == 0 && smoney[i+1] == ' ') {
        for (int k = savei; k <= i; k++) {
          ssilver = ssilver + smoney[k];
        }
        if (ssilver.length() > 2) {
          break;
        }
        savei = i+2;
        bsilver = 1;
      } else if (bcopper == 0 && smoney[i+1] == '\0') {
        for (int l = savei; l <= i; l++) {
          scopper = scopper + smoney[l];
        }
        if (scopper.length() > 2) {
          break;
        }
        bcopper = 1;
      }
    }
    if (!(bgold == 1 && bsilver == 1 && bcopper == 1)) {
      FalseInput();
      continue;
    } else {
      success = 1;
    }
 	   gold = strnum(sgold);
 	   silver = strnum(ssilver);
 	   copper = strnum(scopper);
  }
}

double converter(double g, double s, double c) {
  cout << fixed;
  cout << setprecision(4);
  double cgold = g;
  double csilver = s/100;
  double ccopper = c/10000;
  return cgold + csilver + ccopper;
}

void converter2(double x) {
  string sgold2, ssilver2, scopper2;
  string smoney = to_string(x);
  for (int i = 0; i <= smoney.length()-3; i++) {
    if (smoney[i+1] == '.') {
      for (int j = 0; j <= i; j++) {
        sgold2 = sgold2 + smoney[j];
      }
    } else if (smoney[i-1] == '.') {
      int count = 1;
      for (int j = i; count <= 2; j++) {
        ssilver2 = ssilver2 + smoney[j];
        count++;
      }
      count = 1;
      for (int j = i+2; count <= 2; j++) {
        scopper2 = scopper2 + smoney[j];
        count++;
      }
      break;
    }
	}
  cout << sgold2 << "g " << ssilver2 << "s " << scopper2 << "c";
}	
     
void input_money(double &x, string s) {
  input(s);
  if (!quit) {
    x = converter(gold, silver, copper);
  } else {
    return;
  }
}
       
 
int main() {
  bool bmoney = 0;
  while (!bmoney) {
    SetColor(8);
    cout << "======================================================" << endl;
    SetColor(7);
    double money;
    input_money(money, "Money available");
    if (quit) {
      return 0;
    }
    double money2 = money;
    double SaroniteBar;
    input_money(SaroniteBar, "Saronite bar buying price");
    if (quit) {
      return 0;
    }
    cout << "Number of saronite bar : ";
    int NumOfSaronite;
    cin >> NumOfSaronite;
    cin.ignore();
    int UnusedSaronite = NumOfSaronite % 24;
    int UsedSaronite = NumOfSaronite - UnusedSaronite;
    int NumOfTitansteel = UsedSaronite/24;
    int NumOfTitanium = UsedSaronite/8;
    int NumOfEternals = UsedSaronite/24;
    SetColor(6);
    cout << "------------------------------------------------------" << "\n";
    SetColor(7);
    cout << "You will making " << NumOfTitansteel << " titansteel bars with :" << endl;
    SetColor(10);
    cout << NumOfTitanium << " titanium bars, " << NumOfEternals << " eternal fire, " << NumOfEternals;
    cout << " eternal earth, " << NumOfEternals << " eternal shadow" << endl;
    SetColor(14);
    cout << "Used Saronite bar : " << UsedSaronite << endl;
    SetColor(12);
    cout << "Unused saronite bar : " << UnusedSaronite << endl;
    SetColor(6);
    cout << "------------------------------------------------------" << "\n";
    SetColor(7);
    double EternalFire;
    input_money(EternalFire, "Eternal fire buying price");
    if (quit) {
      return 0;
    }
    double EternalEarth;
    input_money(EternalEarth, "Eternal Earth buying price");
    if (quit) {
      return 0;
    }
    double EternalShadow;
    input_money(EternalShadow, "Eternal Shadow buying price");
    if (quit) {
      return 0;
    }
    double SellTitansteelBar;
    input_money(SellTitansteelBar, "TitansteelBar selling price");
    if (quit) {
      return 0;
    }
    double SellTitaniumBar;
    input_money(SellTitaniumBar, "Titanium bar selling price");
    if (quit) {
      return 0;
    }
    SetColor(8);
    cout << "======================================================" << endl;
    SetColor(7);
    cout << endl;

    SetColor(8);
    cout << "======================================================" << endl;
    SetColor(7);
    cout << "Money available : ";
    converter2(money);
    cout << "\n";
    cout << "Saronite bar buying price : ";
    converter2(SaroniteBar);
    cout << "\n";
    cout << "Eternal fire buying price : ";
    converter2(EternalFire);
    cout << "\n";
    cout << "Eternal earth buying price : ";
    converter2(EternalEarth);
    cout << "\n";
    cout << "Eternal Shadow buying price : ";
    converter2(EternalShadow);
    cout << "\n";
    cout << "\n";
    cout << "Titanium bar selling price : ";
    converter2(SellTitaniumBar);
    cout << "\n";
    cout << "Titansteel bar selling price : ";
    converter2(SellTitansteelBar);
    cout << "\n";
    cout << "\n";
    cout << "Number of saronite bar : " << NumOfSaronite << "\n";
    cout << "Unused saronite bar : " << UnusedSaronite << "\n";
    cout << "Used saronite bar : " << UsedSaronite << "\n";
    cout << "Number of titanium bar : " << NumOfTitanium << "\n";
    cout << "Number of titansteel bar : " << NumOfTitansteel << "\n";
    cout << "Number of Eternals : " << NumOfEternals << " x 3" << "\n";
    cout << "\n";
    cout << "Total used saronite price : ";
    converter2(UsedSaronite*SaroniteBar);
    cout << "\n";
    cout << "Total Eternals Fire price : ";
    converter2(NumOfEternals*EternalFire);
    cout << "\n";
    cout << "Total Eternals Earth price : ";
    converter2(NumOfEternals*EternalEarth);
    cout << "\n";
    cout << "Total Eternals Shadow price : ";
    converter2(NumOfEternals*EternalShadow);
    cout << "\n";
    double ReagentsPrice = UsedSaronite*SaroniteBar + (NumOfEternals*(EternalFire+EternalEarth+EternalShadow));
    cout << "Total Reagents price : ";
    converter2(ReagentsPrice);
    cout << "\n";
    money2 = money2 - ReagentsPrice;
    cout << "Your Money : ";
    converter2(money2);
    cout << "\n";
    if (money2 < 0) {
      SetColor(12);
      cout << "Your money is not enough!" << "\n";
      SetColor(7);                                                
      continue;
    } else {
      bmoney = 1;
    }
    cout << "\n";
    cout << "Titansteel bars total selling price : ";
    converter2(NumOfTitansteel*SellTitansteelBar);
    cout << "\n";
    double deposit48h = 0.75 * NumOfTitansteel;
    cout << "Deposit 48 hour price : ";
    converter2(deposit48h);
    cout << "\n";
    money2 = money2 - deposit48h;
    cout << "Your Money : ";
    converter2(money2);
    cout << "\n";
    if (money2 < 0) {
      SetColor(14);
      cout << "Make sure you add your money" << "\n";
      SetColor(7);
    }
    cout << "\n";
    cout << "Outcome : " << "\n";
    double OutcomeTitansteel = ((NumOfTitansteel*SellTitansteelBar) * 0.95) + deposit48h;
    cout << "Outcome titansteel bars sales (-cuts + deposit) : ";
    converter2(OutcomeTitansteel);
    cout << "\n";
    money2 = money2 + OutcomeTitansteel;
    cout << "Your money : ";
    converter2(money2);
    cout << "\n";
    SetColor(8);
    cout << "======================================================" << endl;
    SetColor(7);
    cout << "\n";

    SetColor(8);
    cout << "======================================================" << endl;
    SetColor(7);
    double OutcomeEachTitanium = SellTitaniumBar * 0.95;
    double OutcomeTitanium = (NumOfTitanium*SellTitaniumBar) * 0.95;
    double CapitalSaronite = UsedSaronite * SaroniteBar;
    bool ProfitTitanium = 0;
    bool LossTitanium = 0;
    bool SameTitanium = 0;
    double profit2, loss2;
    int TitaniumBonus2;
    double dTitaniumBonus2, dNumOfTitanium2, chance2;
    if (OutcomeTitanium > CapitalSaronite) {
      ProfitTitanium = 1;
      profit2 = OutcomeTitanium - CapitalSaronite;
    } else if (CapitalSaronite > OutcomeTitanium) {
      LossTitanium = 1;
      loss2 = CapitalSaronite - OutcomeTitanium;
      TitaniumBonus2 = (loss2/OutcomeEachTitanium) + 1;
      dTitaniumBonus2 = TitaniumBonus2;
      dNumOfTitanium2 = NumOfTitanium;
      chance2 = (dTitaniumBonus2/dNumOfTitanium2)*100;
    } else {
      SameTitanium = 1;
    }
    bool ProfitTitansteel = 0;
    bool LossTitansteel = 0;
    bool SameTitansteel = 0;
    double profit, loss;
    if (money2 > money) {
      ProfitTitansteel = 1;
      SetColor(10);
      cout << "PROFIT!" << "\n";
      SetColor(7);
      profit = money2 - money;
      cout << "Your profit = +";
      converter2(profit);
      cout << "\n";
    } else if (money > money2) {
      LossTitansteel = 1;
      SetColor(14);
      cout << "NO PROFIT!" << "\n";
      SetColor(7);
      loss = money - money2;
      cout << "Your loss : -";
      converter2(loss);
      cout << "\n";
      cout << "Outcome 1 titanium bar sales (-cuts) : ";
      converter2(OutcomeEachTitanium);
      cout << "\n";
      int TitaniumBonus = (loss/OutcomeEachTitanium) + 1;
      cout << "Your loss can be eliminated if and only if you got bonus +" << TitaniumBonus << " titanium bars\n";
      cout << "from your 'Transmute: Titanium' which the chance getting that much bars" << "\n";
      double dTitaniumBonus = TitaniumBonus; 
      double dNumOfTitanium = NumOfTitanium;
      double chance = (dTitaniumBonus/dNumOfTitanium)*100;
      cout << "is : " << chance << "% chance" << endl;
      if (chance > 15) {
        cout << "Your 'must have chance' is high!" << "\n";
        SetColor(12);
        cout << "FINAL CONCLUSION : NO PROFIT!" << "\n";
        SetColor(7);
      } else {
        cout << "Your 'must have chance' is low" << "\n";
        SetColor(10);
        cout << "FINAL CONCLUSION : PROFIT!" << "\n";
        SetColor(7);
      }
    } else {
      SameTitansteel = 1;
      cout << "You got no profit, but you can rely on your 'Transmute: Titanium' bonus" << "\n";
      SetColor(10);
      cout << "PROFIT!" << "\n";
      SetColor(7);
    }
    SetColor(8);
    cout << "======================================================" << endl;
    SetColor(7);
    cout << "\n";

    SetColor(8);
    cout << "======================================================" << endl;
    SetColor(7);
    cout << "Comparing only selling titanium bars and selling titansteel bars : " << "\n";
    if (ProfitTitanium && ProfitTitansteel) {
      cout << "Comparing both outcome (Titanium : Titansteel) : " << "\n";
      converter2(profit2);
      cout << " : ";
      converter2(profit);
      cout << "\n";
      if (profit2 >= profit) {
        SetColor(10);
        cout << "Looks like selling only TITANIUM BARS is the best choice" << "\n";
        SetColor(7);
      } else {
        SetColor(10);
        cout << "Looks like selling TITANSTEEL BARS is the best choice" << "\n";
        SetColor(7);
      }
    } else if (ProfitTitanium && LossTitansteel) {
      cout << "Comparing both outcome (Titanium : Titansteel) : " << "\n"; 
      converter2(profit2);
      cout << " : -(";
      converter2(loss);
      cout << ")\n";
      SetColor(10);
      cout << "Looks like selling only TITANIUM BARS is the best choice" << "\n";
      SetColor(7);
    } else if (ProfitTitanium && SameTitansteel) {
      cout << "Comparing both outcome (Titanium : Titansteel) : " << "\n";
      converter2(profit2);
      cout << " : " << "0g 00s 00c" << "\n";
      SetColor(10);
      cout << "Looks like selling only TITANIUM BARS is the best choice" << "\n";
      SetColor(7);
//-----------------------------------------------------------------------------------------------------------------
    } else if (LossTitanium && ProfitTitansteel) {
      cout << "Comparing both outcome (Titanium : Titansteel) : " << "\n";
      cout << "-(";
      converter2(loss2);
      cout << ") : ";
      converter2(profit);
      cout << "\n";
      SetColor(10);
      cout << "Looks like selling TITANSTEEL BARS is the best choice" << "\n";
      SetColor(7);
    } else if (LossTitanium && LossTitansteel) {
      cout << "Comparing both outcome (Titanium : Titansteel) : " << "\n";
      cout << "-(";
      converter2(loss2);
      cout << ") : -(";
      converter2(loss);
      cout << ")\n";
      if (loss >= loss2) {
        SetColor(10);
        cout << "Looks like selling only TITANIUM BARS is the best choice" << "\n";
        SetColor(7);
        cout << "Your loss can be eliminated if and only if you got bonus +" << TitaniumBonus2 << " titanium bars\n";
        cout << "from your 'Transmute: Titanium' which the chance getting that much bars" << "\n";
        cout << "is : " << chance2 << "% chance" << endl;
        if (chance2 > 15) {
          cout << "Your 'must have chance' still high!" << "\n";
        } else {
          cout << "Your 'must have chance' low" << "\n";
        }
      } else {
        SetColor(10);
        cout << "Looks like selling TITANSTEEL BARS is the best choice" << "\n";
        SetColor(7);
      }
    } else if (LossTitanium && SameTitanium) {
      cout << "Comparing both outcome (Titanium : Titansteel) : " << "\n";
      cout << "-(";
      converter2(loss2);
      cout << ") : " << "0g 00s 00c" << "\n";
      SetColor(10);
      cout << "Looks like selling TITANSTEEL BARS is the best choice" << "\n";
      SetColor(7);
//-------------------------------------------------------------------------------------------------------------------
    } else if (SameTitanium && ProfitTitansteel) {
      cout << "Comparing both outcome (Titanium : Titansteel) : " << "\n";
      cout << "0g 00s 00c" << " : ";
      converter2(profit);
      cout << "\n";
      SetColor(10);
      cout << "Looks like selling TITANSTEEL BARS is the best choice" << "\n";
      SetColor(7);
    } else if (SameTitanium && LossTitansteel) {
      cout << "Comparing both outcome (Titanium : Titansteel) : " << "\n";
      cout << "0g 00s 00c" << " : -(";
      converter2(loss);
      cout << ")\n";
      SetColor(10);
      cout << "Looks like selling only TITANIUM BARS is the best choice" << "\n";
      SetColor(7);
      cout << "You got no profit, but you can rely on your 'Transmute: Titanium' bonus" << "\n";
    } else if (SameTitanium && SameTitansteel) {
      cout << "Comparing both outcome (Titanium : Titansteel) : " << "\n";
      cout << "0g 00s 00c" << " : " << "0g 00s 00c" << "\n";
      SetColor(10);
      cout << "Looks like selling only TITANIUM BARS is the best choice" << "\n";
      SetColor(7);
      cout << "You got no profit, but you can rely on your 'Transmute: Titanium' bonus" << "\n";
    }
    SetColor(8);
    cout << "======================================================" << endl;
    SetColor(7);				  
  }
  return 0;
}
