//
//  cal_diets.c
//  Diets for Calorie Diary
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

#define MAX_DIETS 100      			// Maximum number of diets
#define MAX_FOOD_NAME_LEN 50		// Maximum length of the name of food

//[�ڵ��ۼ�] 1.���α׷� ���۰� �Բ� diet.txt�κ��� �Ĵܰ��� ������ �о�� diet_list[]��� database �迭�� ����



// list of diets 
static Diet diet_list[MAX_DIETS]; //[�ڵ��ۼ�] 1 - �Ĵ� ���� ������ ���� diet_list[]��� database 
static int diet_list_size = 0;  


/*
    description : read the information in "diets.txt"
*/



// Project ���� - ����üȭ 3. �����Լ��� ����  
// 								 loadDiets(const char* DIETFILEPATH) �̿��ϱ� 


void loadDiets(const char* DIETFILEPATH) {
	
	char word[100];//[�ڵ��ۼ�] 1 - ���Ͽ��� �о�� ���ڸ� �ѱ��ھ� ��� �Ͻ����� �迭  
	int calories; //[�ڵ��ۼ�] 1 - ���Ͽ��� �о�� ���ڸ� �ѱ��ھ� ��� �Ͻ����� ����  
	int cnt=0; // [�ڵ��ۼ�] 1 - diet_list[]��� database�� ���°�� ������ �ʿ��� �ε��� ���� 
	
	
	
    FILE *file = fopen(DIETFILEPATH, "r"); //DIETFILEPATH == "diet.txt"
    
	//������ �ҷ��� �� �ְ� �ڵ带 ¥���� 
    // * ������ �ǽ� : week 11 [�ǽ�3], [�ǽ�6] 
    if (file == NULL) {
        printf("There is no file for diets! \n");
        return;
    }

     // ToCode: to read a list of the diets from the given file
    while (fscanf(file, "%s %d", word, &calories) != EOF) {
    	
        if (diet_list_size >= MAX_DIETS){ 
        	break;
		}

		printf("%s %d", word, calories);
		
		diet_list[cnt].food_name = strcpy(diet_list.food_name, word); //strcpy�Լ��� �̿��Ͽ� �Ͻ��� �迭�� ���� �ܾ diet_list.food_name ������ database�� ����  
		diet_list[cnt].calories_intake = calories; // �Ͻ��� ������ ���� Į�θ� ���� diet_list.calories_intake ������ database�� ���� 
		
		// ** diet_list[cnt].calories_intake���� diet_list.calories_intake[cnt]���� �𸣰����� ���ڰ� �´µ� 
		
		cnt++;
// Project ���� - ����üȭ 4. ���Ϸ� ���� ���� ������ ����ü ��� ���� ����
//								- ���Ϸ� ���� ������ �д� �Լ� (fscanf, fgetc, fgets) Ȱ��
//								- ����ü ��� ���� ��� Ȱ��   
    }
    fclose(file);
}

/*
    description : to enter the selected diet and the total calories intake in the health data
    input parameters : health_data - data object to which the selected diet and its calories are added 
    return value : No
    
    operation : 1. provide the options for the diets to be selected
    			2. enter the selected diet and the total calories intake in the health data
*/

void inputDiet(HealthData* health_data) {
    int choice, i;
    
    // ToCode: to provide the options for the diets to be selected
    printf("The list of diets:\n");
    
    
	// ToCode: to enter the diet to be chosen with exit option
    

    // ToCode: to enter the selected diet in the health data
    

    // ToCode: to enter the total calories intake in the health data


}

