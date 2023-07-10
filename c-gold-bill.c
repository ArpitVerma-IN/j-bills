/*
Name      : GoldCalc
File Name : c-gold-bill.c
Version   : 0.41
Date      : 10-07-2023
Time      : 11:29
Language  : C

Variables : g - gst % of gold
            j - gst % of jewellery
            m - making charge %
            t - transportation %
            d - discount %
            w - weight of gold jewelry
            c - purity of gold in carat
           cc - purity of gold in %
           ws - gold wastage
           nw - weight removing wastage
           gt - gold gst amount
           jt - jewellery gst amount
           mc - making charge amount
           tc - transportation amount
           da - discount amount
           tt - total amounted tax
            r - rate of 10 grams of gold
           rd - deducted rate of 10 g
           rt - deducted rate of 1 gram
           ga - gross amount of jewelry
           ta - total amount of jewelry

Program Control Variables :
ch1 - controls the recurion of do while
ch2 - stores char value for buy/sell
ch3 - stores int value for bill type

Functions used - getchar()
               - round()
               - printf()
               - scanf()
               - fflush()
               - switch()
               - do-while()
               - main()

Future additions - additional options for silver jewellery bill, store name, date, address of consumer, store HUID of the jewellery.
*/


#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
float g = 0.05;
float j = 0.03;
float m = 0.15;
float t = 0.02;
  
char ch1;
do
{
fflush(stdin);

printf("\n\nBuy(b)/Sell(s) : ");
char ch2 = getchar();

if(ch2 =='b')
{
double gt, jt, mc, tc, da, tt, r, rt, rd, ga, ta;
float w, c, d;
int cc;
printf("Weight(in g)   : ");
scanf("%f", &w);
printf("Carat          : ");
scanf("%f", &c);
cc = round(c*100/24);
printf("Rate(of 10g)   : ");
scanf("%lf", &r);
rd = r*cc/100;
rt = rd/10;
printf("Deducted rate  : %.2lf", rd);
printf("\nDiscount(%%)    : ");
scanf("%f", &d);

ga = w * rt;
mc = ga * m;
tc = ga * t;
da = ga * (d/100);
gt = ga * g;
jt = ga * j;

printf("Gross amount   : %.2lf", ga);
printf("\nMaking charge  : %.2lf", mc);
printf("\nTransportation : %.2lf", tc);
printf("\nDiscount       : %.2lf", da);

int ch3;
printf("\nBill category  : ");
scanf("%i", &ch3);

switch(ch3)
{
case 1:
printf("Gold GST       : %.2lf", gt);
printf("\nJewelry GST    : %.2lf", jt);
tt = mc + tc + gt + jt;
printf("\nTotal tax      : %.2lf", tt);
break;

default:
tt = mc + tc;
printf("Total tax      : %.2lf", tt);
break;
}

ta = ga + tt - da;
printf("\nTotal amount   : %.2lf", ta);
}

else if(ch2 =='s')
{
float w, c, ws, nw;
double r, rd, rt;

printf("Weight(in g)   : ");
scanf("%f", &w);
printf("Wastage(in g)  : ");
scanf("%f", &ws); 
printf("Carat          : ");
scanf("%f", &c);
int cc = round(c*100/24);
printf("Rate(of 10g)   : ");
scanf("%lf", &r);
rd = r * cc / 100;
printf("Deducted rate  : %.2lf", rd);
rt = rd/10;

nw = w - ws;
double ta = nw * rt;
printf("\nTotal amount   : %.2lf", ta);
}

printf("\nContinue(y/n)  : ");
fflush(stdin);
scanf("%c", &ch1);
} while(ch1=='y');

return 0;
}