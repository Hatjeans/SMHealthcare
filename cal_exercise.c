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



//[코드작성] 1. 프로그램 시작과 함께 exercise.txt로부터 운동관련 정보를 읽어와 exercise_list[]라는 database 배열에 저장 *주로 loadExercise함수와 관련  
//[코드작성] 2. choice가 1일때 exercise_list를 출력 *주로 inputExercise함수와 관련  



// To declare the structure of the exercises
static Exercise exercise_list[MAX_EXERCISES]; //[코드작성] 1- 운동 관련 정보를 담을 exercise_list[]라는 database 
int exercise_list_size = 0;






/*
    description : read the information in "excercises.txt"
*/


// Project 응용 - 구조체화 3. 기존함수의 수정  
// 								  - loadExercises(const char* EXERCISEFILEPATH)  

 
 //[코드작성] 1. 프로그램 시작과 함께 exercise.txt로부터 운동관련 정보를 읽어와 exercise_list[]라는 database 배열에 저장 *주로 loadExercise함수와 관련  
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
	
		strcpy(exercise_list[cnt].exercise_name, word); //[코드작성] 1 - strcpy함수를 이용하여 일시적 배열에 담은 단어를 diet_list.food_name 구조제 database에 복사  
		exercise_list[cnt].calories_burned_per_minute = calories; //[코드작성] 1 - 일시적 변수에 담은 칼로리 양을 diet_list.calories_intake 구조제 database에 복사 
		
		
		
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






//[코드작성] 2. choice가 1일때 exercise_list를 출력 *주로 inputExercise함수와 관련  
void inputExercise(HealthData* health_data) {
    int choice, duration, i;
    int calculation;//+추가설명 : 뒤에 calories_per_minute과 duration을 곱한 총 칼로리를 저장할 변수를 설정. total_calories로 하려했으나 다른 파일에 비슷한 변수가 존재해 calculation으로 표현.  
    
    // ToCode: to provide the options for the exercises to be selected
    printf("The list of exercises: \n");
    
    
    //[코드작성] 2 - [코드작성] 1에서 exercise_list[] 배열에 저장한 운동항목들을 불러와서 출력함. 
    
	for(i=0;i<exercise_list_size;i++)
		printf("%d : %s %d kcal per min \n",i+1,exercise_list[i].exercise_name,exercise_list[i].calories_burned_per_minute); 
		// + 추가설명 : 인덱스를 1부터 시작하게끔 만들었음
		 


    // ToCode: to enter the exercise to be chosen with exit option
    //** exit option과 함께 제공해야함 

    //[코드작성] 2 - 사용자가 리스트들을 보고 입력한 항목을 scanf로 잠시 담아두는 choice 변수에 저장 
	printf("\nEnter the option number of exercise you've done\n");
	printf("(If you want to go to the home menu, press -1)\n");
	printf(" : ");
	scanf("%d", &choice);
	
	//[코드작성] 2 - exit option으로 -1을 넣으면 exit하여 다시 [Healthcare Management Systems] 시스템에 돌아갈 수 있도록 함. 
	if (choice == -1) 
		return;


    // To enter the duration of the exercise
    //[코드작성] 2 - 입력한 항목을 보여줌  
    printf("You choose < %d : %s > \n", choice, exercise_list[choice-1].exercise_name);
    
    //[코드작성] 2 - 운동한 시간을 받을 수 있는 duration 변수를 이용하여 scanf로 해당 값을 받음.  
    printf("Enter the duration of the exercise (in min.): ");
    scanf("%d", &duration);
    
    //[코드작성] 2 - exercis_list와 duration의 간단한 곱셈연산으로 소모한 총 칼로리(calculation)를 계산하고 그 값을 사용자에게 보여줌  
    calculation =  (exercise_list[choice-1].calories_burned_per_minute)*duration;
    printf("You burned %d kcal total\n", calculation);
    
    
    
    // ToCode: to enter the selected exercise and total calcories burned in the health data

	//[코드작성] 2 - health_data 포인터와 ->연산자를  사용하여 database구조체의 exercise[]멤버에 접근
	//				이때 exercise[]는 배열 멤버로 배열의 인덱스는 exercise를 입력받는 횟수인 exercise_count를 사용함. 
	//				exercise_count접근을 위해 healt_data 포인터와  -> 연산자를 활용! 
	// 
	//				database구조체 내 exercise[]배열의 멤버는 calories_burned_per_minute와 exercise_name임
	//				그런데, 우리는 database 속 exercise[]배열에 사용자가 선택한 운동의 이름과 입력받은 duration 동안 소모한 총 칼로리를 저장해야함
	//				운동의 이름은 exercise_name멤버에 저장하면 되어 문제가 되지 않으나,
	//				duration동안 소모한 총 칼로리를 저장할 공간이 마땅하지 않음. 
	//
	//				구조체를 새로 정의하기 힘드므로 기존의 구조체멤버와 구성을 최대한 활용하기 위해서
	//				calories_burned_per_minute라는 멤버를 그냥 duration 동안 소모한 총 칼로리를 저장하는 공간으로 재사용하기로 함!!!!!
	//
	  
	//(a) database 속 exercise[]배열에 사용자가 선택한 운동의 이름을 입력한 순서대로 저장 
	strcpy(health_data->exercises[health_data->exercise_count].exercise_name,exercise_list[choice-1].exercise_name);
	//+추가설명 : strcpy(a,b) 함수를 이용하여 사용자가 선택한 운동의 이름(b)를 복사하여 exercise[]배열의 운동이름에 입력받는 순서(exercise_count)에 따라 저장 
	 
	 
	//(b) database 속 exercise[]배열의 calories_burned_per_minute맴버에 duration동안 소모한 총 칼로리를 입력한 순서대로 저장  
	health_data->exercises[health_data->exercise_count].calories_burned_per_minute = (exercise_list[choice-1].calories_burned_per_minute)*duration;
	//+추가설명 (좌변) : 구조체 포인터 health_data와 -> 연산자를 이용하여 duration 동안 소모한 총 칼로리를 저장하는 공간인 (이름만 per_minute인..) calories_burned_per_minute에 접근함 
	//          (우변) : 앞에서 구한 calculation을 exercise[]배열의 calories_burned_per_minute멤버에 저장                              
	
	
	
	// database에 잘 저장되었는지 확인하기 위한 장치  
	printf("%d %s \n",	health_data->exercises[health_data->exercise_count].calories_burned_per_minute,health_data->exercises[health_data->exercise_count].exercise_name );
	
	//[코드작성] 2 - 입력할 때마다 순서를 늘려주어야 하므로 후위 연산자를 사용  
	health_data->exercise_count++;
	
	// 순서가 잘 증가하는지 확인하기 위한 장치  
	printf("%d\n",health_data->exercise_count);


	


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

