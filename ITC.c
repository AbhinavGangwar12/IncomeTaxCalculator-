#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct Taxpayor{
    char name[50];
    float income[8],deduction[7],taxableIncome,tax,totalIncome,totalDeduction;
};
struct Taxpayor taxpayors[10];
int newEntry =0;
void getPersonDetails(){
    printf("Enter details\n\n");
    struct Taxpayor person;
    printf("Enter your name : ");
    getchar();
    scanf("%[^\n]%*c",person.name);
    printf("Income from salary : ");
    scanf("%f",&person.income[0]);
    printf("Exempt Allowance : ");
    scanf("%f",&person.income[1]);
    printf("Income from interests : ");
    scanf("%f",&person.income[2]);
    printf("Interest paid on house loan : ");
    scanf("%f",&person.income[3]);
    printf("Rental Income received : ");
    scanf("%f",&person.income[4]);
    printf("Interest paid on loan : ");
    scanf("%f",&person.income[5]);
    printf("Income from digital assets : ");
    scanf("%f",&person.income[6]);
    printf("Income from other sources : ");
    scanf("%f",&person.income[7]);
    printf("--------------------------------------------------\n");
    printf("Basic deduction (80C) : ");
    scanf("%f",&person.deduction[0]);
    printf("Interests from deposits (80TTA) : ");
    scanf("%f",&person.deduction[1]);
    printf("Medical insurance (80D) : ");
    scanf("%f",&person.deduction[2]);
    printf("Donation to charity (80G) : ");
    scanf("%f",&person.deduction[3]);
    printf("Interest on Educational loan (80E) : ");
    scanf("%f",&person.deduction[4]);
    printf("Interest on housing loan (80EEA) : ");
    scanf("%f",&person.deduction[5]);
    printf("Contribution to NPS (80CCD) : ");
    scanf("%f",&person.deduction[6]);
    if(person.deduction[0]>150000)person.deduction[0] = 150000;
    if(person.deduction[1]>10000)person.deduction[1] = 10000;
    if(person.deduction[2]>25000)person.deduction[2] = 25000;
    if(person.deduction[5]>150000)person.deduction[5] = 150000;
    if(person.deduction[6]>50000)person.deduction[6] = 50000;
    for (int i = 0; i <= 7; i++)person.totalIncome += person.income[i];
    for (int i = 0; i < 7; i++)person.totalDeduction += person.deduction[i];
    person.taxableIncome = person.totalIncome - person.totalDeduction;
    float tax_=0;
    if(person.taxableIncome <= 5000000){
        if(person.taxableIncome<=300000){
            tax_ += 0;
            person.taxableIncome=0;
        }
        else{
            if(person.taxableIncome>300000){
                if((person.taxableIncome-300000)>=300000)tax_ += 15000;
                else tax_ += (person.taxableIncome-300000)*0.05;
            }
            if(person.taxableIncome>600000){
                if((person.taxableIncome-600000)>=300000)tax_ += 30000;
                else tax_ += (person.taxableIncome-600000)*0.1;
            }
            if(person.taxableIncome>900000){
                if((person.taxableIncome-900000)>=300000)tax_ += 45000;
                else tax_ += (person.taxableIncome-900000)*0.15;
            }
            if(person.taxableIncome>1200000){
                if((person.taxableIncome-1200000)>=300000)tax_ += 60000;
                else tax_ += (person.taxableIncome-1200000)*0.2;
            }
            if(person.taxableIncome>1500000)tax_ += (person.taxableIncome-1500000)*0.3;
            if(person.taxableIncome==1500000)tax_ = 150000;
        }
    }
    else {
        if(person.taxableIncome>5000000){
            if((person.taxableIncome-5000000)>5000000)tax_ += 500000;
            else tax_ += (person.taxableIncome-5000000)*0.1;
        }
        if(person.taxableIncome>10000000){
            if((person.taxableIncome-10000000)>=10000000)tax_ += 1500000;
            else tax_ += (person.taxableIncome-10000000)*0.15;
        }
        if(person.taxableIncome>20000000){
            if((person.taxableIncome-30000000)>=30000000)tax_ += 7500000;
            else tax_ += (person.taxableIncome-5000000)*0.25;
        }
        if(person.taxableIncome>50000000){
            tax_ += (person.taxableIncome-50000000)*0.37;
        }
    }
    tax_ += tax_*0.4;//APPLYING CESS
    person.tax = tax_;
    taxpayors[newEntry] = person;
    newEntry++;
    printf("------------------------------------------------------------\n");
    printf("Taxable Income : %f",person.taxableIncome);
    printf("\nPayable Tax : %f",person.tax);
    printf("\n------------------------------------------------------------\n");
}
void list_taxpayor(){
    if(newEntry==0)printf("No record found.\n");
    else for(int i=0;i<newEntry;i++)printf("Name : %s\nTaxable Income : %.2f\nPayable Tax : %.2f",taxpayors[i].name,taxpayors[i].taxableIncome,taxpayors[i].tax);
}
void search(){
    printf("------------------------------------------------------------\n");
    char name[20];
    printf("\nEnter name : ");
    getchar();
    scanf("%[^\n]%*c",name);
    for(int i=0;i<newEntry;i++){
        if(strcmp(taxpayors[i].name,name)==0){
            printf("Name : %s\nTaxable Income : %.2f\nPayable Tax : %.2f",taxpayors[i].name,taxpayors[i].taxableIncome,taxpayors[i].tax);
            return;
        }
    }
    printf("Not found!\n");
}
void edit(){
    printf("------------------------------------------------------------\n");
    char name[50];
    printf("\nEnter name to edit : ");
    getchar();
    scanf("%[^\n]%*c",name);
    for (int i = 0; i < newEntry; i++)
    {
        if(strcmp(taxpayors[i].name,name)==0){
            printf("Enter new total income : ");
            scanf("%f",&taxpayors[i].totalIncome);
            printf("Enter new total deduction : ");
            scanf("%f",&taxpayors[i].totalDeduction);
        }
        else printf("\nNo record found !");
    }
    
}
void delete(){
    char name[50];
    printf("------------------------------------------------------------\n");
    printf("\nEnter the name to be deleted : ");
    getchar();
    scanf("%[^\n]%*c",name);
    for(int i=0;i<newEntry;i++){
        if(strcmp(taxpayors[i].name,name)==0){
            for(int j =i;j<newEntry-1;j++){
                taxpayors[j] = taxpayors[j+1];
                newEntry--;
            }
            printf("Successfully Deleted !");
            return;
        }
    }
}
void intro(){
    printf("------------------------------------------------------------\n");
    printf("\t\tINCOME TAX CALCULATOR\n");
    printf("------------------------------------------------------------\n");
    printf("Guidelines :\n");
    printf("\n1. This calculator is based on Income tax policy of 2023-24\n2. It takes input upto 6 decimal places\n3. Enter 0 'zero' if you dont want to fill that feild\n4. This calculator is menu driven\n");
    printf("------------------------------------------------------------\n");
}
void display_choices(){
    printf("\n------------------------------------------------------------\n");
    printf("\nChoose the number and press Enter for the operation\n");
    printf("1 to Add new record and calculate tax\n2 to list all tax payors of this session\n3 to search\n4 to edit\n5 to delete record\n6 to exit");
}
int main(){
    intro();
    while (1){
        display_choices();
        printf("\nEnter choice here : ");
        int choice;
        scanf("%d",&choice);
        switch (choice)
        {
           case 1:
                getPersonDetails();
                break;
            case 2:
                list_taxpayor();
                break;
            case 3:
                search();
                break;
            case 4:
                edit();
                break;
            case 5:
                delete();
                break;
            case 6:
                printf("Successfully Exited !");
                exit(0);
                break;
            default:
                printf("Invalid choice. Try again !");
                break;
        }
    }
    return 0;
}