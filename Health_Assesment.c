#include <stdio.h>

//Declaring all the  function prototypes
void BMI();
void BP();
int average();
void ERICE();
char age40_49(), age50_59(), age60_69(), age70_79();
char Gender(), Diabetes(), Smoke();
float Cholesterol();
int SBP();

int main(void)
{
    // Asking the user what he/she want to assess
    int num;
    printf("\n\n\t\t Welcome to Health Assesment \n");
    printf("\t\t*****************************\n\n");
    printf(" Press 1 for checking your BMI \n");
    printf(" Press 2 for checking your Blood Pressure \n");
    printf(" Press 3 for checking your Cardiac Risk Assessment \n");
    printf("\n Your Choice : ");
    scanf("%d",&num);

    // Calling the necessary function of what the user deems
    while (num != 1 && num != 2 && num != 3)
    {
        printf(" \n Sorry wrong input.\n\n Enter your choice again :  ");
        scanf(" %d",&num);
    }

    if (num == 1)
    {
        BMI();
    }
    else if (num == 2)
    {
        BP();
    }
    else 
    {
        ERICE();
    }
    
    printf("\n\n\n\t\t\t Thank You \n\n ");
}

// BMI function to calculate the Body Mass Index
void BMI()
{
    
    printf("\n\n\tYou have selected to assess BMI\n");
    printf("\t-------------------------------\n\n");

    // Asking user the necessary information for calculation
    int weight;
    float height,Bmi;
    char* Result;
    printf("Enter your weight (in kg) : ");
    scanf("%d",&weight);
    printf("Enter your height (in m)  : ");
    scanf("%f",&height);

    while(0.5 <= height && height >= 2.5)
    {
        printf(" \nSorry wrong input.\n\nEnter height again :  ");
        scanf(" %f",&height);
    }

    Bmi = (weight)/(height * height);

    // After calculation of BMI, specifying its category

    if ( Bmi < 18.5 )
      {
          Result="Underweight";
      }
    else if ( Bmi >= 18.5 && Bmi < 25 )
      {
          Result="Normal";
      }
    else if (  Bmi >= 25 && Bmi < 30 )
      {
          Result="Overweight";
      }
    else
      {
          Result="Obese";
      }

      printf("Your BMI is %.2f and so your weight category is %s",Bmi,Result);
}

// BP function to calculate the Blood Pressure
void BP()
{
    printf("\n\n\tYou have selected to assess BP\n");
    printf("\t------------------------------\n\n");

    // Asking user the necessary information for calculation
    int Sbp[5],Dbp[5];
    int avg1,avg2;

    printf(" Enter 5 Stolic blood pressure measures (in mmHg) :- \n");

    for (int i=0;i<5;i++)
    {
        printf(" Reading %d : ",i+1);
        scanf("%d",&Sbp[i]);
    }

    int size1 = sizeof(Sbp) / sizeof(Sbp[0]);
    avg1=average(Sbp,size1);

    printf("\n Enter 5 Diastolic blood pressure measures (in mmHg) :- \n");

    for (int i=0;i<5;i++)
    {
        printf(" Reading %d : ",i+1);
        scanf("%d",&Dbp[i]);
    }

    int size2 = sizeof(Dbp) / sizeof(Dbp[0]);
    avg2=average(Dbp,size2);
    printf("\n");
    // After calculation of BP, specifying its category

    if(40<=avg2 && avg2<60 && 70<=avg1 && avg1<90)
    {
        printf("You have Low Blood Pressure");
    }
    else if(60<=avg2 && avg2<80 && 90<=avg1 && avg1<120)
    {
        printf("You have Ideal Blood Pressure");
    }
    else if(80<=avg2 && avg2<=90 && 120<=avg1 && avg1<140)
    {
        printf("You have Pre-high Blood Pressure");
    }
    else if(90<=avg2 && avg2<100 && 140<=avg1 && avg1<190)
    {
        printf("You have High Blood Pressure");
    }
    else
    {
        printf("You have entered wrong values");
    }
}

