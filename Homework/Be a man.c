#include <stdio.h>

int main() {
    int birth_year, height, weight, age;
    scanf("%d %d %d", &birth_year, &height, &weight);
    printf("Age = %d\n", age = 2020 - birth_year + 1);
    printf("Height = %dcm\n", height);
    printf("Weight = %dkg\n", weight);
    float height_2 = height / 100.0f, BMI;
    printf("BMI = %.1f\n", BMI = weight / height_2 / height_2);
    if (age < 19 || age > 36){
        printf("Not a Draftee (age < 19 or age > 36 years old)\n");
        printf("No need to perform Military Service");
    }
    else if (BMI >= 17.0f && BMI <= 31.0f){
        printf("Physical Status of Regular Service Draftees\n");
        if (birth_year >= 1994){
                printf("4 months of Regular Service");
        }
        else{
            printf("1 year of Regular Service");
        }
    }else if (BMI < 16.5f || BMI > 31.5f){
        printf("Physical Status of Military Service Exemption\n");
        printf("Exemption from Military Service");
    }else{
        printf("Physical Status of Substitute Service Draftees\n");
        if (birth_year >= 1994){
            printf("Replacement Service");
        }else{
            printf("Substitute Services");
        }
    }

    return 0;
}

