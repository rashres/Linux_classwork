#include <stdio.h>

double bill(int unit){
    double total,rate;

    if(unit<=100) rate=0.50;
    else if(unit<=300) rate=0.75;
    else if(unit<=600) rate=1.20;
    else rate=1.50;

    total=unit*rate+20;

    if(total>500) total=total*1.10;
    return total;
}

int main(){

    int n,i,u;
    double totalSum=0, highestBill=0, lowestBill=0, billAmount;

    printf("Enter number of customers: ");

    scanf("%d",&n);

    for(i=1;i<=n;i++){
        printf("\nEnter units consumed by customer %d: ",i);
        scanf("%d",&u);

        billAmount=bill(u);
        printf("Total bill for customer %d:  $%.2f\n",i,billAmount);

        totalSum += billAmount;

        if(i==1){ highestBill = billAmount; lowestBill = billAmount; }
        if(billAmount > highestBill) highestBill = billAmount;
        if(billAmount < lowestBill) lowestBill = billAmount;
    }

    printf("\n--- Billing Summary ---\n");

    printf("Average Bill:  $%.2f\n", totalSum/n);
    printf("Highest Bill:  $%.2f\n", highestBill);
    printf("Lowest Bill:   $%.2f\n", lowestBill);

    return 0;
}