// Average function used for calculating average SBP and DBP in BP function
int average(int array[],int size)
{
    int i, sum = 0,avg;

    for (i = 0; i < size; ++i)
    {
        sum += array[i];
    }

    avg = sum / size;
    return avg;
}

// ERICE function to calculate the ERICE risk score
void ERICE ()
{
    printf("\n\n\tYou have selected to assess ERICE risk score \n");
    printf("\t--------------------------------------------\n\n");

    int age;
    printf("Enter Your age : ");
    scanf("%d",&age);

    // Printing category or calling functions based on age group
    if (age <= 39)
    {
        printf("\nYour ERICE risk score category is in category of : Low");
    }
    else if (40 <= age && age <= 49)
    {
        age40_49();
    }
    else if (50 <= age && age <= 59)
    {
        age50_59();
    }
    else if (60 <= age && age <= 69)
    {
        age60_69();
    }
    else if (70 <= age && age <= 79)
    {
        age70_79();
    }
    else
    {
        printf("\nYour ERICE risk score category is in category of : Very High");
    }

}

// Different age group functions

char age40_49()
{
    if (Gender() == 'F')
    {
        printf("Low");
    }
    else
    {
        char D=Diabetes();
        int S=SBP();

        if (D == 'Y' && ((S >= 180) || (160 <= S && S < 180 && Smoke() == 'N' && Cholesterol() >= 6.5) || (140 < S && Smoke() == 'Y')))
        {
            printf("\nYour ERICE risk score category is in category of : Mild");
        }
        else if ((D == 'N' && Smoke() == 'Y') && ((160 <= S && S < 180 && Cholesterol() >= 6.5) || (S >= 180 && Cholesterol() >= 5.2)))
        {
            printf("\nYour ERICE risk score category is in category of : Mild");
        }
        else
        {
            printf("\nYour ERICE risk score category is in category of : Low");
        }
    }

 }

char age50_59()
{
    if (Gender() == 'F')
        {
            char D=Diabetes();
            int S=SBP();

            if ((D == 'Y' && S < 180  &&  Smoke() == 'Y') || (S >= 180 && ((D == 'Y' && Smoke() == 'N') ||(D == 'N' && Smoke() == 'Y'))))
            {
                printf("\nYour ERICE risk score category is in category of : Moderate");
            }
            else if ((S < 180) || (D =='N' && Smoke() == 'N'))
            {
                printf("\nYour ERICE risk score category is in category of : Mild");
            }
            else
            {
                printf("\nYour ERICE risk score category is in category of : Moderate High");
            }

        }
    else
        {
            char D=Diabetes();
            int S=SBP();
            float C;

            if (D == 'Y' && 160 <= S && Smoke() == 'Y')
            {
                printf("\nYour ERICE risk score category is in category of : Moderate High");
            }
            else if((S >= 140 && ((D == 'Y' && Smoke() == 'N') || (D == 'N' && Smoke() == 'Y') || (S < 160 && Smoke() =='Y'))))
            {
                printf("\nYour ERICE risk score category is in category of : Moderate");
            }
            else if(S < 140 && Smoke() == 'N')
            {
                printf("\nYour ERICE risk score category is in category of : Mild");
            }
            else if (C=Cholesterol() && ((S < 140 && 5.2 <= C && C <= 7.7 && Smoke() == 'Y') || (S >= 180 && C >= 5.2)))
            {
                printf("\nYour ERICE risk score category is in category of : Moderate");
            }
            else
            {
                printf("\nYour ERICE risk score category is in category of : Mild");
            }
        }
}

