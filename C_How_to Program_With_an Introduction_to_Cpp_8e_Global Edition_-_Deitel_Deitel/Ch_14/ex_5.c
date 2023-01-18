#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

void ctrlCHandler(int);

int main(void)
{
  signal(SIGINT, ctrlCHandler);

  while (1) {
     puts("Enter Ctrl-C:");
     pause();
  }
  abort();
}

void ctrlCHandler(int sig)
{
  char c;

  signal(sig, SIG_IGN);
  printf("%s\n%s\n", "OUCH, did you hit Ctrl-C?",
	 "Do you really want to quit? [y/n]");

  c = getchar();

  if (c == 'y' || c == 'Y') {
    exit(0);
  }
  else {
    signal(SIGINT, ctrlCHandler);
  }
  getchar();
}
