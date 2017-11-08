// Chris Fleming ch980803
#include <stdio.h>
#include "SmartArray.h"
#include <stdlib.h>
#include <string.h>
   
    SmartArray *createSmartArray(int length){
        int i, max = DEFAULT_INIT_LEN;
        
        SmartArray *smarty = malloc(sizeof(SmartArray));
        if(smarty == NULL)
            return NULL;
        
        if(length > DEFAULT_INIT_LEN)
            max = length;
        smarty->array = malloc(sizeof(char*)*max);
        if(smarty->array == NULL)
            return NULL;
               
        for(i=0; i<max; i++)
            smarty->array[i] = NULL;
            
        smarty->size = 0;
        smarty->capacity = max;
        
        printf("-> Created new SmartArray of size %d.\n", max);
        
        return smarty;
    }
    
    
    SmartArray *destroySmartArray(SmartArray *smarty){
        int i;
        
        if(smarty == NULL)
            return NULL;
            
            for(i=0;i<smarty->capacity;i++) 
                free(smarty->array[i]);
            free(smarty->array); 
            smarty->array = NULL;
        
        free(smarty);
        smarty = NULL;
        
        return smarty;
    }
    
    
    SmartArray *expandSmartArray(SmartArray *smarty, int length){
        int i;
        
         if(smarty == NULL)
            return NULL;
            
            if(smarty->capacity >= length)
                return NULL;
            else{
                char **expand = malloc(sizeof(char*)*(length+1));
                if(expand == NULL)
                    return NULL;
                for(i=0;i<length;i++)
                    if(i < smarty->capacity)
                        expand[i] = smarty->array[i];   
                    else 
                        expand[i] = NULL;     
                
                free(smarty->array);
                smarty->array = expand;
                smarty->capacity = length;
                printf("-> Expanded SmartArray to size %d.\n", length);
                return smarty;
            }
     
    }
    
    
    SmartArray *trimSmartArray(SmartArray *smarty){
        int i;
        
        if(smarty->array == NULL)
            return NULL;
            if(smarty->capacity > smarty->size){
                char **trim = malloc(sizeof(char*)*(smarty->size+1));
                if(trim == NULL)
                    return NULL;
                for(i=0;i<smarty->size;i++)
                    trim[i] = smarty->array[i];
                free(smarty->array);
                smarty->array = trim;
                smarty->capacity = smarty->size;
                printf("-> Trimmed SmartArray to size %d.\n",smarty->size);
                return smarty;
            }
            else
                return NULL;
    }
    
    char *put(SmartArray *smarty, char *str){
        int i;
        SmartArray *e = NULL;
        
        if(smarty == NULL || str == NULL)
            return NULL;
            
        if(smarty->size == smarty->capacity){
            e = expandSmartArray(smarty,(smarty->capacity*2+1));
            if(e == NULL)
                return NULL;
        }     
        smarty->array[smarty->size] = malloc(sizeof(char) * (strlen(str)+1));
        if(smarty->array[smarty->size] == NULL)
            return NULL;
        strcpy(smarty->array[smarty->size], str);
        smarty->size++;
        return smarty->array[smarty->size-1];  
             
    }
    
    
    char *get(SmartArray *smarty, int index){
        if(smarty == NULL)
            return NULL;
        
        if(index < smarty->size && index >= 0)
            return smarty->array[index];
        else
            return NULL;
        
         
    }
    
    
    char *set(SmartArray *smarty, int index, char *str){
        
        if(smarty == NULL || str == NULL)
            return NULL;
        if(index < 0 || index >= smarty->size)
           return NULL;   
        if(smarty->array[index] == NULL)
            return NULL;
            
        free(smarty->array[index]);

        smarty->array[index] = malloc(sizeof(char)*(strlen(str)+1));
        if(smarty->array[index] == NULL)
            return NULL;
        else{
            strcpy(smarty->array[index],str);
            return smarty->array[index];
         }
            
    }
    
    char *insertElement(SmartArray *smarty, int index, char *str){
        int i;
        SmartArray *e = NULL;
        
        if(smarty == NULL || str == NULL)
            return NULL;
        
        if(smarty->size == smarty->capacity){
            e = expandSmartArray(smarty,(smarty->capacity*2+1));
            if(e == NULL)
                return NULL;
        }         
        if(index >= smarty->size)
            return put(smarty, str);
        
        char *strtemp = malloc(sizeof(char)*(strlen(str)+1));
        if(strtemp == NULL)
            return NULL;   
        strcpy(strtemp, str); 
        smarty->size ++;  
        for(i=smarty->size;i>index;i--)
            smarty->array[i] = smarty->array[i-1];
        smarty->array[index] = NULL;
        smarty->array[index] = strtemp;
           
           
        return smarty->array[index];    
    }
    
    int removeElement(SmartArray *smarty, int index){
        int i;
        
        if(smarty == NULL || smarty->size <1)
            return 0;
            
        if(index >= smarty->size || index < 0)
            return 0;
        free(smarty->array[index]);
        smarty->array[index] = NULL;
        for(i=index;i<smarty->size-1; i++){
            smarty->array[i] = smarty->array[i+1];
               
        }
        smarty->array[smarty->size-1] = NULL;
        smarty->size--;
        return 1;  
    } 
    
    int getSize(SmartArray *smarty){
        int i, sz=0;
        
        if(smarty == NULL)
            return -1;
        
        if(smarty->capacity >= 0){
            for(i=0;i<smarty->capacity;i++)
                if(smarty->array[i] != NULL)
                    sz++;
            return sz;
        }
        else
            return -1;    
    }
     
    void printSmartArray(SmartArray *smarty){
        int i;
        if(smarty == NULL || smarty->size ==0)
            printf("(empty array)\n");
        else
            for(i=0;i<smarty->size;i++)
                printf("%s\n", smarty->array[i]);        
    }
    
    double difficultyRating(void){
    
    return 4.5;
    }
    
    double hoursSpent(void){

    return 40.0;
    }
    
    
    
    
    
    
    
    
    
    
    
    
    
    
