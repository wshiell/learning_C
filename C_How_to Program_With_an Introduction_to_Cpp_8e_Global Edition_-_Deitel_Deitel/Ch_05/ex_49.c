#include <stdio.h>

void quiz(void); // Define function 'quiz'

int main(void) // Begin function 'main'
{
  quiz(); // Run the quiz
}
// End funtion 'main'

void quiz(void) // Begin function 'quiz'
{
  //Define function variables

  int answer1, answer2, answer3, answer4, answer5, total = 0;
  
  // Heading
  
  puts("\n******************************************");
  puts("\n      Global Warming Facts Quiz\n");
  puts("\n******************************************");

  //Quiz Rules

  printf("%s", "\nThis quiz comprises of a set of five multiple choice ");
  printf("questions,\neach with four possible answers.\nEnter a number ");
  printf("between 1 and 4 to answer each question.\n");

  // Ask questions

  puts("\nQuestion #1:\n");
  puts("The earth is a:\n1. Sphere\n2. Cube\n3. Pyramid\n4. Apple\n");
  scanf("%d", &answer1);
  
  puts("\nQuestion #2:\n");
  puts("Clouds are your:\n1. Friends\n2. Enemies\n3. Elbows\n4. Worst nightmare\n");
  scanf("%d", &answer2);  

  puts("\nQuestion #3:\n");
  puts("The elephant was sweating because:\n1. He was hot\n2. Dunno\n3. He's big");
  puts("4. Elephants always sweat\n");
  scanf("%d", &answer3);  

  puts("\nQuestion #4:\n");
  puts("Orange is the new:\n1. Macarena\n2. Black\n3. Orange\n4. Tomato\n");
  scanf("%d", &answer4);  

  puts("\nQuestion #5:\n");
  puts("Warren is a:\n1. Wizard\n2. Warlock\n3. Witch\n4. Wiccan\n");
  scanf("%d", &answer5);

  // Total scores
  
  if (answer1 == 2) {
    total++;
  }
  if (answer2 == 2) {
    total++;
  }
  if (answer3 == 1) {
    total++;
  }
  if (answer4 == 3) {
    total++;
  }
  if (answer5 == 4) {
    total++;
  }
  
  // Print summary
  
  printf("%s", "\nThank you for taking the Global Warming Facts Quiz.\nYour ");
  printf("score was: %d\n", total);

  if (total == 5) {
    puts("\nExcellent!");
  }
  else if (total == 4) {
    puts("\nVery good!");
  }
  else if (total <= 3) {
    puts("\nTime to brush up on your knowledge of global warming");
    puts("\nFor more information, visit:\n\nhttp://www.globalwarmingfacts.com");
    puts("http://www.warmingfacts.org/truth.htm\nhttp://www.gwf.com\n");
  }
}
// End function 'quiz'
