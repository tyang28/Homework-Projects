//Ex1-3: gpaSimple.c


/* The purpose of this program is to compute GPAs for simple letter
   grades - no +/-, only A, B, C, D, F. Credits may be rational
   numbers.  Also determine and display notices for Dean's List
   (>=3.5) and Academic Probation (< 2.0).

SAMPLE RUN:

Welcome to the GPA program!
Enter grade and credits for each course below (Q to end):
course 1: A 4.0
course 2: b 2.7
course 3: B 3.5
course 4: c 3.0
course 5: f 1
course 6: a 3
course 7: Q
Your GPA is 3.06

PSEUDOCODE:

count gets 1
pointSum gets 0
creditSum gets 0
points gets 0
gpa gets 0

display “Welcome to GPA calculator”
prompt for grade & credits
display "course #", count

repeat while there is unread input
    read grade
    [convert grade to points]
    read credits
    add points * credits to pointSum
    add credits to creditSum
    add 1 to count
    display "course #", count

if creditSum > 0
   set gpa to pointSum / creditSum

display "GPA is ", gpa

if gpa >= 3.5
   display "Dean's List"
otherwise if count > 1 and gpa <= 2.0
   display "Uh-oh, Ac Pro..."

*/


#include <stdio.h>

int main(void) {


    //TO DO: add your code here so that your program
    //produces output that would be identical to the
    //given sample run when provided the same input


    return 0;
}
