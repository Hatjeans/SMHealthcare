//
//  cal_exercise.c
//  Excercise for Calorie Diary
//
//  Created by Eunju Cha
//  Developed by Haejin Lee
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cal_exercise.h"
#include "cal_diets.h"
#include "cal_healthdata.h"

#define MAX_EXERCISES 100  			// Maximum number of exercises
#define MAX_EXERCISE_NAME_LEN 50	// Maximum length of the name of exercise





// To declare the structure of the exercises
static Exercise exercise_list[MAX_EXERCISES]; //[코드작성] 1- 운동  관련 정보를 담을 exercise_list[]라는 database 
int exercise_list_size = 0;






/*
    description : read the information in "excercises.txt"
*/


// Project 응용 - 구조체화 3. 기존함수의 수정  
// 								  - loadExercises(const char* EXERCISEFILEPATH)  

 
void loadExercises(const char* EXERCISEFILEPATH) {
	
	
	char word[100];//[코드작성] 1 - 파일에서 읽어올 글자를 한글자씩 담는 일시적인 배열  
	int calories; //[코드작성] 1 - 파일에서 읽어올 글자를 한글자씩 담는 일시적인 변수  
	int cnt=0; // [코드작성] 1 - diet_list[]라는 database에 몇번째로 들어가는지 필요한 인덱스 개념 
	int i;
	
    FILE *file = fopen(EXERCISEFILEPATH, "r");
    
    if (file == NULL) {
        printf("There is no file for exercises! \n");
        return;
    }

    // ToCode: to read a list of the exercises from the given file
    // 운동의 후보군은 'exercise.txt' 파일로부터 읽어와서 저장하며, 아래와 같은 형식으로 저장하고 있음.
	// (사용자가 선택한 운동)*(운동시간 [min]) = (총 소모 칼로리 [kcal]) 
			
    while (fscanf(file, "%s %d", word, &calories) != EOF) {
    	
        if (exercise_list_size >= MAX_EXERCISES){ 
        	break;
		}
	
		strcpy(exercise_list[cnt].exercise_name, word); //strcpy함수를 이용하여 일시적 배열에 담은 단어를 diet_list.food_name 구조제 database에 복사  
		exercise_list[cnt].calories_burned_per_minute = calories; // 일시적 변수에 담은 칼로리 양을 diet_list.calories_intake 구조제 database에 복사 
		
		
		
		cnt++; //[코드작성] 1 - exercise_name과 calories_burned_per_minute가 저장되었을 때마다 카운트 수 증가 
// Project 응용 - 구조체화 4. 파일로 부터 읽은 내용을 구조체 멤버 값에 대입
//								- 파일로 부터 데이터 읽는 함수 (fscanf, fgetc, fgets) 활용
//								- 구조체 멤버 접근 방법 활용   
    }
    exercise_list_size = cnt; //[코드작성] 1 - 저장된 데이터 개수를 카운터 변수를 통해 업데이트 
    fclose(file);
}


/*
    description : to enter the selected exercise and the total calories burned in the health data
    input parameters : health_data - data object to which the selected exercise and its calories are added 
    return value : No
    
    operation : 1. provide the options for the exercises to be selected
    			2. enter the duration of the exercise
    			3. enter the selected exercise and the total calories burned in the health data
*/


void inputExercise(HealthData* health_data) {
    int choice, duration, i;
    
    int cnt; // 카운트를 위해 추가  
    
    // ToCode: to provide the options for the exercises to be selected
    printf("The list of exercises: \n");
    
	for(i=0;i<exercise_list_size;i++)
		printf("%d : %s %d kcal per min \n",i+1,exercise_list[i].exercise_name,exercise_list[i].calories_burned_per_minute);


    // ToCode: to enter the exercise to be chosen with exit option
    //** exit option과 함께 제공해야함 
	printf("\nEnter the option number of exercise you've done\n");
	printf("(If you want to go to the home menu, press -1)\n");
	printf(" : ");
	scanf("%d", &choice);
	
	if (choice == -1) 
		return;


    // To enter the duration of the exercise
    printf("You choose < %d : %s > \n", choice, exercise_list[choice-1].exercise_name);
    printf("Enter the duration of the exercise (in min.): ");
    scanf("%d", &duration);
    
    printf("You burned %d kcal total", (exercise_list[choice-1].calories_burned_per_minute)*duration);
    
    
    
    // ToCode: to enter the selected exercise and total calcories burned in the health data
	my_health_data_history[cnt].total_calories_burned = (exercise_list[choice-1].calories_burned_per_minute)*duration;


	cnt++;
	


/*
Exercise exercises[MAX_EXERCISES];  // exercise history 
// Typedef를 이용하여 exercises 구조체를 정의해서 주셨다. 
//exercise_count변수를 이용해서  운동을 했을때마다 순서가 매겨지는 것을 이용하면 좋을 것 같다.  
 
    Diet diet[MAX_DIETS];                // diet history
// Typedef를 이용하여 Diet 구조체를 정의해서 주셨다. 
//diet_count변수를 이용해서  운동을 했을때마다 순서가 매겨지는 것을 이용하면 좋을 것 같다.  
    
    int exercise_count;                  // number of exercises
    int diet_count;                      // number of diets
    int total_calories_burned;   
    
    
    
    exercise_name[MAX_EXERCISE_NAME_LEN];	// the name of the exercise
    int calories_burned_per_minute
*/
}




//[코드작성]1 - exercise_list가 static선언 되어있어서 main함수에서 프린트하기가 까다로움 따라서 print하는 함수를 추가
void print_exercise_list(void) 
{
	int i;
	
	for(i=0;i<exercise_list_size;i++)
	printf("%s %d kcal per min \n",exercise_list[i].exercise_name,exercise_list[i].calories_burned_per_minute);
}