char age60_69()
{
    if (Gender() == 'F')
    {
        char D=Diabetes();
        int S=SBP();
        char M;

        if((D =='Y' && S >= 180) || (M=Smoke() && (D =='N' && S >= 180 && M =='Y')))
        {
            printf("\nYour ERICE risk score category is in category of : High");
        }
        else if(D =='Y' && M == 'Y')
        {
            printf("\nYour ERICE risk score category is in category of : Moderate High");
        }
        else if(D =='N' && M == 'N' && S < 180)
        {
            printf("\nYour ERICE risk score category is in category of : Mild");
        }
        else
        {
            printf("\nYour ERICE risk score category is in category of : Moderate");
        }
    }
    else
    {
        char D=Diabetes(), M=Smoke();
        int S=SBP();

        if( D =='Y' &&  M == 'Y' && ((S >= 180) || (S >= 160 && S < 180 && Cholesterol() >= 6.5)))
        {
            printf("\nYour ERICE risk score category is in category of : Very High");
        }
        else if((D == 'Y' && S >= 140 ) || (D =='N' && S >= 140 && M =='Y' ))
        {
            printf("\nYour ERICE risk score category is in category of : High");
        }
        else if((D == 'N' && S >= 140 && M == 'N') || (D == 'Y' && M == 'Y' ) || (D == 'Y' && M == 'N' && Cholesterol() >= 5.2 ) || (D =='N' && M == 'Y' && Cholesterol() >= 5.2))
        {
            printf("\nYour ERICE risk score category is in category of : Moderate High");
        }
        else
        {
            printf("\nYour ERICE risk score category is in category of : Low");
        }
    }

}

char age70_79()
{
    if (Gender() == 'F')
    {
        char D=Diabetes(),M;
        int S=SBP();

        if ((D == 'Y' && S >= 180) || (M = Smoke() && (D== 'Y' && S >= 140 && M == 'Y')) || (M == 'Y' && S >= 180))
        {
            printf("\nYour ERICE risk score category is in category of : Very High");
        }
        else if (D == 'N' && S < 180 && M == 'N')
        {
            printf("\nYour ERICE risk score category is in category of : Moderate High");
        }
        else
        {
            printf("\nYour ERICE risk score category is in category of : High");
        }
    }
    else
    {
        char D=Diabetes(),M;
        int S=SBP();

        if (D == 'Y' && S < 140)
        {
            printf("\nYour ERICE risk score category is in category of : High");
        }
        else if((D == 'Y' && S >= 140) || (M = Smoke() && (D == 'N' && S >= 140 && M == 'Y')))
        {
            printf("\nYour ERICE risk score category is in category of : Very High");
        }
        else if ((D =='N' && S >= 140 && M =='N') || (D =='N' && S < 140 && M =='Y'))
        {
            printf("\nYour ERICE risk score category is in category of : High");
        }
        else
        {
            printf("\nYour ERICE risk score category is in category of : Moderate High");
        }
    }

}

// Gender function to take in gender
char Gender()
{
    char gender;
    printf("Enter your Gender (M/F): ");
    scanf(" %c",&gender);

    while (gender != 'M' && gender != 'F')
    {
        printf(" \nSorry wrong input.\n\nEnter value again (M/F) :  ");
        scanf(" %c",&gender);
    }

    return gender;
}

// Diabetes function to take in if person has diabetes or not
char Diabetes()
{
    char diabetes;
    printf("Do you have Diabetes (Y/N) : ");
    scanf(" %c",&diabetes);

    while (diabetes != 'Y' && diabetes != 'N')
    {
        printf(" \nSorry wrong input.\n\nEnter value again (Y/N) :  ");
        scanf(" %c",&diabetes);
    }

    return diabetes;
}

// Smoke function to take in if person smokes or not
char Smoke()
{
    char  smoke;
    printf("Do you Smoke (Y/N) : ");
    scanf(" %c",&smoke);

    while (smoke != 'Y' && smoke != 'N')
    {
        printf(" \nSorry wrong input.\n\nEnter value again (Y/N) : ");
        scanf(" %c",&smoke);
    }

    return smoke;
}

// Cholesterol function to take in users cholesterol
float Cholesterol()
{
    float  cholestrol;
    printf("Enter Your Cholestrol level : ");
    scanf("%.1f",&cholestrol);
    return cholestrol;
}

// SBP function to take in users Systolic Blood Pressure
int SBP ()
{
    int Sbp;
    printf("Enter Your Systolic Blood Pressure (SBP) : ");
    scanf("%d",&Sbp);
    return Sbp;
}
