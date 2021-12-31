# Titansteel_Calculator
Hi 2022, anyway this C++ program allows you to find out whether the sales of your titansteel bar in World of Warcraft: Wrath of the Lich King game is profit or no.
You must have alchemy proffession because this program will calculate your profit (in this case, you don't get profit from selling titansteel bar (sales result - capital  < 0)) based on your how many bonus you get from Transmute: Titanium.



# Input and Output
### input :
- Money available :
- Saronite bar selling price :
- Saronite bar buying price :
- Number of saronite bar :
- Eternal fire buying price :
- Eternal Earth buying price :
- Eternal Shadow buying price :
- TitansteelBar selling price :
- Titanium bar selling price :
### output : 
You can see how the output of this program is from the input and output examples given below :



### input1.txt
```
17248 82 74
9 20 0
10 0 0
509
118 50 0
6 0 0
42 0 0
403 50 0
73 80 0
```
#### output1.txt
```
You will making 21 titansteel bars with :
63 titanium bars, 21 eternal fire, 21 eternal earth, 21 eternal shadow
Unused saronite bar : 5
======================================================
Money available : 17248g 82s 74c
Saronite bar buying price : 10g 00s 00c
Eternal fire buying price : 118g 50s 00c
Eternal earth buying price : 6g 00s 00c
Eternal Shadow buying price : 42g 00s 00c

Number of saronite bar : 509
Unused saronite bar : 5
Used saronite bar : 504
Number of titanium bar : 63
Number of titansteel bar : 21
Number of Eternals : 21 x 3

Total used saronite price : 5040g 00s 00c
Total Eternals Fire price : 2488g 50s 00c
Total Eternals Earth price : 126g 00s 00c
Total Eternals Shadow price : 882g 00s 00c
Total Reagents price : 8536g 50s 00c
Your Money : 8712g 32s 74c

Titansteel bars total selling price : 8473g 50s 00c
Deposit 48 hour price : 15g 75s 00c
Your Money : 8696g 57s 74c

Outcome : 
Outcome titansteel bars sales (-cuts + deposit) : 8065g 57s 50c
Your money : 16762g 15s 24c
======================================================

======================================================
NO PROFIT!
Your loss : 486g 67s 50c
Outcome 1 titanium bar sales (-cuts) : 70g 11s 00c
Your loss can be eliminated if and only if you got bonus +7 titanium bars
from your 'Transmute: Titanium' which the chance getting that much bars
is : 11.1111% chance
Your 'must have chance' is low
FINAL CONCLUSION : PROFIT!
======================================================

======================================================
Comparing only selling titanium bars and selling titansteel bars : 
Comparing both outcome (Titanium : Titansteel) : 
11g 97s 00c : -(486g 67s 50c)
Looks like selling only TITANIUM BARS is the best choice
======================================================
```

#### input2.txt
```
17248 82 74
9 30 0
10 50 0
808
115 50 0
7 0 0
43 0 0
450 50 0
100 80 0
```
#### output2.txt
```
You will making 33 titansteel bars with :
99 titanium bars, 33 eternal fire, 33 eternal earth, 33 eternal shadow
Unused saronite bar : 16
======================================================
Money available : 17248g 82s 74c
Saronite bar buying price : 10g 50s 00c
Eternal fire buying price : 115g 50s 00c
Eternal earth buying price : 7g 00s 00c
Eternal Shadow buying price : 43g 00s 00c

Number of saronite bar : 808
Unused saronite bar : 16
Used saronite bar : 792
Number of titanium bar : 99
Number of titansteel bar : 33
Number of Eternals : 33 x 3

Total used saronite price : 8316g 00s 00c
Total Eternals Fire price : 3811g 50s 00c
Total Eternals Earth price : 231g 00s 00c
Total Eternals Shadow price : 1419g 00s 00c
Total Reagents price : 13777g 50s 00c
Your Money : 3471g 32s 74c

Titansteel bars total selling price : 14866g 50s 00c
Deposit 48 hour price : 24g 75s 00c
Your Money : 3446g 57s 74c

Outcome : 
Outcome titansteel bars sales (-cuts + deposit) : 14147g 92s 50c
Your money : 17594g 50s 24c
======================================================

======================================================
PROFIT!
Your profit = 345g 67s 50c
======================================================

======================================================
Comparing only selling titanium bars and selling titansteel bars : 
Comparing both outcome (Titanium : Titansteel) : 
2482g 92s 00c : 345g 67s 50c
Looks like selling only TITANIUM BARS is the best choice
======================================================
```
