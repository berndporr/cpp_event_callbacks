#include <stdio.h>
#include "KeypressPublisher.h"
#include <unistd.h>

class KeypressSubscriber {
public:
    void anevent() {
	fprintf(stdout,"Buh! ");
	fflush(stdout);
    }
};

int main( int, const char**) {
	KeypressPublisher keypressPublisher;
	KeypressSubscriber keypressSubscriber;
	keypressPublisher.registerEventCallback(
	    [&](){keypressSubscriber.anevent();}
	    );

	keypressPublisher.start();

	// need to implement ctrl-c here really!
	while (true) {
	    std::this_thread::sleep_for(std::chrono::seconds(60));
	}

	printf("\n");
}
