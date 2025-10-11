//To find the current action of a signal using sigaction.
#include<stdio.h>
#include<signal.h>

void isr(int n){
	printf("IN ISR..\n");
}

int main(){
	signal(2,isr);
	struct sigaction newsignal,oldsignal;

	newsignal.sa_handler = isr;
	sigemptyset(&newsignal.sa_mask);
	newsignal.sa_flags = 0;//means there is no flags
	
	sigaction(2,&newsignal,&oldsignal);

	printf("The Old Signal: ");
	if(oldsignal.sa_handler == SIG_DFL)
		printf("Default\n");
	else if(oldsignal.sa_handler == SIG_IGN)
		printf("Ignore\n");
	else
		printf("isr\n");

	printf("Infinite Process\n");
	while(1);

}
