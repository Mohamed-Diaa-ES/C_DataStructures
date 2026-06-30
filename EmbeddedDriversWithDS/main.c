#include "CircularLiknedList/CircularLinkedList.h"
#include "HAL/LCD_128/LCD_Interface.h"
#include <util/delay.h>
/**
 * @note function is written by AI I could not know how to show some test for that :(
 */

 void LCD_TESTING()
 {
        hLCD_Clear(1);
    hLCD_Clear(2);
    hLCD_SetCursor(1, 0);
    
    C_InsertTaskPriority(taskQueue, 1, 5, "Read Sensors");
    CLL_InsertTaskPriority(taskQueue, 2, 1, "Emergency Stop"); 
    CLL_InsertTaskPriority(taskQueue, 3, 3, "Update Display");
    CLL_InsertTaskPriority(taskQueue, 4, 10, "Log Data");      
    CLL_InsertTaskPriority(taskQueue, 5, 2, "Motor Control");
    CLL_InsertTaskPriority(taskQueue, 6, 7, "Check Battery");
    CLL_InsertTaskPriority(taskQueue, 7, 4, "Process Comms");
    CLL_InsertTaskPriority(taskQueue, 8, 8, "Self Test");
    CLL_InsertTaskPriority(taskQueue, 9, 6, "Read Inputs");
    CLL_InsertTaskPriority(taskQueue, 10, 0, "System Fault");  
    CLL_InsertTaskPriority(taskQueue, 11, 12, "Sync Clock");
    CLL_InsertTaskPriority(taskQueue, 12, 9, "Save Config");
    CLL_InsertTaskPriority(taskQueue, 13, 5, "Filter Data");
    CLL_InsertTaskPriority(taskQueue, 14, 2, "PID Compute");
    CLL_InsertTaskPriority(taskQueue, 15, 11, "Send Ping");
    CLL_InsertTaskPriority(taskQueue, 16, 4, "Refresh UI");
    CLL_InsertTaskPriority(taskQueue, 17, 3, "Check Memory");
    CLL_InsertTaskPriority(taskQueue, 18, 15, "Idle Task");    
    CLL_InsertTaskPriority(taskQueue, 19, 1, "Watchdog Reset");
    CLL_InsertTaskPriority(taskQueue, 20, 8, "Calibrate");LL

   
    while (taskQueue->Size > 0)
    {
       
        TaskNode_t* currentTask = CLL_GetHighestPriorityTask(taskQueue);
        
        if (currentTask != NULL)
        {
            /* Display task info on the LCD */
            hLCD_DisplayTask(currentTask->TaskNum, currentTask->Priority, currentTask->TaskName);

            /* Simulate task execution time */
            _delay_ms(1500);

            /* Remove the completed task from the queue */
            CLL_PopHighestPriorityTask(taskQueue);
        }
    }

    /* 5. All tasks completed */
    hLCD_Clear(1);
    hLCD_Clear(2);
    hLCD_SetCursor(1, 0);
    hLCD_WriteString("Queue Empty!");
    hLCD_SetCursor(2, 0);
    hLCD_WriteString("All Tasks Done");
 }
int main(void)
{

    hLCD_Init();
    CircularLinkedList_t* taskQueue = CLL_Init();



    while (1)
    {
        LCD_TESTING();
    }

    return 0;
}