 #include <stdio.h>

int main(void)
{
  int a = 1 + (1 + 7) % 13;
  int b = 1 + (2 + 7) % 13;
  int c = 1 + (3 + 7) % 13;
  int d = 1 + (4 + 7) % 13;
  int f = 1 + (5 + 7) % 13;
  int g = 1 + (6 + 7) % 13;
  int h = 1 + (7 + 7) % 13;
  int i = 1 + (8 + 7) % 13;
  int j = 1 + (9 + 7) % 13;
  int k = 1 + (10 + 7) % 13;
  int l = 1 + (11 + 7) % 13;
  int m = 1 + (12 + 7) % 13;
  int n = 1 + (13 + 7) % 13;

  printf("\n%d %d %d %d %d %d %d %d %d %d %d %d %d\n",
	 a, b, c, d, f, g, h, i, j, k, l, m, n);
}


void straight(int sequence[], char *hands[][2])
{
  int straight = 1;
  int max = 0;
  
  for (int i = 0; i < 4; i++) {

    for (size_t j = 0; j < 4; j++) {

      if (sequence[j] >= sequence[j + 1]) {
	int temp = sequence[j];
	sequence[j] = sequence[j + 1];
	sequence[j + 1] = temp;
      }
      max = sequence[j];
    }
  }

  for (int i = 0; i < 4; i++) {

    for (size_t j = 0; j < 4; j++) {

      if (sequence[j] = max - 1) {
	max = sequence[j];
	straight++;
      }

      if (straight == 5) {
	printf("\n%16s\n", "** Straight **");
	i = 4;
	j = 4;
      }
    }
  }
}

  for (size_t i = 0; i < 5; i++) {

    maxValue = 1 + (sequence[i] + 7) % 13;

    if (maxValue > max) {
      max = maxValue;
    }
  }
  
  for (int pass = 0; pass < 5; pass++) {

    for (int card = 0; card < 5; card++) {

      maxCard = 1 + (sequence[card] + 7) % 13;            
      printf("Maxcard: %d\tMax: %d\t", maxCard, max);
      if (maxCard == max - 1) {
	max = maxCard;
	straight++;
      }

      if (straight == 4 && maxCard == max - 1) {
	straight++;
      }
      printf("straight: %d\n", straight);
      if (straight == 5) {
	printf("\n%16s\n", "** Straight **");
	/* printf("\n%5s%s%-8s\n\n%5s%s%-8s\n\n%5s%s%-8s\n\n%5s%s%-8s\n\n%5s%s%-8s\n\n", */
	/*        hand[max][0], " of ", hand[max][1], */
	/*        hand[max][0], " of ", hand[max][1], */
	/*        hand[max][0], " of ", hand[max][1], */
	/*        hand[max][0], " of ", hand[max][1], */
	/*        hand[max][0], " of ", hand[max][1]); */
	pass = 5;
	card = 5;
      }
    }
